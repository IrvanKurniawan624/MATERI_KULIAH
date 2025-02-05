#include <stdio.h>
#include <stdlib.h>

int numMahasiswa=0;
struct Mahasiswas{
   int maks, min;
   int nilai[4];
   /// NOTE :
   // nilai[0] = eval1;
   // nilai[1] = eval2;
   // nilai[2] = eval3;
   // nilai[3] = uas;
   char nama[50], nrp[15], *huruf;
   float rata_rata;
} Mahasiswa[50];

int main()
{
    int selectedAction;
    do {
        printf("\nSelamat Datang di Program Nilai Mahasiswa\nOleh Irvan Aditya KUrniawan NRP : 31246000444\n");
        printf("\nSilahkan Pilih Menu anda : \n1.Menambahkan mahasiswa dan nilai\n2.Menampilkan Data Mahasiswa\n3.Selesai\n");
        printf("Pilihan Anda : ");
        scanf("%d", &selectedAction);
        switch(selectedAction){
            case 1:
                tambah_mahasiswa();
                break;
            case 2:
                tampilkan_mahasiswa();
                break;
            case 3:
                break;
            default:
                printf("\n\nInput Yang Dimasukkan Salah !\nSilahkan Masukkan Input Lagi");
                break;
        }

    } while(selectedAction != 3);

    return 0;
}

void calculate_huruf(int i){
    int temp = Mahasiswa[i].rata_rata;
    if(temp >= 86 && temp <= 100){
        Mahasiswa[i].huruf = "A";
    } else if(temp >= 81 && temp < 86){
        Mahasiswa[i].huruf = "A-";
    } else if(temp >= 76 && temp < 81){
        Mahasiswa[i].huruf = "AB";
    } else if(temp >= 71 && temp < 76){
        Mahasiswa[i].huruf = "B+";
    } else if(temp >= 66 && temp < 71){
        Mahasiswa[i].huruf = "B";
    } else if(temp >= 61 && temp < 66){
        Mahasiswa[i].huruf = "BC";
    } else if(temp >= 56 && temp < 61){
        Mahasiswa[i].huruf = "C";
    } else if(temp >= 41 && temp < 56){
        Mahasiswa[i].huruf = "D";
    } else if(temp >= 0 && temp < 41){
        Mahasiswa[i].huruf = "E";
    } else {
        printf("Rata-rata Invalid");
    }
    return;
}

void calculate_mahasiswa(int i){
    int j, total_nilai=0;
    Mahasiswa[i].maks = Mahasiswa[i].min = Mahasiswa[i].nilai[0];
    for(j=0; j < 4; j++){
        total_nilai += Mahasiswa[i].nilai[j];
        Mahasiswa[i].maks = (Mahasiswa[i].nilai[j] > Mahasiswa[i].maks) ? Mahasiswa[i].nilai[j] : Mahasiswa[i].maks;
        Mahasiswa[i].min = (Mahasiswa[i].nilai[j] < Mahasiswa[i].min) ? Mahasiswa[i].nilai[j] : Mahasiswa[i].min;
    }
    Mahasiswa[i].rata_rata = total_nilai / 4.0;
    /// Get Huruf Rata2
    calculate_huruf(i);
    numMahasiswa++;
}

void tambah_mahasiswa(){
    char is_continue = 'y';
    static int i = 0;
    do {
        if(i >= 50){
            printf("\nData Mahasiswa Sudah Penuh !");
            break;
        }
        fflush(stdin);
        printf("\nData Mahasiswa ke-%d", i + 1);
        printf("\nNRP : ");
        fgets(Mahasiswa[i].nrp, sizeof(Mahasiswa[i].nrp), stdin);
        Mahasiswa[i].nrp[strcspn(Mahasiswa[i].nrp, "\n")] = '\0';
        fflush(stdin);
        printf("Nama : ");
        fgets(Mahasiswa[i].nama, sizeof(Mahasiswa[i].nama), stdin);
        Mahasiswa[i].nama[strlen(Mahasiswa[i].nama) -1] = '\0';
        printf("Nilai Eval1 Eval2 Eval3 UAS : ");
        scanf("%d %d %d %d", &Mahasiswa[i].nilai[0], &Mahasiswa[i].nilai[1], &Mahasiswa[i].nilai[2], &Mahasiswa[i].nilai[3]);
        calculate_mahasiswa(i);
        fflush(stdin);
        i++;
        do{
            fflush(stdin);
            printf("\nMau Menambahkan lagi ? (y/t) : ");
            scanf("%c", &is_continue);
            if(is_continue != 'y' && is_continue != 't'){
                printf("Input Yang Dimasukkan Salah !");
            }
        } while(is_continue != 'y' && is_continue != 't');
    } while (is_continue == 'y');
    return;
}

void tampilkan_mahasiswa(){
    int i;
    printf("\n\n--------------------------------------------------------------------------------------------------------------\n");
    printf("| %-2s | %-10s | %-24s | %-5s | %-5s | %-5s | %-3s | %-9s | %-4s | %-4s | %-5s |\n",
           "No", "NRP", "Nama", "Eval1", "Eval2", "Eval3", "UAS", "Rata-Rata", "Maks", "Min", "Huruf");
    printf("--------------------------------------------------------------------------------------------------------------\n");

    if(numMahasiswa < 1){
        printf("|                                                 Data Empty                                                 |\n");
    } else {
        for (i = 0; i < numMahasiswa; i++) {
            printf("| %-2d | %-10s | %-24s | %-5d | %-5d | %-5d | %-3d | %-9.2f | %-4d | %-4d | %-5s |\n",
                   i + 1, Mahasiswa[i].nrp, Mahasiswa[i].nama, Mahasiswa[i].nilai[0], Mahasiswa[i].nilai[1], Mahasiswa[i].nilai[2], Mahasiswa[i].nilai[3],
                   Mahasiswa[i].rata_rata, Mahasiswa[i].min, Mahasiswa[i].maks, Mahasiswa[i].huruf);
        }
    }
    printf("--------------------------------------------------------------------------------------------------------------\n");


    float totalRataRata = 0, maxRataRata, minRataRata;
    int indexTertinggi = 0, indexTerendah = 0;
    int indexEval1Tertinggi = 0, indexEval1Terendah = 0;
    int indexEval2Tertinggi = 0, indexEval2Terendah = 0;
    int indexEval3Tertinggi = 0, indexEval3Terendah = 0;
    int indexUasTertinggi = 0, indexUasTerendah = 0;

    minRataRata = maxRataRata = Mahasiswa[0].rata_rata;

    for (i = 0; i < numMahasiswa; i++) {
        totalRataRata += Mahasiswa[i].rata_rata;

        if (Mahasiswa[i].rata_rata > maxRataRata) {
            maxRataRata = Mahasiswa[i].rata_rata;
            indexTertinggi = i;
        }
        if (Mahasiswa[i].rata_rata < minRataRata) {
            minRataRata = Mahasiswa[i].rata_rata;
            indexTerendah = i;
        }

        if (Mahasiswa[i].nilai[0] > Mahasiswa[indexEval1Tertinggi].nilai[0]) indexEval1Tertinggi = i;
        if (Mahasiswa[i].nilai[0] < Mahasiswa[indexEval1Terendah].nilai[0]) indexEval1Terendah = i;

        if (Mahasiswa[i].nilai[1] > Mahasiswa[indexEval2Tertinggi].nilai[1]) indexEval2Tertinggi = i;
        if (Mahasiswa[i].nilai[1] < Mahasiswa[indexEval2Terendah].nilai[1]) indexEval2Terendah = i;

        if (Mahasiswa[i].nilai[2] > Mahasiswa[indexEval3Tertinggi].nilai[2]) indexEval3Tertinggi = i;
        if (Mahasiswa[i].nilai[2] < Mahasiswa[indexEval3Terendah].nilai[2]) indexEval3Terendah = i;

        if (Mahasiswa[i].nilai[3] > Mahasiswa[indexUasTertinggi].nilai[3]) indexUasTertinggi = i;
        if (Mahasiswa[i].nilai[3] < Mahasiswa[indexUasTerendah].nilai[3]) indexUasTerendah = i;
    }

    printf("\n\nNilai rata-rata seluruh Mahasiswa : %.2f", totalRataRata / numMahasiswa);
    printf("\nNilai Mahasiswa tertinggi : %s dengan nilai %.2f", Mahasiswa[indexTertinggi].nama, maxRataRata);
    printf("\nNilai Mahasiswa terendah : %s dengan nilai %.2f", Mahasiswa[indexTerendah].nama, minRataRata);
    printf("\nNilai Mahasiswa dengan Eval1 tertinggi : %s dengan nilai %d", Mahasiswa[indexEval1Tertinggi].nama, Mahasiswa[indexEval1Tertinggi].nilai[0]);
    printf("\nNilai Mahasiswa dengan Eval1 terendah : %s dengan nilai %d", Mahasiswa[indexEval1Terendah].nama, Mahasiswa[indexEval1Terendah].nilai[0]);
    printf("\nNilai Mahasiswa dengan Eval2 tertinggi : %s dengan nilai %d", Mahasiswa[indexEval2Tertinggi].nama, Mahasiswa[indexEval2Tertinggi].nilai[1]);
    printf("\nNilai Mahasiswa dengan Eval2 terendah : %s dengan nilai %d", Mahasiswa[indexEval2Terendah].nama, Mahasiswa[indexEval2Terendah].nilai[1]);
    printf("\nNilai Mahasiswa dengan Eval3 tertinggi : %s dengan nilai %d", Mahasiswa[indexEval3Tertinggi].nama, Mahasiswa[indexEval3Tertinggi].nilai[2]);
    printf("\nNilai Mahasiswa dengan Eval3 terendah : %s dengan nilai %d", Mahasiswa[indexEval3Terendah].nama, Mahasiswa[indexEval3Terendah].nilai[2]);
    printf("\nNilai Mahasiswa dengan UAS tertinggi : %s dengan nilai %d", Mahasiswa[indexUasTertinggi].nama, Mahasiswa[indexUasTertinggi].nilai[3]);
    printf("\nNilai Mahasiswa dengan UAS terendah : %s dengan nilai %d", Mahasiswa[indexUasTerendah].nama, Mahasiswa[indexUasTerendah].nilai[3]);

    printf("\n\n Ketik Apapun untuk kembali !\n");
    fflush(stdin);
    getchar();
}
