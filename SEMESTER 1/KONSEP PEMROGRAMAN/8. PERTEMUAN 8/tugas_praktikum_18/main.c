#include <stdio.h>
#include <stdlib.h>

int main()
{
     /// TUGAS PERCOBAAN PRAKTIKUM 18

    /// TUGAS 1
//    int bilangan[5] = {21, 10, 15, 20, 25}, i;
//    for(i=0; i<=sizeof(bilangan[0]);i++){
//        printf("%d\n", bilangan[i]);
//    }
   /// =======END=======

   /// TUGAS 2
//   int input_bilangan, count=0, i, array_int[100] = {0, 1};
//   printf("Masukkan Bilangan (MAKS : 100) : ");
//   scanf("%d", &input_bilangan);
//   for(i=1; i < input_bilangan; i++){
//    array_int[i+1] = array_int[i] + array_int[i-1];
//    count++;
//   }
//
//    for(i=0; i<=count;i++){
//        printf("%d\n", array_int[i]);
//    }
   /// =======END=======

   /// TUGAS 3
//    const int MAKS = 10;
//    int matriks_A[MAKS][MAKS], matriks_B[MAKS][MAKS], matriks_C[MAKS][MAKS], ordo, i, j, temp_nilai;
//    printf("Masukkan Ordo Matriks (MAKS 10) : ");
//    scanf("%d", &ordo);
//    if(ordo > 10){
//        printf("\nOrdo Melebihi Batas!");
//        return 0;
//    }
//    for(i=0; i<ordo; i++){
//        for(j=0; j<ordo; j++){
//            printf("Masukkan Input Matriks 1 : ");
//            scanf("%d", &temp_nilai);
//            matriks_A[i][j] = temp_nilai;
//        }
//    }
//    printf("\n");
//    for(i=0; i<ordo; i++){
//        for(j=0; j<ordo; j++){
//            printf("Masukkan Input Matriks 2 : ");
//            scanf("%d", &temp_nilai);
//            matriks_B[i][j] = temp_nilai;
//        }
//    }
//    for(i=0; i<ordo; i++){
//        for(j=0; j<ordo; j++){
//            matriks_C[i][j] = matriks_A[i][j] + matriks_B[i][j];
//        }
//    }
//    printf("\n\nMatriks 1\n");
//    for(i=0; i<ordo; i++){
//        for(j=0; j<ordo; j++){
//            printf("%d  ", matriks_A[i][j]);
//        }
//        printf("\n");
//    }
//
//    printf("\n\nMatriks 2\n");
//    for(i=0; i<ordo; i++){
//        for(j=0; j<ordo; j++){
//            printf("%d  ", matriks_B[i][j]);
//        }
//        printf("\n");
//    }
//
//    printf("\n\nMatriks 3\n");
//    for(i=0; i<ordo; i++){
//        for(j=0; j<ordo; j++){
//            printf("%d  ", matriks_C[i][j]);
//        }
//        printf("\n");
//    }
   /// =======END=======

   /// TUGAS 3
   const int MAKS = 20;
   int array_int[20], jumlah, temp_int, i, maksimal=0;
   printf("Masukkan Jumlah Nilai Yang Dimasukkan : ");
   scanf("%d", &jumlah);
   for(i=1;i<=jumlah;i++){
        printf("Masukkan Nilai Ke-%d : ", i);
        scanf("%d", &temp_int);
        array_int[i] = temp_int;
        fflush(stdin);
   }
    printf("\n\n");
   for(i=0;i<jumlah;i++){
    if(array_int[i] > maksimal){
        maksimal = array_int[i];
    }
    if(i == jumlah-1){
        printf("%d", array_int[i]);
    } else {
        printf("%d, ", array_int[i]);
    }
   }
   printf("\nMaksimal : %d", maksimal);


   /// =======END=======
}
