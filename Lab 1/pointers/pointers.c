#include <stdio.h>
//prototype functions


int main(void){
    /* Main Function */

    int x;
    int* xPnt; // address of the int
    x = 3;
    printf("%d, %d\n", x , *xPnt);
    xPnt = &x;
    printf("%d, %d\n", x , *xPnt);
    *xPnt = 5;
    printf("%d, %d\n", x , *xPnt);
    xPnt = 5; // seg fault
    printf("%d, %d\n", x , *xPnt);

    return 0;
}
