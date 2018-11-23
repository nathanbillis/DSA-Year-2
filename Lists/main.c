#include <stdio.h>
#include "list.h"

int main(void){

    struct List* arrayList;
    int* listplace;

    arrayList = listConstructor();

    printf("%d",listAdd(arrayList, 1));
    printf("%d",listAdd(arrayList, 5));
    printf("%d\n",listAdd(arrayList, 67));
        printf("%d",listAdd(arrayList, 5));
    printf("%d\n",listAdd(arrayList, 67));
        printf("%d",listAdd(arrayList, 5));
    printf("%d\n",listAdd(arrayList, 67));
        printf("%d",listAdd(arrayList, 5));
    printf("%d\n",listAdd(arrayList, 67));

    listRead(arrayList, 1, &listplace);


    listDisplay(arrayList);
    printf("\n%d", listplace);

    printf("\nList Search index :%d\n",listSearch(arrayList, 5));
    printf("%d\n",listSearch(arrayList, 500));
    listRemove(arrayList, 1);

    listDisplay(arrayList);


    listDestructior(arrayList);


    return 0;
};
