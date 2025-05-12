#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100
typedef int itemType;

typedef struct {
    itemType data[MAX];
    int count;
} stack;

void initStack(stack *s);
bool isEmpty(stack *s);
bool isFull(stack *s);
void push(itemType x, stack *s);
itemType pop(stack *s);

void konversiBiner(int bil);
void konversiOktal(int bil);
void konversiHeksadesimal(int bil);
char heksaDigit(int digit);
void showCheckMenu(int bil);

int main()
{
    int bil;
    char jawab;

    printf("KONVERSI BILANGAN DESIMAL\n");

    do {
        printf("\nMasukkan bilangan desimal yg akan dikonversi : ");
        scanf("%d", &bil);

        showCheckMenu(bil);

        printf("\nIngin mengkonversi bilangan lain? (y/t) : ");
        scanf(" %c", &jawab);
    } while (jawab != 't' && jawab != 'T');

    return 0;
}

void showCheckMenu(int bil)
{
    int pilihan;
    do {
        printf("\nMenu KONVERSI :\n");
        printf("1. BINER\n2. OKTAL\n3. HEKSADESIMAL\n4. KELUAR\n");
        printf("Masukkan Pilihan Anda : ");
        scanf("%d", &pilihan);

        switch(pilihan) {
            case 1:
                konversiBiner(bil);
                break;
            case 2:
                konversiOktal(bil);
                break;
            case 3:
                konversiHeksadesimal(bil);
                break;
            case 4:
                break;
            default:
                printf("Pilihan tidak valid.\n");
        }
    } while (pilihan != 4);
}

void initStack(stack *s)
{
    s->count = 0;
}

bool isEmpty(stack *s)
{
    return (s->count == 0);
}

bool isFull(stack *s)
{
    return (s->count == MAX);
}

void push(itemType x, stack *s)
{
    if (isFull(s)) {
        printf("Stack Sudah Penuh!\n");
        return;
    }
    s->data[s->count] = x;
    s->count++;
}

itemType pop(stack *s)
{
    if (isEmpty(s)) {
        printf("Stack Masih Kosong!\n");
        return -1;
    }
    s->count--;
    return s->data[s->count];
}

void konversiBiner(int bil)
{
    stack s;
    initStack(&s);

    int n = bil;
    while (n > 0) {
        push(n % 2, &s);
        n = n / 2;
    }

    printf("Hasil konversi %d ke BINER = ", bil);
    while (!isEmpty(&s)) {
        printf("%d", pop(&s));
    }
    printf("\n");
}

void konversiOktal(int bil)
{
    stack s;
    initStack(&s);

    int n = bil;
    while (n > 0) {
        push(n % 8, &s);
        n = n / 8;
    }

    printf("Hasil konversi %d ke OKTAL = ", bil);
    while (!isEmpty(&s)) {
        printf("%d", pop(&s));
    }
    printf("\n");
}

char heksaDigit(int digit)
{
    switch(digit) {
        case 10: return 'A';
        case 11: return 'B';
        case 12: return 'C';
        case 13: return 'D';
        case 14: return 'E';
        case 15: return 'F';
        default: return '?';
    }
}

void konversiHeksadesimal(int bil)
{
    stack s;
    initStack(&s);

    int n = bil;
    while (n > 0) {
        push(n % 16, &s);
        n = n / 16;
    }

    printf("Hasil konversi %d ke HEKSADESIMAL = ", bil);
    while (!isEmpty(&s)) {
        int digit = pop(&s);
        if (digit < 10)
            printf("%d", digit);
        else
            printf("%c", heksaDigit(digit));
    }
    printf("\n");
}
