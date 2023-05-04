/*
** EPITECH PROJECT, 2022
** dante
** File description:
** Generator algorithm for mazes
*/

#include "../includes/my.h"
#include "../includes/lemin.h"

int get_index_room(t_lemin *lemin, char *room)
{
    for (int i = 0; lemin->rooms_names[i]; i++) {
        if (my_strcmp(lemin->rooms_names[i], room) == 0) {
            return (i);
        }
    }
    return (-1);
}

char **get_rooms_available(t_lemin *lemin, char *room)
{
    int i = 0;
    int cnt = 0;
    int index = get_index_room(lemin, room);
    char **rooms_available = malloc(sizeof(char *) * (lemin->num_rooms + 1));

    for (int j = 0; j < lemin->num_rooms + 1; j++) {
        rooms_available[j] = NULL;
    }

    for (; lemin->graph[index][i]; i++) {
        if (lemin->graph[index][i] == '1') {
            rooms_available[cnt++] = lemin->rooms_names[i];
        }
    }
    return (rooms_available);
}

bool room_is_visited(t_node *head, char *room)
{
    t_node *tmp = head;
    for (int i = 0; tmp->next; i++) {
        if (my_strcmp(tmp->name, room) == 0) {
            return (true);
        }
        tmp = tmp->next;
    }
    return (false);
}

void push(t_node **head, char *room)
{
    t_node *new_node = malloc(sizeof(t_node));
    new_node->name = room;
    new_node->visited = true;
    new_node->next = *head;
    *head = new_node;
}

void pop(t_node **head)
{
    if (*head == NULL) return;
    t_node *tmp = *head;
    *head = (*head)->next;
    free(tmp);
}
