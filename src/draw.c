#include "../includes/fdf.h"

void min1(t_fdf **fdf, t_coords *p1)
{
    (*fdf)->d[4] = ((*fdf)->d[1] << 1) - (*fdf)->d[0];
    (*fdf)->d[5] = (*fdf)->d[1] << 1;
    (*fdf)->d[6] = ((*fdf)->d[1] - (*fdf)->d[0]) << 1;
    mlx_pixel_put((*fdf)->mlx, (*fdf)->win,p1->x, p1->y, 0xFFFFFF);
    (*fdf)->d[7] = p1->x + (*fdf)->d[2];
    (*fdf)->d[8] = p1->y;
    (*fdf)->d[9] = 1;
    while ((*fdf)->d[9] <= (*fdf)->d[0])
    {
        if ( (*fdf)->d[4] >0)
        {
            (*fdf)->d[4] += (*fdf)->d[6];
            (*fdf)->d[8] += (*fdf)->d[3];
        }
        else
            (*fdf)->d[4] += (*fdf)->d[5];
        mlx_pixel_put((*fdf)->mlx, (*fdf)->win,(*fdf)->d[7], (*fdf)->d[8], 0xFFFFFF);
        (*fdf)->d[7] += (*fdf)->d[2];
        (*fdf)->d[9]++;
    }
}

void    min2(t_fdf **fdf, t_coords *p1)
{
    (*fdf)->d[4] = ((*fdf)->d[0] << 1) - (*fdf)->d[1];
    (*fdf)->d[5] = (*fdf)->d[0] << 1;
    (*fdf)->d[6] = ((*fdf)->d[0] - (*fdf)->d[1]) << 1;
    mlx_pixel_put((*fdf)->mlx, (*fdf)->win, p1->x, p1->y, 0xFFFFFF);
    (*fdf)->d[8] = p1->y + (*fdf)->d[3];
    (*fdf)->d[7] = p1->x;
    (*fdf)->d[9] = 1;
    while ((*fdf)->d[9] <= (*fdf)->d[1])
    {
        if ((*fdf)->d[4] > 0)
        {
            (*fdf)->d[4] += (*fdf)->d[6];
            (*fdf)->d[7] += (*fdf)->d[2];
        }
        else
            (*fdf)->d[4] += (*fdf)->d[5];
        mlx_pixel_put((*fdf)->mlx, (*fdf)->win, (*fdf)->d[7], (*fdf)->d[8], 0xFFFFFF);
        (*fdf)->d[9]++;
        (*fdf)->d[8] += (*fdf)->d[3];
    }
}

void line(t_coords *p1, t_coords *p2, t_fdf **fdf)
{
    (*fdf)->d[0] = abs(p2->x - p1->x);
    (*fdf)->d[1] = abs(p2->y - p1->y);
    (*fdf)->d[2] = p2->x >= p1->x ? 1 : -1;
    (*fdf)->d[3] = p2->y >= p1->y ? 1 : -1;
    if ((*fdf)->d[1] <= (*fdf)->d[0])
        min1(fdf, p1);
    else
        min2(fdf,p1);
}

void    draw(t_fdf *cord)
{
    int i;
    int count_c;
    int k;

    i = -1;
    info(cord);
    count_c = cord->count_x * cord->count_y;
    k = cord->count_x - 1;
    if (cord->count_x == 1)
        mlx_pixel_put(cord->mlx, cord->win,WIDTH / 2 + cord->cord[0]->x_coords,
                      HEIGHT / 2 + cord->cord[0]->y_coords, 0xFFFFFF);
    while (++i < count_c - 1)
    {
        if (i == k)
            k += cord->count_x;
        else
            calculate_point(cord->cord[i], cord->cord[i + 1], &cord);
    }
    count_c = cord->count_x * cord->count_y;
    i = -1;
    while (++i < count_c - cord->count_x)
        calculate_point(cord->cord[i], cord->cord[i + cord->count_x], &cord);
}