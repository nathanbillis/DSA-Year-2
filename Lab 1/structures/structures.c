#include <stdio.h>
#include <stdlib.h>

/*Structures */
struct Point{
    float x;
    float y;
};

void displayPoint(struct Point point);
struct Point initialisePoint(float x, float y);
struct Point* initialisePointDynamically(float x, float y);
void freePoint(struct Point *);


int main(void){
    struct Point members;
    struct Point test;
    members.x = 12;
    members.y = 11;
    displayPoint(members);
    initialisePointDynamically(12,13);

    //displayPoint(initialisePointDynamically(12,13));

    return 0;
}

void displayPoint(struct Point point) {
    printf("%f, %f", point.x, point.y);
}

struct Point initialisePoint(float x, float y) {
    struct Point temp;
    temp.x  = x;
    temp.y = y;
    return temp;
}

struct Point* initialisePointDynamically(float x, float y){
    struct Point *temp;
    temp = malloc(sizeof(struct Point));

    temp->x = x;
    temp->y = y;

    printf("%f, %f", temp->x, temp->y);
    free(temp);
    return temp;


}

