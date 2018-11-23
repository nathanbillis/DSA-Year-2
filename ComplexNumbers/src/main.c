#include <stdio.h>
#include "complexNumber.h"

int main (void){
    struct ComplexNumber *number;
    struct ComplexNumber *numbertwo;
    struct ComplexNumber *numberresult;

    number = complexNumberConstructor(1,2.5);
    numbertwo = complexNumberConstructor(3,5.5);
    numberresult = complexNumberConstructor(0,0); // creates memory for the congirgate

    complexNumberDivide(number,numbertwo, numberresult);


    complexNumberDisplay(number);
    complexNumberDisplay(numbertwo);
    complexNumberDisplay(numberresult);

    complexNumberDestructor(number);
    complexNumberDestructor(numbertwo);
    complexNumberDestructor(numberresult);



return 0;
}
