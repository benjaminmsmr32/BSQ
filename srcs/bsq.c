/*
** EPITECH PROJECT, 2020
** bsq
** File description:
** bsq
*/

#include "../include/my_bsq.h"

char **prepare_map(bsq_t *bsq)
{
    int k = 0;

    bsq->map = malloc(sizeof(char *) * (bsq->lines + 2));
    for (int i = 0; i != bsq->lines + 2; i++)
        bsq->map[i] = malloc(sizeof(char) * (bsq->len + 2));
    for (int i = 0; i != bsq->lines; i++) {
        for (int j = 0; j != bsq->len + 1; j++, k++)
            bsq->map[i][j] = bsq->buffer[k];
    }
    return (bsq->map);
}

int **prepare_imap(bsq_t *bsq)
{
    bsq->i_map = malloc(sizeof(int *) * (bsq->lines + 2));
    for (int i = 0; i != bsq->lines + 2; i++)
        bsq->i_map[i] = malloc(sizeof(int) * (bsq->len + 2));
    for (int i = 0; i != bsq->lines; i++) {
        for (int j = 0; j != bsq->len + 1; j++) {
            if (bsq->map[i][j] == '.')
                bsq->i_map[i][j] = 1;
            if (bsq->map[i][j] == 'o')
                bsq->i_map[i][j] = 0;
            if (bsq->map[i][j] == '\n')
                bsq->i_map[i][j] = -1;
        }
    }
    return (bsq->i_map);
}

int prepare_bsq(bsq_t *bsq, size_t size, int fd)
{
    bsq->map = prepare_map(bsq);
    bsq->i_map = prepare_imap(bsq);
    algo(bsq);
    write(1, bsq->buffer, (size - (bsq->l + 1)));
    free_ress(bsq);
    close(fd);
    return (0);
}

int algo(bsq_t *bsq)
{
    int smallest;

    for (int i = 1; i != bsq->lines; i++) {
        for (int j = 1; j != bsq->len + 1; j++) {
            if (bsq->i_map[i][j] > 0) {
                smallest = comp(bsq->i_map[i][j - 1], \
                bsq->i_map[i - 1][j], bsq->i_map[i - 1][j - 1]);
                bsq->i_map[i][j] += smallest;
            }
        }
    }
    find_max_val(bsq);
    return (0);
}

int free_ress(bsq_t *bsq)
{
    for (int i = 0; i != bsq->lines + 2; i++) {
        free(bsq->map[i]);
        free(bsq->i_map[i]);
    }
    free(bsq->map);
    free(bsq->i_map);
    bsq->buffer -= (bsq->l + 1);
    free(bsq->buffer);
    return (0);
}