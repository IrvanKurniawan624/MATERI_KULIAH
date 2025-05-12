#include <stdio.h>
#include <stdlib.h>
#define MAX 10

void displayArr(int arr[]);

int main()
{
    int arr[MAX] = {7, 2, 5, 9, 8, 1, 3, 4, 6, 10};
    int c = 0, s = 0, m = 0;
    int i, k, checker, temp;
    printf("SHELL SORT\n\n");
    printf("ARRAY SEBELUM SORT: \n");
    displayArr(arr);
    for (k = MAX / 2; k >= 1; k /= 2) {
        m++;
        for (i = k; i < MAX; i++) {
            temp = arr[i];
            int j = i;
            c++;
            if(j >= k && (arr[j - k] > temp)) {
                arr[j] = arr[j - k];
                j -= k;
                s++;
            }
            arr[j] = temp;
        }
    }

    printf("HASIL ARRAY SESUDAH SORT : \n");
    displayArr(arr);
    printf("S = %d, C = %d, M = %d", s, c, m);
}

void displayArr(int arr[]){
    int i;
    for(i=0; i<MAX; i++){
        printf("%d, ", arr[i]);
    }
    printf("\n\n");
}
