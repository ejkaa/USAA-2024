#include <stdio.h>
#include "traverse.h"
#include "lstack.h"

static int *value;
static int *left;
static int *middle;
static int *right;

void SetBT(int* V,int* L,int* R){
    value=V;
    left=L;
    right=R;
}

void SetTT(int* V, int* L, int* M, int* R) {
    value = V;
    left = L;
    middle = M;
    right = R;
}

void inorder(int root){
    if(left[root]!=0)inorder(left[root]);
    printf("%d ",value[root]);
    if(right[root]!=0)inorder(right[root]);
}

void preorder(int root){
    printf("%d ",value[root]);
    if(left[root]!=0)preorder(left[root]);
    if(right[root]!=0)preorder(right[root]);
}

void postorder(int root){
    if(left[root]!=0)postorder(left[root]);
    if(right[root]!=0)postorder(right[root]);
    printf("%d ",value[root]);
}

void levelorder(int root) {
    if (!root) return;

    int start = 0, end = 1;
    int Q[100]; Q[0] = root;
    int current;

    while (start < end) {
        current = Q[start];
        start++;
        int L = left[current];
        int R = right[current];

        if (L != 0) {
            Q[end] = L;
            end++;
        }
        if (R != 0) {
            Q[end] = R;
            end++;
        }
        printf("%d ", value[current]);
    }
}

void inorderNR(int v){
    LStack S;
    S = CreateStack();
    LT:  while(left[v]!=0){
    Push(v,S);
    v=left[v];
}
    NODE:printf("%d ",value[v]);
    if(right[v]!=0){
        v=right[v];
        goto LT;
    }
    if(!IsEmptyStack(S)){
        v=Top(S);
        Pop(S);
        goto NODE;
    }
    RemoveStack( &S );
}

void preorderNR(int v){
    LStack stack = CreateStack();
    Push(v, stack);
    int current, L, R;

    while (!IsEmptyStack(stack)) {
        current = Top(stack), Pop(stack);
        R = right[current];
        L = left[current];

        if (R != 0) Push(R, stack);
        if (L != 0) Push(L, stack);

        printf("%d ", value[current]);
    }

    RemoveStack(&stack);
}

void preorderTT(int root){
    if (!root) return;
    printf("%d ", value[root]);

    int L = left[root];
    int M = middle[root];
    int R = right[root];

    if (L != 0) preorderTT(L);
    if (M != 0) preorderTT(M);
    if (R != 0) preorderTT(R);
}

void postorderTT(int root){
    if (!root) return;

    int L = left[root];
    int M = middle[root];
    int R = right[root];

    if (L != 0) postorderTT(L);
    if (M != 0) postorderTT(M);
    if (R != 0) postorderTT(R);

    printf("%d ", value[root]);
}