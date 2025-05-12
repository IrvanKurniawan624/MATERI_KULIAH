#include <stdio.h>
#include <stdlib.h>

int i;

typedef struct{
    int tugas, uts, uas;
    char nama[50];
} Mhs;

typedef struct {
    int nilai;
    char nama[50];
} Maksimal;

void tampil(Mhs *Mahasiswa, Maksimal *Maks, int jumlah_mahasiswa);
void input(Mhs *Mahasiswa, Maksimal *Maks, int *jumlah_mahasiswa);
int calculate_akhir(Mhs *Mahasiswa);
char calculate_grade(int);
void compare_nilai(Mhs *Mahasiswa, Maksimal *Maks, int jumlah_mahasiswa);

int main()
{
    Mhs Mahasiswa[50];
    Maksimal Maks = {0};
    int jumlah_mahasiswa = 0;
    int pilihan_user;

    while(1){
        printf("MENGHITUNG NILAI AKHIR!\nMATA KULIAH KONSEP PEMROGRAMAN\n\n");
        printf("Pilih Action : \n 1. Tampilkan Mahasiswa \n 2. Input Mahasiswa \n Pilihan : ");
        scanf("%d", &pilihan_user);
        if(pilihan_user == 1){
            tampil(Mahasiswa, &Maks, jumlah_mahasiswa);
            continue;
        } else if (pilihan_user == 2){
            input(Mahasiswa, &Maks, &jumlah_mahasiswa);
            compare_nilai(Mahasiswa, &Maks, jumlah_mahasiswa);
            continue;
        } else if (pilihan_user == 3){
            break;
        } else {
            printf("\nInput yang dimasukkan salah !");
            continue;
        }
    }
}

void compare_nilai(Mhs *Mahasiswa, Maksimal *Maks, int jumlah_mahasiswa){
    i = jumlah_mahasiswa;
    int nilai_akhir = calculate_akhir(Mahasiswa);
    if(Maks->nilai < nilai_akhir){
        Maks->nilai = nilai_akhir;
        strcpy(Maks->nama, Mahasiswa[i].nama);
    }
}

int calculate_akhir(Mhs *Mahasiswa){
    int nilai_akhir;
    nilai_akhir = (Mahasiswa[i].tugas * .2) + (Mahasiswa[i].uts* .4) + (Mahasiswa[i].uas* .4);
    return nilai_akhir;
}

char calculate_grade(nilai_akhir){
    if(nilai_akhir >= 80 && nilai_akhir <= 100){
        return 'A';
    } else if (nilai_akhir >= 70 && nilai_akhir < 80){
        return 'B';
    } else if (nilai_akhir >= 60 && nilai_akhir < 70){
        return 'C';
    } else if (nilai_akhir >= 50 && nilai_akhir < 60){
        return 'D';
    } else if (nilai_akhir >= 0 && nilai_akhir < 50){
        return 'E';
    } else {
        return 'Z';
    }
}

void tampil(Mhs *Mahasiswa, Maksimal *Maks, int jumlah_mhs){
    int nilai_akhir;
    char nilai_grade;
    printf("--------------------------------------------------------------------------\n");
    printf("| %-2s | %-25s | %-5s | %-5s | %-5s | %-5s | %-5s |", "No", "Nama Mahasiswa", "Tugas", "UTS", "UAS", "Akhir", "Grade");
    printf("\n--------------------------------------------------------------------------\n");
    if(jumlah_mhs > 0){
        for(i=1; i<=jumlah_mhs; i++){
            nilai_akhir = calculate_akhir(Mahasiswa);
            nilai_grade = calculate_grade(nilai_akhir);
            printf("| %-2d | %-25s | %-5d | %-5d | %-5d | %-5d | %-5c |",
                    i, Mahasiswa[i].nama, Mahasiswa[i].tugas, Mahasiswa[i].uts, Mahasiswa[i].uas, nilai_akhir, nilai_grade);
            printf("\n");
        }
    } else {
        printf("|                               Data Empty                               |\n");
    }
    printf("\n--------------------------------------------------------------------------\n");
    printf("\n\nMahasiswa Terbaik = %s\n", Maks->nama);
    printf("Nilai Mahasiswa Terbaik = %d\n", Maks->nilai);
    printf("\nTotal Mahasiswa = %d\n", jumlah_mhs);

}

void input(Mhs *Mahasiswa, Maksimal *Maks, int *jumlah_mhs){
    printf("Berapa jumlah mahasiswa : ");
    int tmp_jumlah;
    scanf("%d", &tmp_jumlah);
    printf("\nMasukkan Data Mahasiswa\n");
    for(i=1;i<=tmp_jumlah;i++){
        fflush(stdin);
        printf("Mahasiswa ke-%d\n", i);
        printf("%-12s : ", "Nama");
        fgets(Mahasiswa[i].nama, sizeof(Mahasiswa[i].nama), stdin);
        fflush(stdin);
        printf("%-12s : ", "Nilai Tugas");
        scanf("%d", &Mahasiswa[i].tugas);
        printf("%-12s : ", "Nilai UTS");
        scanf("%d", &Mahasiswa[i].uts);
        printf("%-12s : ", "Nilai UAS");
        scanf("%d", &Mahasiswa[i].uas);
        Mahasiswa[i].nama[strlen(Mahasiswa[i].nama) -1] = '\0';
        *jumlah_mhs = *jumlah_mhs + 1;
    }
    printf("\n\n");
    return 0;
}
