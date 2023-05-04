/*
** EPITECH PROJECT, 2022
** dante
** File description:
** Generator algorithm for mazes
*/

#include "../includes/my.h"
#include "../includes/lemin.h"

bool is_comment(char *line)
{
    return line[0] == '#' && (line[1] != '#' ||
    (my_strcmp(line, "##start") != 0 && my_strcmp(line, "##end") != 0));
}

void print_file_without_comments(char *line)
{
    bool printed_content = false;

    for (int i = 0; line[i]; i++) {
        if (line[i] == '#' && my_strcmp(line, "##start") != 0 &&
            my_strcmp(line, "##end") != 0) {
            break;
        }
        my_putchar(line[i]);
        printed_content = true;
    }
    if (printed_content) {
        my_putchar('\n');
    }
}

void print_file(char **file)
{
    int passes = 0;

    my_putstr("#number_of_ants\n");
    for (int i = 0; file[i]; i++) {
        if (is_comment(file[i])) {
            continue;
        }
        if ((my_strcmp(file[i], "##start") == 0 ||
        !is_relation(file[i])) && passes == 0 && i != 0) {
            my_putstr("#rooms\n");
            passes++;
        }
        if (is_relation(file[i]) && passes == 1) {
            my_putstr("#tunnels\n");
            passes++;
        }
        print_file_without_comments(file[i]);
    }
    my_putstr("#moves\n");
}
