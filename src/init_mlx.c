/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vliubko <vliubko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 14:18:37 by vliubko           #+#    #+#             */
/*   Updated: 2018/03/20 14:43:51 by vliubko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		set_center(t_mlx *mlx, t_map **start)
{
	int		key;
	int		i;

	mlx->center_x = (start[0][mlx->map_x - 1].x - start[0][0].x) / 2
																+ start[0][0].x;
	mlx->center_y = (start[mlx->map_y - 1][0].y - start[0][0].y) / 2
																+ start[0][0].y;
	key = 12;
	i = -1;
	while (++i < 8)
		rotate_mlx(mlx, key);
	key = 13;
	i = -1;
	while (++i < 3)
		rotate_mlx(mlx, key);
	i = -1;
	key = 2;
	while (++i < 3)
		rotate_mlx(mlx, key);
}

void		set_mlx(t_mlx *mlx)
{
	mlx->move_h = 0;
	mlx->move_v = 0;
	mlx->legend = 0;
}

void		init_mlx(t_mlx *mlx, char *str)
{
	mlx->win_name = ft_strjoin("FdF - ", str);
	mlx->ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->ptr, WIN_W, WIN_H, mlx->win_name);
	mlx->map_x = 0;
	mlx->map_y = 0;
	mlx->map = NULL;
	mlx->start = NULL;
	set_mlx(mlx);
}
