#ifndef FDF_FDF_H
# define FDF_FDF_H

# include "../miniLibX/mlx.h"
# include <mlx.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include <math.h>
# define HEIGHT 800
# define WIDTH 1600

typedef enum	e_del
{
    FIRST,
    SECOND,
    BOTH
}				t_del;

typedef struct  s_coords
{
    int         x_coords;
    int         y_coords;
    int         cord_z;
    int      x;
    int      y;
}               t_coords;

typedef struct  s_fdf
{
    t_coords **cord;
    int     count_y;
    int     z_len;
    int     count_x;
    void    *mlx;
    void    *win;
    int     scale;
    double  angle[3];
    int         shift_x;
    int         shift_y;
    int     upz;
    int     d[10];
}               t_fdf;


int     parse_coords(int fd ,t_fdf **cords, char *line);
int     count_coord_x(char *line);
void    fill_struct(t_fdf **cord);
void    generate_new_cords(t_fdf *cord);
void    init_first_cam(t_fdf *fdf);
int     check_arg(int ac);
int     exit_x(void *par);
int     key_hook(int keycode, t_fdf *fdf);
void    draw(t_fdf *cord);
void    calculate_point(t_coords *p1, t_coords *p2, t_fdf **fdf);
void    line(t_coords *p1, t_coords *p2, t_fdf **fdf);
double calc_x_p1(t_coords *p1, t_fdf **fdf);
double calc_y_p1(t_coords *p1, t_fdf **fdf);
double calc_x_p2(t_coords *p2, t_fdf **fdf);
double calc_y_p2(t_coords *p2, t_fdf **fdf);
void    info(t_fdf *fdf);
void	ft_close(t_fdf *e);
void    move_figure(int keycode, t_fdf *fdf);
void    rotate_figure(int keycode, t_fdf *fdf);
void    def_parameters(int keycode, t_fdf *fdf);
void    push_other_cords(t_fdf **cord, t_coords *cords);
void    new_cord_z(t_fdf **cord, int c_y, char *arr, int ix);
void    parse_cord(t_fdf **cord, char *line);



#endif