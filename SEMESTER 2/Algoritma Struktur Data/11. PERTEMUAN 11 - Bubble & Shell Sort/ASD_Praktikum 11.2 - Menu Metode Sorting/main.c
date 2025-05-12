#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX 15

typedef struct {
    int no;
    char nama[50];
    int nilai;
} siswa;

void inputData(siswa data[], int *count);
void sortingMethod(siswa data[], int *count);
void insertionSort(siswa data[], int type, int field, int *count);
void selectionSort(siswa data[], int type, int field, int *count);
void bubbleSort(siswa data[], int type, int field, int *count);
void shellSort(siswa data[], int type, int field, int *count);
int modeUrut();
int modeField();
void tampilkanData(siswa data[], int count);

int main() {
    int count = 0;
    siswa data[MAX];
    inputData(data, &count);
    tampilkanData(data, count);
    sortingMethod(data, &count);
    tampilkanData(data, count);
}

void inputData(siswa data[], int *count) {
    int i = 0;
    char isLoop = 'y';
    for (i = 0; i < MAX; i++) {
        printf("(Siswa ke-%d)\n", i + 1);
        printf("No : ");
        scanf("%d", &data[i].no);
        fflush(stdin);
        printf("Nama : ");
        fgets(data[i].nama, sizeof(data[i].nama), stdin);
        data[i].nama[strlen(data[i].nama) - 1] = '\0';
        printf("Nilai (Angka) : ");
        scanf("%d", &data[i].nilai);
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

int modeField() {
    int field;
    printf("\nUrut berdasarkan :\n1.\tNo\n2.\tNama\n3.\tNilai\n");
    printf("Pilihan Anda [1/2/3] : ");
    scanf("%d", &field);
    return field;
}

void sortingMethod(siswa data[], int *count) {
    int pilihan, type, field;
    printf("MENU METODE SORTING\n1.Insertion Sort\n2.Selection Sort\n3.Bubble Sort\n4.Shell Sort\n5.Keluar\n");
    printf("Pilihan Anda [1/2/3/4/5] : ");
    scanf("%d", &pilihan);
    if (pilihan >= 1 && pilihan <= 4) {
        type = modeUrut();
        field = modeField();
    }
    switch (pilihan) {
        case 1:
            insertionSort(data, type, field, count);
            break;
        case 2:
            selectionSort(data, type, field, count);
            break;
        case 3:
            bubbleSort(data, type, field, count);
            break;
        case 4:
            shellSort(data, type, field, count);
            break;
        case 5:
            exit(0);
        default:
            sortingMethod(data, count);
            break;
    }
}

bool compare(siswa a, siswa b, int type, int field) {
    int result = 0;
    if (field == 1)
        result = a.no - b.no;
    else if (field == 2)
        result = strcmp(a.nama, b.nama);
    else if (field == 3)
        result = a.nilai - b.nilai;
    return (type == 1) ? (result > 0) : (result < 0);
}

void insertionSort(siswa data[], int type, int field, int *count) {
    int i, checker;
    siswa key;
    for (i = 1; i < *count; i++) {
        key = data[i];
        checker = i - 1;
        while (checker >= 0 && compare(data[checker], key, type, field)) {
            data[checker + 1] = data[checker];
            checker--;
        }
        data[checker + 1] = key;
    }
}

void selectionSort(siswa data[], int type, int field, int *count) {
    int i, checker, minmax;
    siswa temp;
    for (i = 0; i < *count - 1; i++) {
        minmax = i;
        for (checker = i + 1; checker < *count; checker++) {
            if (compare(data[minmax], data[checker], type, field)) {
                minmax = checker;
            }
        }
        if (minmax != i) {
            temp = data[i];
            data[i] = data[minmax];
            data[minmax] = temp;
        }
    }
}

void bubbleSort(siswa data[], int type, int field, int *count) {
    int i, checker;
    siswa temp;
    for (i = 0; i < *count - 1; i++) {
        for (checker = 0; checker < *count - i - 1; checker++) {
            if (compare(data[checker], data[checker + 1], type, field)) {
                temp = data[checker];
                data[checker] = data[checker + 1];
                data[checker + 1] = temp;
            }
        }
    }
}

void shellSort(siswa data[], int type, int field, int *count) {
    int gap, i, checker;
    siswa temp;
    for (gap = *count / 2; gap > 0; gap /= 2) {
        for (i = gap; i < *count; i++) {
            temp = data[i];
            checker = i;
            while (checker >= gap && compare(data[checker - gap], temp, type, field)) {
                data[checker] = data[checker - gap];
                checker -= gap;
            }
            data[checker] = temp;
        }
    }
}

void tampilkanData(siswa data[], int count) {
    int i;
    printf("\n%-5s %-20s %-6s\n", "No", "Nama", "Nilai");
    printf("--------------------------------------\n");
    for (i = 0; i < count; i++) {
        printf("%-5d %-20s %-6d\n", data[i].no, data[i].nama, data[i].nilai);
    }
    printf("\n");
}
