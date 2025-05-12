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

void showMenu(int* pilihanMenu, int* pilihanType);
void checkJwb(int* pilihanMenu, int* pilihanType);
void alokasi();
bool require_linked_list_data();
void getInput();

/// Insert Init
void insertAwal();
void insertAkhir();
void insertAfter();
void insertBefore();

/// Delete Init
void deleteAwal();
void deleteAkhir();
void deleteTertentu();

int main()
{
    int pilihanMenu, pilihanType;
    do{
        showMenu(&pilihanMenu, &pilihanType);
        alokasi();
        checkJwb(&pilihanMenu, &pilihanType);
        fflush(stdin);

    }while(pilihanMenu != 3);
    return 0;
}

void showMenu(int* pilihanMenu, int* pilihanType)
{
    showSLL();
    printf("Pilih Menu\n1. Insert\n2. Delete\n3. Keluar\n");
    printf("Masukkan Pilhan Menu : ");
    scanf("%d", pilihanMenu);

    if(*pilihanMenu== 1){
        printf("\nMenu Insert \n1. Awal\n2. Akhir\n3. After\n4. Before\n5. Keluar\n");
        printf("Masukkan Pilihan Type : ");
        scanf("%d", pilihanType);
    } else if(*pilihanMenu == 2){
        printf("\nMenu Delete \n1. Awal\n2. Akhir\n3. Node Tertentu\n");
        printf("Masukkan Pilihan Type : ");
        scanf("%d", pilihanType);
    }else {
        exit(0);
    }
}

void alokasi()
{
    p = (Node *)malloc(sizeof(Node));
    if(p==NULL){
        puts("Alokasi Gagal !");
        exit(0);
    }
}

bool require_linked_list_data()
{
    if(head == NULL){
        puts("Linked List masih Kosong");
        return false;
    }
    return true;
}

void checkJwb(int* pilihanMenu, int* pilihanType)
{
    if(*pilihanMenu == 1){
        switch(*pilihanType){
            case 1:
                insertAwal();
                getInput();
                break;
            case 2:
                insertAkhir();
                getInput();
                break;
            case 3:
                if (!require_linked_list_data()) return;
                insertAfter();
                getInput();
                break;
            case 4:
                if (!require_linked_list_data()) return;
                insertBefore();
                getInput();
                break;
            case 5:
                break;
            default:
                printf("Pilihan Type tidak terdaftar !");
        }
    } else if(*pilihanMenu == 2){
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
                printf("Pilihan Type tidak terdaftar !");
        }
    } else {
        printf("Pilihan Menu tidak terdaftar");
    }
    printf("\n");
}

void getInput()
{
    printf("%-6s : ", "No");
    scanf("%d", &p->data.no);
    getchar();

    printf("%-6s : ", "Nama");
    fgets(p->data.nama, sizeof(p->data.nama), stdin);
    p->data.nama[strlen(p->data.nama) -1] = '\0';
    fflush(stdin);

    printf("%-6s : ", "Nilai");
    scanf("%f", &p->data.nilai);
}

void showSLL(){
    Node *read;
    printf("\nData yang telah diinputkan : \n");
    printf("%-8s %-8s %-8s\n", "No", "Nama", "Nilai");
    read = head;
    if(head == NULL){
        printf("Data Konsong\n");
    }else {
        while (read != NULL) {
            printf("%-8d %-8s %-8.2f\n", read->data.no, read->data.nama, read->data.nilai);
            read = read->next;
        }
    }
}

void insertAwal()
{
    p->next = head;
    head = p;
}

void insertAkhir()
{
    Node *tail;
    p->next = NULL;
    if(head==NULL){
        head = p;
    }else{
        tail = head;
        while(tail->next != NULL)
            tail = tail->next;

        tail->next = p;
        tail = tail->next;
    }
}

void insertAfter()
{
    Node *after;
    int key;
    printf("Dimasukkan setelah node berapa ? ");
    scanf("%d", &key);
    after = head;
    while (after != NULL && after->data.no != key) {
        after = after->next;
    }
    if (after == NULL) {
        printf("Node dengan nilai %d tidak ditemukan dalam Linked List.\n", key);
        return;
    }
    p->next = after->next;
    after->next = p;
}

void insertBefore()
{
    Node *bef, *pbef;
    int key;
    printf("Dimasukkan sebelum node berapa ? ");
    scanf("%d", &key);
    if(head->data.no == key){
        insertAwal();
        return;
    }
    bef = head;
    do{
        pbef = bef;
        if(bef->next == NULL){
            printf("Node dengan nilai %d tidak ditemukan dalam Linked List.\n", key);
            return;
        }
        bef = bef->next;
    }while(bef->data.no != key);
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

void deleteTertentu(){
    Node *ph;           
    int selectedNode;
    printf("\nData yang mau dihapus ? : ");
    scanf("%d", &selectedNode);
    hapus = head;
    if(hapus->data.no == selectedNode)
        deleteAwal();
    else{
        while(hapus->data.no != selectedNode){
            if(hapus->next == NULL){
                printf("Key Tidak Ditemukan !");
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
