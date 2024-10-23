#include <stdio.h>
#include <stdlib.h>

void print_menu_1();
void triangular_2(int);
float kuadrat_3(float);
int fungsi_cn_4(int);
int fungsi_sn_4(int);

int main()
{
    /// TUGAS PERCOBAAN PRAKTIKUM 13

    /// TUGAS 1
//    int input_bilangan, i;
//
//    printf("Masukkan Jumlah Perulangan : ");
//    scanf("%d", &input_bilangan);
//    for(i=0;i<input_bilangan;i++){
//        print_menu_1();
//    }
    /// =======END=======

    /// TUGAS 2
//    int input_bilangan;
//    printf("Masukkan Bilangan : ");
//    scanf("%d", &input_bilangan);
//    triangular_2(input_bilangan);
    /// =======END=======

    /// TUGAS 3
//    float input_bilangan, hasil;
//    printf("Masukkan Bilangan yang akan dikuadratkan : ");
//    scanf("%f", &input_bilangan);
//    hasil = kuadrat_3(input_bilangan);
//    printf("Hasil Kuadrat Bilangan Tersebut = %.2f", hasil);
    /// =======END=======

    /// TUGAS 4
//    int input_bilangan, hasil_cn, hasil_sn;
//    printf("Masukkan Input Bilangan : ");
//    scanf("%d", &input_bilangan);
//    hasil_cn = fungsi_cn_4(input_bilangan);
//    hasil_sn = fungsi_sn_4(input_bilangan);
//    printf("Hasil Fungsi Cn = 2*Cn-1 + 2 adalah %d\nHasil Fungsi Sn = Sn-1 + n - 1 adalah %d", hasil_cn, hasil_sn);
    /// =======END=======

}

void print_menu_1(){
    printf("Pilihan Menu\n");
}

void triangular_2(int input){
    input = input*(input + 1)/2;
    printf("\nJumlah Triangular : %d",input);
}

float kuadrat_3(float input){
    input = input*input;
    return input;
}

int fungsi_cn_4(int input){
    int hasil;
    while(1){
        if(input == 0){
            return 1;
        }
        hasil = 2*fungsi_cn_4(input - 1) + 1;
        return hasil;
    }
}

int fungsi_sn_4(int input){
    int hasil;
    while(1){
        if(input == 1){
            return 0;
        }
        hasil = fungsi_sn_4(input - 1) + input - 1;
        return hasil;
    }
}
