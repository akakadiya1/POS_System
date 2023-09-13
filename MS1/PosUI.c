/*
My Name: Archi Mukeshbhai Kakadiya
Email: akakadiya1@myseneca.ca
Student ID: 117470229
Date: 02/04/2023
*/

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

/* Citation and Sources...
Final Project Milestone1
Module: Whatever
Filename: PosUI.c
Version 1.0
Author	Archi Kakadiya
Revision History
-----------------------------------------------------------
Date      Reason
2020/?/?  Preliminary release
2020/?/?  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------
*/

#include <stdio.h>
#include "utils.h"
#include "PosUI.h"
#include "PosApp.h"

int menu(void) {
    int sel = -1;
    while (sel < 0 || sel > 5) {
        printf("The Sene-Store\n");
        printf("1- Inventory\n");
        printf("2- Add item\n");
        printf("3- Remove item\n");
        printf("4- Stock item\n");
        printf("5- POS\n");
        printf("0- exit program\n");
        printf("> ");
        sel = getIntMM(0, 5, "Selection");
    }
    return sel;
}

int returnSel(void){
    int sel = 0;
    int done = 0;
    while(!done){
        sel = menu();
        switch (sel) {
        case 1:
            inventory();
            break;
        case 2:
            addItem();
            break;
        case 3:
            removeItem();
            break;
        case 4:    
            stockItem();
            break;
        case 5:  
            POS();
            break;
        case 0:
            done = 1;
            break;
        default:
            printf("Invalid selection, try again.\n");
            break;
        }
    }
    return sel;
}

void runPos(const char filename[]) {
    loadItems(filename);
    int choice = -1;
    while (choice != 0) {
        choice = returnSel();
    }
    saveItems(filename);
    printf("Goodbye!\n");
}
