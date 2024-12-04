// Binary Search Tree islemleri
#include <stdio.h>
#include <stdlib.h>

struct dugum {
  int veri;
  struct dugum *sol, *sag;
};

// Dugum olusturma bolumu
struct dugum *Yeni_Dugum(int item) {
  struct dugum *gecici = (struct dugum *)malloc(sizeof(struct dugum));
  gecici->veri = item;
  gecici->sol = gecici->sag = NULL;
  return gecici;
}

// Inorder gezinme
void inorder(struct dugum *Kok_Dugum) {
  if (Kok_Dugum != NULL) {
    inorder(Kok_Dugum->sol); //SOL
    printf("%d -> ", Kok_Dugum->veri); //VERI
    inorder(Kok_Dugum->sag); //SAG
  }
}

///Postorder (menü seçeneði halinde olsun.)

///preorder eklenecek (menü seçeneði halinde olsun.)

// Ekle a dugum
struct dugum *Ekle(struct dugum *dugum, int veri) {
  // Eðer düðüm boþsa
  if (dugum == NULL)
    return Yeni_Dugum(veri);

  // eklenecek veri dugumdeki degerden kucukse
  if (veri < dugum->veri)
    dugum->sol = Ekle(dugum->sol, veri);
  else
    dugum->sag = Ekle(dugum->sag, veri);

  return dugum;
}

// Find the inorder successor
struct dugum *en_kucuk_dugum_degeri_bulma(struct dugum *dugum) {
  struct dugum *mevcut_dugum = dugum;

  // Find the sol most leaf
  while (mevcut_dugum && mevcut_dugum->sol != NULL)
    mevcut_dugum = mevcut_dugum->sol;

  return mevcut_dugum;
}

// Dugum Silme
struct dugum *Dugum_sil(struct dugum *Kok_Dugum, int veri) {
  // Eger agac bos ise
  if (Kok_Dugum == NULL){
    return Kok_Dugum;
  }
  // Aranan deger kok dugumden kucukse
  if (veri < Kok_Dugum->veri){
    Kok_Dugum->sol = Dugum_sil(Kok_Dugum->sol, veri);
  }else if (veri > Kok_Dugum->veri){
            Kok_Dugum->sag = Dugum_sil(Kok_Dugum->sag, veri);
        }else {
            // Dugum tek çocuklu veya çocuksuz ise
            if (Kok_Dugum->sol == NULL) {
              struct dugum *gecici = Kok_Dugum->sag;
              free(Kok_Dugum);
              return gecici;
            } else if (Kok_Dugum->sag == NULL) {
                      struct dugum *gecici = Kok_Dugum->sol;
                      free(Kok_Dugum);
                      return gecici;
                   }
            // Dugumun iki çocuðu varsa
            struct dugum *gecici = en_kucuk_dugum_degeri_bulma(Kok_Dugum->sag);

            // Silinen kok ve diger dugumler arasýndaki bag ayarlanýr
            Kok_Dugum->veri = gecici->veri;
            //Dugum silinir.
            Kok_Dugum->sag = Dugum_sil(Kok_Dugum->sag, gecici->veri);
        }
  return Kok_Dugum;
}

int main() {
  struct dugum *Kok_Dugum = NULL;
  ///Deðerler kullanýcýdan istensin.
  Kok_Dugum = Ekle(Kok_Dugum, 8);
  Kok_Dugum = Ekle(Kok_Dugum, 3);
  Kok_Dugum = Ekle(Kok_Dugum, 1);
  Kok_Dugum = Ekle(Kok_Dugum, 6);
  Kok_Dugum = Ekle(Kok_Dugum, 7);
  Kok_Dugum = Ekle(Kok_Dugum, 10);
  Kok_Dugum = Ekle(Kok_Dugum, 14);
  Kok_Dugum = Ekle(Kok_Dugum, 4);

  ///menüde olacak
  printf("Inorder gezinme: ");
  inorder(Kok_Dugum);

  ///menü seçeneðinde olacak
  printf("\n10 degeri Silindikten sonra\n");
  Kok_Dugum = Dugum_sil(Kok_Dugum, 10);
  //printf("%d\n",Kok_Dugum->veri);
  printf("Inorder gezinme: ");
  inorder(Kok_Dugum);
  return 0;
}
