/*
** EPITECH PROJECT, 2022
** is_float
** File description:
** handle the string
*/

#include <stdbool.h>

bool is_array_num(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] < '0' || str[i] > '9')
            return false;
    }
    return true;
}
