#include <stdio.h>
#include <stdlib.h>

int main()
{
/// TUGAS PERCOBAAN PRAKTIKUM 6

/// ====== TUGAS 1 ======
//    int input_user;

//    printf("Silahkan Masukkan Suhu : ");
//    scanf("%d", &input_user);
//    if(input_user < 0){
//        printf("Benda berbentuk padat");
//    } else if (input_user >= 0 && input_user <= 100){
//        printf("Benda berbentuk cair");
//    } else {
//        printf("Benda berbentuk gas");
//    }
//    printf("\n\n=============================\n");
/// =======END=======

/// ====== TUGAS 2 ======
//    int tes_akademik, tes_keterampilan, tes_psikologi, rata_rata;
//
//    printf("Tes Akademik : ");
//    scanf("%d", &tes_akademik);
//    printf("Tes Keterampilan : ");
//    scanf("%d", &tes_keterampilan);
//    printf("Tes Psikologi : ");
//    scanf("%d", &tes_psikologi);
//
//    rata_rata = (tes_akademik + tes_keterampilan + tes_psikologi) / 3;
//    printf("\nNilai Rata-rata Peserta : %d\n", rata_rata);
//    if(rata_rata < 75){
//        printf("Peserta dinyatakan tidak lulus");
//        return 0;
//    }
//
//    if(tes_akademik > tes_keterampilan && tes_akademik > tes_psikologi){
//        printf("Peserta diterima dan ditempatkan di bagian administrasi");
//    } else if (tes_keterampilan > tes_akademik && tes_keterampilan > tes_psikologi){
//        printf("Peserta diterima dan ditempatkan di bagian produksi");
//    } else if (tes_psikologi > tes_akademik && tes_psikologi > tes_keterampilan){
//        printf("Peserta diterima dan ditempatkan di bagian pemasaran");
//    } else {
//        printf("Nilai Peserta sama rata peserta dapat memilih bagian administrasi, produksi, ataupun pemasaran");
//    }
//    printf("\n\n=============================\n");
/// =======END=======

/// ====== TUGAS 3 ======
//    float bilangan_pertama, bilangan_kedua, hasil;
//    int pilihan_operasi;
//
//    printf("Masukkan Bilangan Pertama : ");
//    scanf("%f", &bilangan_pertama);
//    printf("Masukkan Bilangan Kedua : ");
//    scanf("%f", &bilangan_kedua);
//    printf("Menu Matematika\n1. Penjumalahan\n2. Pengurangan\n3. Pembagian\n4. Perkalian\nMasukkan pilihan anda : ");
//    scanf("%d", &pilihan_operasi);
//
//    if(pilihan_operasi == 1){
//        hasil = bilangan_pertama + bilangan_kedua;
//    } else if(pilihan_operasi == 2){
//        hasil = bilangan_pertama - bilangan_kedua;
//    } else if(pilihan_operasi == 3){
//        hasil = bilangan_pertama / bilangan_kedua;
//    } else if(pilihan_operasi == 4){
//        hasil = bilangan_pertama * bilangan_kedua;
//    } else {
//        printf("Pilihan operasi tidak ada didalam list..");
//        return 0;
//    }
//
//    printf("\nHasil Operasi Tersebut : %.2f", hasil);
//    printf("\n\n=============================\n");
/// =======END=======

/// ====== TUGAS 4 ======
    int nilai_angka;
    char hasil;
    printf("Masukkan Nilai : ");
    scanf("%d", &nilai_angka);

    if(nilai_angka <= 40){
        hasil = 'E';
    } else if (nilai_angka > 40 && nilai_angka <= 55){
        hasil = 'D';
    } else if (nilai_angka > 55 && nilai_angka <= 60){
        hasil = 'C';
    } else if (nilai_angka > 60 && nilai_angka <= 80){
        hasil = 'B';
    } else if (nilai_angka > 80 && nilai_angka <= 100){
        hasil = 'A';
    } else {
        printf("Nilai Tidak Masuk Kedalam Range Penilaian.");
        return 0;
    }

    printf("\nNilai huruf adalah : %c", hasil);
    printf("\n\n=============================\n");
/// =======END=======

    return 0;
}
