#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAKS 5

typedef char itemType;

typedef struct {
    itemType data[MAKS];
    int front;
    int rear;
    int count;
} queue;

int i;
void initQueue(queue *q);
bool isFull(queue *q);
bool isEmpty(queue *q);
void enqueue(queue *q);
itemType dequeue(queue *q);
void showMenu(int *pilihan, queue *q);
void showQueue(queue *q);
void cariData(queue *q, itemType target);
void tampilMinMax(queue *q);

int main() {
    queue antrian;
    int pilihan;
    initQueue(&antrian);
    do {
        showMenu(&pilihan, &antrian);
        fflush(stdin);
        printf("\n");
    } while (pilihan != 6);
}

void initQueue(queue *q) {
    q->count = 0;
    q->rear = 0;
    q->front = 0;
}

bool isFull(queue *q) {
    return (q->count == MAKS);
}

bool isEmpty(queue *q) {
    return (q->count == 0);
}

void showMenu(int *pilihan, queue *q) {
    char temp, dicari;
    printf("MENU QUEUE using ARRAY\n");
    printf("1. Enqueue (Masukkan Data)\n");
    printf("2. Dequeue (Ambil Data)\n");
    printf("3. Tampilkan MIN & MAX\n");
    printf("4. Cari Data\n");
    printf("5. Cetak Isi Queue\n");
    printf("6. Keluar\n");
    printf("Masukkan Pilihan Anda : ");
    scanf("%d", pilihan);
    switch (*pilihan) {
        case 1:
            enqueue(q);
            break;
        case 2:
            temp = dequeue(q);
            if (temp != ' ')
                printf("Item yang anda ambil adalah %c\n", temp);
            break;
        case 3:
            tampilMinMax(q);
            break;
        case 4:
            fflush(stdin);
            printf("Masukkan data yang ingin dicari: ");
            scanf("%c", &dicari);
            cariData(q, dicari);
            break;
        case 5:
            showQueue(q);
            break;
        case 6:
            printf("Keluar dari program.\n");
            break;
        default:
            printf("Pilihan Menu tidak sesuai\n");
    }
}

void enqueue(queue *q) {
    itemType x;
    if (isFull(q)) {
        printf("STOP !!!\nQueue Sudah penuh tidak bisa menambah data lagi!\n");
        return;
    }
    fflush(stdin);
    printf("Masukkan Data Anda : ");
    scanf("%c", &x);
    q->data[q->rear] = x;
    q->rear = (q->rear + 1) % MAKS;
    q->count++;
}

itemType dequeue(queue *q) {
    itemType temp;
    if (isEmpty(q)) {
        printf("Queue Masih Kosong!\n");
        return ' ';
    }
    temp = q->data[q->front];
    q->front = (q->front + 1) % MAKS;
    q->count--;
    return temp;
}

void showQueue(queue *q) {
    if (isEmpty(q)) {
        printf("Queue kosong!\n");
        return;
    }

    printf("Isi Queue: ");
    for (i = 0; i < q->count; i++) {
        int index = (q->front + i) % MAKS;
        printf("%c ", q->data[index]);
    }
    printf("\n");
}

void cariData(queue *q, itemType target) {
    bool ketemu = false;
    for (i = 0; i < q->count; i++) {
        int index = (q->front + i) % MAKS;
        if (q->data[index] == target) {
            printf("Data %c ditemukan pada posisi %d dalam queue.\n", target, i + 1);
            ketemu = true;
        }
    }
    if (!ketemu)
        printf("Data %c tidak ditemukan dalam queue.\n", target);
}

void tampilMinMax(queue *q) {
    if (isEmpty(q)) {
        printf("Queue kosong, tidak ada data.\n");
        return;
    }

    itemType min = q->data[q->front];
    itemType max = q->data[q->front];

    for (i = 0; i < q->count; i++) {
        int index = (q->front + i) % MAKS;
        if (q->data[index] < min)
            min = q->data[index];
        if (q->data[index] > max)
            max = q->data[index];
    }

    printf("Data Minimum dalam Queue: %c\n", min);
    printf("Data Maksimum dalam Queue: %c\n", max);
}
