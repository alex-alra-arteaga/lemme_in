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
#include <stddef.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

void allocate_and_initialize_arrays(char ***tunnels_ptr,
char ***cells_ptr, int index_tunnel, int index_cell)
{
    char **tunnels = malloc((sizeof(char *) * (index_tunnel) + 1));
    char **cells = malloc((sizeof(char *) * (index_cell) + 1));

    for (int i = 0; i < index_cell; i++) {
        cells[i] = my_strdup("h");
    }

    for (int i = 0; i < index_tunnel; i++) {
        tunnels[i] = my_strdup("h");
    }

    cells[index_cell] = NULL;
    tunnels[index_tunnel] = NULL;

    *cells_ptr = cells;
    *tunnels_ptr = tunnels;
}

void process_arguments(char **arguments, error_t *error,
char **tunnels, char **cells)
{
    int num_tunnels = 0; int num_cells = 0;
    for (; *arguments; arguments++) {
        if (my_strcmp(*arguments, "##start") == 0) {
            error->start = true; continue;
        }
        if (my_strcmp(*arguments, "##end") == 0) {
            error->end = true; continue;
        }
        if ((*arguments[0] && *arguments[0] == '#')
        && (*arguments[1] && *arguments[1] != '#'))
            continue;
        if (is_tunnel(*arguments)) {
            tunnels[num_tunnels++] = my_strdup(*arguments);
            continue;
        }
        if (is_cell(*arguments)) {
            cells[num_cells++] = my_strdup(*arguments);
        }
    }
    cells[num_cells] = NULL; tunnels[num_tunnels] = NULL;
}

bool handle_error(char **arguments, error_t *error)
{
    int index_tunnel = 0;
    int index_cell = 0;
    char **tunnels = NULL;
    char **cells = NULL;
    allocate_and_initialize_arrays(&tunnels, &cells, index_tunnel, index_cell);
    process_arguments(arguments, error, tunnels, cells);
    if (!arguments || !error)
        return true;
    if (!is_only_num(*arguments))
        return true;
    int ants = my_getnbr(*arguments);
    if (ants <= 0)
        return true;
    process_arguments(arguments, error, tunnels, cells);
    check_cells(cells, error);
    check_tunnels(tunnels, error, cells);
    if (error->start == false || error->end == false)
        return true;
    return false;
}

int error(int argc, char ***arguments)
{
    char *line = NULL;
    char *line2 = NULL;
    line2 = malloc(sizeof(char) * (10000));
    size_t len = 0;
    error_t *error = malloc(sizeof(error_t));
    error->start = false;
    error->end = false;
    error->is_error = false;
    if (error == NULL)
        return (84);
    if (argc != 1)
        return 84;
    while (getline( &line, &len, stdin) != -1) {
        my_strcat(line2, line);
    }
    *arguments = my_split(line2, '\n');
    if (handle_error(*arguments, error))
        return 84;
    return 0;
}
