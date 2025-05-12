#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef char itemType;

typedef struct Node {
    itemType data;
    struct Node *next;
} Node;

typedef struct {
    Node *front;
    Node *rear;
} queue;

void initQueue(queue *q);
bool isEmpty(queue *q);
void enqueue(queue *q);
itemType dequeue(queue *q);
void showMenu();
void showQueue(queue *q);

int main() {
    queue antrian;
    int pilihan;
    initQueue(&antrian);

    do {
        printf("\nMENU QUEUE using LINKED LIST\n");
        printf("1. Mengisi Queue (Enqueue)\n");
        printf("2. Mengambil isi queue (Dequeue)\n");
        printf("3. Menampilkan isi Queue -> FIFO\n");
        printf("4. Keluar\n");
        printf("Masukkan Pilihan Anda : ");
        scanf("%d", &pilihan);
        getchar();

        switch(pilihan){
            case 1:
                enqueue(&antrian);
                break;
            case 2: {
                itemType temp = dequeue(&antrian);
                if (temp != '\0') {
                    printf("Item yang anda ambil adalah %c\n", temp);
                }
                break;
            }
            case 3:
                showQueue(&antrian);
                break;
            case 4:
                break;
            default:
                printf("Pilihan Menu tidak sesuai!\n");
        }

    } while(pilihan != 4);

    return 0;
}

void initQueue(queue *q) {
    q->front = NULL;
    q->rear = NULL;
}

bool isEmpty(queue *q) {
    return q->front == NULL;
}

void enqueue(queue *q) {
    itemType x;
    printf("Masukkan Data Anda : ");
    scanf(" %c", &x);

    Node *newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memori tidak cukup!\n");
        return;
    }

    newNode->data = x;
    newNode->next = NULL;

    if (isEmpty(q)) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }

    printf("Data berhasil dimasukkan ke dalam queue.\n");
}

itemType dequeue(queue *q) {
    if (isEmpty(q)) {
        printf("Queue masih kosong!\n");
        return;
    }

    Node *temp = q->front;
    itemType data = temp->data;

    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    return data;
}

void showQueue(queue *q) {
    if (isEmpty(q)) {
        printf("Queue kosong!\n");
        return;
    }

    Node *current = q->front;
    printf("Isi queue (FIFO):\n");
    while (current != NULL) {
        printf("%c\n", current->data);
        current = current->next;
    }
}
