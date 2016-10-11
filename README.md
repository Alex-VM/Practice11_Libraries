Practice 11: Libraries

Advanced programming class. Practice 11: create a Static and a Dynamic Library

This repository contains several files, most of them from the DLL implementation.

------------- STATIC LIBRARY: P11_Static.h ----------------------

This is a static library that has several base conversion functions.
All the functions take an ASCII number in the specified base and
convert it to decimal.

Functions are:
   - Binary (ASCII) to Integer
   - Hex (ASCII) to Integer
   - Double (ASCII) to Double
All functions take as a paremeter a pointer to the first character in the ASCII string that is to be
converted.

In order to use this library, just import the library with
   #include "P11_Static.h"

------------- DYNAMIC LIBRARY: P11_DLL.dll ----------------------

All other files in the repository were used to make the DLL. The dll file itself is in bin/Debug folder.
The library contains a function to read a long string dinamically. It allocates more memory as needed and
stops reading when told so (the user types the pipe '|' character). The function does not take any parameter.

To use the DLL, download the file and take note on the path to it.

In your program, make sure to include windows.h
Declare "HINSTANCE hCodigoDll;" as a global variable
Use a function pointer to the function extremelyLargeString.
The following instruction fetches the library, and the following one, the library.

hCodigoDll = LoadLibrary("P11_DLL.dll");
ptrFuncion= GetProcAddress(hCodigoDll, "extremelyLargeString");

Afterwards, you can call the function using the pointer
(*ptrFuncion)();
