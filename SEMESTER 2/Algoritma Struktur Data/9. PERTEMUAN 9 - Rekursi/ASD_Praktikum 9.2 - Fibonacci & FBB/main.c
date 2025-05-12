#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool isPrime(int n, int pembagi);
bool isPrime(int n);

int main() {
    int angka;
    char jawab;

    do {
        printf("=== CEK BILANGAN PRIMA (REKURSI) ===\n");
        printf("Masukkan angka: ");
        scanf("%d", &angka);

        if (isPrime(angka))
            printf("%d adalah bilangan prima.\n", angka);
        else
            printf("%d bukan bilangan prima.\n", angka);

        printf("Ingin cek angka lain? (y/t): ");
        scanf(" %c", &jawab);
        printf("\n");
    } while(jawab == 'y' || jawab == 'Y');
    return 0;
}

bool isPrime(int n) {
    return isPrime(n, 2);
}

bool isPrime(int n, int pembagi) {
    if (n <= 1)
        return false;
    if (pembagi > sqrt(n))
        return true;
    if (n % pembagi == 0)
        return false;
    return isPrime(n, pembagi + 1);
}
