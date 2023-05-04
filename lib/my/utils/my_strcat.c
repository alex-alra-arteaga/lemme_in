/*
** EPITECH PROJECT, 2022
** my_strcat
** File description:
** Concatenates two strings
*/

int my_strlen(char const *str);

char* my_strcat(char* dest, const char* src)
{
    char* ptr = dest + my_strlen(dest);
    while (*src != '\0') {
        *ptr++ = *src++;
    }
    *ptr = '\0';
    return dest;
}
