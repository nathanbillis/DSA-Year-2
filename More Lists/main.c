#include <stdio.h>
#include "list.h"
#include "time.h"


int main(void){
    #define DYNAMIC_RESIZE 1


    double timeStart;
    double timeEnd;
    double elapsedTimeSeconds;

    struct List* linkedList;
    linkedList = listConstructor();


    for (int i = 0; i < 5000; i++){
    listAdd(linkedList,rand() % 99);}
    timeStart = (double)clock();
    listQuickSort(linkedList);
    timeEnd = (double)clock();

    elapsedTimeSeconds = timeEnd - timeStart;
    printf("%f seconds", elapsedTimeSeconds/ CLOCKS_PER_SEC);

 //  listQuickSort(linkedList);



    listDestructior(linkedList);


    return 0;
};

