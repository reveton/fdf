/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_new_cords.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afomenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 22:50:45 by afomenko          #+#    #+#             */
/*   Updated: 2017/10/21 22:50:53 by afomenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	info(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx, fdf->win, 20, 0, 0x00FFFFFF, "---HOT KEYS---");
	mlx_string_put(fdf->mlx, fdf->win, 20, 30, 0x00FFFFFF, "ROTATE (Z):");
	mlx_string_put(fdf->mlx, fdf->win, 140, 30, 0xFFFF00, "Z,X");
	mlx_string_put(fdf->mlx, fdf->win, 20, 60, 0x00FFFFFF, "ROTATE (X):");
	mlx_string_put(fdf->mlx, fdf->win, 140, 60, 0xFFFF00, "A,S");
	mlx_string_put(fdf->mlx, fdf->win, 20, 90, 0x00FFFFFF, "ROTATE (Y):");
	mlx_string_put(fdf->mlx, fdf->win, 140, 90, 0xFFFF00, "Q,W");
	mlx_string_put(fdf->mlx, fdf->win, 20, 120, 0x00FFFFFF, "MOVE:");
	mlx_string_put(fdf->mlx, fdf->win, 80, 120,
			0xFFFF00, "ARROW LEFT,RIGHT,UP,DOWN");
	mlx_string_put(fdf->mlx, fdf->win, 20, 150, 0x00FFFFFF, "ZOOM:");
	mlx_string_put(fdf->mlx, fdf->win, 80, 150, 0xFFFF00, "+ -");
	mlx_string_put(fdf->mlx, fdf->win, 20, 180, 0x00FFFFFF, "QUIT:");
	mlx_string_put(fdf->mlx, fdf->win, 80, 180, 0xFFFF00, "ESC");
	mlx_string_put(fdf->mlx, fdf->win, 20, 210,
			0x00FFFFFF, "RAISE AND DECRASE Z_CORD:");
	mlx_string_put(fdf->mlx, fdf->win, 280, 210, 0xFFFF00, "C,V");
}

void	generate_new_cords(t_fdf *cord)
{
	int	i;
	int	count_c;

	count_c = cord->count_x * cord->count_y;
	i = 0;
	while (count_c)
	{
		cord->cord[i]->x_coords =
			(cord->cord[i]->x_coords - 1) - cord->count_x / 2;
		cord->cord[i]->y_coords =
			(cord->cord[i]->y_coords - 1) - cord->count_y / 2;
		count_c--;
		i++;
	}
}
