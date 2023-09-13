/*
My Name: Archi Mukeshbhai Kakadiya
Email: akakadiya1@myseneca.ca
Student ID: 117470229
Date: 18/04/2023
*/

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_UTILS_H
#define SDDS_UTILS_H

/// <summary>
/// Performs a fool-proof console data entry for an integer
/// </summary>
/// <returns>The entered integer</returns>
int getInt(void);

/// <summary>
/// Performs a limited fool-proof console data entry for an integer
/// </summary>
/// <param name="min">Minimum acceptable value</param>
/// <param name="max">Maximum acceptable value</param>
/// <param name="valueName">Name of the value (for the error message)</param>
/// <returns>the entered integer</returns>
int getIntMM(int min, int max, const char valueName[]);

/// <summary>
/// Performs a fool-proof console data entry for a double
/// </summary>
/// <returns>The entered double</returns>
double getDbl(void);

/// <summary>
/// Performs a limited fool-proof console data entry for a double
/// </summary>
/// <param name="min">Minimum acceptable value</param>
/// <param name="max">Maximum acceptable value</param>
/// <param name="valueName">Name of the value (for the error message)</param>
/// <returns>the entered double</returns>
double getDblMM(double min, double max, const char valueName[]);

/// <summary>
/// Flushes the console entry by reading characters upto and including the newline '\n' character 
/// </summary>
void flushKey(void);

/// <summary>
/// First prompts "(Y)es/(N)o: " and then performs a fool-proof for Y and N data entry
/// </summary>
/// <returns>Returns true (1) is the user enters Y and false (0) if user entern N</returns>
int yes(void);

/// <summary>
/// Prompts: "Press <ENTER> to continue...." and then waits for user to hit ENTER
/// </summary>
void pause(void);

/// <summary>
/// Flushes the console entry by reading characters upto and including the newline '\n' character in file
/// </summary>
/// <param name="file"> Receives data from file </param>
void fflushKey(FILE* file);

#endif // !SDDS_UTILS_H
