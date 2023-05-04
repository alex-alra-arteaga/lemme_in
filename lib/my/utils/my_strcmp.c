/*
** EPITECH PROJECT, 2022
** my_strcmp
** File description:
** task06
*/

int my_strlen(char const *str);

int my_strcmp (char const *s1, char const *s2)
{
    int i = 0;

    while (s1[i] && s2[i] && s1[i] == s2[i])
        i++;
    if (s1[i] == s2[i])
        return 0;
    else if (s1[i] < s2[i])
        return -1;
    else
        return 1;
}
