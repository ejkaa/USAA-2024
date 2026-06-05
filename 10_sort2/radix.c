#include <stdio.h>
#include "lqueue.h"

void RadixSort(char* array[], int n, int k){
    char* B[10][n];
    int counterB[10];

    for (int i = 0; i < 10; ++i) {
        counterB[i] = 0; // number of elements

        for(int j = 0; j < n; ++j) // init
            B[i][j] = NULL;
    }

    // 2d array
    for (int j = k - 1; j >= 0; --j) { // cislice z konca
        for (int i = 0; i < n; ++i) { // cisla od zaciatku
            int num = array[i][j] - '0';
            B[num][counterB[num]] = array[i];
            counterB[num]++;
        }

        printf(" --- j = %d ---", j);
        for (int x = 0, count = 0; x < 10 ; ++x) {
            printf("\nB[%d]:", x);
            for (int y = 0; y < counterB[x]; ++y, ++count) {
                array[count] = B[x][y];
                printf(" %s", array[count]);
            }
            counterB[x] = 0;
        }


        printf("\nQ:");
        for (int i = 0; i < n; ++i) {
            printf(" %s", array[i]);
        }
        printf("\n");
    }
}

void RadixSortQueue(char* array[], int n, int k){
    LQueue Q, B[10];
    Q=CreateQueue();
    for (int i = 0; i < n; ++i) Enqueue(array[i], Q);
    for (int i = 0; i < 10; ++i) B[i] = CreateQueue();
    TElem temp;

    for (int j = k - 1; j >= 0; --j) {
        for (int i = 0; i < n; ++i) {
            char* elem = FrontAndDequeue(Q);
            int num = elem[j] - '0';
            Enqueue(elem, B[num]);
        }

//        printf(" --- j = %d ---", j);
        for (int x = 0; x < 10 ; ++x) {
            while (!IsEmptyQueue(B[x])) {
                temp = FrontAndDequeue(B[x]);
                Enqueue(temp, Q);
            }
        }

        PrintQueue(Q);
        printf("\n");
    }

    int i = 0;
    while(!IsEmptyQueue(Q)) array[i++] = FrontAndDequeue(Q);

    for(int i = 0; i < 10; ++i) RemoveQueue(&B[i]);
    RemoveQueue(&Q);
}

