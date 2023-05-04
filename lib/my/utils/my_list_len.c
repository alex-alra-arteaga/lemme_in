/*
** EPITECH PROJECT, 2022
** my_lib
** File description:
** Linked list my_strlen
*/

#include "../../../includes/my.h"
#include "../../../includes/lemin.h"

int my_list_len(t_node *head)
{
    int length = 0;
    t_node *current = head;

    while (current) {
        length++;
        current = current->next;
    }
    return length;
}
