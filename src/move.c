/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vliubko <vliubko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 14:31:18 by vliubko           #+#    #+#             */
/*   Updated: 2018/03/20 14:31:30 by vliubko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		map_move(t_map **map, t_mlx *mlx)
{
	int		y;
	int		x;

	y = -1;
	while (++y < mlx->map_y)
	{
		x = -1;
		while (++x < mlx->map_x)
		{
			map[y][x].x += mlx->move_h;
			map[y][x].y += mlx->move_v;
		}
	}
}

void		key_move(int key, t_mlx *mlx)
{
	if (key == 123)
	{
		mlx->move_h = -50;
		mlx->center_x -= 50;
	}
	if (key == 124)
	{
		mlx->move_h = 50;
		mlx->center_x += 50;
	}
	if (key == 125)
	{
		mlx->move_v = 50;
		mlx->center_y += 50;
	}
	if (key == 126)
	{
		mlx->move_v = -50;
		mlx->center_y -= 50;
	}
	map_move(mlx->map, mlx);
}
