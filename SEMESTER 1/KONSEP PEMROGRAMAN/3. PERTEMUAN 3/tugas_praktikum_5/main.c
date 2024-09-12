#include <stdio.h>
#include <stdlib.h>

int main()
{
/// TUGAS PERCOBAAN PRAKTIKUM 5

/// ====== TUGAS 1 ======
//    int input_user;
//    printf("Silahkan Masukkan Nilai : ");
//    scanf("%d", &input_user);/// =======END=======
//
//    if(input_user >= 0)
//        printf("Nilai %d Merupakan Nilai Positif !", input_user);
//    else
//        printf("Nilai %d Merupakan Nilai Negatif !", input_user);
/// =======END=======

/// ====== TUGAS 2 ======
//    int input_user;
//    printf("Silahkan Masukkan Bilangan : ");
//    scanf("%d", &input_user);
//    if(input_user % 2 == 0)
//        printf("%d Merupakan Bilangan Genap", input_user);
//    else (input_user % 2 == 1)
//        printf("%d Merupakan Bilangan Ganjil", input_user);
/// =======END=======

/// ====== TUGAS 3 ======
//    float input_user, diskon = 0;
//    printf("Silahkan Masukkan Total Pembelian : ");
//    scanf("%f", &input_user);
//
//    if(input_user >= 100000)
//        diskon = 0.05 * input_user;
//
//    printf("\n\n=============================");
//    printf("\nTotal Pembelian : %.0f \nDiskon : %.0f \nGrand Total : %.0f", input_user, diskon, input_user - diskon);
//    printf("\n=============================\n\n");
/// =======END=======

/// ====== TUGAS 3 ======
//    int bilangan_pertama, bilangan_kedua;
//    printf("Masukkan Bilangan (ex: 12 dan 15): ");
//    scanf("%d dan %d", &bilangan_pertama, &bilangan_kedua);
//    if(bilangan_pertama % bilangan_kedua == 0)
//        printf("Bilangan pertama adalah kelipatan persekutuan bilangan kedua");
//    else
//        printf("Bilangan pertama bukan kelipatan persekutuan bilangan kedua");
//    printf("\n\n=============================\n");
/// =======END=======

/// ====== TUGAS 4 ======
    float bilangan_pertama, bilangan_kedua;
    printf("Masukkan Bilangan (ex: 12 dan 15): ");
    scanf("%d dan %d", &bilangan_pertama, &bilangan_kedua);
    if(bilangan_pertama == 0 || bilangan_kedua == 0){
        printf("division by zero");
        return 0;
    }
    printf("\nHasil Pembagian Bilangan Pertama dan Kedua : %.3f", bilangan_pertama/bilangan_kedua);
    printf("\n\n=============================\n");
/// =======END=======

}
