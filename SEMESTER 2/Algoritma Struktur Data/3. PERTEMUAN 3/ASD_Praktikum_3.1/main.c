#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct simpul Node;
struct simpul{
    int data;
    Node *next;
};
Node *head = NULL, *p, *hapus;
is_insert = true;

void alokasi();
void handleMenu(bool is_first);
void showSLL();
void insertAkhir(int temp);
void deleteAwal();
void deleteAkhir();
void deleteTertentu();

int main()
{
    char jwb; int count; bool is_first = true;
    for (count = 0; count < 2; count++){
        do{
            alokasi();
            handleMenu(is_first);
            printf("Lagi (y/t) : ");
            fflush(stdin);
            scanf("%c", &jwb);
            is_first = false;
        } while (jwb == 'y');
        is_insert = !is_insert;
        showSLL();
    }
}

void alokasi(){
    p = (Node *)malloc(sizeof(Node));
    if(p == NULL){
        printf("Alokasi Gagal");
        exit(0);
    }
}

void handleMenu(bool is_first){
    if(is_insert){
        int temp;
        if(is_first)
            printf("Single Linked List - Insert di Akhir\n");
        printf("Data yang mau disimpan : ");
        scanf("%d", &temp);
        insertAkhir(temp);
    } else if(!is_insert){
        printf("\nMenghapus dari Node Tertentu...");
        deleteTertentu();
        showSLL();
        fflush(stdin);
    } else {
        printf("Type Action Undefined");
        exit(0);
    }
}

void showSLL(){
    Node *read;
    read = head;
    printf("\nIsi dari SLL\n");
    if(read == NULL){
        printf("Kosong");
        exit(0);
    }
    while(read!=NULL){
        printf("%d\n", read->data);
        read = read->next;
    }
}

void insertAkhir(temp){
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
    if(hapus->data == selectedNode)
        deleteAwal();
    else{
        while(hapus->data != selectedNode){
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


