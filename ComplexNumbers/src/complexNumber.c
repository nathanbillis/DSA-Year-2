#include <stdio.h>
#include <math.h>

struct ComplexNumber{
    float real;
    float imaginary;
};

struct ComplexNumber* complexNumberConstructor(float real, float imaginary){
    struct ComplexNumber* complexnumber;

    complexnumber = malloc(sizeof(struct ComplexNumber));

    complexnumber -> real = real;
    complexnumber -> imaginary = imaginary;

    return complexnumber;
};

void complexNumberDestructor(struct ComplexNumber* complexnumber){
    free(complexnumber);
};

float complexNumberGetReal(struct ComplexNumber* complexnumber){
    return complexnumber -> real;
};

float complexNumberGetImag(struct ComplexNumber* complexnumber){
    return complexnumber -> imaginary;
};

float complexNumberGetMag(struct ComplexNumber* complexnumber){
    float mag;
    mag = (complexnumber -> real * complexnumber -> real) *(complexnumber -> imaginary * complexnumber -> imaginary);
    return mag;
};

float complexNumberGetAngle(struct ComplexNumber* complexnumber){
    float angle;
    angle = atan(complexnumber -> imaginary / complexnumber -> real);
    return angle;
};

void complexNumberDisplay(struct ComplexNumber* complexnumber){
    printf("%f + %f j\n", complexnumber -> real, complexnumber -> imaginary);
};


void complexNumberConjugate(struct ComplexNumber* input, struct ComplexNumber* result){
    result -> real = input -> real;
    result -> imaginary = - input -> imaginary;
};

void complexNumberMulti(struct ComplexNumber* input,struct ComplexNumber* inputtwo, struct ComplexNumber* result){
    result -> real = ((input->real*inputtwo->real)-(input->imaginary * inputtwo -> imaginary));
    result -> imaginary = ((input->real*inputtwo->imaginary)+(input->imaginary * inputtwo -> real));
};

void complexNumberAdd(struct ComplexNumber* input,struct ComplexNumber* inputtwo, struct ComplexNumber* result){
    result -> real = (input->real+inputtwo->real);
    result -> imaginary = (input->imaginary+inputtwo->imaginary);
};
void complexNumberSub(struct ComplexNumber* input,struct ComplexNumber* inputtwo, struct ComplexNumber* result){
    result -> real = (input->real-inputtwo->real);
    result -> imaginary = (input->imaginary-inputtwo->imaginary);
};

void complexNumberDivide(struct ComplexNumber* input,struct ComplexNumber* inputtwo, struct ComplexNumber* result) {
// this is hacky
    result -> real = (((input->real*inputtwo->real)+(input->imaginary * inputtwo -> imaginary))/
        (((inputtwo -> real)* (inputtwo -> real)) + ((inputtwo -> imaginary)* (inputtwo -> imaginary))));
    result -> imaginary = (((input->imaginary*inputtwo->real)-(input->real * inputtwo -> imaginary))/
        (((inputtwo -> real)* (inputtwo -> real)) + ((inputtwo -> imaginary)* (inputtwo -> imaginary))));;
};

