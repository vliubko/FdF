/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_bresenham.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vliubko <vliubko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 14:20:39 by vliubko           #+#    #+#             */
/*   Updated: 2018/03/20 16:07:12 by vliubko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void				error_step(t_bres *bres, t_map first, t_map next)
{
	bres->x = (int)first.x;
	bres->y = (int)first.y;
	bres->dx = abs((int)next.x - (int)first.x);
	bres->sx = (int)first.x < (int)next.x ? 1 : -1;
	bres->dy = abs((int)next.y - (int)first.y);
	bres->sy = (int)first.y < (int)next.y ? 1 : -1;
	bres->err = (bres->dx > bres->dy ? bres->dx : -bres->dy) / 2;
}

void				draw_line(t_map first, t_map next, t_mlx *mlx)
{
	t_bres	bres;

	error_step(&bres, first, next);
	while (1)
	{
		bres.col = (first.col == 1) ? 0xFF76BC : 0xFFFFFF;
		mlx_pixel_put(mlx->ptr, mlx->win, bres.x, bres.y, bres.col);
		if (bres.x == (int)next.x && bres.y == (int)next.y)
			break ;
		bres.e2 = bres.err;
		if (bres.e2 > -bres.dx)
		{
			bres.err -= bres.dy;
			bres.x += bres.sx;
		}
		if (bres.e2 < bres.dy)
		{
			bres.err += bres.dx;
			bres.y += bres.sy;
		}
	}
}
