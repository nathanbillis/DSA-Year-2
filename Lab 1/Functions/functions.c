#include <stdio.h>

/* prototype functions */

int isNegative(int x);
void negativeNumberChecker(void);
int factorial(int n);
void FizzBuzz(void);

/*Main Function */

int main(void){
    int n = NULL;
    n = factorial(6);
    printf("%d", n);
    FizzBuzz();
    return 0;
}


/* Functions */

int isNegative(int x){
/* Function to check if the number is < 0 */
 if (x < 0){
    printf("The Number %d is Negative", x);
 }
 else {
    printf("The Number %d is Positive", x);
 }
}

void negativeNumberChecker(void){
/* ask user for input */
    int number = NULL;
    printf("enter a number\n");
    scanf("%d", &number);
    isNegative(number);
}


int factorial(int n){
/* recursive function */
    if (n <= 1){
        return 1;
    }
    return n * factorial(n - 1);
}

// Fizz Buzz

void FizzBuzz(void){
/* FizzBuzz Function */
    for(int i = 1; i <= 100; i ++){
    if ((i % 15) == 0){
        printf("FizzBuzz\n");}
    else if ((i % 5) == 0){
        printf("Buzz\n");}
    else if ((i %3)== 0) {
        printf("Fizz\n");}
    else{
        printf("%d\n", i);
        }
    }
}
