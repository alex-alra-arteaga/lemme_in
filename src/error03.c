/*
** EPITECH PROJECT, 2022
** lemin
** File description:
** Pathfinding and adjacency matrix
*/

#include "../includes/my.h"
#include "../includes/lemin.h"
#include "stdlib.h"
#include "../includes/error_parse.h"

void free_split_array(char **split_array)
{
    for (int i = 0; split_array[i]; i++) {
        free(split_array[i]);
    }
    free(split_array);
}

int tunnel_control(char **tunnel, char **cell)
{
    int control = 0;
    (my_strcmp(tunnel[0], cell[0]) == 0) ? control++ : 0;
    (my_strcmp(tunnel[1], cell[0]) == 0) ? control++ : 0;
    return control;
}

void check_tunnels(char **tunnels, error_t *error, char **cells)
{
    for (int i = 0; tunnels[i] && !error->is_error; i++) {
        char **tunnel = my_split(tunnels[i], '-');
        check_tunnel_error(tunnel, error);
        if (error->is_error) {
            free_split_array(tunnel);
            return;
        }
        int control = 0;
        for (int j = 0; cells[j]; j++) {
            char **cell = my_split(cells[j], ' ');
            control += tunnel_control(tunnel, cell);
            free_split_array(cell);
        }
        if (control != 2) {
            error->is_error = true;
        }
        free_split_array(tunnel);
    }
}

void check_cells(char **cells, error_t *error)
{
    char **cell;
    char **cell2;

    for (int i = 0; cells[i] && !error->is_error; i++) {
        cell = my_split(cells[i], ' ');
        (!cell[0] || !cell[1] || !cell[2]) ? error->is_error = true : 0;
        for (int j = 0; cells[j] && !error->is_error; j++) {
            cell2 = my_split(cells[j], ' ');
            (my_strcmp(cell[0], cell2[0]) == 0 && i != j)
            ? error->is_error = true : 0;
        }
    }
}
