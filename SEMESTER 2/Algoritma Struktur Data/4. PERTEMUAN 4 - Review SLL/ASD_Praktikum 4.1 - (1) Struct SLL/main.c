#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct mahasiswas Mahasiswa;
struct mahasiswas{
    int no;
    char nama[20];
    float nilai;
};

typedef struct simpul Node;
struct simpul {
    Mahasiswa data;
    Node *next;
};
Node *head = NULL, *p, *hapus;

void showMenu(int* pilihanMenu);
void checkJwb(int* pilihanMenu);
void alokasi();
void getInput();
bool checkNodeEmpty();
void showSLL();
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

int main()
{
    int pilihanMenu;
    do{
        showMenu(&pilihanMenu);
        checkJwb(&pilihanMenu);
    } while(pilihanMenu != 4);
}

void showMenu(int* pilihanMenu)
{
    printf("MENU UTAMA :\n1. Penambahan secara terurut\n2. Pencarian data\n3. Penghapusan Data\n4. Keluar\n");
    printf("Masukkan pilihan Anda : ");
    scanf("%d", pilihanMenu);
}

void alokasi()
{
    p = (Node *)malloc(sizeof(Node));
    if(p == NULL){
        printf("Alokasi Gagal !");
        exit(0);
    }
    p->next = NULL;
    getInput();
}

void getInput()
{
    printf("%-6s : ", "No");
    scanf("%d", &p->data.no);
    getchar();

    printf("%-6s : ", "Nama");
    fgets(p->data.nama, sizeof(p->data.nama), stdin);
    p->data.nama[strlen(p->data.nama) -1] = '\0';

    printf("%-6s : ", "Nilai");
    scanf("%f", &p->data.nilai);
}

void checkJwb(int* pilihanMenu)
{
    switch(*pilihanMenu){
        case 1:
            alokasi();
            penambahan_terurut();
            showSLL();
            break;
        case 2:
            pencarian_data();
            break;
        case 3:
            penghapusan_data();
            showSLL();
            break;
        case 4:
            break;
        default:
            printf("Pilihan Menu Tidak Terdaftar\n\n");
    }
}

void showSLL(){
    Node *read = head;
    printf("\nData yang telah diinputkan : \n");
    printf("%-8s %-8s %-8s\n", "No", "Nama", "Nilai");
    if(head == NULL){
        printf("Data Kosong\n");
        return;
    }
    while(read != NULL){
        printf("%-8d %-8s %-8.2f\n", read->data.no, read->data.nama, read->data.nilai);
        read = read->next;
    }
    printf("\n\n");
}

bool checkNodeEmpty()
{
    if(head == NULL){
        printf("\nData Node Masih Kosong\n");
        return true;
    }
    return false;
}

void freeNode(){
    free(hapus);
    hapus = NULL;
}

void insertAwal()
{
    p->next = head;
    head = p;
}

void insertAkhir(){
    if(head==NULL){
        insertAwal();
    }else{
        Node *tail = head;
        while(tail->next != NULL)
            tail = tail->next;
        tail->next = p;
    }
}

void insertBefore(int key)
{
    Node *bef, *pbef;
    if (head == NULL) {
        puts("Linked List masih Kosong\n\n");
        return;
    }

    if (head->data.no == key) {
        insertAwal();
        return;
    }

    bef = head;
    pbef = NULL;

    while (bef != NULL && bef->data.no != key) {
        pbef = bef;
        bef = bef->next;
    }

    if (bef == NULL) {
        printf("Node dengan No %d tidak ditemukan dalam Linked List.\n\n", key);
        return;
    }

    p->next = bef;
    pbef->next = p;
}

void penambahan_terurut()
{
    if (head == NULL || p->data.no < head->data.no) {
        insertAwal();
        return;
    }

    Node *temp = head;
    while (temp->next != NULL && p->data.no > temp->next->data.no) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        insertAkhir();
    } else {
        insertBefore(temp->next->data.no);
    }
}


void pencarian_data()
{
    Node *temp = head;
    int key, count = 0;
    printf("Masukkan No Mahasiswa yang mau dicari : ");
    scanf("%d", &key);
    while(temp != NULL){
        if(temp->data.no == key){
            count++;
        }
        temp = temp->next;
    }
    if(count == 0){
        printf("Data %d tidak ada dalam LL\n\n", key);
    } else {
        printf("Data %d ketemu sebanyak %d kali\n\n", key, count);
    }
}

void deleteAwal(){
    if(head == NULL) return;
    hapus = head;
    head = head->next;
    freeNode();
}

void deleteAkhir(){
    Node *ph;
    hapus = head;
    if(hapus->next == NULL)
        head = NULL;
    else {
        while(hapus->next != NULL){
            ph = hapus;
            hapus = hapus->next;
        }
        ph->next = NULL;
    }
    freeNode();
}

void deleteTertentu(int key){
    if(head == NULL) return;
    if(head->data.no == key){
        deleteAwal();
        return;
    }
    Node *temp = head;
    while(temp->next != NULL && temp->next->data.no != key){
        temp = temp->next;
    }
    if(temp->next == NULL){
        printf("Key Tidak Ditemukan !\n\n");
        return;
    }
    Node *hapus = temp->next;
    temp->next = temp->next->next;
    freeNode();
}

void penghapusan_data()
{
    int key;
    bool isEmpty = checkNodeEmpty();
    if (isEmpty)
        return;

    printf("\nMasukkan No Mahasiswa yang ingin dihapus: ");
    scanf("%d", &key);

    if (head->data.no == key) {
        deleteAwal();
        return;
    }

    Node *temp = head;
    while (temp->next != NULL) {
        if (temp->next->data.no == key) {
            if (temp->next->next == NULL) {
                deleteAkhir();
            } else {
                deleteTertentu(key);
            }
            return;
        }
        temp = temp->next;
    }

    printf("Data dengan No %d tidak ditemukan!\n\n", key);
}

