#include <stdio.h>
#include <stdlib.h>

int main()
{
///    TUGAS PENDAHULUAN PRAKTIKUM 4

///    =======TUGAS 1=======
//    float fahrenheit, celcius;
//    printf("PROGRAM KONVERSI SUHU CELCIUS KE FAHRENHEIT\n\n");
//    printf("MASUKKAN SUHU CELCIUS : ");
//    scanf("%f", &celcius);
//    fahrenheit = celcius * 1.8 + 32;
//    printf("SUHU FAHRENHEIT : %.2f", fahrenheit);
///    =======END=======

///    =======TUGAS 2=======
//    float gaji_pokok, jumlah_anak, masa_kerja, masuk_kerja, tunjangan_istri, tunjangan_anak, thr, pajak, bantuan_transport, polis_asuransi = 20000,
//    total_pendapatan;
//    printf("Masukkan Nilai Gaji Pokok : ");
//    scanf("%f", &gaji_pokok);
//
//    printf("Masukkan Jumlah Anak : ");
//    scanf("%f", &jumlah_anak);
//
//    printf("Masukkan Masa Kerja (Tahun) : ");
//    scanf("%f", &masa_kerja);
//
//    printf("Masukkan Masuk Kerja (Hari) : ");
//    scanf("%f", &masuk_kerja);
//
//    tunjangan_istri = gaji_pokok * 0.1;
//    tunjangan_anak = (0.05 * gaji_pokok) * jumlah_anak;
//    thr = 5000 * masa_kerja;
//    pajak = (0.15 * gaji_pokok) + (0.15 * tunjangan_istri) + (0.15 * tunjangan_anak);
//    bantuan_transport = 3000 * masuk_kerja;
//
//    total_pendapatan += (tunjangan_istri + tunjangan_anak + thr + bantuan_transport + gaji_pokok);
//    total_pendapatan -= (polis_asuransi + pajak);
//
//    printf("\n\n ==== PERHITUNGAN PENDAPATAN BULANAN ===");
//    printf("\n Tunjangan Istri = %.0f", tunjangan_istri);
//    printf("\n Tunjangan Anak = %.0f", tunjangan_anak);
//    printf("\n THR = %.0f", thr);
//    printf("\n Bantuan Transport = %.0f", bantuan_transport);
//    printf("\n Pajak = -%.0f", pajak);
//    printf("\n Polis Asuransi = -%.0f", polis_asuransi);
//    printf("\n\n Total Pendapatan = %.0f", total_pendapatan);
//    printf("\n ==== END PERHITUNGAN PENDAPATAN BULANAN ===\n\n");
///    =======END=======

///    =======TUGAS 3=======
    int jumlah_tiket, total_beli_tiket, sisa_bagi, total_harga, harga_tiket = 50000;
    printf("MASUKKAN JUMLAH TIKET : ");
    scanf("%d", &jumlah_tiket);

    sisa_bagi = jumlah_tiket % 3;
    total_beli_tiket = jumlah_tiket / 3;
    total_harga = (total_beli_tiket * (harga_tiket * 2)) + (sisa_bagi * harga_tiket);
    printf("\n\nNOTE : SETIAP PEMBELIAN 2 TIKET GRATIS 1 TIKET");
    printf("\nHARGA TIKET : %d", harga_tiket);
    printf("\n\nJUMLAH BELI TIKET : %d", sisa_bagi + total_beli_tiket * 2);
    printf("\nJUMLAH TIKET GRATIS : %d", total_beli_tiket);
    printf("\n\nTOTAL HARGA TIKET = Rp. %d\n\n", total_harga);

    return 0;
}
