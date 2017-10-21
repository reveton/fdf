#include "../includes/fdf.h"

int main(int ac, char **av)
{
    t_fdf *cord;
    int fd;

    if (!check_arg(ac))
        return (0);
    fd = open(av[1], O_RDONLY);
    fill_struct(&cord);
    if (parse_coords(fd, &cord, 0) == 0)
    {
        write(1, "Map Error\n", 11);
        exit(-1);
    }
    cord->mlx = mlx_init();
    cord->win = mlx_new_window(cord->mlx, WIDTH, HEIGHT, "afomenko");
    generate_new_cords(cord);
    init_first_cam(cord);
    mlx_hook(cord->win, 17, 1L << 17, exit_x, cord);
    mlx_hook(cord->win, 2, 5, key_hook, cord);
    draw(cord);
    mlx_loop(cord->mlx);
}