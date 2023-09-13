/*
My Name: Archi Mukeshbhai Kakadiya
Email: akakadiya1@myseneca.ca
Student ID: 117470229
Date: 12/04/2023
*/

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

/* Citation and Sources...
Final Project Milestone34
Module: 4
Filename: PosApp.h
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


#ifndef SDDS_POSAPP_H
#define SDDS_POSAPP_H

#include <stdio.h>
#include "POS.h"

/// <summary>
/// Structure of Items
/// </summary>
struct Item {
	char sku[MAX_SKU_LEN + 1];
	char name[61];
	double price;
	int taxed;
	int quantity;
};

/// <summary>
/// Global Array of item structure type
/// </summary>
struct Item items[MAX_NO_ITEMS];

/// <summary>
/// Global Integer Variable to hold Number Of Records
/// </summary>
int noOfItems;

/// <summary>
/// Ask user to enter SKU and search it in items array
/// </summary>
/// <param name=""></param>
/// <returns> index of item holding the same SKU </returns>
int search(void);

/// <summary>
/// Print an Item in a "Form"
/// </summary>
/// <param name="item">pass item pointer struct</param>
void display(const struct Item* item);

/// <summary>
/// Print a bill
/// </summary>
/// <param name="item">Pass item pointer structure</param>
/// <returns>Cost after Taxed</returns>
double billDisplay(const struct Item* item);

/// <summary>
/// Receives address of Item structure, Pass Pointers
/// </summary>
/// <param name=""></param>
/// <returns> Cost of Items after Tax </returns>
double cost(const struct Item* item);

/// <summary>
/// Check If user enters Proper input, Pass Item and File Pointer
/// </summary>
/// <returns> Yes or No </returns>
int getItems(struct Item* item, FILE* fptr);

/// <summary>
/// Print Message in Same Format, Pass String Pointer
/// </summary>
void start(const char* action);

/// <summary>
/// Call listItems Function for listing all items and Print Total Assets
/// </summary>
void inventory(void);

/// <summary>
/// Print Add Items Message
/// </summary>
void addItem(void);

/// <summary>
/// Print Removing Items Message
/// </summary>
void removeItem(void);

/// <summary>
/// Print Stocking Items Message
/// </summary>
void stockItem(void);

/// <summary>
/// Print Point Of Sale Message
/// </summary>
void POS(void);

/// <summary>
/// Lists the items in the items array up to noOfItems
/// </summary>
void listItems(void);

/// <summary>
/// Loads all the items from a data file
/// </summary>
/// <returns> noOfItems </returns>
int loadItems(const char filename[]);

/// <summary>
/// Saves all the elements of the items array in file Receives from file
/// </summary>
void saveItems(const char filename[]);


#endif // !SDDS_POSAPP_H