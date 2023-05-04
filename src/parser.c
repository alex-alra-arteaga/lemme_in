/*
** EPITECH PROJECT, 2022
** dante
** File description:
** Generator algorithm for mazes
*/

#include "../includes/my.h"
#include "../includes/lemin.h"

int num_of_rooms(char **file)
{
    int cnt = 0;
    for (int i = 2; file[i]; i++)
        if (!is_relation(file[i]) && file[i][0] != '#')
            cnt++;
    return cnt;
}

int store_rooms(char **file, int i, t_lemin *lemin, int cnt)
{
    char **split_line;

    if (my_strcmp(file[i], "##start") == 0) {
        split_line = my_split(file[i + 1], ' ');
        lemin->start = my_strdup(split_line[0]);
        lemin->start_index = cnt;
    }
    if (my_strcmp(file[i], "##end") == 0) {
        split_line = my_split(file[i + 1], ' ');
        lemin->end = my_strdup(split_line[0]);
        lemin->end_index = cnt;
    }
    if (file[i][0] != '#') {
        split_line = my_split(file[i], ' ');
        lemin->rooms_names[cnt] = my_strdup(split_line[0]);
        cnt++;
    }
    return (cnt);
}

t_lemin *read_file(char **file, t_lemin *lemin)
{
    int cnt = 0;

    lemin->num_ants = my_getnbr(file[0]);
    lemin->num_rooms = num_of_rooms(file);
    lemin->rooms_names = malloc(sizeof(char *) * (lemin->num_rooms + 1));
    for (int i = 1; !is_relation(file[i]); i++)
        cnt = store_rooms(file, i, lemin, cnt);
    lemin->rooms_names[cnt] = NULL;
    return (lemin);
}

void complete_graph(char **file, char **rooms, int num_rooms, char **graph)
{
    char **split_line;
    int i = num_rooms + 2;
    int x = 0;
    int y = 0;

    for (; !is_relation(file[i]); i++);
    for (; file[i] && is_relation(file[i]); i++) {
        split_line = my_split(file[i], '-');
        for (int j = 0; rooms[j]; j++)
            (my_strcmp(split_line[0], rooms[j]) == 0) ? x = j : 0;
        for (int j = 0; rooms[j]; j++) {
            (my_strcmp(split_line[1], rooms[j]) == 0) ? y = j : 0;
        }
        graph[x][y] = '1';
        graph[y][x] = '1';
    }
}

t_lemin *parser(char **file)
{
    t_lemin *lemin = malloc(sizeof(t_lemin));

    print_file(file);
    lemin = read_file(file, lemin);
    lemin->graph = malloc(sizeof(char *) * (lemin->num_rooms + 1));

    for (int i = 0; i < lemin->num_rooms; i++) {
        lemin->graph[i] = malloc(sizeof(char) * (lemin->num_rooms + 1));
        for (int j = 0; j < lemin->num_rooms; j++)
            lemin->graph[i][j] = '0';
        lemin->graph[i][lemin->num_rooms] = '\0';
    }
    lemin->graph[lemin->num_rooms] = NULL;
    complete_graph(file, lemin->rooms_names, lemin->num_rooms, lemin->graph);
    return (lemin);
}
