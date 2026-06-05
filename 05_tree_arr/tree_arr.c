#include "err.h"
#include "tree_arr.h"
#include <stdio.h>
#include <stdlib.h>

struct TreeRecord{
    int MaxLevel;
    int *Array;
};

Tree CreateTree( int MaxLevel ){
    Tree T;

    T = malloc( sizeof( struct TreeRecord ) );
    if( T == NULL ) Error( "Out of space!!!" );
    T->Array = malloc(pow(2,MaxLevel+1)*sizeof(int));
    if(T->Array == NULL) Error( "Out of space!!!" );
    T->MaxLevel = MaxLevel;
    MakeEmpty( T );

    return T;
}

void MakeEmpty( Tree T ){
    int i;
    if(T == NULL) Error("No tree!");
    for(i = 0; i<pow(2,T->MaxLevel+1);i++)
        T->Array[i] = 0;
}

void Insert( Tree T, int Index, int Elem ){
    if(T == NULL) Error("No tree!");
    if(Index < 1 || Index > pow(2,T->MaxLevel+1)-1)
        Error("Bad index!");
    else T->Array[Index] = Elem;
}

void DisposeTree( Tree T ){
    if( T != NULL ){
        free( T->Array );
        free( T );
    }
}

void PrintTree( Tree T ){
    if(T == NULL) Error("No tree!");
    int i, j, k = 1, l, m = 4*pow(2,T->MaxLevel), n;

    for(i = 1; i<=T->MaxLevel+1; i++) {
        n = pow(2, i - 1);
        for (j = 0; j < pow(2, i - 1); j++) {
            l = (m - 2 * n) / n;
            if (j == 0) PrintSpaces(l - (l / 2)); else PrintSpaces(l);
            printf("%02d", T->Array[k++]);
        }
        putchar('\n');
    }
}

void PrintSpaces(int Count){
    while(Count-- > 0) putchar(' ');
}

void PrintRow(Tree T, int Level) {
    if (!T || !Level || Level > T->MaxLevel+1) exit(EXIT_SUCCESS);
    int begin = pow(2, Level);
    int end = pow(2, Level +1);

    for (int i = begin; i < end; ++i) {
        printf("%02d ", T->Array[i]);
    }
    putchar('\n');
}

void PrintSubtree( Tree T, int Index ){
    if (!T || !Index) exit(EXIT_SUCCESS);
    int last = pow(2, T->MaxLevel +1) -1;
    if (Index < 1 || Index > last) exit(EXIT_SUCCESS);

    printf("%02d ", T->Array[Index]);
    int first_in_row = Index*2;
    int last_in_row = Index*2 +1;

    while (T->Array[first_in_row]){
        for (int i = first_in_row; i <= last_in_row ; ++i) {
            printf("%02d ", T->Array[i]);
        }
        first_in_row = first_in_row*2;
        last_in_row = last_in_row*2 +1;
    }
    putchar('\n');
}