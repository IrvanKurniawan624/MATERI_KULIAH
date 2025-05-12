#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAKS 5

typedef char itemType;
typedef struct{
    itemType data[MAKS];
    int front;
    int rear;
    int count;
} queue;

void initQueue(queue *q);
bool isFull(queue *q);
bool isEmpty(queue *q);
void enqueue(queue *q);
itemType dequeue(queue *q);
void showMenu();

int main()
{
    queue antrian;
    int pilihan;
    initQueue(&antrian);
    do{
        showMenu(&pilihan, &antrian);
        fflush(stdin);
        printf("\n");
    }while(pilihan != 4);
}

void initQueue(queue *q)
{
    q->count = 0;
    q->rear = 0;
    q->front = 0;
}

bool isFull(queue *q)
{
    return (q->count == MAKS) ? true : false;
}

bool isEmpty(queue *q)
{
    return (q->count == 0) ? true : false;
}

void showMenu(int *pilihan, queue *q)
{
    char temp;
    printf("MENU QUEUE using ARRAY\n1. Mengisi Queue (Enqueue)\n2. Mengambil isi queue (Dequeue)\n3. Menampilkan isi Queue -> FIFO\n4. Keluar\n");
    printf("Masukkan Pilihan Anda : ");
    scanf("%d", pilihan);
    switch(*pilihan){
        case 1:
            enqueue(q);
            break;
        case 2:
            temp = dequeue(q);
            printf("Item yang anda amibil adalah %c\n", temp);
            break;
        case 3:
            showQueue(q);
            break;
        case 4:
            break;
        default:
            printf("Pilihan Menu tidak seusai\n");
    }
}

void enqueue(queue *q)
{
    itemType x;
    if(isFull(q)){
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

itemType dequeue(queue *q)
{
    itemType temp;
    if(isEmpty(q)){
        printf("Queue Masih Kosong!\n");
        return " ";
    }
    temp = q->data[q->front];
    q->front= (q->front+ 1) % MAKS;
    q->count--;
    return temp;
}

void showQueue(queue *q)
{
    int i;
    for (i = q->front; i <= q->rear; i++) {
        printf("%c\n", q->data[i]);
    }
}
