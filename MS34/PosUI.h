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
Filename: PosUI.h
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


#ifndef SDDS_POSUI_H
#define SDDS_POSUI_H

/// <summary>
/// Display menu on screen and ask user to select one option
/// </summary>
/// <returns> The entered Selection </returns>
int menu(void);

/// <summary>
/// Call loadItems ,saveItems function and In loop, Call returnSel function for checking options
/// </summary>
/// <param name="filename"> receives the name of data file </param>
void runPos(const char filename[]);

/// <summary>
/// Call menu function for checking which option will run according to user's input [Use Mock-Up Functions]
/// </summary>
/// <returns> The entered Selection </returns>
int returnSel(void);

#endif // !SDDS_POSUI_H
