/*
** EPITECH PROJECT, 2022
** dante
** File description:
** Generator algorithm for mazes
*/

#include "../includes/my.h"
#include "../includes/lemin.h"

bool are_there_any_unvisited_room(t_node *head, char **rooms_available)
{
    t_node *tmp = head;
    for (int i = 0; rooms_available[i]; i++) {
        if (!room_is_visited(tmp, rooms_available[i])) {
            return (true);
        }
    }
    return (false);
}

char **get_unvisited_rooms(t_node *head, char **rooms_available)
{
    int cnt = 0;
    char **unvsited_rooms;
    unvsited_rooms = malloc(sizeof(char *) * (my_arrlen(rooms_available) + 1));

    for (int i = 0; rooms_available[i]; i++) {
        if (!room_is_visited(head, rooms_available[i])) {
            unvsited_rooms[cnt++] = rooms_available[i];
        }
    }
    unvsited_rooms[cnt] = NULL;

    return unvsited_rooms;
}

bool is_relation(char *line)
{
    for (int i = 0; line[i]; i++)
        if (line[i] == '-')
            return true;
    return false;
}
