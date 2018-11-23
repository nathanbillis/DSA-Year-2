#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"


struct List {
    int capacity;
    int numEntities;
    int* entities;
    int isSorted;

};


#define ARRAY_LIST_CAPACITY 5000
// Must match the DYNAMIC_RESIZE #define in main.c
#define DYNAMIC_RESIZE 1



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
    // If our list is already full then we cannot add a new item
    if(list->numEntities >= list->capacity)
    {
        if(DYNAMIC_RESIZE == 0)
        {
            // In this case we should simply tell the user this by returning 0
            // Once a return statement is reached in a function no other code is
            // executed so we do not need to worry about anything below here.
            return 0;
        }
        else
        {
            // Call our list resize function so that we now have room for more elements
            // Once this has been done, since we have not executed a return statement,
            // we will continue to the code below which adds a new element
            listResize(list, list->capacity * 2);
            list->capacity = list->capacity*2;
        }
    }

    // Set the slot of the next free entity to the value we are given
    // If we current have 0 elements stored then we save in slot 0 and so on
    list->entities[list->numEntities] = entity;

    // Update our entity count
    list->numEntities++;

    list->isSorted = 0;

    // And return 1 to indicate success
    return 1;}


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



void listBubbleSort(struct List* list){

    while (list->isSorted == 0){
        list->isSorted = 1;
        int size = list->numEntities;
        for(int i = 0 ; i < size; i ++){
            if (list->entities[i-1] > list->entities[i]){
                list->isSorted = 0;
                swap_pos(&list->entities[i-1], &list->entities[i]);
            }
        }
    }
};

int listAddOrdered(struct List* list, int entity){
    listAdd(list, entity);
    listBubbleSort(list);
    return 1;
};


int listAddindex(struct List* list, int entity, int index){
    // Check that the index is valid before we try to add the element
    if(index < 0 || index > list->numEntities)
    {
        // Invalid index, indicate failure
        return 0;
    }

    // Now try to add to the end of the list
    // This reuses our existing size handling/dynamic resizing
    int addSuccess = listAdd(list, entity);

    // Fail if we can not add a new item to the end
    if(addSuccess == 0)
    {
        return 0;
    }

    // We can now move the items from index [index, numEntities) along by 1
    memmove(&list->entities[index+1], &list->entities[index], sizeof(int) * (list->numEntities-index));

    // And add our new item to the desired index
    list->entities[index] = entity;

    list->isSorted = 0;

    // And indicate success
    return 1;
};




void listInsertionSort(struct List* list)
{
    if(listIsSorted(list) == 1)
    {
        return;
    }

    // Until we are confident that the full list is sorted
    for(int unsortedStartIndex = 1; unsortedStartIndex < list->numEntities; unsortedStartIndex++)
    {
        // Get the value to insert into the correct place
        int valueToSort = list->entities[unsortedStartIndex];

        // Find its appropriate location
        int sortedIdx;
        for(sortedIdx = 0; sortedIdx < unsortedStartIndex; sortedIdx++)
        {
            // Check if the item we are checking is greater than the item to sort
            // If so then we want to add our item before it
            if(valueToSort < list->entities[sortedIdx])
            {
                // Shuffle later items along
                memmove(&list->entities[sortedIdx+1], &list->entities[sortedIdx], (unsortedStartIndex - sortedIdx) * sizeof(int));

                // And set the new value for the required index
                list->entities[sortedIdx] = valueToSort;

                // Now we do not want to check any further values for this iteration so break from the inner for loop
                break;
            }
        }

        // If we did not find the correct place to insert the item in the loop above then it
        // must be the largest item in the sorted section and we do not need to do anything
    }

    list->isSorted = 1;
}

int listIsSorted(struct List* list)
{
    return list->isSorted;
}


int listBinarySearch(struct List* list, int target){
    int low = 0;
    int high = list->numEntities -1;

    if (list->isSorted == 0){
        listBubbleSort(list);
    };

    while (low < high ){
        int mid = (low+high)/2; // casts down ie 3.5 -> 3
        if (list->entities[mid] == target){
            return mid;
        }
        else if (list-> entities[mid] < target ){
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return -1;
};


void listQuickSort(struct List* list){
    int low = 0;
    int high = list->numEntities -1;

    implementQuickSort(list->entities, low, high);
    list->isSorted = 1;
};

void implementQuickSort(int* list_entities, int low, int high){

    if(high>low){
        int pivotPoint = partitionList(list_entities, low, high);
        implementQuickSort(list_entities, low, pivotPoint - 1);
        implementQuickSort(list_entities, pivotPoint + 1, high);
    }
};

int partitionList(int* values, int low, int high){
    int pivotPoint = low;
    int pivot = values[low];

    for (int i = low + 1; i <= high ; i ++){
        if (values[i] <= pivot){
            pivotPoint ++;
            swap_pos(&values[i], &values[pivotPoint]);
        }
    }
    swap_pos(&values[low],&values[pivotPoint]);

    return pivotPoint;
};
