/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   legend_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vliubko <vliubko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 14:19:41 by vliubko           #+#    #+#             */
/*   Updated: 2018/03/20 14:39:42 by vliubko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

char		**str_legend(void)
{
	char **av;

	av = ft_strsplit("KEYS USE ESC exit MOVE ROTATE ZOOM <-- \
						--> up down Q A W S E D Z X R reset", ' ');
	return (av);
}

void		draw_keys3(int j, t_mlx *mlx)
{
	int x;
	int y;

	x = 165;
	while (x < 208)
	{
		y = 52 + j;
		while (++y < 92 + j)
			mlx_pixel_put(mlx->ptr, mlx->win, x, y, 0xFFFFFF);
		x += 42;
	}
	y = 52 + j;
	while (y < 93 + j)
	{
		x = 165;
		while (++x < 208)
		{
			mlx_pixel_put(mlx->ptr, mlx->win, x, y, 0xFFFFFF);
		}
		y += 40;
	}
}

void		draw_keys2(int j, t_mlx *mlx)
{
	int x;
	int y;

	x = 105;
	while (x < 148)
	{
		y = 52 + j;
		while (++y < 92 + j)
			mlx_pixel_put(mlx->ptr, mlx->win, x, y, 0xFFFFFF);
		x += 42;
	}
	y = 52 + j;
	while (y < 93 + j)
	{
		x = 105;
		while (++x < 148)
		{
			mlx_pixel_put(mlx->ptr, mlx->win, x, y, 0xFFFFFF);
		}
		y += 40;
	}
}

int			recurs_draw_keys(int j, t_mlx *mlx)
{
	draw_keys(j + 50, mlx);
	if (j != 200)
		draw_keys2(j, mlx);
	draw_keys2(j + 50, mlx);
	draw_keys3(j + 50, mlx);
	if (j != 250)
		return (1);
	return (0);
}

void		draw_keys(int j, t_mlx *mlx)
{
	int		x;
	int		y;

	if (j == 100 || j == 200 || j == 250)
		if (recurs_draw_keys(j, mlx) == 1)
			return ;
	if (j == 0 || j == 400)
		draw_keys2(j, mlx);
	x = 45;
	while (x < 88)
	{
		y = 52 + j;
		while (++y < 92 + j)
			mlx_pixel_put(mlx->ptr, mlx->win, x, y, 0xFFFFFF);
		x += 42;
	}
	y = 52 + j;
	while (y < 93 + j)
	{
		x = 45;
		while (++x < 87)
			mlx_pixel_put(mlx->ptr, mlx->win, x, y, 0xFFFFFF);
		y += 40;
	}
}
