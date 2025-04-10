#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct mahasiswas Mahasiswa;
struct mahasiswas {
    int no;
    char nama[20];
    float nilai;
};

typedef struct simpul Node;
struct simpul {
    Mahasiswa data;
    Node *next;
    Node *prev;
};
Node *head = NULL, *p, *hapus;

void showMenu(int* pilihanMenu);
void checkJwb(int* pilihanMenu);
void alokasi();
void getInput();
bool checkNodeEmpty();
void showDLL();
void freeNode();

/// init Type
void insertAwal();
void insertAkhir();
void insertBefore(int key);

void deleteAwal();
void deleteAkhir();
void deleteTertentu(int key);

void penambahan_terurut();
void pencarian_data();
void penghapusan_data();

int main() {
    int pilihanMenu;
    do {
        showMenu(&pilihanMenu);
        checkJwb(&pilihanMenu);
        fflush(stdin);
    } while (pilihanMenu != 4);
}

void showMenu(int* pilihanMenu) {
    printf("MENU UTAMA :\n1. Penambahan secara terurut\n2. Pencarian data\n3. Penghapusan Data\n4. Keluar\n");
    printf("Masukkan pilihan Anda : ");
    scanf("%d", pilihanMenu);
}

void alokasi() {
    p = (Node *)malloc(sizeof(Node));
    if (p == NULL) {
        printf("Alokasi Gagal !");
        exit(0);
    }
    p->next = NULL;
    p->prev = NULL;
    getInput();
}

void getInput() {
    printf("%-6s : ", "No");
    scanf("%d", &p->data.no);
    getchar();

    printf("%-6s : ", "Nama");
    fgets(p->data.nama, sizeof(p->data.nama), stdin);
    p->data.nama[strlen(p->data.nama) - 1] = '\0';

    printf("%-6s : ", "Nilai");
    scanf("%f", &p->data.nilai);
}

void checkJwb(int* pilihanMenu) {
    switch (*pilihanMenu) {
        case 1:
            alokasi();
            penambahan_terurut();
            showDLL();
            break;
        case 2:
            pencarian_data();
            break;
        case 3:
            penghapusan_data();
            showDLL();
            break;
        case 4:
            break;
        default:
            printf("Pilihan Menu Tidak Terdaftar\n\n");
    }
}

void showDLL() {
    Node *read = head;
    printf("\nData yang telah diinputkan : \n");
    printf("%-8s %-8s %-8s\n", "No", "Nama", "Nilai");
    if (head == NULL) {
        printf("Data Kosong\n");
        return;
    }
    while (read != NULL) {
        printf("%-8d %-8s %-8.2f\n", read->data.no, read->data.nama, read->data.nilai);
        read = read->next;
    }
    printf("\n\n");
}

bool checkNodeEmpty() {
    if (head == NULL) {
        printf("\nData Node Masih Kosong\n");
        return true;
    }
    return false;
}

void freeNode() {
    free(hapus);
    hapus = NULL;
}

void insertAwal() {
    p->next = head;
    if (head != NULL)
        head->prev = p;
    head = p;
}

void insertAkhir() {
    if (head == NULL) {
        insertAwal();
    } else {
        Node *tail = head;
        while (tail->next != NULL)
            tail = tail->next;
        tail->next = p;
        p->prev = tail;
    }
}

void insertBefore(int key) {
    Node *bef = head;
    while (bef != NULL && bef->data.no != key)
        bef = bef->next;

    if (bef == NULL) {
        printf("Node dengan No %d tidak ditemukan dalam Linked List.\n\n", key);
        return;
    }

    p->next = bef;
    p->prev = bef->prev;
    if (bef->prev != NULL)
        bef->prev->next = p;
    else
        head = p;
    bef->prev = p;
}

void penambahan_terurut() {
    if (head == NULL || p->data.no < head->data.no) {
        insertAwal();
        return;
    }

    Node *temp = head;
    while (temp->next != NULL && p->data.no > temp->next->data.no)
        temp = temp->next;

    if (temp->next == NULL)
        insertAkhir();
    else
        insertBefore(temp->next->data.no);
}

void deleteAwal() {
    if (head == NULL) return;
    hapus = head;
    head = head->next;
    if (head != NULL)
        head->prev = NULL;
    freeNode();
}

void deleteAkhir() {
    if (head == NULL) return;
    Node *tail = head;
    while (tail->next != NULL)
        tail = tail->next;

    if (tail->prev != NULL)
        tail->prev->next = NULL;
    else
        head = NULL;
    hapus = tail;
    freeNode();
}

void deleteTertentu(int key) {
    Node *temp = head;
    while (temp != NULL && temp->data.no != key)
        temp = temp->next;

    if (temp == NULL) {
        printf("Key Tidak Ditemukan !\n\n");
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    hapus = temp;
    freeNode();
}

void pencarian_data() {
    Node *temp = head;
    int key, count = 0;
    printf("Masukkan No Mahasiswa yang mau dicari : ");
    scanf("%d", &key);
    while (temp != NULL) {
        if (temp->data.no == key) count++;
        temp = temp->next;
    }
    printf(count == 0 ? "Data tidak ditemukan\n\n" : "Data ditemukan %d kali\n\n", count);
}

void penghapusan_data() {
    int key;
    if (checkNodeEmpty()) return;
    printf("\nMasukkan No Mahasiswa yang ingin dihapus: ");
    scanf("%d", &key);

    Node *temp = head;
    while (temp != NULL && temp->data.no != key)
        temp = temp->next;

    if (temp == NULL) {
        printf("Data dengan No %d tidak ditemukan!\n\n", key);
        return;
    }

    if (temp == head)
        deleteAwal();
    else if (temp->next == NULL)
        deleteAkhir();
    else
        deleteTertentu(key);
}
