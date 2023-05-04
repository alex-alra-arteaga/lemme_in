/*
** EPITECH PROJECT, 2022
** dante
** File description:
** Generator algorithm for mazes
*/

#include "../includes/my.h"
#include "../includes/lemin.h"
#include "stdio.h"
#include "stdlib.h"
#include "../includes/error_parse.h"
#include "string.h"

bool is_tunnel(char *line)
{
    for (int i = 0; line[i]; i++) {
        if (line[i] == '-') {
            return true;
        }
    }
    return false;
}

bool is_cell(char *line)
{
    char **cell = my_split(line, ' ');

    if (cell == NULL || cell[0] == NULL || cell[1] == NULL || cell[2] == NULL)
        return false;
    if (!is_only_num(cell[1]) || !is_only_num(cell[2]))
        return false;

    return true;
}

void free_array(char **tunnels, char **cells, int num_tunnels, int num_cells)
{
    for (int i = 0; i < num_tunnels; i++) {
        free(tunnels[i]);
    }
    for (int i = 0; i < num_cells; i++) {
        free(cells[i]);
    }
    free(tunnels);
    free(cells);
}

void count_cell_tunnel(char **arguments, int *num_tunnels, int *num_cells)
{
    for (int i = 0; arguments[i]; i++) {
        if (is_tunnel(arguments[i])) {
            (*num_tunnels)++;
            continue;
        }
        if (is_cell(arguments[i])) {
            (*num_cells)++;
        }
    }
}

void check_tunnel_error(char **tunnel, error_t *error)
{
    if (!tunnel[0] || !tunnel[1]) {
        error->is_error = true;
    } else if (my_strcmp(tunnel[0], tunnel[1]) == 0) {
        error->is_error = true;
    }
}
