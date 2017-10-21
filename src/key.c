#include "../includes/fdf.h"

void    move_figure(int keycode, t_fdf *fdf)
{
    if (keycode == 124)
        fdf->shift_x += 10;
    if (keycode == 123)
        fdf->shift_x -= 10;
    if (keycode == 126)
        fdf->shift_y -= 10;
    if (keycode == 125)
        fdf->shift_y += 10;
}

void    rotate_figure(int keycode, t_fdf *fdf)
{
    if (keycode == 12)
        fdf->angle[0] += 0.15;
    if (keycode == 13)
        fdf->angle[0] -= 0.15;
    if (keycode == 0)
        fdf->angle[1] += 0.15;
    if (keycode == 1)
        fdf->angle[1] -= 0.15;
    if (keycode == 6)
        fdf->angle[2] += 0.15;
    if (keycode == 7)
        fdf->angle[2] -= 0.15;
}

void    def_parameters(int keycode, t_fdf *fdf)
{
    if (keycode == 49)
    {
        fdf->scale = 10;
        fdf->angle[0] = 0;
        fdf->angle[1] = 0;
        fdf->angle[2] = 0;
        fdf->shift_x = 0;
        fdf->shift_y = 0;
    }
    if (keycode == 8)
        fdf->upz += 10;
    if (keycode == 9)
        fdf->upz -= 10;
}

int key_hook(int keycode, t_fdf *fdf)
{
    if (keycode == 53)
    {
        mlx_destroy_window(fdf->mlx,fdf->win);
        ft_close(fdf);
    }
    if (keycode == 69)
        fdf->scale += 10;
    if (keycode == 78)
        fdf->scale -= 10;
    def_parameters(keycode, fdf);
    move_figure(keycode, fdf);
    rotate_figure(keycode, fdf);
    mlx_clear_window(fdf->mlx,fdf->win);
    draw(fdf);
    return (0);
}
