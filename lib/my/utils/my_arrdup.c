/*
** EPITECH PROJECT, 2022
** my_arrdup.c
** File description:
** my_strdup but for arrays
*/

#include "../../../includes/my.h"

int my_arrcpy(char **dst, char **src, int size)
{
    int l = 0;
    while (l < size && src[l] != NULL)
        dst[l] = my_strdup(src[l]), l++;
    return l;
}

char **my_arrdup(char **src, int size)
{
    char **str_array;
    int l;

    if (src == NULL || src[0] == NULL)
        return NULL;
    str_array = malloc(sizeof(char *) * (size + 1));
    if (str_array == NULL)
        return NULL;
    l = my_arrcpy(str_array, src, size);
    str_array[l] = NULL;
    if (l != size) {
        for (int i = 0; i < l; i++)
            free(str_array[i]);
        free(str_array);
        return NULL;
    }
    return str_array;
}
