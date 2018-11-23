#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct ListNode{
    int data;

    struct ListNode* next;
    struct ListNode* prev;
};


struct ListNode* listNodeConstructor(int value){
    struct ListNode* newNode;

    newNode = malloc(sizeof(struct ListNode));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
};

void listNodeDeconstructor(struct ListNode* node){
    free(node);
};

struct List{
    int size;

    struct ListNode* head;
    struct ListNode* tail;

};

struct List* listConstructor(){
    struct List* newLinkedList;

    newLinkedList = malloc(sizeof(struct List));

    newLinkedList->size = 0;
    newLinkedList->head = NULL;
    newLinkedList->tail = NULL;

    return newLinkedList;
};

void listDestructior(struct List* linkedList){
    struct ListNode* currentRecord;
    struct ListNode* nextRecord = linkedList->head;

    while(nextRecord != NULL){
        currentRecord = nextRecord;
        nextRecord = currentRecord->next;

        listNodeDeconstructor(currentRecord);
    }

    free(linkedList);

};


int listSize(struct List* linkedList){
    return linkedList->size;
};

int listIsEmpty(struct List* linkedList){
    if (linkedList ->size == 0){
        return 1;
    }
        return 0;
};


int listAdd(struct List* linkedList, int entity){
    // generate new node
   struct ListNode* newNode = listNodeConstructor(entity);

   //set prev to the tail of the list
   newNode->prev = linkedList->tail;
   newNode->next = NULL; // adds to end of the list

   if(linkedList -> tail != NULL){
   // if the list isn't empty add new node
    linkedList->tail->next = newNode;
   }

   linkedList->tail = newNode;

   if (linkedList->head  == NULL){
    linkedList->head = newNode;
   }

    linkedList->size++;

    return 1;
};


void listDisplay(struct List* linkedList){
    struct ListNode* currentRecord;
    struct ListNode* nextRecord = linkedList->head;

    while(nextRecord != NULL){
        currentRecord = nextRecord;
        nextRecord = currentRecord->next;

        printf("%d\n",currentRecord->data);
    }

};

int listRead(struct List* linkedList, int index, int* entity){
        struct ListNode* answer = ListGetNode(linkedList, index);
        if (answer != NULL){
        *entity = answer->data;
        return 1;}
        *entity = NULL;
        return 0;}
;

struct ListNode* ListGetNode(struct List* linkedList, int index){
    struct ListNode* currentRecord;
    struct ListNode* nextRecord = linkedList->head;
   if (index < listSize(linkedList) || index < 0){
        for(int i = 0; i <= index; i++){
            currentRecord = nextRecord;
            nextRecord = currentRecord->next;}
            return  currentRecord;}
            return NULL;
};


void listRemove(struct List* linkedList, int index){
    struct ListNode* node = ListGetNode(linkedList, index);
    if (node != NULL){
        if (node->prev != NULL){
            node->prev->next = node->next;
        }
        if(node->next != NULL){
            node->next->prev = node->prev;
        }
        // deal if at head or tail
        if(node == linkedList -> head){
            linkedList->head = node->next;
        }
        if(node == linkedList -> tail){
            linkedList->tail = node->prev;
        }
        listNodeDeconstructor(node);
        linkedList->size--;
    }


};

int listSearch(struct List* linkedList, int entity){
    int* searched_ent;
    for(int i = 0; i< linkedList->size; i++){
        listRead(linkedList, i, &searched_ent);
        if(entity == searched_ent){
            return i;
        }
    }
    return -1;
};
