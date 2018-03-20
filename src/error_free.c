/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vliubko <vliubko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 14:16:37 by vliubko           #+#    #+#             */
/*   Updated: 2018/03/20 14:45:16 by vliubko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	free_map(t_map **map, t_mlx *mlx)
{
	int		y;

	y = -1;
	while (++y < mlx->map_y)
		free(map[y]);
	free(map);
}

void	error(char *str)
{
	ft_putendl_fd(str, 2);
	exit(1);
}
