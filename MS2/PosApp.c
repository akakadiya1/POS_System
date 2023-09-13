/*
My Name: Archi Mukeshbhai Kakadiya
Email: akakadiya1@myseneca.ca
Student ID: 117470229
Date: 10/04/2023
*/

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

/* Citation and Sources...
Final Project Milestone2
Module: 1
Filename: PosApp.c
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


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "utils.h"
#include "PosApp.h"

void start(const char* action) {
	printf(">>>> %s...\n", action);
}

double cost(const struct Item* item) {
	return item->price * (1 + item->taxed * TAX);
}

int getItems(struct Item* item, FILE* fptr) {
	int ret = 0;
	if (fscanf(fptr, "%[^,],%[^,],%lf,%d,%d\n", item->sku, item->name, &item->price,
												&item->taxed, &item->quantity) == 5) {
		ret = 1;
	}
	return ret;
}

int loadItems(const char filename[]) {
	start("Loading Items");
	FILE* file = fopen(filename, "r");
	int i = 0;
	while (file!= NULL && i < MAX_NO_ITEMS && getItems(&items[i], file)) {
		i++;
	}
	fclose(file);
	noOfItems = i;
	start("Done!");
	return noOfItems;
}

void listItems(void) {
	char iName[18 + 1];
	int i;
	printf(" Row | SKU    | Item Name          | Price |TX | Qty |   Total |\n");
	printf("-----|--------|--------------------|-------|---|-----|---------|\n");
	for (i = 0; i < noOfItems; i++) {
		strncpy(iName, items[i].name, 18);
		iName[18] = '\0';
		printf("%4d | %6s | %-18s |%6.2lf | %c | %3d |%8.2lf |\n", i + 1, items[i].sku,
											iName, items[i].price, items[i].taxed ? 'T' : ' ', 
											items[i].quantity, cost(&items[i]) * items[i].quantity);
	}
	printf("-----^--------^--------------------^-------^---^-----^---------^\n");
}

void inventory(void) {
	double tav = 0;
	int i;
	start("List Items");
	listItems();
	for (i = 0; i < noOfItems; i++) {
		tav += cost(&items[i]) * items[i].quantity;
	}
	printf("                               Total Asset: $  | %13.2lf |\n", tav);
	printf("-----------------------------------------------^---------------^\n");
}

void saveItems(const char filename[]) {
	start("Saving Items");
}

void addItem(void) {
	start("Adding Item");
}

void removeItem(void) {
	start("Remove Item");
}

void stockItem(void) {
	start("Stock Items");
}

void POS(void) {
	start("Point Of Sale");
} 