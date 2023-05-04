/*
** EPITECH PROJECT, 2022
** dante
** File description:
** Generator algorithm for mazes
*/

#include "../includes/my.h"
#include "stdio.h"
#include "stdlib.h"
#include "../includes/error_parse.h"
#include "string.h"
#include "../includes/lemin.h"
#include "../includes/ants.h"
#include "../includes/ants.h"

t_ant *create_ant(int index, char **path)
{
    t_ant *ant = malloc(sizeof(t_ant));
    ant->index = index;
    ant->times_moved = 0;

    ant->path = malloc(sizeof(char *) * my_arraylen(path));
    for (int i = 0; path[i]; i++) {
        ant->path[i] = malloc(sizeof(char) * my_strlen(path[i]));
        my_strcpy(ant->path[i], path[i]);
    }
    ant->next = NULL;
    return ant;
}

bool is_room_empty(t_ant *ant, char *room, int index, t_ant *actual)
{
    t_ant *current = ant;
    char *start_room = ant->path[0];
    char *end_room = ant->path[my_arraylen(ant->path) - 1];

    if (my_arraylen(actual->path) - 1 == actual->times_moved)
        return true;
    if (my_strcmp(room, start_room) == 0 || my_strcmp(room, end_room) == 0)
        return true;
    while (current != NULL) {
        if (my_strcmp(current->path[current->times_moved], room) == 0)
            return false;
        current = current->next;
    }
    return true;
}

int move(t_ant *ant)
{
    int control = 0;
    t_ant *current = ant;
    while (current != NULL) {
        if (current->path[current->times_moved] != NULL &&
            current->path[current->times_moved + 1] != NULL &&
            is_room_empty(ant, current->path[current->times_moved + 1],
            current->index, current)) {
            my_putstr("P"); my_put_nbr(current->index); my_putchar('-');
            my_putstr(current->path[current->times_moved + 1]);
            my_putchar(' ');
            current->times_moved++;
            control += 1;
        }
        current = current->next;
    }
    if (control != 0)
        my_putchar('\n');
    if (control == 0)
        return 1;
    return move(ant);
}

int print_routes(char **route, t_lemin *lemin)
{
    int nb_ants = lemin->num_ants;
    int i = 1, j = 1, final = 0;
    t_ant *head = NULL, *current = NULL;
    while (nb_ants > 0) {
        (head == NULL) ? (head = create_ant(i, route), current = head)
        : (current->next = create_ant(j, route),
        current = current->next, current->next = NULL);
        if (i == (my_arraylen(route) - 1)) {
            i = 0; j++; nb_ants--; continue;
        }
        nb_ants--; i++; j++;
    }
    current->next = NULL;
    if (move(head) == 1)
        return 0;
    return 0;
}
