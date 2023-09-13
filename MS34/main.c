/*
My Name: Archi Mukeshbhai Kakadiya
Email: akakadiya1@myseneca.ca
Student ID: 117470229
Date: 12/04/2023
*/

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

// Final Project 
// Student POS App M34 tester program
// Version 1.0
// Date	2023-04-01
// Author	Fardad Soleimanloo
// Description
// This program test the student implementation of the Item class
// for submission.
//
/////////////////////////////////////////////////////////////////
#include <stdio.h>
#include "PosApp.h"
int main() {
    int i;
    int foundIndex;
    loadItems("posdata.csv");
    for (i = 0; (foundIndex = search()) != -2; i++) {
        if (foundIndex >= 0) {
            printf("SKU found at index %d\n", foundIndex);
        }
        else {
            printf("SKU not found!\n");
        }
    }
    printf("Search was executed %d times...", i);
    return 0;
}
