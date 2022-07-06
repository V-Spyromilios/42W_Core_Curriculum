/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espyromi <espyromi@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:47:49 by espyromi          #+#    #+#             */
/*   Updated: 2022/06/29 11:46:24 by espyromi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>

# define UP 119
# define DOWN 115
# define RIGHT 97
# define LEFT 100
# define ESC 65307
# define LARROW 65361
# define RARROW 65363

# define C_WALL		0xFFFFFF
# define C_SPACE	0x000000
# define C_PLAYER	0xFF0000
# define C_RAY_N	0x00FF00
# define C_RAY_E	0x0000FF
# define C_RAY_S	0xFF00FF
# define C_RAY_W	0xFFFF00

# ifndef MAX_FD
#  define MAX_FD 1024
# endif

typedef struct s_key_handle
{
	int	up;
	int	down;
	int	left;
	int	right;
	int	turn_left;
	int	turn_right;
	int	end;
}					t_key_handle;

typedef struct s_player
{
	double	xy[2];
	int		orientation;
}					t_player;

typedef struct s_texture
{
	void	*img;
	int		*data;
	int		bpp;
	int		size_l;
	int		endian;
}					t_texture;

typedef struct s_data
{
	void		*img;
	int			*data;
	void		*img_bg;
	int			*data_bg;
	int			size_l;
	int			bpp;
	int			endian;
	int			tile_size;
	char		*texture_path[4];
	int			c_floor[3];
	int			c_ceil[3];
	t_texture	tex_no;
	t_texture	tex_so;
	t_texture	tex_we;
	t_texture	tex_ea;
	int			texture_h;
	int			texture_w;
	int			is_color;
	int			is_texture;
	int			lines_in_file;
	int			lines_in_map;
	int			line_len;
	int			player;
	int			curr_line;
}					t_data;

typedef struct s_screen
{
	double	height;
	double	width;
	int		wall_height;
	t_data	img;
	int		c_floor;
	int		c_ceil;
	double	*distance;
	char	*worient;
	double	*w_heights;
	double	*w_hits_xy;
}					t_screen;

typedef struct s_window
{
	void			*mlx;
	void			*mlx_win;
	t_data			img;
	t_list			*map;
	int				score;
	int				move_count;
	int				height;
	int				width;
	t_player		player;
	t_key_handle	keys;
	t_screen		screen;
}					t_window;

//	src/main.c
void	create_map(int fd, t_window *mlx);
int		handle_loop(t_window *mlx);
void	start_game(t_window *mlx);

//	src/init.c
void	initialize(t_window *mlx);
void	initialize_with_zeros(t_window *mlx);

//	src/exit_game.c
void	exit_game(t_window *mlx);
void	throw_error(int error_code);

//	src/handle_keys.c
void	move_player(t_window *mlx, double xy[2], double dx, double dy);
int		check_keys(t_window *mlx);
int		handle_key_press(int key, t_window *mlx);
int		handle_key_release(int key, t_window *mlx);

//	src/copy_map.c
void	cpy_map(t_window *mlx);

//	src/draw/calc.c
void	calc_orientation(t_window *mlx, int texxy[2], int i, int j);
double	calc_dist(t_window *mlx, double xy1[2], char *w_orient, \
		double p_orient);

//	src/draw/get_next_point.c
char	get_next_point(t_window *mlx, double xy1[2], \
		double xy2[2], double orient);
char	gnp_special_orientations(t_window *mlx, double xy1[2], \
		double dxy1[2], double orient);
char	gnp_other_dxy(t_window *mlx, double xy1[2], \
		double dxy1[2], double orient);

//	src/draw/help_draw.c
void	draw_line(t_window *mlx, double xy1[2], double xy2[2], int color);
void	draw_rectangle(t_window *mlx, int x, int y, int color);
void	draw_player(t_window *mlx, int color);
void	draw_map_line(t_window *mlx, char *line, int y_row, int x_col);
void	draw_map(t_window *mlx);

//	src/draw/ray_casting.c
int		is_it_wall(t_window *mlx, double xy[2]);
char	cast_till_wall(t_window *mlx, double xy1[2], double orientation);
void	draw_fov(t_window *mlx, double xy1[2], char *wall_orientation);
void	correct_rays(t_window *mlx);
void	ray_cast(t_window *mlx);

//	src/draw/screen_draw.c
void	draw_screen_rectangle(t_window *mlx, int xy1[2], int xy2[2], int color);
void	draw_screen_vertical(t_window *mlx, int x, int distance, int color);
void	draw_texture_on_wall(t_window *mlx, int i);
void	draw_screen(t_window *mlx);

//	src/draw/utils.c
int		to_coord(int width, double x, double y);
void	copy_coord(double from[2], double to[2]);
void	create_coord(int xy[2], int x, int y);
int		sum_neighbours(t_window *mlx, int *data, double xy1[2]);
int		convert_color(int rgb[3]);

//	src/map_check/map_check_handler.c
int		check_line_content(char *line, t_data *data, t_window *mlx);
int		check_game_components(char *line, t_data *data);
int		free_map_arr(int nr_of_lines, char **map_arr);
int		is_map_valid(t_window *mlx, t_data *data, t_list **map);
int		check_fd(int fd);

//	src/map_check/map_check_helper.c
int		free_str(char *str, int ret);
int		is_inner_game_char(char c);
char	**convert_map_to_arr(t_list **map, int total_lines);
int		is_zero_enclosed(char **map_arr, int i, int j);
int		closed_map_check(t_list **map, int total_lines, char **map_arr);

//	src/map_check/map_check.c
int		is_empty_line(char *line);
int		count_lines_in_file(char *file);
int		check_file_extension(char *filename);
int		readin_map(t_list **map, t_data *data, t_window *mlx, char *line);
int		map_check(int fd, t_list **map, t_data *data, t_window *mlx);

//	src/map_check/map_color_helper.c
int		map_color_check(t_data *data, char *line, int color_code);
int		get_floor_rgb_values(t_data *data, char *line);
int		store_floor_rgb_values(t_data *data, char *digit_str, int index);
int		get_ceil_rgb_values(t_data *data, char *str);
int		store_ceil_rgb_values(t_data *data, char *digit_str, int index);

//	src/map_check/map_texture_helper.c
int		read_textures(t_window *mlx, t_data *data);
int		map_tex_check(t_data *data, t_window *mlx, char *line, int tex_code);
int		get_tex_values(t_data *data, char *line, int tex_code);

#endif
