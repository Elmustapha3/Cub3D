/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eej-jama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 00:14:58 by eej-jama          #+#    #+#             */
/*   Updated: 2023/09/04 20:09:42 by eej-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	first_h_inters_help(t_mlx_data *m, double alpha)
{
	if (sin(alpha * (M_PI / 180)) > 0)
	{
		m->inf->m_h.y = (int)(m->inf->p.y_position
				/ SQUARE_SIZE) * SQUARE_SIZE - 0.0001;
		m->inf->m_h.x = m->inf->p.x_position
			+ (m->inf->p.y_position - m->inf->m_h.y)
			/ tan(alpha * (M_PI / 180));
	}
	else if (sin(alpha * (M_PI / 180)) < 0)
	{
		m->inf->m_h.y = (int)((m->inf->p.y_position + SQUARE_SIZE)
				/ SQUARE_SIZE) *SQUARE_SIZE;
		m->inf->m_h.x = m->inf->p.x_position
			+ (m->inf->p.y_position - m->inf->m_h.y)
			/ tan(alpha * (M_PI / 180));
	}
}

double	first_h_inters(t_mlx_data *m, double alpha)
{
	first_h_inters_help(m, alpha);
	if (alpha == 180.00)
	{
		m->inf->m_h.y = m->inf->p.y_position;
		m->inf->m_h.x = 0.0;
		return (INT_MAX);
	}
	if (alpha == 0.00 || alpha == 360.00)
	{
		m->inf->m_h.y = m->inf->p.y_position;
		m->inf->m_h.x = m->inf->max_len * SQUARE_SIZE;
		return (INT_MAX);
	}
	return (sqrt(pow(m->inf->m_h.x - m->inf->p.x_position, 2)
			+ pow(m->inf->m_h.y - m->inf->p.y_position, 2)));
}

void	get_minimap_ray(t_mlx_data *m, int i, double alpha)
{
	m->inf->m_minimap.x = m->inf->p.x_p_minimap
		+ (cos(alpha * (M_PI / 180)) * i);
	m->inf->m_minimap.y = m->inf->p.y_p_minimap
		- (sin(alpha * (M_PI / 180)) * i);
}

int	get_xpm_pixel(t_mlx_data *data, int x, int y, int i)
{
	char	*dst;

	if (y > data->inf->txts[i].height)
		return (0);
	dst = data->inf->txts[i].addr
		+ (y * data->inf->txts[i].line_length
			+ x * (data->inf->txts[i].bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

int	rgb_to_hex(int red, int green, int blue)
{
	return ((red << 16) | (green << 8) | blue);
}
