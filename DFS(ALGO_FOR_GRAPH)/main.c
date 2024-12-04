#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
int adjacency[20][20];
int reached[20];
char letters[20];
int let_count=0,counter=1,ctrl_rv;
int edge_number=0,graph_size;

struct vertis{
 char X;
 int N;
 struct vertis *edge[19];
};

struct vertis *clone[20];
struct vertis *start=NULL;
//struct vertis *move_to_next=NULL;
struct vertis *memory_allocate(){
   int successful,successful_2,R,S,L;
   char C,O[5];
   struct vertis *IST;
   IST=(struct vertis *)malloc(sizeof(struct vertis)*1);
   successful:
   printf("ONLY LETTERS ARE VALID AS VERTEX NAME\n");
   printf("Please Enter A Letter To Name A %d.Vertex:",let_count+1);
   scanf("%c",&C);
   fflush(stdin);
   if((C>=65 && C<=90) || (C>=97 && C<=132)){
   letters[let_count]=IST->X=C;
   printf("let_count:%d\n",let_count);
   ++let_count;
   printf("let_count:%d\n",let_count);
   if(graph_size>1){
   successful_2:
   printf("How many edges does have this vertex?:");
   fgets(O,sizeof(O),stdin);
   S=strlen(O);
   if(O[S-1]!='\0'){
    O[S-1]='\0';
   }
   L=real_value(O,&R);
   if(L==1){
   printf("R:%d",R);
   if(R>graph_size){
    printf("YOUR EDGE NUMBER CANT BE MORE THAN GRAPH SIZE!\n");
    double_button();
    fflush(stdin);
    goto successful_2;
   }else{
    IST->N=R;
   }
   }else{
   printf("PLEASE ENTER AN INTEGER VALUE!");
   double_button();
   }
   }else{
   IST->N=1;
   printf("YOUR GRAPH CONSISTS OF ONLY ONE VERTIS SO EDGE NUMBER OF THIS VERTEX MUST BE ONLY 1\n");
   double_button();
   }
   return IST;
   }else{
   printf("INVALID NAME TYPE FOR VERTEX!");
   double_button();
   goto successful;
   }
}
int free_all_vertex(){
 int i=0;
 while(clone[graph_size-1]!=NULL){
    free(clone[i]);
    i++;
 }
 if(clone[0]==NULL && clone[graph_size-1]==NULL){
    return 1;
 }else{
    return 0;
 }
}
int real_value(char *T,int *sum){//HATALI FONKSIYON
 int ctrl_rv=0;
 char *X;
 *sum=0;
 X=T;
 while((*X!='\0') && (*X>='0') && (*X<='9')){
   (*sum)=(*sum)*10+(*X-'0');
   X++;
 }
 if(*X=='\0'){
   ctrl_rv=1;
 }
 return ctrl_rv;
}
void define_all_0(){
 int i,j;
 for(i=0; i<graph_size; i++){
    reached[i]=0;
   for(j=0; j<graph_size; j++){
    adjacency[i][j];
   }
 }
}
int find_X(char Q){
  int i;
  for(i=0; i<let_count; i++){
    if(Q==clone[i]->X)
       break;
  }
  return i;
}
void owner_of_code(){
 printf("THIS CODE IS WRITTEN BY OMER GOKSOY WHO IS COMPUTER PROGRAMMING STUDENT IN MALTEPE UNIVERSITY.\nIT CAN INCLUDES MISTAKES.DO NOT DELETE HERE\n");
}
void edge_connections(int size_ec_f,char letter_F){
  int i,j,k=0,ctrl,ctrl_2,ctrl_3,A;
  char C_F;
  A=find_X(letter_F);
  printf("A:%d\n",A);
  printf("***FOR VERTEX [%c]***\n",letter_F);
  printf("---------------\n");
  for(i=0; i<size_ec_f; i++){
    ctrl_2=0;
    ctrl:
    fflush(stdin);
    printf("WHICH VERTEX IS CONNECTED WITH THIS VERTEX?:");
    C_F=getchar();
    for(j=0; j<let_count; j++){
        if(C_F==letters[j]){
        ctrl_2=1;
        break;
        }
    }
    if(ctrl_2==1){
        clone[A]->edge[k]=clone[j];
        adjacency[A][j]=1;
        edge_number++;
        k++;
    }
    if(ctrl_2==0){
        printf("INPUT VALUE DOESN'T MATCH WITH VERTEX NAMES!PLEASE ENTER VALID LETTER\n");
        double_button();
        goto ctrl;
    }
  }
}
int create_graph(){
 int j,s,k;
 char F[4];
 s:
 printf("FOR RETURN MAIN MENU ENTER '-1'\n");
 printf("HOW MANY VERTEX DO YOU WANT TO CREATE?:");
 fgets(F,sizeof(F),stdin);
 getchar();
 sscanf(F,"%d",&k);
 if(graph_size>1){
 for(j=0; j<graph_size; j++){
    printf("\nj:%d\n",j);
    clone[j]=memory_allocate();
 }
 system("cls");
 for(j=0; j<graph_size; j++){
    edge_connections(clone[j]->N,clone[j]->X);
 }
 return 1;
 }else if(graph_size==1){
   clone[0]=memory_allocate();
   system("cls");
   edge_connections(clone[0]->N,clone[0]->X);
 return 1;
 }else if(graph_size==-1){
 printf("RETURNING TO MAIN MENU...\nPRESS ANY BUTTON TWO TIMES\n");
 return 0;
 }else{
 printf("WRONG VALUE ENTERED PLEASE ENTER A VALID NUMBER!");
 double_button();
 system("cls");
 goto s;
 }
 }
void double_button(){
    getch();
    getch();
}
void graph_info(){
  int i;
  printf("TOTAL VERTEX NUMBER:%d\n",graph_size);
  printf("TOTAL EDGE NUMBER:%d\n",edge_number);
  printf("----------------------\n");
  for(i=0; i<graph_size; i++){
  printf("VERTEX NAME:%c",clone[i]->X);
  printf("\tEDGE NUMBER OF %c:%d\n",clone[i]->X,clone[i]->N);
  printf("----------------------\n");
  }
  double_button();
}
int edgeptr_control(int o,struct vertis *XD){
    int i;
    for(i=0; i<XD->N; i++){
        if(letters[o]==XD->edge[i]->X){
            break;
        }
    }
    return i;
}
void depth_first_search(struct vertis *begin,int R){
 reached[R]=1;
 ++counter;
 int i,l;
 if(counter==graph_size){
 printf("%c",begin->X);
 }else{
 printf("%c->",begin->X);
 }
for(i=0; i<graph_size; i++){
  if((reached[i]==0) && (adjacency[R][i]==1)){
    l=edgeptr_control(i,begin);
    depth_first_search(begin->edge[l],i);
  }
 }
}
int control_for_dfs(){
 char D,ctrl_D;
 int i,j,again;
 fflush(stdin);
 again:
 printf("WHICH VERTEX DO YOU WANT TO DEFINE AS START VERTEX OF DFS ALGORITHM:");
 D=getchar();
 for(i=0; i<let_count; i++){
    if(D==clone[i]->X){
        ctrl_D='T';
        start=clone[i];
        break;
    }
 }
 if(ctrl_D!='T'){
    printf("ENTERENCE OF NON-EXIST VERTEX NAME, PLEASE ENTER VALID VERTEX\n");
    double_button();
    goto again;
 }else{
 return i;
 }
}
int main()
{
    int choice,Z,str_size;
    char ctrl_char[10];
    while(1){
        system("cls");
        printf("THIS CODE IS WRITTEN BY OMER GOKSOY WHO IS COMPUTER PROGRAMMING STUDENT AT MALTEPE UNIVERSITY.\nIT CAN BE INCLUDES LOGICAL MISTAKES,DO NOT DELETE HERE!\n");
        printf("FOR PROCESSING ON PROGRAM PRESS ANY BUTTON TWO TIMES\n");
        printf("FOR CREATE GRAPH PRESS [1] AND [ENTER]\n");
        printf("FOR DEPTH FIRST SEARCH ALGORITHM PRESS BUTTON [2] AND [ENTER]\n");
        printf("FOR GET INFO ABOUT GRAPH PRESS BUTTON [3] AND [ENTER]\n");
        printf("FOR FREE ALL VERTEX PRESS BUTTON [4] AND ENTER\n");
        printf("FOR EXIT PROGRAM PRESS BUTTON [5] AND [ENTER]\n");
        printf("PLEASE ENTER YOUR CHOICE:");
        scanf("%d",&choice);
        fflush(stdin);
        switch(choice){
    case 1:
        system("cls");
        create_graph();
        double_button();
        break;
    case 2:
        if(clone[0]==NULL){
        printf("GRAPH DOESN'T EXIST PLEASE CREATE A GRAPH FIRSTLY!\n");
        double_button();
        }else{
        system("cls");
        define_all_0();
        Z=control_for_dfs();
        depth_first_search(start,Z);
        double_button();
        }
        break;
    case 3:
        if(clone[0]==NULL){
        printf("GRAPH DOESN'T EXIST PLEASE CREATE A GRAPH FIRSTLY!");
        double_button();
        }else{
        system("cls");
        graph_info(graph_size);
        }
        break;
    case 4:
        if(clone[0]==NULL){
        printf("FOR FREEING MEMORY ALLOCATE MEMORY FIRSTLY!\n");
        }else{
        if(free_all_vertex()!=0){
            printf("FREEING MEMORY IS SUCCESFULL\n");
        }else{
            printf("PROCCESS IS UNSUCCESSFULL\n");
        }};
        double_button();
        break;
    case 5:
        system("cls");
        owner_of_code();
        printf("FOR EXIT THE PROGRAM PRESS ANY BUTTON TWO TIMES");
        if(clone[0]!=NULL){
        free_all_vertex();
        }
        double_button();
        exit(0);
        break;
    default:
        printf("WRONG INPUT VALUE ENTERED PLEASE ENTER A VALID VALUE!\n");
        double_button();
        }
    }
    return 0;
}
/*THIS CODE IS WRITTEN BY OMER GOKSOY WHO IS COMPUTER PROGRAMMING STUDENT AT MALTEPE UNIVERSITY.
DO NOT DELETE HERE!*/
