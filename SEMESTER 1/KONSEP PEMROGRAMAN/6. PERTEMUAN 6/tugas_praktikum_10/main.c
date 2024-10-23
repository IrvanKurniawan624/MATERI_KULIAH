#include <stdio.h>
#include <stdlib.h>

int main()
{
    /// TUGAS PERCOBAAN PRAKTIKUM 10

    /// ====== TUGAS 1 ======
//        char input_user[100] = "";
//        int i = 0;
//        printf("Masukkan Kalimat : ");
//        fgets(input_user, sizeof(input_user), stdin);
//        printf("\n");
//        while(input_user[i] != 'X'){
//            printf("%c ", input_user[i]);
//            i++;
//            if(input_user[i] == '\n'){
//                break;
//            }
//        }
    /// =======END=======

    /// ====== TUGAS 2 ======
//    int input_bilangan, hasil = 0, is_loop = 1, i = 0;
//    char input_konfirmasi;
//    while (is_loop == 1){
//        i++;
//        printf("Masukkan bilangan ke-%d :", i);
//        scanf("%d", &input_bilangan);
//        hasil += input_bilangan;
//        fflush(stdin);
//        printf("Mau memasukkan data lagi [y/t] ? ");
//        scanf("%c", &input_konfirmasi);
//        if(input_konfirmasi == 't'){
//            is_loop = 0;
//        }
//    }
//    printf("\nTotal Bilangan = %d\n\n", hasil);
    /// =======END=======

    /// ====== TUGAS 3 ======
//    int input_bilangan, hasil = 0, is_loop = 1, i = 0, minimum = 0, maximum = 0, rata_rata = 0;
//    char input_konfirmasi;
//    while (is_loop == 1){
//        i++;
//        printf("Masukkan bilangan ke-%d : ", i);
//        scanf("%d", &input_bilangan);
//        hasil += input_bilangan;
//        minimum = (input_bilangan < minimum || minimum == 0) ? input_bilangan : minimum;
//        maximum = (input_bilangan > maximum || maximum == 0) ? input_bilangan : maximum;
//        fflush(stdin);
//        printf("Mau memasukkan data lagi [y/t] ? ");
//        scanf("%c", &input_konfirmasi);
//        if(input_konfirmasi == 't'){
//            is_loop = 0;
//        }
//    }
//
//    rata_rata = hasil / i;
//    printf("\n\nMinimum = %d", minimum);
//    printf("\nMaximum = %d", maximum);
//    printf("\nRata-Rata = %d", rata_rata);
//    printf("\nTotal Bilangan = %d\n\n", hasil);
    /// =======END=======

    /// ====== TUGAS 4 ======
//    int input_bilangan, i = 0, increment_plus = 0;
//    printf("Masukkan Bilangan : ");
//    scanf("%d", &input_bilangan);
//    printf("\n");
//    while(i <= input_bilangan){
//        printf("%d ", i);
//        increment_plus++;
//        i += increment_plus;
//    }
//    printf("\n");
    /// =======END=======

    /// ====== TUGAS 5 ======
//    char input[100] = "";
//    int i = 0, jumlah_karakter = 0, jumlah_spasi = 0;
//    printf("Masukkan Input : ");
//    fgets(input, sizeof(input), stdin);
//    while(input[i] != '\n'){
//        if(input[i] == ' '){
//            jumlah_spasi++;
//        } else {
//            jumlah_karakter++;
//        }
//        i++;
//    }
//    printf("\nJumlah Spasi : %d\nJumlah Karakter : %d ", jumlah_spasi, jumlah_karakter);
    /// =======END=======

    /// ====== TUGAS 6 ======
//    int input_bilangan, total_penjumlahan = 0, temp_bilangan = 0;
//    printf("Masukkan Bilangan : ");
//    scanf("%d", &input_bilangan);
//    printf("Jumlah Angka dari bilangan %d = ", input_bilangan);
//
//    while(input_bilangan > 0){
//        temp_bilangan = input_bilangan % 10;
//        total_penjumlahan += temp_bilangan;
//        input_bilangan /= 10;
//    }
//
//    printf("%d", total_penjumlahan);
    /// =======END=======

    /// ====== TUGAS 7 ======
//    float biaya_haji, cicilan_per_bulan, total_cicilan=0, kenaikan, total_kenaikan;
//    int jumlah_bulan_dibutuhkan = 0;
//    printf("Masukkan Berapa Biaya Awal : ");
//    scanf("%f", &biaya_haji);
//    printf("Berapa Cicilan yang mampu dibayarkan per-bulan : ");
//    scanf("%f", &cicilan_per_bulan);
//    printf("Berapa Rata-rata kenaikan per-tahun (%) : ");
//    scanf("%f", &kenaikan);
//    total_kenaikan = biaya_haji * (kenaikan/100);
//    while(total_cicilan < biaya_haji){
//        total_cicilan += cicilan_per_bulan;
//        jumlah_bulan_dibutuhkan++;
//        if(jumlah_bulan_dibutuhkan % 12 == 0){
//            biaya_haji += total_kenaikan;
//        }
//    }
//    printf("\n\nWaktu yang dibutuhkan untuk melunasi haji adalah %d Bulan", jumlah_bulan_dibutuhkan);
    /// =======END=======
    return 0;
}
