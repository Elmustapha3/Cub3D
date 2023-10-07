/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_3d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eej-jama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 22:14:21 by eej-jama          #+#    #+#             */
/*   Updated: 2023/09/04 21:53:30 by eej-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_wall(t_mlx_data *m, double wall_heigth, int i, double img_x)
{
	double	inc;
	double	d;
	double	c;
	double	y;
	double	x;

	d = WIN_H / 2 - wall_heigth / 2;
	x = m->inf->txts[i].width * (img_x / SQUARE_SIZE
			- (int)(img_x / SQUARE_SIZE));
	c = m->inf->txts[i].height / wall_heigth;
	y = 0;
	inc = 0;
	while (inc < wall_heigth)
	{
		my_mlx_pixel_put(m, m->inf->s, d++, get_xpm_pixel(m, x, y, i));
		y += c;
		inc++;
	}
}

void	draw_line_help(t_mlx_data *m, double alpha,
	double h_distance, double v_distance)
{
	double	wall_height;

	if (h_distance < v_distance)
	{
		wall_height = (WIN_W * SQUARE_SIZE)
			/ (2 * tan(30 * (M_PI / 180)) * h_distance
				* cos((alpha - m->inf->p.p_angle) * (M_PI / 180)));
		if (sin(alpha * (M_PI / 180)) > 0)
			draw_wall(m, wall_height, 1, m->inf->m_h.x);
		else
			draw_wall(m, wall_height, 0, m->inf->m_h.x);
	}
	else
	{
		wall_height = (WIN_W * SQUARE_SIZE)
			/ (2 * tan(30 * (M_PI / 180)) * v_distance
				* cos((alpha - m->inf->p.p_angle) * (M_PI / 180)));
		if (cos(alpha * (M_PI / 180)) > 0)
			draw_wall(m, wall_height, 3, m->inf->m_v.y);
		else
			draw_wall(m, wall_height, 2, m->inf->m_v.y);
	}
}

void	draw_line(t_mlx_data *m, double alpha)
{
	double	h_distance;
	double	v_distance;

	h_distance = first_h_inters(m, alpha);
	v_distance = first_v_inters(m, alpha);
	while (!is_wall_for_ray(m, m->inf->m_h.x, m->inf->m_h.y))
	{
		h_distance = get_h_dist_to_wall(m, alpha);
	}
	while (!is_wall_for_ray(m, m->inf->m_v.x, m->inf->m_v.y))
	{
		v_distance = get_v_dist_to_wall(m, alpha);
	}
	draw_line_help(m, alpha, h_distance, v_distance);
}

void	draw_sky_(t_mlx_data *m)
{
	int		i;
	int		j;

	i = 0;
	while (i < WIN_H)
	{
		j = 0;
		while (j < WIN_W)
		{
			if (i > WIN_H / 2)
				my_mlx_pixel_put(m, j, i,
					rgb_to_hex(m->inf->f[0], m->inf->f[1], m->inf->f[2]));
			else
				my_mlx_pixel_put(m, j, i,
					rgb_to_hex(m->inf->c[0], m->inf->c[1], m->inf->c[2]));
			j++;
		}
		i++;
	}
}

void	render3d(t_mlx_data *m)
{
	double	alpha;

	mlx_destroy_image(m->mlx_ptr, m->img_ptr);
	m->img_ptr = mlx_new_image(m->mlx_ptr, WIN_W, WIN_H);
	m->addr = mlx_get_data_addr(m->img_ptr, &m->bits_per_pixel,
			&m->line_length, &m->endian);
	draw_sky_(m);
	m->inf->s = WIN_W - 1;
	alpha = m->inf->p.p_angle - 30;
	while (m->inf->s >= 0)
	{
		draw_line(m, alpha);
		alpha += (double)(60) / (double)WIN_W;
		m->inf->s--;
	}
	mlx_put_image_to_window(m->mlx_ptr, m->wind_ptr, m->img_ptr, 0, 0);
}
