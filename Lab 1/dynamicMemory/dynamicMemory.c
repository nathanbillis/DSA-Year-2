#include <stdio.h>
#include <stdlib.h>

int arraysize();
void fill_array(int* array, int length);
void print_array(int* array, int length);

int main(void){
    int *array;
    int size = arraysize();
    array = (int *)malloc(sizeof(int)*size);
    if (array == NULL){
    printf("ERROR");
    return -1;
    }

    fill_array(&array, size);
    print_array(&array, size);

    free(array);
    return 0;
}

int arraysize(){
    int array_size;
    printf("what size array?\n");
    scanf("%d", &array_size);
    return array_size;
}

void fill_array(int* array, int length){
    int i;
    for( i = 0; i < length; i ++){
        scanf("%d", &array[i]);
    }
}

void print_array(int* array, int length){
    int i;
    for( i = 0; i < length; i ++){
        printf("%d\n", array[i]);
    }
}

