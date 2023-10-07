/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eej-jama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 00:57:15 by eej-jama          #+#    #+#             */
/*   Updated: 2023/09/05 09:34:53 by eej-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double	first_v_inters(t_mlx_data *m, double alpha)
{
	first_v_inters_help(m, alpha);
	if (alpha == 90.00)
	{
		m->inf->m_v.x = m->inf->p.x_position;
		m->inf->m_v.y = 0;
		return (INT_MAX);
	}
	if (alpha == 270.000000)
	{
		m->inf->m_v.y = m->inf->y_len * SQUARE_SIZE;
		m->inf->m_v.x = m->inf->p.x_position;
		return (INT_MAX);
	}
	return (sqrt(pow(m->inf->m_v.x - m->inf->p.x_position, 2)
			+ pow(m->inf->m_v.y - m->inf->p.y_position, 2)));
}

void	get_h_dist_to_wall_help(t_mlx_data *m, double alpha)
{
	if (sin(alpha * (M_PI / 180)) > 0 && cos(alpha * (M_PI / 180)) > 0)
	{
		m->inf->m_h.y -= SQUARE_SIZE;
		m->inf->m_h.x += SQUARE_SIZE / tan(alpha * (M_PI / 180));
	}
	else if (sin(alpha * (M_PI / 180)) > 0 && cos(alpha * (M_PI / 180)) < 0)
	{
		m->inf->m_h.y -= SQUARE_SIZE;
		m->inf->m_h.x -= -SQUARE_SIZE / tan(alpha * (M_PI / 180));
	}
	else if (sin(alpha * (M_PI / 180)) < 0 && cos(alpha * (M_PI / 180)) > 0)
	{
		m->inf->m_h.y += SQUARE_SIZE;
		m->inf->m_h.x -= SQUARE_SIZE / tan(alpha * (M_PI / 180));
	}
	else if (sin(alpha * (M_PI / 180)) < 0 && cos(alpha * (M_PI / 180)) < 0)
	{
		m->inf->m_h.y += SQUARE_SIZE;
		m->inf->m_h.x -= SQUARE_SIZE / tan(alpha * (M_PI / 180));
	}
}

double	get_h_dist_to_wall(t_mlx_data *m, double alpha)
{
	if (alpha == 0.00 || alpha == 180.00 || alpha == 360.00)
	{
		m->inf->m_h.y = m->inf->p.y_position;
		m->inf->m_h.x = m->inf->max_len * SQUARE_SIZE;
		return (INT_MAX);
	}
	if (alpha == 90.00)
	{
		m->inf->m_h.y -= SQUARE_SIZE;
		m->inf->m_h.x = m->inf->p.x_position;
	}
	else if (alpha == 270.00)
	{
		m->inf->m_h.y += SQUARE_SIZE;
		m->inf->m_h.x = m->inf->p.x_position;
	}
	else
		get_h_dist_to_wall_help(m, alpha);
	return (sqrt(pow(m->inf->m_h.x - m->inf->p.x_position, 2)
			+ pow(m->inf->m_h.y - m->inf->p.y_position, 2)));
}

void	get_v_dist_to_wall_help(t_mlx_data *m, double alpha)
{
	if (cos(alpha * (M_PI / 180)) > 0 && sin(alpha * (M_PI / 180)) > 0)
	{
		m->inf->m_v.x += SQUARE_SIZE;
		m->inf->m_v.y -= tan(alpha * (M_PI / 180)) * SQUARE_SIZE;
	}
	else if (cos(alpha * (M_PI / 180)) > 0 && sin(alpha * (M_PI / 180)) < 0)
	{
		m->inf->m_v.x += SQUARE_SIZE;
		m->inf->m_v.y -= tan(alpha * (M_PI / 180)) * SQUARE_SIZE;
	}
	else if (cos(alpha * (M_PI / 180)) < 0 && sin(alpha * (M_PI / 180)) > 0)
	{
		m->inf->m_v.x -= SQUARE_SIZE;
		m->inf->m_v.y += tan(alpha * (M_PI / 180)) * SQUARE_SIZE;
	}
	else if (cos(alpha * (M_PI / 180)) < 0 && sin(alpha * (M_PI / 180)) < 0)
	{
		m->inf->m_v.x -= SQUARE_SIZE;
		m->inf->m_v.y += tan(alpha * (M_PI / 180)) * SQUARE_SIZE;
	}
}

double	get_v_dist_to_wall(t_mlx_data *m, double alpha)
{
	if (alpha == 270.00)
	{
		m->inf->m_v.x = m->inf->p.x_position;
		m->inf->m_v.y = m->inf->y_len * SQUARE_SIZE;
		return (INT_MAX);
	}
	if (alpha == 0.00 || alpha == 360.00)
	{
		m->inf->m_v.x += SQUARE_SIZE;
		m->inf->m_v.y = m->inf->p.y_position;
	}
	else
		get_v_dist_to_wall_help(m, alpha);
	return (sqrt(pow(m->inf->m_v.x - m->inf->p.x_position, 2)
			+ pow(m->inf->m_v.y - m->inf->p.y_position, 2)));
}
