#include <stdio.h>
#define MAX_BOYUT 10

int matris[MAX_BOYUT][MAX_BOYUT];
int guzergah[MAX_BOYUT][MAX_BOYUT];

void Giris(int boyut) {
    printf("Matris elemanlarini girin:\n");
    int i, j;
    for (i = 0; i < boyut; i++) {
        for (j = 0; j < boyut; j++) {
            scanf("%d", &matris[i][j]);
        }
    }
}

void matrisiYazdir(int boyut) {
    printf("Matris:\n");
    int i, j;
    for (i = 0; i < boyut; i++) {
        for (j = 0; j < boyut; j++) {
            printf("%d ", matris[i][j]);
        }
        printf("\n");
    }
}

int yolHesap(int x, int y, int boyut) {
    if (x >= boyut || y >= boyut || matris[x][y] == 0 || guzergah[x][y] != -1) {
        return 0;
    }

    if (x == boyut - 1 && y == boyut - 1) {
        guzergah[x][y] = 1;
        return 1;
    }

    int sagYol = yolHesap(x, y + 1, boyut);
    int asagiYol = yolHesap(x + 1, y, boyut);
    guzergah[x][y] = sagYol + asagiYol;

    return guzergah[x][y];
}

void guzergahYazdir(int x, int y, int boyut, int adim, int toplamYol) {
    if (x >= boyut || y >= boyut || matris[x][y] == 0 || guzergah[x][y] == -1) {
        return;
    }

    guzergah[x][y] = -1; // Güzergahý kullanýldý olarak iþaretle

    printf("(%d, %d) ", x, y);

    if (x == boyut - 1 && y == boyut - 1) {
        printf("\n");
        if (--toplamYol == 0) {
            return;
        }
    }

    if (y + 1 < boyut && guzergah[x][y + 1] >= adim) {
                guzergahYazdir(x, y + 1, boyut, adim + 1, toplamYol);
    }
    if (x + 1 < boyut && guzergah[x + 1][y] >= adim) {
        guzergahYazdir(x + 1, y, boyut, adim + 1, toplamYol);
    }
}

int main() {
    int boyut,i,j;
    printf("Matris boyutunu girin: ");
    scanf("%d", &boyut);

    if (boyut > MAX_BOYUT) {
        printf("Hata: Matris boyutu %d'den buyuk olamaz.\n", MAX_BOYUT);
        return 1;
    }

    Giris(boyut);
    matrisiYazdir(boyut);

    for (i = 0; i < boyut; i++) {
        for (j = 0; j < boyut; j++) {
            guzergah[i][j] = -1;
        }
    }

    int tumYollar = yolHesap(0, 0, boyut);
    printf("Toplam alinabilen yol sayisi: %d\n", tumYollar);

    printf("Guzergahlar:\n");
    guzergahYazdir(0, 0, boyut, 1, tumYollar);

    return 0;
}
