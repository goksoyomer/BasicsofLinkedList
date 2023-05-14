#include <stdio.h>
#include <stdlib.h>
///ASAGIDA IPTAL EDILMIS TEK VOID FONKSIYONUNDA IC ICE FOR DONGULERI KULLANILARAK '*' SEMBOLUYLE X SEKLI OLUSTURAN BIR FONKSIYON BULUNMAKTADIR.
/*void Xolustur(int boyutf){
    int i,j;
    for(i=1; i<=boyutf; i++){
        for(j=1; j<=boyutf; j++){
        if(i==j || i+j==boyutf+1){
        printf("*");
       }else{
        printf(" ");
             }

            }
      printf("\n");
    }

}*/
///BURADA ISE 2 FARKLI FONKSIYONDAN BIRISININ DIGERININ ICERISINDE CALISMASIYLA X SEKLINI OLUSTURAN FONKSIYON KODLARI VERILMISTIR.
///CALISMA PRENSIBI YUKARIDAKIYLE AYNIDIR XolusturI2 FONKSIYONU ICTEKI J DEGISKENIYLE OLUSTURULMUS FOR DONGUSUNE DENK GELMEKTEDIR.
///XolusturI FONKSIYONU ISE I DEGISKENIYLE OLUSTURULMS FOR DONUGUSUNE DENK GELMEKTEDIR.
///XolusturI'DAKI I PARAMETRESI SATIR DEGERINI TUTAR,XolusturI2'DEKI J DEGISKENIYSE SUTUN DEGERINI TUTAR.
int XolusturI(int boyutf,int i){
    if(i==boyutf+1){
    return -1;
    }
    XolusturI2(boyutf,i,1);
    printf("\n");
    XolusturI(boyutf,i+1);
}
int XolusturI2(int boyutf,int i,int j){
    if(j==boyutf+1){
        return -1;
    }
    if(i==j || i+j==boyutf+1){
        printf("*");
    }else{
        printf(" ");
    }
     XolusturI2(boyutf,i,j+1);
}
int main() {
    int boyut,boyut2;
    /*printf("AxA BOYUTLARINDAKI X SEKLI ICIN A DEGERINI GIRINIZ:");
    scanf("%d",&boyut);
    Xolustur(boyut);*/
    printf("AxA BOYUTLARINDAKI X SEKLI ICIN A DEGERINI GIRINIZ:");
    scanf("%d",&boyut2);
    XolusturI(boyut2,1);
    return 0;
}
