/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** Contains the prototypes of all the functions in libmy.a
*/

#include "my.h"

#ifndef ERROR_PARSE_
    #define ERROR_PARSE_

    typedef struct {
        bool start;
        bool end;
        bool is_error;
    } error_t;

    void check_cells(char **cells, error_t *error);
    void check_tunnels(char **tunnels, error_t *error, char **cells);
    int tunnel_control(char **tunnel, char **cell);
    void check_tunnel_error(char **tunnel, error_t *error);
    void count_cell_tunnel(char **arguments, int *num_tunnels, int *num_cells);
    void free_array
    (char **tunnels, char **cells, int num_tunnels, int num_cells);
    bool is_cell(char *line);
    bool is_tunnel(char *line);

#endif
