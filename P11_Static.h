//Alejandro Villaseñor Medina
//A01196169
//Static Library using the functions from practice 9
//Functions to convert numbers from ascii to hex, binary and double

//Receives a character and returns true or false (1, 0)
//if the received character is valid in binary language
int validateBinary(char c)
{
    return c == '0' || c == '1' ? 1 : 0;
}

//Receives a character and returns true or false (1, 0)
//if the received character is valid in hexadecimal language
int validateHex(char c)
{
    if(c >= 48 && c <= 57 )
        return 1;

    if( c >= 'a' && c <= 'f')
        return 1;

    if( c >= 'A' && c <= 'F')
        return 1;

    return 0;
}

//Receives a character and returns true or false (1, 0)
//if the received character is a valid numerical value or +, -, .
int validateDouble(char c)
{
    if(c >= 48 && c <= 57 )
        return 1;

    if( c == '-' || c == '+' || c == '.' )
        return 1;

    return 0;
}

//Receives a character pointer to a string
//This string is a binary code that represents an integer number
//Returns the integer number
int asciiBinaryToInt(char *string)
{
    //Final result, sum will be accumulated
    int iSum = 0, iCount = 1;

    while( *string != '\0' && validateBinary(*string )==1 && iCount <= 32)
    {
        //Multiply current by 2
        iSum *= 2;

        //Sum 1 if bit is on
        if (*string == '1')
            iSum += 1;

        string ++;
        iCount ++;
    }

    printf("%c\n", *string);
    if( *string != '\0' && ( (iCount>32 )|| (validateBinary(*string) != 1) ) )
        printf("Number didn't process correctly. Last known value will be used.\n");

    return iSum;
}

//Receives a character pointer to a string
//This string is a hex code that represents an integer
//Returns said integer
int asciiHEXtoInt(char *string)
{
    //Final result, sum will be accumulated
    int iSum = 0, iCount = 1;

    while( *string != '\0' && validateHex(*string )==1 && iCount <= 8)
    {
        //Multiply current value by 16
        iSum *= 16;

        //If its a number, subtract 48 (ASCII 0) and sum that numbre
        if (*string >= 48 && *string <= 57 )
            iSum+= *string - 48;

        //If its a lowercase letter, subtract 87 (ASCII a is 97, so it leaves 10+offset)
        else if(*string >= 'a' && *string <= 'f')
            iSum += *string - 87;

        //If its an uppercase letter, subtract 55 (ASCII a is 65, so it leaves 10+offset)
        else if(*string >= 'A' && *string <= 'F')
            iSum += *string - 55;

        string ++;
        iCount ++;
    }

    if( *string != '\0' && ( validateHex(*string )==0 || iCount > 32) )
        printf("Number didn't process correctly. Last known value will be used.\n");

    return iSum;
}

//Receives a character pointer to a string
//This string is an ASCII that represents a double
//Returns the double with precision 2
double asciiToDouble(char *string)
{
    //Final result, sum will be accumulated
    double dSum = 0;
    int iNeg = 1;

    while( *string != '\0' && validateDouble(*string )==1 && *string != '.')
    {
        //Multiply current value by 16
        dSum *= 10;

        //If its a minus sign, make iNeg negative
        if (*string == '-' )
            iNeg= -1;

        //Ignore the + sign
        else if( *string != '+' )
            dSum += *string - 48;

        string ++;
    }

    //Move from dot before processing decimals
    if(*string == '.')
        string++;

    int iCount = 10;

    //Decimal processing - after dot
    while( *string != '\0' && validateDouble(*string )==1 )
    {
        dSum += ((double)(*string - 48) )/ iCount;

        iCount*= 10;
        string++;
    }

    if( *string != '\0' && validateDouble(*string )==0)
        printf("Number didn't process correctly. Last known value will be used.\n");

    return dSum*iNeg;
}