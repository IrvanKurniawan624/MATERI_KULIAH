#include <stdio.h>
#include <stdlib.h>

/// FUNCTION
int ganjil_1(int);
long int faktorial_2(int);
int prima_3(int);
float radian_4(int);
float konversi_5(float, char, char);

int main()
{
    /// TUGAS PERCOBAAN PRAKTIKUM 14

    /// TUGAS 1
//    int input_bilangan, hasil;
//    printf("Masukkan Bilangan : ");
//    scanf("%d", &input_bilangan);
//    hasil = ganjil_1(input_bilangan);
//    if(hasil == 1){
//        printf("Bilangan Ganjil");
//    } else {
//        printf("Bilangan Genap");
//    }
    /// =======END=======

    /// TUGAS 2
//    int input_bilangan;
//    long int hasil;
//    printf("Masukkan Input Untuk Faktorial : ");
//    scanf("%d", &input_bilangan);
//    hasil = faktorial_2(input_bilangan);
//    printf("Hasil Faktorial : %d", hasil);
    /// =======END=======

    /// TUGAS 3
//    int input_bilangan, is_prime;
//    printf("Masukkkan Input Untuk Cek Bilangan Prima : ");
//    scanf("%d", &input_bilangan);
//    is_prime = prima_3(input_bilangan);
//    if(is_prime == 1){
//        printf("\n%d Merupakan Bilangan Prima", input_bilangan);
//    } else {
//        printf("\n%d Bukan Bilangan Prima", input_bilangan);
//    }
    /// =======END=======

    /// TUGAS 4
//    int input_bilangan;
//    float hasil_radian;
//    printf("Masukkan Input Drajat : ");
//    scanf("%d", &input_bilangan);
//    hasil_radian = radian_4(input_bilangan);
//    printf("\nRadian = %.2f", hasil_radian);
    /// =======END=======

    /// TUGAS 5
    float input_suhu, hasil_konversi;
    char satuan_asal, satuan_tujuan;
    printf("MENGUBAH SUHU CELCIUS, FARENHEIT, REAMUR");
    printf("\nMasukkan Input Suhu : ");
    scanf("%f", &input_suhu);
    fflush(stdin);
    printf("Masukkan Satuan Asal (C, F, R) : ");
    scanf("%c", &satuan_asal);
    fflush(stdin);
    printf("Masukkan Satuan Tujuan (C, F, R) : ");
    scanf("%c", &satuan_tujuan);
    hasil_konversi = konversi_5(input_suhu, satuan_asal, satuan_tujuan);
    printf("\nHasil Konversi : %.2f %c", hasil_konversi, satuan_tujuan);

    /// =======END=======
}

int ganjil_1(int input){
    return input % 2;
}

long int faktorial_2(int input){
    int i;
    int hasil = input;
    for(i=input;i>1;i--){
        hasil *= (i-1);
    }
    return hasil;
}

int prima_3(int input){
    int i, is_prime = 1;
    for (i=2;i<=input/2;i++){
        if(input%i==0){
            is_prime = 0;
            break;
        }
    }
    return is_prime;
}

float radian_4(int input){
    const float PI = 3.14159;
    return input/180.0*PI;
}

float konversi_5(float suhu, char asal, char tujuan){
    float hasil_konversi;
    switch (asal){
        case 'C':
            if(tujuan == 'R'){
                hasil_konversi = suhu * 4/5;
            } else if(tujuan == 'F'){
                hasil_konversi = suhu * 9/5 + 32;
            } else if(tujuan == 'C'){
                hasil_konversi = suhu;
            }
            break;
        case 'R':
            if (tujuan == 'C') {
                hasil_konversi = suhu * 5 / 4;
            } else if (tujuan == 'F') {
                hasil_konversi = suhu * 9 / 4 + 32;
            } else if (tujuan == 'R') {
                hasil_konversi = suhu;
            }
            break;
        case 'F':
            if (tujuan == 'C') {
                hasil_konversi = (suhu - 32) * 5 / 9;
            } else if (tujuan == 'R') {
                hasil_konversi = (suhu - 32) * 4/9;
            } else if (tujuan == 'F') {
                hasil_konversi = suhu;
            }
            break;
        default:
            printf("KONVERSI TIDAK VALID");
            return -1;
    }
    return hasil_konversi;
}
