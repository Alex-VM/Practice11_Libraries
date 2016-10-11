//Alejandro Villaseñor Medina
//A01196169
//October 10, 2016
//Header file for the DLL, contains function definitions and
//libraries used

#include <windows.h>
#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*  To use this exported function of dll, include this header
 *  in your project.
 */

#define DLL_EXPORT __declspec(dllexport)

//Only function used in the app, reads a large string
void DLL_EXPORT extremelyLargeString();

//OTHER FUNCTIONS

//Allocates new memory
void allocateMemory(int *ptrSpace, char** cPtrPtrString, char** cPtrPtrCurrent);

//Prints the stored string
void printString(int iChars, char** cPtrPtrString);

