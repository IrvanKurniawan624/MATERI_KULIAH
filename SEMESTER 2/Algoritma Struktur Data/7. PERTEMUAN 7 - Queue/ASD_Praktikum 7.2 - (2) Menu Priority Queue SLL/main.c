#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    char data;
    int prioritas;
    struct node *next;
} node;

void tampilMenu(int *pilihan);
void enqueue(node **head);
void dequeue(node **head);
void tampilQueue(node *head);
node* buatNode(char data, int prioritas);
void insertPrioritas(node **head, node *baru);

int main() {
    node *head = NULL;
    int pilihan;

    do {
        tampilMenu(&pilihan);
        switch (pilihan) {
            case 1:
                enqueue(&head);
                break;
            case 2:
                dequeue(&head);
                break;
            case 3:
                tampilQueue(head);
                break;
            case 4:
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
        }
        printf("\n");
    } while (pilihan != 4);

    return 0;
}

void tampilMenu(int *pilihan) {
    printf("MENU PRIORITY Queue using LINKED LIST :\n");
    printf("1. Mengisi Queue\n");
    printf("2. Mengambil isi Queue\n");
    printf("3. Menampilkan isi Queue\n");
    printf("4. Keluar\n");
    printf("Masukkan pilihan Anda : ");
    scanf("%d", pilihan);
}

node* buatNode(char data, int prioritas) {
    node *baru = (node*) malloc(sizeof(node));
    baru->data = data;
    baru->prioritas = prioritas;
    baru->next = NULL;
    return baru;
}

void insertPrioritas(node **head, node *baru) {
    if (*head == NULL || baru->prioritas < (*head)->prioritas) {
        baru->next = *head;
        *head = baru;
    } else {
        node *temp = *head;
        while (temp->next != NULL && temp->next->prioritas <= baru->prioritas) {
            temp = temp->next;
        }
        baru->next = temp->next;
        temp->next = baru;
    }
}

void enqueue(node **head) {
    char data;
    int prioritas;

    fflush(stdin);
    printf("Masukkan data Anda : ");
    scanf(" %c", &data);

    printf("Nilai prioritasnya : ");
    scanf("%d", &prioritas);

    node *baru = buatNode(data, prioritas);
    insertPrioritas(head, baru);
}

void dequeue(node **head) {
    if (*head == NULL) {
        printf("Queue kosong!\n");
        return;
    }
    node *hapus = *head;
    printf("Item yang Anda ambil adalah %c\n", hapus->data);
    *head = (*head)->next;
    free(hapus);
}

void tampilQueue(node *head) {
    if (head == NULL) {
        printf("Queue kosong!\n");
        return;
    }

    printf("Isi Queue saat ini adalah :\n");
    printf("Data\tPrioritas\n");
    node *temp = head;
    while (temp != NULL) {
        printf("%c\t%d\n", temp->data, temp->prioritas);
        temp = temp->next;
    }
}
