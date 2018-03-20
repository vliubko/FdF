/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vliubko <vliubko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 14:27:16 by vliubko           #+#    #+#             */
/*   Updated: 2018/03/20 14:41:07 by vliubko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	reset_draw(t_mlx *mlx)
{
	int		x;
	int		y;

	set_mlx(mlx);
	y = -1;
	while (++y < mlx->map_y)
	{
		x = -1;
		while (++x < mlx->map_x)
		{
			mlx->map[y][x] = mlx->start[y][x];
		}
	}
	set_center(mlx, mlx->start);
}

void	reset_steps(t_mlx *mlx)
{
	mlx->move_h = 0;
	mlx->move_v = 0;
}

int		ft_keys(int key, t_mlx *mlx)
{
	if (key == 53)
	{
		(mlx->map) ? free_map(mlx->map, mlx) : 0;
		(mlx->start) ? free_map(mlx->start, mlx) : 0;
		(mlx->win_name) ? ft_strdel(&mlx->win_name) : 0;
		(mlx->file) ? ft_strdel(&mlx->file) : 0;
		exit(0);
	}
	if (key == 48)
	{
		if (mlx->legend == 0)
			mlx->legend = 1;
		else
			mlx->legend = 0;
	}
	(key == 123 || key == 124 || key == 125 || key == 126) ?
											key_move(key, mlx) : 0;
	(key == 7 || key == 6) ? map_zoom(key, mlx) : 0;
	(key == 36 || key == 15) ? reset_draw(mlx) : 0;
	(key == 12 || key == 0 || key == 13 || key == 1 ||
					key == 14 || key == 2) ? rotate_mlx(mlx, key) : 0;
	draw_map(mlx);
	reset_steps(mlx);
	return (0);
}
