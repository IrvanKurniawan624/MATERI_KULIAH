#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
/// TUGAS PERCOBAAN PRAKTIKUM 9

/// ====== TUGAS 1 ======
//    int input_user, i;
//    printf("Masukkan Input : ");
//    scanf("%d", &input_user);
//    for(i = 0; i <= input_user; i++){
//        if(i % 2 != 0){
//            if(i != 1){
//                printf(", ");
//            }
//            printf("%d", i);
//        }
//
//    }
/// =======END=======

/// ====== TUGAS 2 ======
//    int input_user, i, result = 0;
//    printf("Masukkan Input : ");
//    scanf("%d", &input_user);
//    printf("Triangular : ");
//    for(i = 0; i < input_user; i++){
//        if(i != 0){
//            printf("+ ");
//        }
//        printf("%d ", input_user - i);
//        result += (input_user - i);
//    }
//    printf("= %d", result);
/// =======END=======

/// ====== TUGAS 3 ======
//    char ch = 'Z';
//
//    for(ch = 'Z'; ch >= 'A'; --ch){
//        printf("\n%c", ch);
//    }
//
/// =======END=======

/// ====== TUGAS 4 ======
//    int input_user, i, result;
//    printf("Masukkan Input : ");
//    scanf("%d", &input_user);
//
//    for(i = 1; i <= input_user; i++){
//        result = (i % 2 == 0) ? i - (i*2) : i;
//        printf("%d ", result);
//    }
/// =======END=======

/// ====== TUGAS 5 ======
//    int input_user, i;
//    bool is_prime = true;
//
//    printf("Masukkan Bilangan : ");
//    scanf("%d", &input_user);
//
//    for(i = 2; i <= input_user/2; i++){
//        if(input_user % i == 0){
//            is_prime = false;
//            printf("Bilangan bukan bilangan prima");
//            break;
//        }
//    }
//
//    if(is_prime)
//        printf("Bilangan adalah bilangan prima");
/// =======END=======

/// ====== TUGAS 6 ======
//    char nilai_matkul_[6];
//    int jml_jam_matkul_[6], i, temp_int_1, temp_int_2, jumlah_jam = 0, result = 0;
//
//    for (i = 1; i <= 5; i++) {
//
//        printf("\nNilai Mata Kuliah %d : ", i);
//        scanf(" %c", &nilai_matkul_[i]);
//
//        printf("Jumlah Jam : ");
//        scanf("%d", &jml_jam_matkul_[i]);
//
//        switch(nilai_matkul_[i]){
//            case 'A':
//                nilai_matkul_[i] = 4;
//                break;
//            case 'B':
//                nilai_matkul_[i] = 3;
//                break;
//            case 'C':
//                nilai_matkul_[i] = 2;
//                break;
//            case 'D':
//                nilai_matkul_[i] = 1;
//                break;
//            case 'E':
//                nilai_matkul_[i] = 0;
//                break;
//            default:
//                nilai_matkul_[i] = 0;
//                break;
//        }
//
//        result += (nilai_matkul_[i] * jml_jam_matkul_[i]);
//        jumlah_jam += jml_jam_matkul_[i];
//
//    }
//
//    printf("\nIndeks Prestasi Semester : %d", result/jumlah_jam);
/// =======END=======
    return 0;
}
