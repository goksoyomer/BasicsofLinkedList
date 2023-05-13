#include <stdio.h>
#include <stdlib.h>
///BELLEGIN KULLANIM VERIMINI ARTTIRMAK ICIN TASARLANMIS BIR LINKED LIST ORNEGI
int i;
struct liste{///Bu yapiya dugum yani node da denir ayni zamanda.
 int veri;
 struct liste *sonraki;///Structin icinde bir sonraki structin adresini tutacak struct pointerini tanimliyoruz.
};
struct liste *ilk=NULL;///Bellekten ilk yer tahsisinin yapilacagi ve dolu-bos'mu kontrolunun yapilacagi struct isaretcisi.
struct liste *yeni;///Her bir sonraki veri icin bellekte yer acilmasini saglayacak olan isaretci.
struct liste *baslangic;///Ilk verinin bulundugu adresi tutacak ve free fonk. ile bellek bosaltiminin yapilmasini saglayacak isaretci.
struct liste *gecici;///Veriler arasinda gezinmemizi ve listelememizi saglayacak olan isaretci.
void ekle(int verif){
 if(ilk==NULL){
    ilk=(struct liste*)malloc(sizeof(struct liste));///Null oldugu i�in ilk isaretcisi adina bellek tahsisi.
    ilk->veri=verif;///Fonksiyona yolladigimiz veriyi listenin ilk structinin verisine atiyoruz.
    baslangic=ilk;///Ilk structin adresini kaybetmemek i�in ilkin adresini baslangic'a atiyoruz.
    gecici=ilk;///Geciciye veriler arasinda gezinebilmek i�in ilkin adresini veriyoruz.
}else{
    yeni=(struct liste*)malloc(sizeof(struct liste));///Ilk struct pointeri dolu oldugundan yeni structi ile bellekten yer tahsis ediyoruz.
    yeni->veri=verif;///Yeni structinin verisine fonksiyona yollanan degeri atiyoruz.
    ilk->sonraki=yeni;///Ilkin sonrakisi adli ptrsine yeni structin adresini gosterecek adresi atiyoruz.
    yeni->sonraki=NULL;///Son gelen veri son d�g�m olabilecegi icin her yeni struct adina yer acildiginda sonraki ptrsi NULL'a esitlenir.
    ilk=yeni;///Ilk structi artik en sonki yeninin adresini tutuyor boylece yeni veri geldiginde 2 satir onceki ifadeyle d�g�mlerin birbirine baglanmasi saglanacak.
    }
}
void goster(){///Elemanlari alt alta gosteren fonksiyon.
    if(gecici==NULL){
      printf("LISTE BOSTUR");
    }else{
    while(gecici!=NULL){///Gecici degeri NULL'a esit degilken ifadesi d�ng�n�n listenin son elemanina kadar gitmesini sa�lar.
        printf("%d\n",gecici->veri);///Gecicideki veriyi yazdirir su anda ilk dong� i�in baslangi� adresinin verisi var.
        gecici=gecici->sonraki;///Geciciye bir sonraki d�g�m�n adresi verilir.Bu d�ng�lerdeki i++'ya benzer.
    }}
}
void bellekbosalt(){
   while(baslangic!=NULL){///Baslangic null olana kadar.
    free(baslangic);///Her bir struct i�in bellekte tahsis edilen alani sirayla bosalt.
    baslangic=baslangic->sonraki;///Baslangicin tuttugu adresi listenin bir sonraki structinin adresi olacak sekilde g�ncelle.
   }
}
int main()
{
    int *veriptr;///Pointer degiskeni ilani.
    veriptr=(int *)calloc(5,sizeof(int));///5 adet int t�r�nde ve boyutunda bellek tahsisi.
    for(i=0; i<5; i++){
        printf("GIRMEK ISTEDIGINIZ DEGERI YAZINIZ:"); scanf("%d",&*(veriptr+i));///Sirasiyla her bir eleman i�in tahsis edilen belleklere degerlerin atanmasi.
        ekle(veriptr[i]);///Degerler�n sirasiyla fonksiyona yollanmasi.
    }
    goster();///Degerlerin eklenip sirasina gore ekranda listelenmesi.
    free(veriptr);///Bu pointer ile tahsis edilmis alanin serbest birakilmasi
    bellekbosalt;///Her bir struct i�in tahsis edilen belleklerin bosaltilmasi.
    return 0;
}





///github:goksoyomer
