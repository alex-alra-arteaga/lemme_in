/*
** EPITECH PROJECT, 2022
** dante
** File description:
** Generator algorithm for mazes
*/

#include "../includes/my.h"
#include "../includes/lemin.h"

void store_route
(t_store_routes *store_routes, int *cnt, int depth, int *min_depth)
{
    if (depth < *min_depth || *min_depth == -1) {
        t_node *tmp = store_routes->head;
        int list_len = my_list_len(store_routes->head);
        (*store_routes->routes)[*cnt] = malloc(sizeof(char *) * (list_len + 1));

        for (int j = 0; j < list_len; j++) {
            (*store_routes->routes)[*cnt][j] = tmp->name;
            tmp = tmp->next;
        }
        (*store_routes->routes)[*cnt][list_len] = NULL;

        *min_depth = depth;
    }
}

void explore_routes
(t_explore_info *ex_info, char ****routes, int depth, int *min_depth)
{
    t_store_routes store_routes;
    char **rooms_available;
    rooms_available = get_rooms_available(ex_info->lemin, ex_info->head->name);
    char **unvisited_rooms;
    unvisited_rooms = get_unvisited_rooms(ex_info->head, rooms_available);
    int cnt = 0;

    for (int i = 0; unvisited_rooms[i]; i++) {
        push(&ex_info->head, unvisited_rooms[i]);
        store_routes.head = ex_info->head;
        store_routes.routes = routes;
        if (my_strcmp(unvisited_rooms[i], ex_info->lemin->end) == 0)
            store_route(&store_routes, &cnt, depth, min_depth);
        else
            explore_routes(ex_info, routes, depth + 1, min_depth);
        pop(&ex_info->head);
    }
    free(unvisited_rooms);
}

char ***bfs(t_lemin *lemin)
{
    t_explore_info *explore_info = malloc(sizeof(t_explore_info));
    int min_depth = -1;
    char ***routes = malloc(sizeof(char **) * (lemin->num_rooms + 1));
    routes[lemin->num_rooms] = NULL;
    explore_info->head = NULL;
    explore_info->lemin = lemin;
    push(&(explore_info->head), lemin->start);
    explore_routes(explore_info, &routes, 0, &min_depth);
    return routes;
}

void algorithm(t_lemin *lemin)
{
    char ***routes = bfs(lemin);

    for (int i = 0; routes[i]; i++) {
        revstr_array(routes[i], my_arrlen(routes[i]));
        print_routes(routes[i], lemin);
    }

    for (int i = 0; routes[i]; i++) {
        for (int j = 0; routes[i][j]; j++) {
            free(routes[i][j]);
        }
        free(routes[i]);
    }
}
