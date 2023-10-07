/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eej-jama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 01:23:30 by eej-jama          #+#    #+#             */
/*   Updated: 2023/09/04 14:38:05 by eej-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_rays(t_mlx_data *m, double alpha)
{
	int	i;
	int	k;
	int	s;

	i = 0;
	while (i < 30 * MAP_PRCNT)
	{
		get_minimap_ray(m, i, alpha);
		k = 0;
		while (k < WIN_H * MAP_PRCNT)
		{
			s = 0;
			if (k == floor(m->inf->m_minimap.y))
			{
				while (s < WIN_W * MAP_PRCNT)
				{
					if (s == floor(m->inf->m_minimap.x))
						my_mlx_pixel_put(m, s, k, 0xFFFFFF);
					s++;
				}
			}
			k++;
		}
		i++;
	}
}

void	draw_player(t_mlx_data *m)
{
	int	k;
	int	s;

	k = 0;
	while (k < WIN_H * MAP_PRCNT)
	{
		s = 0;
		if (k == floor(m->inf->p.y_p_minimap))
		{
			while (s < WIN_W * MAP_PRCNT)
			{
				if (s == floor(m->inf->p.x_p_minimap))
					circle(m, m->inf->p.x_p_minimap,
						m->inf->p.y_p_minimap, 2);
				s++;
			}
		}
		k++;
	}
	draw_rays(m, m->inf->p.p_angle);
}

void	draw_square(t_mlx_data *m, int x, int y)
{
	int	k;
	int	s;

	k = 0;
	while (k < WIN_H * MAP_PRCNT / m->inf->y_len)
	{
		s = 0;
		while (s < WIN_W * MAP_PRCNT / m->inf->max_len)
		{
			my_mlx_pixel_put(m, s + (x * SQUARE_SIZE * m->inf->percent_v_mini),
				k + (y * SQUARE_SIZE * m->inf->percent_h_mini), 0xFFFFFF);
			s++;
		}
		k++;
	}
}

void	draw_space(t_mlx_data *m, int x, int y)
{
	int	k;
	int	s;

	k = 0;
	while (k < WIN_H * MAP_PRCNT / m->inf->y_len)
	{
		s = 0;
		while (s < WIN_W * MAP_PRCNT / m->inf->max_len)
		{
			my_mlx_pixel_put(m, s + (x * SQUARE_SIZE * m->inf->percent_v_mini),
				k + (y * SQUARE_SIZE * m->inf->percent_h_mini), SPACE);
			s++;
		}
		k++;
	}
}

void	display_map(t_mlx_data *m, t_infos *inf)
{
	int		i;
	int		j;

	i = 0;
	while (inf->map2d[i])
	{
		j = 0;
		while (inf->map2d[i][j])
		{
			if (inf->map2d[i][j] == '1' || inf->map2d[i][j] == 32)
				draw_square(m, j, i);
			else
				draw_space(m, j, i);
			j++;
		}
		i++;
	}
	draw_player(m);
	mlx_put_image_to_window(m->mlx_ptr, m->wind_ptr, m->img_ptr, 0, 0);
}
