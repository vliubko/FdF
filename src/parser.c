/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vliubko <vliubko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 13:13:16 by vliubko           #+#    #+#             */
/*   Updated: 2018/03/20 14:31:02 by vliubko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_map		**dup_map(t_map **old, t_mlx *mx)
{
	t_map	**map;
	int		x;
	int		y;

	MALLCHECK((map = (t_map**)malloc(sizeof(t_map) * (mx->map_y * mx->map_x))));
	y = -1;
	while (++y < mx->map_y)
	{
		x = -1;
		MALLCHECK((map[y] = (t_map*)malloc(sizeof(t_map) * mx->map_x)));
		while (++x < mx->map_x)
		{
			map[y][x].x = old[y][x].x;
			map[y][x].y = old[y][x].y;
			map[y][x].z = old[y][x].z;
			map[y][x].col = old[y][x].col;
		}
	}
	return (map);
}

void		check_valid_file(t_mlx *mlx, int fd)
{
	char *line;
	char **splitted;

	while (get_next_line(fd, &line))
	{
		splitted = ft_strsplit(line, ' ');
		ft_strdel(&line);
		(mlx->map_x == 0) ? mlx->map_x = ft_count_elems(0, splitted, 2) : 0;
		if (mlx->map_x != ft_count_elems(0, splitted, 2))
			error(ERR_MAP);
		ft_free_2d_array(splitted);
		mlx->map_y++;
	}
	close(fd);
	mlx->zoom_x = 800 / mlx->map_x;
	mlx->zoom_y = 600 / mlx->map_y;
}

int			set_z(t_mlx *mlx)
{
	if (mlx->map_x * mlx->map_y > 1000)
		return (2);
	return (5);
}

t_map		**fill_map(t_mlx *mx, int fd)
{
	char	*line;
	char	**splitted;
	t_map	**map;
	int		x;
	int		y;

	MALLCHECK((map = (t_map**)malloc(sizeof(t_map) * (mx->map_y * mx->map_x))));
	fd = open(mx->file, O_RDONLY);
	y = -1;
	while (get_next_line(fd, &line) && ++y < mx->map_y)
	{
		splitted = ft_strsplit(line, ' ');
		ft_strdel(&line);
		x = -1;
		MALLCHECK((map[y] = (t_map*)malloc(sizeof(t_map) * mx->map_x)));
		while (++x < mx->map_x && splitted[x])
		{
			map[y][x].x = (x == 0) ? START_X : map[y][x - 1].x + mx->zoom_x;
			map[y][x].y = (y == 0) ? START_Y : map[y - 1][x].y + mx->zoom_y;
			map[y][x].z = ft_atoi(splitted[x]) * set_z(mx);
			map[y][x].col = (map[y][x].z != 0) ? 1 : 0;
		}
		ft_free_2d_array(splitted);
	}
	return (map);
}

t_map		**parse_file(t_mlx *mlx)
{
	int		fd;
	t_map	**map;

	fd = open(mlx->file, O_RDONLY);
	if (read(fd, "", 0) == -1)
		error(ERR_NO_OPEN);
	check_valid_file(mlx, fd);
	map = fill_map(mlx, fd);
	close(fd);
	return (map);
}
