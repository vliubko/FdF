/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vliubko <vliubko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 14:10:31 by vliubko           #+#    #+#             */
/*   Updated: 2018/03/20 15:43:56 by vliubko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		center_map(t_mlx *mlx)
{
	int y;
	int x;

	y = -1;
	while (++y < mlx->map_y)
	{
		x = -1;
		while (++x < mlx->map_x)
		{
			mlx->map[y][x].x -= mlx->center_x;
			mlx->map[y][x].y -= mlx->center_y;
		}
	}
}

void		de_center_map(t_mlx *mlx)
{
	int y;
	int x;

	y = -1;
	while (++y < mlx->map_y)
	{
		x = -1;
		while (++x < mlx->map_x)
		{
			mlx->map[y][x].x += mlx->center_x;
			mlx->map[y][x].y += mlx->center_y;
		}
	}
}

void		map_zoom(int key, t_mlx *mlx)
{
	double	zoom;
	int		y;
	int		x;

	zoom = (key == 6) ? 1.1 : 0.9;
	center_map(mlx);
	y = -1;
	while (++y < mlx->map_y)
	{
		x = -1;
		while (++x < mlx->map_x)
		{
			mlx->map[y][x].x *= zoom;
			mlx->map[y][x].y *= zoom;
			mlx->map[y][x].z *= zoom;
		}
	}
	de_center_map(mlx);
}
