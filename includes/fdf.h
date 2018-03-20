/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vliubko <vliubko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 13:34:07 by vliubko           #+#    #+#             */
/*   Updated: 2018/03/20 16:07:59 by vliubko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include "../libft/includes/libft.h"
# include "../minilibx_macos/mlx.h"
# include <time.h>

# define WIN_H 1080
# define WIN_W 1920
# define START_X (WIN_W / 2) - 300
# define START_Y 300

# define MALLCHECK(ptr) if (!ptr)	error(ERR_MALLOC)

# define ERR_ARG		"Wrong number of arguments. Usage: ./test maps.fdf"
# define ERR_NO_OPEN	"File error: Failed to open the file."
# define ERR_MAP		"Map error: wrong map."
# define ERR_MALLOC		"Malloc Error."

# define ROT	6 * (M_PI / 180)

typedef struct			s_bres
{
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		err;
	int		e2;
	int		x;
	int		y;
	int		col;
}						t_bres;

typedef struct			s_map
{
	double		x;
	double		y;
	double		z;
	int			col;
}						t_map;

typedef struct			s_mlx
{
	void		*ptr;
	void		*win;
	double		zoom_x;
	double		zoom_y;
	double		center_x;
	double		center_y;
	char		*file;
	char		*win_name;
	int			move_v;
	int			move_h;
	int			map_x;
	int			map_y;
	int			legend;
	t_map		**map;
	t_map		**start;
}						t_mlx;

void					init_mlx(t_mlx *mlx, char *str);
t_map					**parse_file(t_mlx *mlx);
t_map					**fill_map(t_mlx *mlx, int fd);
void					check_valid_file(t_mlx *mlx, int fd);
int						set_z(t_mlx *mlx);
t_map					**dup_map(t_map **old, t_mlx *mlx);
void					error(char *str);
void					free_map(t_map **map, t_mlx *mlx);
void					map_zoom(int key, t_mlx *mlx);
void					center_map(t_mlx *mlx);
void					de_center_map(t_mlx *mlx);
void					set_center(t_mlx *mlx, t_map **start);
void					set_mlx(t_mlx *mlx);
void					key_move(int key, t_mlx *mlx);
void					map_move(t_map **map, t_mlx *mlx);
void					rotate_mlx(t_mlx *mlx, int key);
t_map					rot_matrix(double alpha, double beta,
											double gamma, t_map map);
char					**str_legend(void);
void					draw_keys(int j, t_mlx *mlx);
void					draw_line(t_map first, t_map next, t_mlx *mlx);
int						ft_keys(int key, t_mlx *mlx);
void					draw_map(t_mlx *mlx);
void					draw_legend(t_mlx *mlx);

#endif
