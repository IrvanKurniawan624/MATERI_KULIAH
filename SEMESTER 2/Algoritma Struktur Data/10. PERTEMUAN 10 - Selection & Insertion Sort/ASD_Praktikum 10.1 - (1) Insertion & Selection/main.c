#include <stdio.h>
#include <stdlib.h>

int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
//{3, 10, 4, 6, 8, 9, 7, 2, 1, 5};
//{1, 2, 3, 4, 5, 9, 7, 6, 8, 10};
//{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//{10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

int main()
{
    int checker_count = 0, switch_count = 0;
    printf("ARRAY SEBELUM DIURUTKAN : ");
    showArray(arr, (sizeof(arr) / sizeof(arr[0])));

    selectionSort(arr, &checker_count, &switch_count, (sizeof(arr) / sizeof(arr[0])));

    printf("\nARRAY SETELAH DIURUTKAN : ");
    showArray(arr, (sizeof(arr) / sizeof(arr[0])));
    printf("\n\nJUMLAH PERBANDINGAN : %d\nJUMLAH PERTUKARAN : %d", checker_count, switch_count);
}

void showArray(int *arr, int sizeArray){
    int i;
    for(i = 0; i < sizeArray; i++){
        printf(" %d |", arr[i]);
    }
}

void selectionSort(int arr[], int *checker_count, int *switch_count, int arraySize){
    int checker, temp, idx_now, min;
    for(idx_now = 0; idx_now < arraySize; idx_now++){
        min = idx_now;
        checker = idx_now + 1;
        while(checker < arraySize){
            (*checker_count)++;
            if(arr[checker] < arr[min]){
                min = checker;
            }
            checker++;
        }
        if(arr[idx_now] > arr[min]){
            temp = arr[idx_now];
            arr[idx_now] = arr[min];
            arr[min] = temp;
            (*switch_count)++;
        }
    }
}
