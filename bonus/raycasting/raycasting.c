/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eej-jama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 23:30:29 by eej-jama          #+#    #+#             */
/*   Updated: 2023/09/04 18:55:22 by eej-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	initailize_angle(t_mlx_data *m)
{
	if (m->inf->map2d[m->inf->p.y_start_pos][m->inf->p.x_start_pos] == 'N')
		m->inf->p.p_angle = 90.00;
	else if (m->inf->map2d[m->inf->p.y_start_pos][m->inf->p.x_start_pos] == 'S')
		m->inf->p.p_angle = 270.00;
	else if (m->inf->map2d[m->inf->p.y_start_pos][m->inf->p.x_start_pos] == 'E')
		m->inf->p.p_angle = 0.00;
	else if (m->inf->map2d[m->inf->p.y_start_pos][m->inf->p.x_start_pos] == 'W')
		m->inf->p.p_angle = 180.00;
}

void	get_textures_help(t_mlx_data *m, int i)
{
	if (!m->inf->txts[i].img_ptr)
		print_error("xpm corrupted");
	m->inf->txts[i].addr = mlx_get_data_addr(m->inf->txts[i].img_ptr,
			&m->inf->txts[i].bits_per_pixel, &m->inf->txts[i].line_length,
			&m->inf->txts[i].endian);
}

void	get_textures(t_mlx_data *m)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (i == 0)
			m->inf->txts[i].img_ptr = mlx_xpm_file_to_image(m->mlx_ptr,
					m->inf->no, &m->inf->txts[i].width,
					&m->inf->txts[i].height);
		if (i == 1)
			m->inf->txts[i].img_ptr = mlx_xpm_file_to_image(m->mlx_ptr,
					m->inf->so, &m->inf->txts[i].width,
					&m->inf->txts[i].height);
		if (i == 2)
			m->inf->txts[i].img_ptr = mlx_xpm_file_to_image(m->mlx_ptr,
					m->inf->ea, &m->inf->txts[i].width,
					&m->inf->txts[i].height);
		if (i == 3)
			m->inf->txts[i].img_ptr = mlx_xpm_file_to_image(m->mlx_ptr,
					m->inf->we, &m->inf->txts[i].width,
					&m->inf->txts[i].height);
		get_textures_help(m, i);
		i++;
	}
}

void	initialize_pos(t_mlx_data *mlx)
{
	mlx->inf->percent_h_mini = WIN_H * MAP_PRCNT
		/ (mlx->inf->y_len * SQUARE_SIZE);
	mlx->inf->percent_v_mini = WIN_W * MAP_PRCNT
		/ (mlx->inf->max_len * SQUARE_SIZE);
	mlx->inf->p.x_position = mlx->inf->p.x_start_pos
		* SQUARE_SIZE + SQUARE_SIZE / 2;
	mlx->inf->p.y_position = mlx->inf->p.y_start_pos
		* SQUARE_SIZE + SQUARE_SIZE / 2;
	mlx->inf->p.x_p_minimap = (mlx->inf->p.x_start_pos + 0.5)
		* SQUARE_SIZE * mlx->inf->percent_v_mini;
	mlx->inf->p.y_p_minimap = (mlx->inf->p.y_start_pos + 0.5)
		* SQUARE_SIZE * mlx->inf->percent_h_mini;
}

void	raycasting(t_infos *inf)
{
	t_mlx_data	mlx;

	inf->p = player_pos(inf->map2d);
	mlx.map2d = inf->map2d;
	mlx.inf = inf;
	mlx.mlx_ptr = mlx_init();
	get_textures(&mlx);
	mlx.wind_ptr = mlx_new_window(mlx.mlx_ptr, WIN_W, WIN_H, "cub3d");
	mlx.img_ptr = mlx_new_image(mlx.mlx_ptr, WIN_W, WIN_H);
	mlx.addr = mlx_get_data_addr(mlx.img_ptr, &mlx.bits_per_pixel,
			&mlx.line_length, &mlx.endian);
	initailize_angle(&mlx);
	initialize_pos(&mlx);
	render3d(&mlx);
	display_map(&mlx, inf);
	mlx_hook(mlx.wind_ptr, 2, 1L << 0, move, &mlx);
	mlx_hook(mlx.wind_ptr, 17, 1L << 0, close_wind, &mlx);
	mlx_mouse_hook(mlx.wind_ptr, mouse_hook, &mlx);
	mlx_loop(mlx.mlx_ptr);
}
