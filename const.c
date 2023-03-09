/// @file       const.c
/// @author     Denys SHCHERBA, Ivan OSADTSIV
/// @brief      Defines all constants

#include "const.h"

/// @brief  finds the lengt of the integer
/// @param  number 
/// @return the length of given integer
int number_lenght(int number)
{
    if (number == 0)
    {
        return 0;
    }
    else
    {
        return number_lenght(number / 10) + 1;
    }
}
