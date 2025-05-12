#include <stdio.h>

int faktorial(int n);

int permutasi(int n, int r);
int kombinasi(int n, int r);

int main() {
    int n, r, hasil_permutasi, hasil_kombinasi;
    char ulang;

    do {
        printf("Masukkan nilai n: ");
        scanf("%d", &n);
        printf("Masukkan nilai r: ");
        scanf("%d", &r);

        if (r > n || n < 0 || r < 0) {
            printf("Nilai r harus kurang dari atau sama dengan n, dan n, r tidak boleh negatif!\n");
        } else {
            hasil_permutasi = permutasi(n, r);
            hasil_kombinasi = kombinasi(n, r);

            printf("Permutasi P(%d, %d) = %d\n", n, r, hasil_permutasi);
            printf("Kombinasi C(%d, %d) = %d\n", n, r, hasil_kombinasi);
        }

        printf("Ingin menghitung lagi? (y/t): ");
        scanf(" %c", &ulang);

    } while (ulang == 'y' || ulang == 'Y');

    return 0;
}

int faktorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * faktorial(n - 1);
}

int permutasi(int n, int r) {
    return faktorial(n) / faktorial(n - r);
}

int kombinasi(int n, int r) {
    return faktorial(n) / (faktorial(r) * faktorial(n - r));
}
