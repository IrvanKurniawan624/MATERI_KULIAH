#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct simpul Node;
struct simpul {
    int data;
    Node *next;
};
Node *head = NULL, *p, *hapus;

void showMenu(int* pilihanMenu);
void checkJwb(int* pilihanMenu);
void alokasi();
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
        fflush(stdin);
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
    printf("Masukan datanya : ");
    scanf("%d", &p->data);
    p->next = NULL;
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
    Node *read;
    read = head;
    if(head == NULL){
        printf("Data Kosong\n");
        return;
    }
    while(read != NULL){
        printf("%d ", read->data);
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
    if(head != NULL)
        p->next = head;
    head = p;
}

void insertAkhir(){
    Node *tail;
    if(head==NULL){
        insertAwal();
    }else{
        tail = head;
        while(tail->next != NULL)
            tail = tail->next;

        tail->next = p;
        tail = tail->next;
    }
}

void insertBefore(int key)
{
    Node *bef, *pbef;
    if(head == NULL){
        puts("Linked List masih Kosong\n\n");
        return;
    }
    if(head->data == key){
        insertAwal();
        return;
    }
    bef = head;
    pbef = NULL;
    while (bef != NULL && bef->data != key) {
        pbef = bef;
        bef = bef->next;
    }

    if (bef == NULL) {
        printf("Node dengan nilai %d tidak ditemukan dalam Linked List.\n\n", key);
        return;
    }

    p->next = bef;
    pbef->next = p;
}

void deleteAwal(){
    hapus = head;
    if(hapus->next == NULL)
        head = NULL;
    else
        head = hapus->next;

    free(hapus);
    hapus = NULL;
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
    free(hapus);
    hapus = NULL;
}

void deleteTertentu(int key){
    Node *ph;
    hapus = head;
    if(hapus->data == key)
        deleteAwal();
    else{
        while(hapus->data != key){
            if(hapus->next == NULL){
                printf("Key Tidak Ditemukan !\n\n");
                break;
            }
            ph = hapus;
            hapus = hapus->next;
        }
        ph->next = hapus->next;
    }
    free(hapus);
    hapus = NULL;
}

void penambahan_terurut()
{
    Node *temp;
    if(head == NULL || p->data < head->data){
        insertAwal();
        return;
    }
    temp = head;

    while(temp->next != NULL && p->data > temp->next->data){
        temp = temp->next;
    }

    if(temp->next == NULL){
        insertAkhir();
    } else {
        insertBefore(temp->next->data);
    }
}

void pencarian_data()
{
    Node *temp;
    int key, count = 0;
    temp = head;
    printf("Masukkan data yang mau dicari : ");
    scanf("%d", &key);
    while(temp != NULL){
        if(temp->data == key){
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

void penghapusan_data()
{
    int key;
    bool isEmpty = checkNodeEmpty();
    if(isEmpty)
        return;
    printf("\nMasukkan data yang ingin dihapus: ");
    scanf("%d", &key);

    if (head->data == key) {
        deleteAwal();
        return;
    }

    Node *temp = head;
    while (temp->next != NULL) {
        if (temp->next->data == key && temp->next->next == NULL) {
            deleteAkhir();
            return;
        }
        temp = temp->next;
    }

    deleteTertentu(key);

}
