#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct List {
    int capacity;
    int numEntities;
    int* entities;
};


#define ARRAY_LIST_CAPACITY 4


struct List* listConstructor(){
/* Dynamically Allocates Memory for the Array List*/
    struct List* arrayList;

    arrayList = malloc(sizeof(struct List));
    arrayList ->entities = malloc(ARRAY_LIST_CAPACITY * sizeof(int));

    arrayList ->capacity = ARRAY_LIST_CAPACITY;
    arrayList->numEntities = 0;

    return arrayList;
};


void listDestructior(struct List* list){

/*Frees the List from Memory*/
    free(list ->entities);
    free(list);
};

void listResize(struct List* list, int newSize){
    if (list->numEntities <= newSize){
        return;
    }
    list->entities = realloc(list->entities, newSize * sizeof(int));

    list->numEntities = newSize;


};

int listAdd(struct List* list, int entity ){
  //  if (list->numEntities < list->capacity){
    list->entities[list->numEntities] = entity;
    list->numEntities++;
    return 1;//}
//    else{
 //   listResize(list, list->numEntities*2);
//    listAdd(list, entity);
//    }
    return 0;
};

void listDisplay(struct List* list){
    printf("Capacity = %d\n", list->capacity);
    printf("Number of Entities = %d\n", list->numEntities);

    for (int i = 0 ; i < list->numEntities; i++ ){
    printf("Entity[%d] = %d\n", i,list->entities[i]);};
};

int listRead(struct List* list, int index, int* entity){
    if(index <= list->numEntities){
        *entity = list->entities[index];
    return 1;
    }
    else{ return 0 ;}

};

int listSearch(struct List* list, int entity){
    for (int i =0 ;i <= list->numEntities; i++){
            if (entity == list->entities[i]){
                return i;}
                else{continue;}}
    return -1;

};


void listRemove(struct List* list, int index){
    int element_rem = list->numEntities - index;

    if(index < 0 || index >= list->numEntities)
    {
        return;
    }
    memmove(&list->entities[index], &list->entities[index + 1], element_rem *sizeof(int));
    list->numEntities--;
};

int listSize(struct List* list){
    return list->numEntities;

};

int listIsEmpty(struct List* list){
    if (list->numEntities == 0){
        return 1;
    }
    return 0;
};

