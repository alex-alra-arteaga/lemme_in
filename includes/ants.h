/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** Contains the prototypes of all the functions in libmy.a
*/

#include "my.h"

#ifndef ANTS_H_
    #define ANTS_H_

    typedef struct s_ant {
        int index;
        char **path;
        char *current_room;
        int times_moved;
        struct s_ant *next;
    } t_ant;

#endif
