/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vliubko <vliubko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 14:18:37 by vliubko           #+#    #+#             */
/*   Updated: 2018/03/20 14:29:56 by vliubko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		rotate_mlx(t_mlx *mlx, int key)
{
	int		y;
	int		x;
	double	rot;

	center_map(mlx);
	rot = ROT;
	if (key == 0 || key == 1 || key == 2)
		rot *= -1;
	y = 0;
	while (y < mlx->map_y)
	{
		x = 0;
		while (x < mlx->map_x)
		{
			if (key == 12 || key == 0)
				mlx->map[y][x] = rot_matrix(rot, 0, 0, mlx->map[y][x]);
			else if (key == 13 || key == 1)
				mlx->map[y][x] = rot_matrix(0, rot, 0, mlx->map[y][x]);
			else if (key == 14 || key == 2)
				mlx->map[y][x] = rot_matrix(0, 0, rot, mlx->map[y][x]);
			x++;
		}
		y++;
	}
	de_center_map(mlx);
}

t_map		rot_matrix(double alpha, double beta, double gamma, t_map map)
{
	double	mat[3][3];
	t_map	ret;

	mat[0][0] = cos(beta) * cos(gamma);
	mat[1][0] = cos(gamma) * sin(alpha) * sin(beta) - cos(alpha) * sin(gamma);
	mat[2][0] = cos(alpha) * cos(gamma) * sin(beta) + sin(alpha) * sin(gamma);
	mat[0][1] = cos(beta) * sin(gamma);
	mat[1][1] = cos(alpha) * cos(gamma) + sin(alpha) * sin(beta) * sin(gamma);
	mat[2][1] = -cos(gamma) * sin(alpha) + cos(alpha) * sin(beta) * sin(gamma);
	mat[0][2] = -sin(beta);
	mat[1][2] = cos(beta) * sin(alpha);
	mat[2][2] = cos(alpha) * cos(beta);
	ret.x = (mat[0][0] * map.x) + (mat[1][0] * map.y) +
			(mat[2][0] * map.z);
	ret.y = (mat[0][1] * map.x) + (mat[1][1] * map.y) +
			(mat[2][1] * map.z);
	ret.z = (mat[0][2] * map.x) + (mat[1][2] * map.y) +
			(mat[2][2] * map.z);
	ret.col = map.col;
	return (ret);
}
