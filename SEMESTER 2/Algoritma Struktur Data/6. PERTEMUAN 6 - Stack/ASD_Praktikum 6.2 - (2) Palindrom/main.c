#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX 100

typedef struct {
    char data[MAX];
    int count;
} stack;


void initStack(stack *s);
bool isEmpty(stack *s);
bool isFull(stack *s);
void push(char x, stack *s);
char pop(stack *s);

int main() {
    char kalimat[MAX];
    char dibalik[MAX];
    char jawaban;
    int i;
    stack s;

    printf("MENGECEK PALINDROM\n");

    do{
        printf("Masukkan kata yang dicek : ");
        fgets(kalimat, MAX, stdin);
        kalimat[strcspn(kalimat, "\n")] = '\0';

        initStack(&s);

        for (i = 0; kalimat[i]; i++) {
            push(kalimat[i], &s);
        }

        for (i = 0; kalimat[i]; i++) {
            dibalik[i] = pop(&s);
        }
        dibalik[strlen(kalimat)] = '\0';

        if (strcmpi(kalimat, dibalik) == 0) {
            printf("%s adalah PALINDROM.\n", kalimat);
        } else {
            printf("%s adalah BUKAN PALINDROM.\n", kalimat);
        }
        printf("\nMau coba lagi (y/t) : ");
        scanf("%c", &jawaban);
        fflush(stdin);
    } while(jawaban != 't');

}

void initStack(stack *s) {
    s->count = 0;
}

bool isEmpty(stack *s) {
    return s->count == 0;
}

bool isFull(stack *s) {
    return s->count == MAX;
}

void push(char c, stack *s) {
    if (!isFull(s)) {
        s->data[s->count++] = c;
    }
}

char pop(stack *s) {
    if (!isEmpty(s)) {
        return s->data[--s->count];
    }
    return '\0';
}


