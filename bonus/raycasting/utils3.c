/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eej-jama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 05:35:25 by eej-jama          #+#    #+#             */
/*   Updated: 2023/09/04 14:38:05 by eej-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	close_wind(void *param)
{
	(void)param;
	exit(0);
}

int	mouse_hook(int keycode, int x, int y, t_mlx_data *mlx)
{
	(void)x;
	(void)y;
	if (keycode == 4)
		mlx->inf->p.p_angle += 2;
	if (keycode == 5)
		mlx->inf->p.p_angle -= 2;
	if (mlx->inf->p.p_angle > 360)
		mlx->inf->p.p_angle = 2;
	if (mlx->inf->p.p_angle < 0)
		mlx->inf->p.p_angle = 358;
	render3d(mlx);
	display_map(mlx, mlx->inf);
	return (0);
}

void	first_v_inters_help(t_mlx_data *m, double alpha)
{
	if (cos(alpha * (M_PI / 180)) > 0)
	{
		m->inf->m_v.x = floor((m->inf->p.x_position + SQUARE_SIZE)
				/ SQUARE_SIZE) * SQUARE_SIZE;
		m->inf->m_v.y = m->inf->p.y_position - tan(alpha * (M_PI / 180))
			* (m->inf->m_v.x - m->inf->p.x_position);
	}
	else if (cos(alpha * (M_PI / 180)) < 0)
	{
		m->inf->m_v.x = (int)((m->inf->p.x_position)
				/ SQUARE_SIZE)*SQUARE_SIZE - 0.0001;
		m->inf->m_v.y = m->inf->p.y_position - tan(alpha * (M_PI / 180))
			* (m->inf->m_v.x - m->inf->p.x_position);
	}
}
