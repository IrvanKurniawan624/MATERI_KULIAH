#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
#define MAX 20000

void generate(int x[]);
void initTime();
void showMenu(int *pilMenu, int *pilType, int arr[]);
void modeUrut(int *pilType);
void insertionSort(int pilType, int arr[]);
void selectionSort(int pilType, int arr[]);
void bubbleSort(int pilType, int arr[]);
void shellSort(int pilType, int arr[]);
void displayArr(int arr[]);
clock_t start_time, end_time;

int main()
{
    int arr[MAX];
    int pilMenu = 0, pilType;
    srand(time(NULL));
    generate(arr);
    while(pilMenu != 3){
        showMenu(&pilMenu, &pilType, arr);
        end_time = clock();
        double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;
        printf("Durasi = %f\n", time_taken);
        printf("-------------------------------------\n\n");
    }
    return 0;
}

void generate(int x[]){
    int i;
    for(i=0;i<MAX;i++)
        x[i] = rand()/1000;
}

void showMenu(int *pilMenu, int *pilType, int arr[])
{
    printf("Menu Sorting : \n1. Insertion\n2. Selection\n3. Bubble\n4. Shell\n5. Keluar\n");
    printf("Pilihan Anda : ");
    scanf("%d", pilMenu);
    switch(*pilMenu){
        case 1:
            initTime();
            modeUrut(pilType);
            insertionSort(*pilType, arr);
            break;
        case 2:
            initTime();
            modeUrut(pilType);
            selectionSort(*pilType, arr);
            break;
        case 3:
            initTime();
            modeUrut(pilType);
            bubbleSort(*pilType, arr);
            break;
        case 4:
            initTime();
            modeUrut(pilType);
            shellSort(*pilType, arr);
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("Input yang dimasukkan Salah !\n\n");
            showMenu(pilMenu, pilType, arr);
    }
}

void modeUrut(int *pilType)
{
    printf("\nMode Urut : \n1. Ascending\n2. Descending\n");
    printf("Pilihan Anda : ");
    scanf("%d", pilType);
    if(*pilType != 1 && *pilType != 2){
        printf("Input Type yang dimasukkan Salah !\n\n");
        modeUrut(pilType);
    }
}

void insertionSort(int pilType, int arr[])
{
    int i, checker, temp;
    for(i = 1; i < MAX; i++){
        temp = arr[i];
        checker = i - 1;

        if (pilType == 1) {
            while (checker >= 0 && arr[checker] > temp) {
                arr[checker + 1] = arr[checker];
                checker--;
            }
        } else {
            while (checker >= 0 && arr[checker] < temp) {
                arr[checker + 1] = arr[checker];
                checker--;
            }
        }

        arr[checker + 1] = temp;
    }
}


void selectionSort(int pilType, int arr[])
{
    int i, checker, minmax, temp;
    bool logicType;
    for(i = 0; i < MAX - 1; i++){
        minmax = i;
        for(checker = i+1; checker < MAX; checker++){
            if(pilType == 1)
                logicType = arr[checker] < arr[minmax];
            else
                logicType = arr[checker] > arr[minmax];
        }
        if(minmax != i){
            temp = arr[i];
            arr[i] = arr[minmax];
            arr[minmax] = temp;
        }
    }
}

void bubbleSort(int pilType, int arr[])
{
    int i, checker, temp;
    bool logicType;
    for(i = 0; i <= MAX - 1; i++){
        for(checker = 0; checker <= MAX - i - 1; checker++){
            if(pilType == 1){
                logicType = arr[checker] > arr[checker + 1];
            } else {
                logicType = arr[checker] < arr[checker + 1];
            }
            if(logicType){
                temp = arr[checker];
                arr[checker] = arr[checker + 1];
                arr[checker + 1] = temp;
            }
        }
    }
}

void shellSort(int pilType, int arr[])
{
    int i, j, k, checker, temp;
    for(k=MAX/2; k >= 1; k /= 2){
        for(i = k; i < MAX; i++){
            temp = arr[i];
            checker = i;
            if(pilType == 1){
                while(checker >= k && arr[checker - k] > temp){
                    arr[checker] = arr[checker - k];
                    checker -= k;
                }
            } else {
                while(checker >= k && arr[checker - k] < temp){
                    arr[checker] = arr[checker - k];
                    checker -= k;
                }
            }
            arr[checker] = temp;
        }
    }
}

void displayArr(int arr[]){
    int i;
    for(i=0; i<MAX; i++){
        printf("%d, ", arr[i]);
    }
    printf("\n\n");
}

void initTime(){
    start_time = clock();
}
