#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 15

typedef struct {
    int no;
    char nama[50];
    char nilai;
} siswa;

void inputData(siswa data[], int *count);
void sortingMethod(siswa data[], int *count);
void insertionSort(siswa data[], int type, int *count);
void selectionSort(siswa data[], int type, int *count);
int modeUrut();
void tampilkanData(siswa data[], int count);

int main() {
    int count = 0; char jwb = 'y';
    printf("PROGRAM SORTING SISWA (STRUCT) | 10.2 \n");
    siswa data[MAX];
    inputData(data, &count);
    tampilkanData(data, count);
    sortingMethod(data, &count);
    tampilkanData(data, count);
}

void inputData(siswa data[], int *count) {
    int i = 0;
    char isLoop = 'y';
    printf("\n=== INPUT DATA ===\n");
    for (i = 0; i < MAX; i++) {
        printf("(Siswa ke-%d)\n", i + 1);
        printf("No : ");
        scanf("%d", &data[i].no);
        fflush(stdin);
        printf("Nama : ");
        fgets(data[i].nama, sizeof(data[i].nama), stdin);
        data[i].nama[strlen(data[i].nama) -1] = '\0';
        printf("Nilai (Huruf) : ");
        scanf(" %c", &data[i].nilai);
        (*count)++;
        printf("\nIngin input lagi (y/n) : ");
        scanf(" %c", &isLoop);
        printf("\n");
        if (isLoop == 'n')
            break;
    }
}

int modeUrut() {
    int type;
    printf("Pengurutan yang dipilih :\n1.\tAscending\n2.\tDescending\n");
    printf("Pilihan Anda [1/2] : ");
    scanf("%d", &type);
    return type;
}

void sortingMethod(siswa data[], int *count) {
    int pilihan, type;
    printf("MENU METODE SORTING\n1.\tInsertion Sort\n2.\tSelection Sort\n3.\tKeluar\n");
    printf("Pilihan Anda [1/2/3] : ");
    scanf("%d", &pilihan);
    if (pilihan == 1 || pilihan == 2) {
        type = modeUrut();
    }
    switch (pilihan) {
        case 1:
            insertionSort(data, type, count);
            break;
        case 2:
            selectionSort(data, type, count);
            break;
        case 3:
            break;
        default:
            printf("\n Input yang anda Masukkan salah !\n");
            sortingMethod(data, count);
            break;
    }
}

void insertionSort(siswa data[], int type, int *count) {
    int idx_now, checker;
    siswa key;
    for (idx_now = 1; idx_now < *count; idx_now++) {
        key = data[idx_now];
        checker = idx_now - 1;

        if (type == 1) {
            while (checker >= 0 && data[checker].no > key.no) {
                data[checker + 1] = data[checker];
                checker--;
            }
        } else {
            while (checker >= 0 && data[checker].no < key.no) {
                data[checker + 1] = data[checker];
                checker--;
            }
        }
        data[checker + 1] = key;
    }
}

void selectionSort(siswa data[], int type, int *count) {
    int idx_now, checker, minmax;
    siswa temp;
    for (idx_now = 0; idx_now < *count - 1; idx_now++) {
        minmax = idx_now;
        for (checker = idx_now + 1; checker < *count; checker++) {
            if ((type == 1 && data[checker].no < data[minmax].no) ||
                (type == 2 && data[checker].no > data[minmax].no)) {
                minmax = checker;
            }
        }
        if (minmax != idx_now) {
            temp = data[idx_now];
            data[idx_now] = data[minmax];
            data[minmax] = temp;
        }
    }
}

void tampilkanData(siswa data[], int count) {
    int i;
    printf("\n%-5s %-20s %-6s\n", "No", "Nama", "Nilai");
    printf("--------------------------------------\n");
    for (i = 0; i < count; i++) {
        printf("%-5d %-20s %-6c\n", data[i].no, data[i].nama, data[i].nilai);
    }
    printf("\n");
}

