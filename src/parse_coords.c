#include "../includes/fdf.h"

void    push_other_cords(t_fdf **cord, t_coords *cords)
{
    t_coords    **arr;
    t_fdf       *tmp;
    int         i;
    int         size;

    tmp = *cord;
    size = 1;
    arr = (t_coords**)malloc(sizeof(t_coords) * tmp->z_len + size);
    i = 0;
    while (i < tmp->z_len)
    {
        arr[i] = tmp->cord[i];
        i++;
    }
    i = 0;
    while (i < size)
    {
        arr[i + tmp->z_len] = cords;
        i++;
    }
    tmp->z_len += size;
    tmp->cord = arr;
}

void    new_cord_z(t_fdf **cord, int c_y, char *arr, int ix)
{
    t_coords *cords;

    cords = (t_coords*)malloc(sizeof(t_coords));
    cords->y_coords = c_y;
    cords->x_coords = ix;
    cords->cord_z = (int)ft_atoi(arr);
    push_other_cords(cord, cords);
}

void    parse_cord(t_fdf **cord, char *line)
{
    t_fdf    *tmp;
    int         ix;
    char        **str;
    int         c_y;
    int         i;

    tmp = *cord;
    tmp->count_x = count_coord_x(line);
    str = ft_strsplit(line, ' ');
    tmp->count_y++;
    c_y = tmp->count_y;
    i = 0;
    ix = 0;
    while (str[i])
    {
        new_cord_z(&tmp, c_y, str[i], (ix++) + 1);
        i++;
    }
}

int     count_coord_x(char *line)
{
    char        **str;
    int         i;

    i = 0;
    str = ft_strsplit(line, ' ');
    while (str[i])
        i++;
    return (i);
}


int     parse_coords(int fd ,t_fdf **cords, char *line)
{
    while (get_next_line(fd, &line) && line)
    {
        parse_cord(cords, line);
    }
    if (line == NULL)
        return (0);
    return (1);
}