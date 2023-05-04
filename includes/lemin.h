/*
** EPITECH PROJECT, 2022
** lemin.h
** File description:
** Contains the interfaces of the lemin project
*/

#include "my.h"

#ifndef LEMIN_H_
    #define LEMIN_H_

    typedef struct {
        int num_ants;
        int num_rooms;
        // int num_tunnels;
        char *start;
        int start_index;
        char *end;
        int end_index;
        char **rooms_names;
        char **graph;
    } t_lemin;

    typedef struct explore_info {
        t_lemin *lemin;
        t_node *head;
    } t_explore_info;

    typedef struct store_routes {
        t_node *head;
        char ****routes;
    } t_store_routes;

    typedef struct memory_s {
        char **tunnels;
        char **cells;
        int num_tunnels;
        int num_cells;
    } memory_t;

    t_lemin *parser(char **file);
    int error(int argc, char ***arguments);
    void algorithm(t_lemin *lemin);
    bool is_relation(char *line);
    int get_index_room(t_lemin *lemin, char *room);
    char **get_rooms_available(t_lemin *lemin, char *room);
    bool room_is_visited(t_node *head, char *room);
    void push(t_node **head, char *room);
    void pop(t_node **head);
    char **get_unvisited_rooms(t_node *head, char **rooms_available);
    int print_routes(char **routes, t_lemin *lemin);
    void revstr_array(char *arr[], int n);
    void swap_strings(char **a, char **b);
    int my_arraylen(char **array);
    void print_file(char **file);

#endif
