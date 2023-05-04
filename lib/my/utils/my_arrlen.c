/*
** EPITECH PROJECT, 2022
** my_arrlen.c
** File description:
** read the length of an array of arrays
*/

int my_arrlen(char **arr)
{
    int i = 0;
    while (arr[i]) {
        i++;
    }
    return (i);
}
