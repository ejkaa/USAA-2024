#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"

unsigned int Hash(char *key,int htsize){
    int i;
    unsigned int value=0;
    for(i=0;i<strlen(key);i++)
        value =  (value<<5)+key[i];
    return value%htsize;
}

PHASHTABLE HTinit(int size){
    int i;
    PHASHTABLE ht=malloc(sizeof(HASHTABLE));
    ht->size=size;
    ht->table=malloc(size*sizeof(PNODE));
    for(i=0;i<size;i++)
        ht->table[i]=NULL;
    return ht;
}

void HTinsert(PHASHTABLE t, char* key){
     unsigned int h;
     PNODE ptr,tmp;
     h=Hash(key,t->size);
     if(t->table[h]==NULL){
         tmp=malloc(sizeof(NODE));
         tmp->key=key;
         tmp->next=NULL;
         t->table[h]=tmp;
     } else {
         ptr=t->table[h];
         while(ptr->next!=NULL){
             //no duplicate values
             if(strcmp(key,ptr->key)==0)return;
             ptr=ptr->next;
           }
         //no duplicate values
         if(strcmp(key,ptr->key)==0)return;
         tmp=malloc(sizeof(NODE));
         tmp->key=key;
         tmp->next=NULL;
         ptr->next=tmp;
     }
}

int  HTmember(PHASHTABLE t, char* key){
     unsigned int h;
     PNODE ptr;
     h=Hash(key,t->size);
     if(t->table[h]==NULL)return 0;
     ptr=t->table[h];
     while(ptr!=NULL){
         if(strcmp(key,ptr->key)==0)return 1;
         ptr=ptr->next;
         }
     return 0;
}

void HTdelete(PHASHTABLE T, char *key) {
    if (T == NULL || T->table == NULL || key == NULL) return;
    unsigned int H = Hash(key, T->size);
    PNODE node = T->table[H];
    PNODE previous = NULL;

    while (node != NULL) {

        if (strcmp(key, node->key) == 0) {
            if (previous == NULL)
                T->table[H] = node->next;
            else
                previous->next = node->next;

            free(node);
            return;
        }
        previous = node;
        node = node->next;
    }
}

void HTprint(PHASHTABLE T) {
    if (T == NULL || T->table == NULL) return;

    printf("\n");
    for (int i = 0; i < T->size; i++) {
        printf("%d:", i);

        PNODE node = T->table[i];
        if (node != NULL) {
            while (node != NULL) {
                printf(" %s", node->key);
                node = node->next;
            }
        }
        if (i < T->size-1) printf("\n");
    }
}