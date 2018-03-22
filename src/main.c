/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vliubko <vliubko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 13:28:27 by vliubko           #+#    #+#             */
/*   Updated: 2018/03/22 14:04:19 by vliubko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		main(int ac, char **av)
{
	t_mlx	mlx;
	t_map	**map;

	if (ac != 2)
		error(ERR_ARG);
	init_mlx(&mlx, av[1]);
	mlx.file = ft_strdup(av[1]);
	map = parse_file(&mlx);
	mlx.map = map;
	mlx.start = dup_map(map, &mlx);
	set_center(&mlx, mlx.map);
	mlx_string_put(mlx.ptr, mlx.win, WIN_W / 2 - 75,
							WIN_H / 2 - 200, 0xffc40d, "Welcome to FdF");
	mlx_string_put(mlx.ptr, mlx.win, WIN_W / 2 - 80,
							WIN_H / 2 - 185, 0xffc40d, "~ ~ ~ ~ ~ ~ ~ ~");
	mlx_string_put(mlx.ptr, mlx.win, WIN_W / 2 - 100,
							WIN_H / 2 - 100, 0x7FFFD4, "PRESS ENTER TO START");
	mlx_hook(mlx.win, 2, 5, ft_keys, (void*)&mlx);
	mlx_loop(mlx.ptr);
	return (95);
}
