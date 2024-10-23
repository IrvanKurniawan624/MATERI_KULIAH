#include <stdio.h>
#include <stdlib.h>

int main()
{
    /// TUGAS PERCOBAAN PRAKTIKUM 11

    /// Var Check Loop (Tugas 7)
    char is_loop = 'y', check_user_loop = 't';
    do{
        /// ====== TUGAS 1 ======
//        char input_user;
//        printf("Masukkan Karakter : ");
//        while(1){
//            input_user = getchar();
//            printf("%c", input_user);
//            if (input_user == '\n') {
//                break;
//            }
//        }

        /// =======END=======

        /// ====== TUGAS 2 ======
    //    int input_bilangan, i;
    //    printf("Masukkan Bilangan : ", input_bilangan);
    //    scanf("%d", &input_bilangan);
    //
    //    for(i=1; i<=input_bilangan; i++){
    //        if(i % 2 == 1){
    //            if(i % 3 == 0){
    //                continue;
    //            }
    //            printf("%d ", i);
    //        }
    //    }
        /// =======END=======

        /// ====== TUGAS 3 ======
//        int input_bilangan, i;
//        printf("Masukkan Bilangan : ", input_bilangan);
//        scanf("%d", &input_bilangan);
//
//        for(i=1; i<=input_bilangan; i++){
//            if(i > 100){
//                break;
//            }
//            if(i % 2 == 1){
//                if(i % 7 == 0 || i % 11 == 0){
//                    continue;
//                }
//                printf("%d ", i);
//            }
//        }
        /// =======END=======

        /// ====== TUGAS 4 ======
    //    int input_jumlah, total_nilai = 0, rata_rata, minimal, maximal, temp_nilai, i;
    //
    //    printf("Masukkan Jumlah Data : ");
    //    scanf("%d", &input_jumlah);
    //
    //    for(i = 1; i <= input_jumlah; i++){
    //        printf("Masukkan Nilai ke-%d : ", i);
    //        scanf("%d", &temp_nilai);
    //
    //        if(i == 1){
    //            minimal = maximal = temp_nilai;
    //        }
    //
    //        total_nilai += temp_nilai;
    //        minimal = (temp_nilai < minimal) ? temp_nilai : minimal;
    //        maximal = (temp_nilai > maximal) ? temp_nilai : maximal;
    //    }
    //    rata_rata = total_nilai / input_jumlah;
    //
    //    printf("\nNilai Maximal : %d\nNilai Minimum : %d\nNilai Rata-Rata : %d", maximal, minimal, rata_rata);
        /// =======END=======

        /// ====== TUGAS 5 ======
    //        int input_bilangan, i, j;
    //        printf("Masukkan Input Bilangan : ");
    //        scanf("%d", &input_bilangan);
    //
    //        for(i=1; i<=input_bilangan; i++){
    //            for(j=1; j<=input_bilangan; j++){
    //                printf("%d ", j);
    //            }
    //            printf("\n");
    //        }
        /// =======END=======

        /// ====== TUGAS 6 ======
    //        int input_bilangan, i, j;
    //        printf("Masukkan Input Bilangan : ");
    //        scanf("%d", &input_bilangan);
    //
    //        for(i=1; i<=input_bilangan; i++){
    //            for(j=1; j<=i; j++){
    //                printf("%d ", j);
    //            }
    //            printf("\n");
    //        }
        /// =======END=======


        /// Check Apakah Mau Mengulang (Tugas 7)
        fflush(stdin);
        printf("\napakah anda ingin keluar (y/t)");
        scanf("%c", &check_user_loop);
        is_loop = (check_user_loop == 't') ? 'y' : 't';
        printf("\n");
        fflush(stdin);
    } while (is_loop == 'y');

}
