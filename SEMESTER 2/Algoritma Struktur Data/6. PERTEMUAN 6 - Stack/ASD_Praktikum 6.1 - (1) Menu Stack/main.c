#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 5
typedef int itemType;
typedef struct {
    itemType data[MAX];
    int count;
} stack;

void showMenu(int *pilihanMenu);
void checkJwb(int *pilihanMenu, stack *s);

/// STACK FUNCTION
void initStack(stack *s);
bool isEmpty(stack *s);
bool isFull(stack *s);

void push(itemType x, stack *s);
itemType pop(stack *s);
void showStack(stack *s);

int main()
{
    stack tumpukan;
    int pilihanMenu;
    initStack(&tumpukan);
    do{
        showMenu(&pilihanMenu);
        checkJwb(&pilihanMenu, &tumpukan);
        fflush(stdin);
    } while (pilihanMenu != 4);
}

void showMenu(int *pilihanMenu)
{
    printf("MENU STACK using ARRAY : \n");
    printf("1. Mengisi Stack (PUSH)\n2. Mengambil isi Stack (POP)\n3. Menampilkan isi Stack -> LIFO\n4. Keluar\n\n");
    printf("Masukkan Pilihan Anda : ");
    scanf("%d", pilihanMenu);
}

void checkJwb(int *pilihanMenu, stack *s)
{
    itemType key;
    switch(*pilihanMenu){
        case 1:
            printf("Masukkan Data Anda : ");
            scanf("%d", &key);
            printf("\n");
            push(key, s);
            break;
        case 2:
            pop(s);
            break;
        case 3:
            showStack(s);
            break;
        case 4:
            break;
        default:
            printf("Pilihan Menu Tidak Valid \n");
    }
}

void initStack(stack *s)
{
    s->count=0;
}

bool isEmpty(stack *s)
{
    return (s->count == 0 ? true : false);
}

bool isFull(stack *s)
{
    return (s->count == MAX ? true : false);
}

void push(itemType x, stack *s)
{
    if(isFull(s)){
        puts("Stack Sudah Penuh !");
        return;
    }
    s->data[s->count] = x;
    s->count++;
}

//itemType pop(stack *s)
//{
//    itemType temp;
//    if(isEmpty(s)){
//        puts("Stack Masih Kosong !");
//        return;
//    }
//    s->count--;
//    temp = s->data[s->count];
//    return temp;
//}

itemType pop(stack *s)
{
    int i, key;
    bool found = false;

    printf("Item yang mau Diambil : ");
    scanf("%d", &key);

    for (i = s->count - 1; i >= 0; i--) {
        if (s->data[i] == key) {
            found = true;
            break;
        }
    }

    if (!found) {
        printf("Elemen %d tidak ditemukan dalam stack!\n", key);
        return;
    }
    s->data[i] = s->data[s->count - 1];
    s->count--;
}

void showStack(stack *s)
{
    int i = s->count - 1;
    printf("Isi dari Stack : \n");
    while(i >= 0){
        printf("%d\n", s->data[i]);
        i--;
    }
}
