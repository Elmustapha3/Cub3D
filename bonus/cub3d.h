/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eej-jama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 16:41:47 by maneddam          #+#    #+#             */
/*   Updated: 2023/09/04 17:44:20 by eej-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../get_next_line/get_next_line.h"
# include "mlx.h"
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define PURPLE "\e[35m"
# define RESET "\n\033[0m"
# define GREEN "\033[0;32m"
# define RED "\033[0;31m"

# define SPACE 0x2BE3E8
# define WALL 0x1300C3F
# define PLAYER 0x2CA0F6

# define ESC 65307
# define W 119
# define D 100
# define A 97
# define S 115
# define RIGHT 65363
# define LEFT 65361
# define UP 126
# define DOWN 125
# define SPEED 5
# define WIN_H 700
# define WIN_W 1300
# define SQUARE_SIZE 60
# define MAP_PRCNT 0.2

typedef struct s_point
{
	double			x;
	double			y;
}					t_point;

typedef struct s_player
{
	double			x_position;
	double			y_position;
	int				x_start_pos;
	int				y_start_pos;
	double			x_p_minimap;
	double			y_p_minimap;
	char			direction;
	double			p_angle;
}					t_player;

typedef struct s_mlx_data
{
	void			*mlx_ptr;
	void			*wind_ptr;
	void			*img_ptr;
	char			**map2d;

	struct s_infos	*inf;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	char			*addr;

}					t_mlx_data;

typedef struct s_texts
{
	void			*mlx_ptr;
	void			*img_ptr;
	int				width;
	int				height;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	char			*addr;
}					t_texts;

typedef struct s_infos
{
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	int				*f;
	int				*c;
	char			*infos_arr[6];
	char			*infos_arr_tmp[6];
	int				parameters;
	int				map_start_index;
	char			**map2d;
	char			**tmp_1;
	char			*map1d;
	int				y_len;
	int				max_len;
	int				index_max_len;
	double			percent_h_mini;
	double			percent_v_mini;
	int				s;
	t_player		p;
	t_texts			txts[4];
	t_point			m_h;
	t_point			m_v;
	t_point			m_minimap;
}					t_infos;

void				check_arg(char *mapPath);
int					close_wind(void *param);
void				check_attr(char *readline, t_infos *infos, int i);
void				check_map_items(char **map2d);
void				print_error(char *msg);
void				get_minimap_ray(t_mlx_data *m, int i, double alpha);
void				parsing(char *argv, t_infos *infos);
char				*get_next_line(int fd);
char				*ft_strjoin_free(char *s1, char *s2);
char				*ft_strjoin_char(char *s1, char c);
int					ft_strcmp(char *s1, char *s2);
void				get_nord(char *readLine, t_infos *infos, int pos);
void				get_south(char *readLine, t_infos *infos, int pos);
void				get_west(char *readLine, t_infos *infos, int pos);
void				get_east(char *readLine, t_infos *infos, int pos);
void				get_floor(char *readLine, t_infos *infos, int pos);
void				get_ceiling(char *readLine, t_infos *infos, int pos);
bool				is_compound(t_infos *infos);
void				handle_floor_details(char *readLine, t_infos *infos);
void				handle_ceiling_details(char *readLine, t_infos *infos);
void				count_commas(char *readLine);
void				invalid_characters(char *readline);
int					count_words(char *str);
void				invalid_form(char *readLine);
void				handle_map(char *fullmap, t_infos *infos);
void				handle_player(char **map, t_infos *infos);
char				**re_forme_map(char **map2d, t_infos *infos);
void				raycasting(t_infos *inf);
t_player			player_pos(char **table_2d);
bool				is_wall(t_mlx_data *m, double x, double y);
int					rgb_to_hex(int red, int green, int blue);
void				draw_rays(t_mlx_data *m, double beta);
void				circle(t_mlx_data *m, int x, int y, int radius);
void				draw_space(t_mlx_data *m, int x, int y);
void				draw_square(t_mlx_data *m, int x, int y);
void				draw_player(t_mlx_data *m);
void				my_mlx_pixel_put(t_mlx_data *data, int x, int y, int color);
int					get_xpm_pixel(t_mlx_data *data, int x, int y, int i);
int					mouse_hook(int keycode, int x, int y, t_mlx_data *mlx);
int					move(int keycode, t_mlx_data *m);
void				draw_wall(t_mlx_data *m, double wall_heigth, int i,
						double x);
void				draw_line(t_mlx_data *m, double beta);
void				render3d(t_mlx_data *m);
void				display_map(t_mlx_data *m, t_infos *inf);
void				first_v_inters_help(t_mlx_data *m, double alpha);
void				initailize_angle(t_mlx_data *m);
bool				is_wall_for_ray(t_mlx_data *m, double x, double y);

void				get_textures(t_mlx_data *m);
double				first_h_inters(t_mlx_data *m, double alpha);
double				first_v_inters(t_mlx_data *m, double alpha);
double				get_h_dist_to_wall(t_mlx_data *m, double alpha);
double				get_v_dist_to_wall(t_mlx_data *m, double alpha);
void				draw_pixel(t_mlx_data *data, int x, int y, int color);
void				handle_white_spaces(char **map);
bool				is_rest_empty(char *rest);
int					get_y_len(char **map);
int					get_map_start(char *fullmap);
void				is_space(char **map2d, int i, int j);
#endif
