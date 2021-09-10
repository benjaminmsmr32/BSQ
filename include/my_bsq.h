/*
** EPITECH PROJECT, 2020
** my_bsq
** File description:
** my_bsq
*/

#ifndef MY_BSQ_H
#define MY_BSQ_H

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

typedef struct bsq_s
{
    char *buffer;
    char **map;
    int **i_map;
    int len;
    int lines;
    int l;
    int nbr_lines;
    int count_lines;
} bsq_t;

int prepare_bsq(bsq_t *, size_t, int);
int free_ress(bsq_t *);
int algo(bsq_t *);
int comp(int, int, int);
int find_max_val(bsq_t *);
int map_handling(bsq_t *, size_t, int);

#endif