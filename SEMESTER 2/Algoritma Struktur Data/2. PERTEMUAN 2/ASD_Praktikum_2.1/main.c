#include <stdio.h>
#include <stdlib.h>

typedef struct simpul Node;
struct simpul {
    int data;
    Node *next;
};
Node *head = NULL, *p;

void showMenu();
void checkJwb(int* jwb);
void alokasi();

/// Insert Init
void insertAwal();
void insertAkhir();
void insertAfter();
void insertBefore();

int main()
{
    int jwb;
    do{
        showMenu();
        scanf("%d", &jwb);
        alokasi();
        checkJwb(&jwb);
        fflush(stdin);

    }while(jwb != 5);
    return 0;
}

void showMenu()
{
    Node *read;
    printf("\nData yang ada dalam SSL : \n");
    read = head;
    while(read!=NULL){
        printf("%d\n", read->data);
        read = read->next;
    }
    printf("\nMenu Insert \n1. Awal\n2. Akhir\n3. After\n4. Before\n5. Keluar\n");
    printf("Masukkan Pilihan Anda : ");
}

void alokasi()
{
    p = (Node *)malloc(sizeof(Node));
    if(p==NULL){
        puts("Alokasi Gagal !");
        exit(0);
    }
}

void checkJwb(int* jwb)
{
    switch(*jwb){
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
        case 5:
            break;
        default:
            printf("Pilihan tidak terdaftar !");
    }
}

void insertAwal()
{
    int temp;
    printf("Nilai yang akan disimpan : ");
    scanf("%d", &temp);
    p->data = temp;
    p->next = head;
    head = p;
}

void insertAkhir()
{
    int temp;
    printf("Nilai yang akan disimpan : ");
    scanf("%d", &temp);
    Node *tail;
    p->data = temp;
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
    int temp;
    if(head == NULL){
        puts("Linked List masih Kosong");
        return;
    }
    printf("Nilai yang akan disimpan : ");
    scanf("%d", &temp);
    printf("Dimasukkan setelah node berapa ? ");
    scanf("%d", &key);
    after = head;
    while (after != NULL && after->data != key) {
        after = after->next;
    }
    if (after == NULL) {
        printf("Node dengan nilai %d tidak ditemukan dalam Linked List.\n", key);
        return;
    }
    p->data = temp;
    p->next = after->next;
    after->next = p;
}

void insertBefore()
{
    Node *bef, *pbef;
    int key;
    int temp;
    if(head == NULL){
        puts("Linked List masih Kosong");
        return;
    }
    printf("Nilai yang akan disimpan : ");
    scanf("%d", &temp);
    printf("Dimasukkan sebelum node berapa ? ");
    scanf("%d", &key);

    p->data = temp;
    if(head->data == key){
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
    }while(bef->data != key);
    p->next = bef;
    pbef->next = p;
}
