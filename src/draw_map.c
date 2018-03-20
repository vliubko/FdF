/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vliubko <vliubko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 14:45:25 by vliubko           #+#    #+#             */
/*   Updated: 2018/03/20 15:05:00 by vliubko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		draw_map(t_mlx *mlx)
{
	int		y;
	int		x;

	if (mlx->legend == 1)
		draw_legend(mlx);
	else
	{
		mlx_clear_window(mlx->ptr, mlx->win);
		mlx_string_put(mlx->ptr, mlx->win, 50, 30, 0xFFFFFF,
													"(use TAB for MAP INFO)");
	}
	y = -1;
	while (++y < mlx->map_y)
	{
		x = -1;
		while (++x < mlx->map_x)
		{
			if (x + 1 < mlx->map_x)
				draw_line(mlx->map[y][x], mlx->map[y][x + 1], mlx);
			if (y + 1 < mlx->map_y)
				draw_line(mlx->map[y][x], mlx->map[y + 1][x], mlx);
		}
	}
}
