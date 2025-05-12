#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

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
char peek(stack *s);
void infixToPostfix(char *infix, char *postfix);
int precedence(char op);

int main()
{
    char infix[MAX], postfix[MAX];
    char jawab;

    printf("MENGUBAH NOTASI INFIX MENJADI POSTFIX\nDENGAN MEMANFAATKAN STRUKTUR STACK\n");

    do {
        printf("\nMasukkan ekspresi dalam notasi infix : ");
        fgets(infix, sizeof(infix), stdin);
        infix[strcspn(infix, "\n")] = 0;

        infixToPostfix(infix, postfix);
        printf("Postfix : %s\n", postfix);
        fflush(stdin);
        printf("Mau mencoba Lagi (y/t) : ");
        scanf(" %c", &jawab);
        getchar();
    } while (jawab != 't');

    return 0;
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

void push(char x, stack *s)
{
    if (isFull(s)) {
        printf("Stack Sudah Penuh !\n");
        return;
    }
    s->data[s->count] = x;
    s->count++;
}

char pop(stack *s)
{
    if (isEmpty(s)) {
        printf("Stack Masih Kosong !\n");
        return '\0';
    }
    s->count--;
    return s->data[s->count];
}

char peek(stack *s)
{
    if (isEmpty(s)) {
        return '\0';
    }
    return s->data[s->count - 1];
}

int precedence(char op)
{
    switch(op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

void infixToPostfix(char *infix, char *postfix)
{
    stack s;
    initStack(&s);
    int i, j = 0;

    for (i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];
        if (isspace(c)) continue;

        if (isdigit(c)) {
            while (isdigit(infix[i]) || infix[i] == '.') {
                postfix[j++] = infix[i];
                i++;
            }
            postfix[j++] = ' ';
            i--;
        }
        else if (c == '(') {
            push(c, &s);
        }
        else if (c == ')') {
            while (!isEmpty(&s) && peek(&s) != '(') {
                postfix[j++] = pop(&s);
                postfix[j++] = ' ';
            }
            if (!isEmpty(&s) && peek(&s) == '(') {
                pop(&s);
            }
        }
        else if (strchr("+-*/^", c)) {
            while (!isEmpty(&s) && precedence(peek(&s)) >= precedence(c)) {
                postfix[j++] = pop(&s);
                postfix[j++] = ' ';
            }
            push(c, &s);
        }
    }

    while (!isEmpty(&s)) {
        postfix[j++] = pop(&s);
        postfix[j++] = ' ';
    }

    // Remove trailing space and null-terminate
    if (j > 0 && postfix[j-1] == ' ') j--;
    postfix[j] = '\0';
}

