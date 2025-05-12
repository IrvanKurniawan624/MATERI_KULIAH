#include <stdio.h>
#include <stdlib.h>

void showArray(int *arr, int sizeArray);
void insertionSort(int arr[], int *checker_count, int *switch_count, int *insert_count, int arraySize);

int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
//{3, 10, 4, 6, 8, 9, 7, 2, 1, 5};
//{1, 2, 3, 4, 5, 9, 7, 6, 8, 10};
//{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//{10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

int main()
{
    int checker_count = 0, switch_count = 0, insert_count = 0;
    printf("ARRAY SEBELUM DIURUTKAN : ");
    showArray(arr, (sizeof(arr) / sizeof(arr[0])));

    insertionSort(arr, &checker_count, &switch_count, &insert_count, (sizeof(arr) / sizeof(arr[0])));

    printf("\nARRAY SETELAH DIURUTKAN : ");
    showArray(arr, (sizeof(arr) / sizeof(arr[0])));

    printf("\n\nJUMLAH PERBANDINGAN : %d\nJUMLAH PERGESERAN : %d\nJUMLAH PENYISIPAN : %d\n",
           checker_count, switch_count, insert_count);
}

void showArray(int *arr, int sizeArray){
    int i;
    for(i = 0; i < sizeArray; i++){
        printf(" %d |", arr[i]);
    }
}

void insertionSort(int arr[], int *checker_count, int *switch_count, int *insert_count, int arraySize){
    int checker, key, idx_now;
    for(idx_now = 1; idx_now < arraySize; idx_now++){
        key = arr[idx_now];
        checker = idx_now - 1;

        while(checker >= 0){
            (*checker_count)++;
            if(arr[checker] > key){
                arr[checker + 1] = arr[checker];
                (*switch_count)++;
                checker--;
            } else {
                break;
            }
        }

        arr[checker + 1] = key;
        (*insert_count)++;
    }
}
