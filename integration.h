/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   integration.h
 * Author: Antnik45
 *
 * Created on July 2, 2017, 3:10 PM
 */
#ifndef INTEGRATION_H_
#define INTEGRATION_H_

#include <math.h>

// Num. of Subintervals for each interval of length 1. If <1, use 500
#define PRECISION 1000

float integrate(float *coeffs, int polyLen, float x1, float x2);
float evalPolynomial(float *coeffs, int polyLen, float x);

float integrate(float *coeffs, int polyLen, float x1, float x2){
    // Numerically integrate polynomial with the Trapezoidal Rule
    float width, x, yval[PRECISION];
    float sum, area;
    // Calculate interval width
    width = (x2-x1) / PRECISION;
    
    // Store all y-values to be used in evaluating integral
    for(int i=0; i<=PRECISION; i++){
        x = x1 + width*i;
        yval[i] = evalPolynomial(coeffs, polyLen, x);
    }
    
    // Trapezoid Formula
    area = 0;
    sum = yval[0] + yval[PRECISION];
    for(int i=1; i<PRECISION; i++){
        sum+= 2*yval[i];
    }
    area = (width/2)*sum;
    return area;
}

float evalPolynomial(float *coeffs, int polyLen, float x){
    float y;
   
    y = 0;
    for(int i=0; i<polyLen; i++){
        y+= coeffs[i] * powf(x, (float)i);
    }
    return y;
}

#endif