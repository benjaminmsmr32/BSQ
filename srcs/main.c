/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include "../include/my_bsq.h"

void count_val(bsq_t *bsq)
{
    int i = 0;

    bsq->lines = 0;
    for (; bsq->buffer[i] != '\n'; i++);
    bsq->len = i;
    i = 0;
    for (; bsq->buffer[i] != '\0'; i++)
        if (bsq->buffer[i] == '\n')
            bsq->lines++;
    return;
}

char *move_pointer(bsq_t *bsq)
{
    bsq->l = 0;
    bsq->nbr_lines = 0;
    for (int i = 0; bsq->buffer[i] != '\n'; i++) {
        bsq->nbr_lines *= 10;
        bsq->nbr_lines += bsq->buffer[i] - '0';
    }
    for (; bsq->buffer[bsq->l] != '\n'; bsq->l++);
    return (bsq->buffer += (bsq->l + 1));
}

int error_hdl(bsq_t *bsq)
{
    int count_len = 0;
    int i = 0;

    for (; bsq->buffer[i]; i++) {
        count_len++;
        if (bsq->buffer[i] != '.' && bsq->buffer[i] != 'o' && \
            bsq->buffer[i] != '\n' && bsq->buffer[i] != '\0')
            return (84);
        if (bsq->buffer[i] == '\n') {
            bsq->count_lines++;
            if (count_len != (bsq->len + 1))
                return (84);
            count_len = 0;
        }
    }
    if (bsq->buffer[i] == '\0')
        if (bsq->count_lines != bsq->nbr_lines)
            return (84);
    return (0);
}

int open_file(char *filepath, bsq_t *bsq)
{
    struct stat s;
    int fd;
    size_t size;

    fd = open(filepath, O_RDONLY);
    if (fd <= 0)
        return (84);
    stat(filepath, &s);
    size = s.st_size;
    if (map_handling(bsq, size, fd) == 84)
        return (84);
    if (bsq->buffer == NULL)
        return (84);
    bsq->buffer[size] = '\0';
    bsq->buffer = move_pointer(bsq);
    count_val(bsq);
    if (error_hdl(bsq) == 84)
        return (84);
    prepare_bsq(bsq, size, fd);
    return (0);
}

int main(int ac, char **av)
{
    bsq_t bsq;

    if (ac != 2)
        return (84);
    if (open_file(av[1], &bsq) == 84)
        return (84);
    return (0);
}
