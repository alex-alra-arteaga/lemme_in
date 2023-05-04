/*
** EPITECH PROJECT, 2022
** dante
** File description:
** Generator algorithm for mazes
*/

#include "../includes/my.h"
#include "../includes/lemin.h"

void swap_strings(char **a, char **b)
{
    char *temp = *a;
    *a = *b;
    *b = temp;
}

void revstr_array(char *arr[], int n)
{
    for (int i = 0; i < n / 2; ++i) {
        swap_strings(&arr[i], &arr[n - i - 1]);
    }
}

int my_arraylen(char **array)
{
    int i = 0;
    while (array[i] != NULL) {
        i++;
    }
    return i;
}
