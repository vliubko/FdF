/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_legend.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vliubko <vliubko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 15:03:05 by vliubko           #+#    #+#             */
/*   Updated: 2018/03/20 15:42:28 by vliubko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	write_control(t_mlx *mlx, char **s)
{
	mlx_string_put(mlx->ptr, mlx->win, 100, 10, 0xffc40d, s[0]);
	mlx_string_put(mlx->ptr, mlx->win, 160, 10, 0xffc40d, s[1]);
	mlx_string_put(mlx->ptr, mlx->win, 50, 60, 0xFFFFFF, s[2]);
	mlx_string_put(mlx->ptr, mlx->win, 120, 60, 0xFFFFFF, s[19]);
	mlx_string_put(mlx->ptr, mlx->win, 45, 90, 0xFFFFFF, s[3]);
	mlx_string_put(mlx->ptr, mlx->win, 100, 90, 0xFFFFFF, s[20]);
	mlx_string_put(mlx->ptr, mlx->win, 106, 120, 0xffc40d, s[4]);
	mlx_string_put(mlx->ptr, mlx->win, 100, 270, 0xffc40d, s[5]);
	mlx_string_put(mlx->ptr, mlx->win, 106, 420, 0xffc40d, s[6]);
	mlx_string_put(mlx->ptr, mlx->win, 50, 210, 0xFFFFFF, s[7]);
	mlx_string_put(mlx->ptr, mlx->win, 172, 210, 0xFFFFFF, s[8]);
	mlx_string_put(mlx->ptr, mlx->win, 115, 160, 0xFFFFFF, s[9]);
	mlx_string_put(mlx->ptr, mlx->win, 106, 210, 0xFFFFFF, s[10]);
	mlx_string_put(mlx->ptr, mlx->win, 61, 312, 0xFFFFFF, s[11]);
	mlx_string_put(mlx->ptr, mlx->win, 61, 360, 0xFFFFFF, s[12]);
	mlx_string_put(mlx->ptr, mlx->win, 120, 312, 0xFFFFFF, s[13]);
	mlx_string_put(mlx->ptr, mlx->win, 120, 360, 0xFFFFFF, s[14]);
	mlx_string_put(mlx->ptr, mlx->win, 181, 312, 0xFFFFFF, s[15]);
	mlx_string_put(mlx->ptr, mlx->win, 181, 360, 0xFFFFFF, s[16]);
	mlx_string_put(mlx->ptr, mlx->win, 61, 460, 0xFFFFFF, s[17]);
	mlx_string_put(mlx->ptr, mlx->win, 120, 460, 0xFFFFFF, s[18]);
}

void	draw_legend(t_mlx *mlx)
{
	int		y;
	int		x;
	char	**s;
	int		j;

	j = 0;
	y = -1;
	while (++y < WIN_H)
	{
		x = -1;
		while (++x < 300)
			mlx_pixel_put(mlx->ptr, mlx->win, x, y, 0x008299);
	}
	s = str_legend();
	while (j < 401)
	{
		draw_keys(j, mlx);
		j += 100;
	}
	write_control(mlx, s);
	mlx->legend = 0;
	ft_free_2d_array(s);
}
