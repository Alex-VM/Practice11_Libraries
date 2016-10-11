//Alejandro Villaseñor Medina
//A01196169
//October 10, 2016
//Dynamic Library containing functions to read large string
//dynamically (allocating memory when more is needed)

#include "main.h"

#define DllExport __declspec(dllexport)

//Dinamically allocates memory to the string
void allocateMemory(int *ptrSpace, char** cPtrPtrString, char** cPtrPtrCurrent)
{
    //Temporal pointer to the new string
    char *tempPtr;

    *ptrSpace += 5;
    tempPtr = (char *) malloc(sizeof(char) * (*ptrSpace));

    //If its not the first allocation, copy the old string
    if(*cPtrPtrString !=NULL)
    {
        int i = 0;

        //Current pointer goes to the new memory
        *cPtrPtrCurrent = tempPtr;
        char *temp = *cPtrPtrString;

        //Moving pointers while copying
        for( i ; i < *ptrSpace -5 ; i++)
        {
            * (*cPtrPtrCurrent) = *temp;
            (*cPtrPtrCurrent)++;
            temp++;
        }
    }

    //Free the previous array
    if((*cPtrPtrString )!= NULL)
    {
        free(*cPtrPtrString);
    }

    //Move the pointer to the new memory
    *cPtrPtrString = tempPtr;

    //Point Current to the first character
    if(*cPtrPtrCurrent == NULL)
    {
        *cPtrPtrCurrent = *cPtrPtrString;
    }
}

//Prints the whole string
void printString(int iChars, char** cPtrPtrString)
{
    char *temp;
    temp = *cPtrPtrString;

    while(iChars > 0)
    {
        printf("%c", *temp);
        temp++;
        iChars--;
    }
    printf("\n");
}

//Function that allows a user to type in characters for as long
//as the computer can allocate memory
//This is the only exportable function
void DllExport extremelyLargeString( )
{
    char cRead;
    //Number of characters typed
    int iCharNum= 0;

    //String pointers
    char *cPtrString = NULL, *cPtrCurrent = NULL;
    int iSpace= 0;

    do
    {
        //+1
        iCharNum++;

        cRead = getchar();

        //If there are more characters than space
        if(iCharNum > iSpace)
            allocateMemory(&iSpace, &cPtrString, &cPtrCurrent);

        if(cRead !=124)
        {
            //Assign the value in the string
            *cPtrCurrent = cRead;
            cPtrCurrent++;
        }

    }while(cRead != 124);

    printf("String length: %d\n", iCharNum-1);
    printString(iCharNum-1, &cPtrString);

    //Frees the string when the end character is read
    free(cPtrString);
}


/*extern "C" DLL_EXPORT BOOL APIENTRY DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    switch (fdwReason)
    {
        case DLL_PROCESS_ATTACH:
            // attach to process
            // return FALSE to fail DLL load
            break;

        case DLL_PROCESS_DETACH:
            // detach from process
            break;

        case DLL_THREAD_ATTACH:
            // attach to thread
            break;

        case DLL_THREAD_DETACH:
            // detach from thread
            break;
    }
    return TRUE; // succesful
}*/
