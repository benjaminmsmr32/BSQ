/*
** EPITECH PROJECT, 2020
** map_handling
** File description:
** map_handling
*/

#include "../include/my_bsq.h"

int map_handling(bsq_t *bsq, size_t size, int fd)
{
    int i = 0;
    bsq->buffer = malloc(sizeof(char) * (size + 1));
    read(fd, bsq->buffer, size + 1);
    if (bsq->buffer[0] == '\0' || bsq->buffer[0] == '\n')
        return (84);
    for (; bsq->buffer[i] >= '0' && bsq->buffer[i] <= '9'; i++);
    if (bsq->buffer[i] != '\n' || bsq->buffer[i + 1] == '\0')
        return (84);
    return (0);
}
