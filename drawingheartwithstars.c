#include <stdio.h>
#include <stdlib.h>

int main()
{
    int h,i,j,boyut,kalpsayisi,kalpkat,k;///Kullanılacak degiskenlerin ilanı.
    char str[]="PROJE BASARILI SONUCLANDI";///1 ve 1'den fazla kalp baskisi talebi olması durumunda yazılacak yazı.
    printf("KAC TANE KALP BASKISI CIKARTMAK ISTERSIN?:");
    scanf("%d",&kalpsayisi);///1 adet kalp genisligindeki sutunda alt alta kac adet kalbin bulunacagini veren sayi.
    printf("VERDIGIN KALPLERI KACA KATINA CIKARALIM?:");
    scanf("%d",&kalpkat);///1 adet kalp yuksekligindeki satırda kac adet kalbin yan yana bulunacagini veren sayi.

    if(kalpsayisi >= 1 && kalpkat >=0){///kalp olusturma talebinin olup olmadiginin kontrolu.

    if(kalpkat==0){
    kalpkat+=1;
    }

    for(h=1; h<=kalpsayisi; h++){///sutunda kalp sayisi kadar kalp olusmasini saglayan dongu.


    for(i=1; i<=4; i++){///1 kalbın yamuktan olusan kismindaki satırları sayan dongu.
    //YAMUKLARDAN OLUSAN KISIM
       for(k=1; k<=kalpkat; k++){///1 kalbin iki yamuktan olusan kismindaki her bir satir icin sutunlari sayan dongu.

        for(j=1; j<=(22-(i-1)); j++){///her bir satirda koyulan bosluk icin dongu.
        if(k>=5){
            continue;
        }
            printf(" ");
        }

        for(j=(14-10)+(2*i-2); j>=1; j--){///yamuklardan ilki icin her bir kalbin her bir satirindaki yildizlari olusturan dongu.
        if(k>=5){
            continue;
        }
            printf("*");

        }
        for(j=(14-(2*i+5)); j>=1; j--){///yamuklar arasındaki boslugu saglayan dongu.
        if(k>=5){
            continue;
        }
            printf(" ");

        }
        for(j=(14-10)+(2*i-2); j>=1; j--){///yamuklardan ikincisi icin her bir kabin her bir satirindaki yildizlari olusturan dongu.
        if(k>=5){
            continue;
        }
            printf("*");
            }

        for(j=1; j<=(11-(i-1)); j++){
        if(k>=5){
            continue;
        }
            printf(" ");///sonraki sutuna bosluk birakarak gecmeyi saglayan dongu.
        }

       }

printf("\n");///bir satir icin tüm sütünlardaki islemler yapildiktan sonra alt satira gecisin saglanmasi.

    }
    //UCGENDEN OLUSAN ALT KISIM
    for(i=1; i<=10; i++){///1 kalbin ucgen kismindaki satirlari sayan dongu.
          for(k=1; k<=kalpkat; k++){///1 kalbin ucgenden olusan kisminin her satiri icin sutunlari sayan dongu.

            for(j=1; j<=(19+i); j++){///her bir satiri icin bosluk miktarini ve birakilmasini saglayan dongu.
                 if(k>=5){
                continue;
            }
                printf(" ");
            }
            for(j=1; j<=((22-2*i)-1); j++){///her bir satiri icin yildizlari olusturan dongu.
                if(k>=5){
                continue;
            }
                printf("*");
            }
           for(j=1; j<=(8+i); j++){///her bir sati icin sonraki sutuna gecmesini saglayan dongu.
                if(k>=5){
                continue;
            }
                printf(" ");
            }


    }
  printf("\n");///bir satir icin tum sutunlar tamamlandiktan sonra alta gecmeyi saglayan ifade.
    }
    }
    printf("\n\t");///yaziyi daha iyi ortalıyabilmek icin alta satira gecip 6-8 karakter bosluk birakan ifade.
    i=1;
    while(i<=9){
    printf("%3s ",str);///stringdeki ifadenin en alt satirdaki tum kalplerin altina gelecek yazi.
    i++;
    }
    }else{
    printf("[KALPSIZSIN ZALIM!]");

    }
getch();
return 0;
    }





























