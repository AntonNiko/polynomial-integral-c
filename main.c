/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Antnik45
 *
 * Created on June 26, 2017, 9:04 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include "integration.h"

void inputCoeffs(float coeffs[], int polyLen);
float inputFloat(char arg[]);
int inputInt(char arg[]);

int main(int argc, char** argv){
    printf("Polynomial Integral\n");
    
    // Input number of coefficients in polynomial 
    int polyLen = inputInt("Length of Polynomial: ");  
    // Declare array of coefficients
    float coeffs[polyLen];
    inputCoeffs(coeffs, polyLen);
    
    // Input limits of integration 
    float x1 = inputFloat("Lower limit: ");
    float x2 = inputFloat("Upper limit: ");
    // Integrate polynomial
    printf("Area: %f", integrate(coeffs, polyLen, x1, x2));
}

void inputCoeffs(float coeffs[], int polyLen){
    char inputArg[10];
    // For the length of the polynomial, input all coeff values
    for(int i=0; i<polyLen; i++){
        sprintf(inputArg, "x^%d: ", i);
        coeffs[i] = inputFloat(inputArg);
    } 
}

int inputInt(char arg[]){
    int inputInt;
    printf("\n%s", arg);
    scanf("%d", &inputInt);
    return inputInt;
}

float inputFloat(char arg[]){
    float inputFloat;
    printf("%s", arg);
    scanf("%f", &inputFloat);
    return inputFloat;
}






