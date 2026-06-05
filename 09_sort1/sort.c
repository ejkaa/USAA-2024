#include <stdio.h>
#include "sort.h"

void PrintArray(int array[],int n, int offset) {
    int j;
    for( j=1; j<=n; j+=offset)printf("%2d ",array[j]);
    printf("\n");
}

void bubbleSort(int array[], int length, int direction) { // ignore index 0
    for (int i = 1; i < length; ++i) {
        for (int j = length; j > i; --j) {
            if ((array[j-1] > array[j] && direction == ASC) ||
                (array[j-1] < array[j] && direction == DSC)) {
                int temp = array[j];
                array[j] = array[j-1];
                array[j-1] = temp;
            }
        }
        PrintArray(array, length, 1);
    }
    if (length > 0) PrintArray(array, length, 1);
}

void insertSort(int *array, int length, int direction) {
    for (int i = 1; i < length +1; ++i) {
        int value = array[i];
        int j = i-1; //??
        while (j > 0 &&
               ((direction == ASC && array[j] > value) ||
                (direction == DSC && array[j] < value))) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j+1] = value;
        PrintArray(array, length, 1);
    }
}

void selectionSort(int array[], int length, int direction) {
    if (length > 0) PrintArray(array, length, 1);
    for (int i = 1; i < length; ++i) {
        int index = i;
//        for (int j = i+1; j <= length; ++j) {
        for (int j = length; j > i; --j) {
            if ((array[j] < array[index] && direction == ASC) ||
                (array[j] > array[index] && direction == DSC))
                index = j;
        }
        int temp = array[i];
        array[i] = array[index];
        array[index] = temp;
        PrintArray(array, length, 1);
    }
}