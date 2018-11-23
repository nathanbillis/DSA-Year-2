#include <stdio.h>

int doubleByValue(int x);
void doubleByReferance(int* number);
void swap(int*x, int*y);

int main(void){
    int ans = doubleByValue(12);
    printf("%d\n",ans);
    doubleByReferance(&ans);
    printf("%d\n", ans);

    int a = 12;
    int b = 13;

    printf("%d, %d\n", a , b);
    swap(&a , &b);
    printf("%d, %d", a , b);
    return 0;
}

//double by value
int doubleByValue(int x){
    int ans = x * x ;
    return ans;
}

//doube by referance

void doubleByReferance(int* number){
    int ans = *number * *number;
    *number = ans;
}

void swap(int*x, int*y){
    int hold = NULL;
    hold = *x;
    *x = *y;
    *y = hold;
}
