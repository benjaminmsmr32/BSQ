/*
** EPITECH PROJECT, 2020
** algo
** File description:
** algo
*/

#include "../include/my_bsq.h"

int comp(int nb1, int nb2, int nb3)
{
    if (nb1 == 0 || nb2 == 0 || nb3 == 0)
        return (0);
    else {
        if (nb1 == nb2 && nb2 == nb3)
            return (nb1);
        if (nb1 <= nb2 && nb1 <= nb3)
            return (nb1);
        if (nb2 <= nb1 && nb2 <= nb3)
            return (nb2);
        if (nb3 <= nb2 && nb3 <= nb1)
            return (nb3);
    }
    return (0);
}

int replace_x(bsq_t *bsq, int x, int y, int max_val)
{
    int temp_loop = y;
    int temp_x = x - max_val;
    int temp_y = y - max_val;

    for (; x > temp_x; x--) {
        for (; y > temp_y; y--)
            bsq->buffer[y + (x * (bsq->len + 1))] = 'x';
        y = temp_loop;
    }
    return (0);
}

int find_max_val(bsq_t *bsq)
{
    int max_val = 0;
    int x = 0;
    int y = 0;

    for (int i = 0; i != bsq->lines; i++) {
        for (int j = 0; j != bsq->len + 1; j++) {
            if (bsq->i_map[i][j] > max_val) {
                max_val = bsq->i_map[i][j];
                x = i;
                y = j;
            }
        }
    }
    replace_x(bsq, x, y, max_val);
    return (0);
}