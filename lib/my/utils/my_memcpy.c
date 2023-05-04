/*
** EPITECH PROJECT, 2022
** my_memcpy
** File description:
** temporal file
*/
#include <stddef.h>
#include <stdint.h>

void *my_memcpy(void *dest, const void *src, int32_t size)
{
    char *pdest = (char *) dest;
    char *psrc = (char *) src;

    for (int32_t i = 0; i < size; i++) {
        pdest[i] = psrc[i];
    }
    return dest;
}
