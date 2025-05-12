#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct simpul Dnode;
struct simpul {
    int data;
    Dnode *next, *prev;
};
Dnode *head = NULL, *prev,  *p, *hapus;

void showMenu(int *pilihanMenu, int *pilihanType);
void alokasi();
void checkPilihan(int *pilihanMenu, int *pilihanType);
bool checkNodeEmpty();
void showSLL();
void freeNode();

/// init Type
void insertAwal();
void insertAkhir();
void insertAfter();
void insertBefore();

void deleteAwal();
void deleteAkhir();
void deleteTertentu();

int main()
{
    /// MENU INSERT DLL
    int pilihanMenu, pilihanType;
    do{
        showMenu(&pilihanMenu, &pilihanType);
        checkPilihan(&pilihanMenu, &pilihanType);
        fflush(stdin);
        showSLL();
    } while(pilihanMenu != '3');
}

void showMenu(int *pilihanMenu, int *pilihanType)
{
    printf("Menu Utama\n");
    printf("1. Insert\n2. Delete\n3. Keluar\n");
    printf("Masukkan Pilihan Menu Anda : ");
    scanf("%d", pilihanMenu);
    if(*pilihanMenu == 1){
        printf("MENU INSERT\n");
        printf("1. Insert Awal\n2. Insert Akhir\n3. Insert After\n4. Insert Before\n5. Keluar\n");
    } else if (*pilihanMenu == 2){
        printf("MENU DELETE\n");
        printf("1. Delete Awal\n2. Delete Akhir\n3. Delete Tertentu\n");
    } else {
        if(*pilihanMenu != 3)
            printf("Pilihan Tidak Valid\n");
        return;
    }
    printf("Masukkan Pilihan Type Anda : ");
    scanf("%d", pilihanType);
}

void alokasi()
{
    p = (Dnode *)malloc(sizeof(Dnode));
    if(p == NULL){
        printf("Alokasi Gagal !");
        exit(0);
    } else {
        p->next = NULL;
        p->prev = NULL;
    }
    printf("Data yang mau disimpan : ");
    scanf("%d", &p->data);
}

void checkPilihan(int *pilihanMenu, int *pilihanType)
{
    if(*pilihanMenu == 1){
        alokasi();
        switch(*pilihanType){
            case 1:
                insertAwal();
                break;
            case 2:
                insertAkhir();
                break;
            case 3:
                insertAfter();
                break;
            case 4:
                insertBefore();
                break;
            default:
                printf("\nPilihan Type Tidak Valid");
        }
    } else if(*pilihanMenu == 2){
        bool isEmpty = checkNodeEmpty();
        if(isEmpty)
            return;
        switch(*pilihanType){
            case 1:
                deleteAwal();
                break;
            case 2:
                deleteAkhir();
                break;
            case 3:
                deleteTertentu();
                break;
            default:
                printf("\nPilihan Type Tidak Valid");
        }
    } else {
        printf("\nPilihan Menu Tidak Valid");
    }
}

bool checkNodeEmpty()
{
    if(head == NULL){
        printf("\nData Node Masih Kosong\n\n");
        return true;
    }
    return false;
}

void freeNode(){
    free(hapus);
    hapus = NULL;
}

void showSLL()
{
    Dnode *read;
    read = head;
    printf("Isi dari DLL : \n");
    if(head == NULL)
        printf("Data Kosong\n");
    else{
        while(read != NULL){
            printf("%d \n", read->data);
            read = read->next;
        }
    }
    printf("\n");
}

void insertAwal()
{
    if(head != NULL){
        p->next = head;
        head->prev = head;
    }
    head = p;
}

void insertAkhir()
{
    Dnode *tail;
    if(head == NULL){
        head = p;
        return;
    }
    tail = head;
    while(tail->next != NULL)
        tail = tail->next;

    p->prev = tail;
    tail->next = p;
    tail = p;
}

void insertAfter()
{
    Dnode *after;
    int key;
    bool isEmpty = checkNodeEmpty();
    if(isEmpty)
        return;
    printf("Sisipkan after brp : ");
    scanf("%d", &key);
    after = head;
    while(after->data != key){
        if(after->next == NULL){
            printf("Nilai %d tidak ada \n", key);
            exit(0);
        } else {
            after = after->next;
        }
    }
    p->next = after->next;
    p->prev = after;
    after->next->prev = p;
    after->next = p;
}

void insertBefore()
{
    Dnode *bef, *prevBef;
    int key;
    bool isEmpty = checkNodeEmpty();
    if(isEmpty)
        return;
    printf("Sisipkan Before brp : ");
    scanf("%d", &key);
    bef = head;
    while(bef->data != key){
        if(bef->next == NULL){
            printf("Node %d tidak ada \n", key);
            exit(0);
        }
        bef = bef->next;
    }
    p->next = bef;
    p->prev = bef->prev;
    bef->prev->next = p;
    bef->prev = p;
}

void deleteAwal(){
    hapus = head;
    hapus = hapus->next;
    freeNode();
}

void deleteAkhir(){
    hapus = head;
    while(hapus->next != NULL){
        hapus = hapus->next;
    }
    hapus->prev->next = hapus->next;
    freeNode();
}

void deleteTertentu(){
    int key;
    hapus = head;
    printf("Node yang mau dihapus : ");
    scanf("%d", &key);
    while(hapus->data != key){
        if(hapus->next == NULL){
            puts("Node Tidak Ditemukan");
            exit(0);
        }
        hapus = hapus->next;
    }
    hapus->prev->next = hapus->next;
    freeNode();
}
