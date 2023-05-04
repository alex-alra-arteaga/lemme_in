/*
** EPITECH PROJECT, 2022
** dante
** File description:
** Generator algorithm for mazes
*/

#include "../includes/my.h"
#include "../includes/lemin.h"

int main(int argc, char **argv)
{
    t_lemin *lemin;
    char **file = NULL;
    if (error(argc, &file) == 84)
        return 84;
    lemin = parser(file);
    algorithm(lemin);
    return 0;
}
