#include "../includes/fdf.h"

void    init_first_cam(t_fdf *fdf)
{
    fdf->scale = 30;
    fdf->angle[2] = 0.45;
    fdf->angle[0] = -0.15;
}

int exit_x(void *par)
{
    par = NULL;
    exit(0);
    return (0);
}

void	ft_close(t_fdf *e)
{
    free(e);
    exit(0);
}

int     check_arg(int ac)
{
    if (ac < 2)
    {
        printf("Please send map to FDF");
        return (0);
    }
    else if (ac >= 3)
    {
        printf("Use only 1 map!");
        return (0);
    }
    return (1);
}

void    fill_struct(t_fdf **cord)
{
    t_fdf *tmp;

    tmp = (t_fdf*)malloc(sizeof(t_fdf));
    tmp->scale = 10;
    tmp->cord = 0;
    tmp->count_y = 0;
    tmp->z_len = 0;
    tmp->angle[0] = 0;
    tmp->shift_x = 0;
    tmp->shift_y = 0;
    tmp->d[0] = 0;
    tmp->mlx = 0;
    tmp->win = 0;
    tmp->upz = 0;
    *cord = tmp;
}