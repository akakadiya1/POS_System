/*
My Name: Archi Mukeshbhai Kakadiya
Email: akakadiya1@myseneca.ca
Student ID: 117470229
Date: 18/04/2023
*/

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

/* Citation and Sources...
Final Project Milestone35
Module: 5
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

void POS(void) {
	const struct Item* bill[MAX_BILL_ITEMS] = { NULL };
	int noOfItems = 0;
	int done = 0;
	double total = 0.0;
	int fIndex, i;
	start("Point Of Sale");
	while (noOfItems < MAX_BILL_ITEMS && !done) {
		fIndex = search();
		if (fIndex > 0 && items[fIndex].quantity > 0) {
			//if () {
			items[fIndex].quantity--;
			display(&items[fIndex]);
			bill[noOfItems++] = &items[fIndex];
		}
		else if (fIndex >= 0) {
			printf("Item sold out!\n");
		}
		else if (fIndex == -1) {
			printf("SKU not found!\n");
		}
		else {
			done = 1;
		}
	}
	if (noOfItems) {
		printf("+---------------v-----------v-----+\n");
		printf("| Item          |     Price | Tax |\n");
		printf("+---------------+-----------+-----+\n");
		for (i = 0; i < noOfItems; i++) {
			total += billDisplay(bill[i]);
		}
		printf("+---------------^-----------^-----+\n");
		printf("| total:          %9.2lf |\n", total);
		printf("^---------------------------^\n");
	}
}

int search(void) {
	char sku[MAX_SKU_LEN + 1] = { '\0' };
	int i, foundIndex = -1;
	printf("Sku: ");
	scanf("%7[^\n]", sku);
	flushKey();
	if (sku[0] == '\0') {
		foundIndex = -2;
	}
	else {
		for (i = 0; i < MAX_NO_ITEMS && foundIndex == -1; i++) {
			if (strcmp(items[i].sku, sku) == 0) {
				foundIndex = i;
			}
		}
	}
	return foundIndex;
}

void display(const struct Item* item) {
	printf("=============v\n");
	printf("Name:        %s\n", item->name);
	printf("Sku:         %s\n", item->sku);
	printf("Price:       %.2lf\n", item->price);
	printf("Price + tax: ");
	if (item->taxed) printf("%.2lf\n", cost(item));
	else printf("N/A\n");
	printf("Stock Qty:   %d\n", item->quantity);
	printf("=============^\n");
}

double billDisplay(const struct Item* item) {
	char tempString[14 + 1];
	strncpy(tempString, item->name, 14);
	tempString[14] = '\0';
	printf("| %-14s|%10.2lf | %s |\n", tempString, cost(item), item->taxed ? "Yes" : "   ");
	return cost(item);
}

int loadItems(const char filename[]) {
	start("Loading Items");
	FILE* file = fopen(filename, "r");
	int i = 0;
	while (file != NULL && i < MAX_NO_ITEMS && getItems(&items[i], file)) {
		i++;
	}
	fclose(file);
	noOfItems = i;
	start("Done!");
	return noOfItems;
}

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
	int i;
	FILE* file = fopen(filename, "w");
	if (file != NULL) {
		for (i = 0; i < noOfItems; i++) {
			fprintf(file, "%s,%s,%.2lf,%d,%d\n", items[i].sku, items[i].name,
				          items[i].price, items[i].taxed, items[i].quantity);
		}
		fclose(file);
	}
	else {
		printf("Could not open >>%s<<\n", filename);
	}
	start("Done!");
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

