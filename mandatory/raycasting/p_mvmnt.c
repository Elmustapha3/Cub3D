/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_mvmnt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eej-jama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 00:20:23 by eej-jama          #+#    #+#             */
/*   Updated: 2023/09/04 17:46:04 by eej-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	move_w(int keycode, t_mlx_data *m)
{
	if (keycode == W)
	{
		if (is_wall(m, m->inf->p.x_position
				+ (cos(m->inf->p.p_angle * (M_PI / 180)) * (SPEED * 1.5)),
				m->inf->p.y_position
				- (sin(m->inf->p.p_angle * (M_PI / 180)) * (SPEED * 1.5))))
			return (0);
		m->inf->p.y_position -= (sin(m->inf->p.p_angle * (M_PI / 180))
				* (SPEED));
		m->inf->p.x_position += (cos(m->inf->p.p_angle * (M_PI / 180))
				* (SPEED));
		m->inf->p.y_p_minimap -= (sin(m->inf->p.p_angle * (M_PI / 180))
				* (SPEED) * m->inf->percent_h_mini);
		m->inf->p.x_p_minimap += (cos(m->inf->p.p_angle * (M_PI / 180))
				* (SPEED) * m->inf->percent_v_mini);
	}
	return (1);
}

int	move_s(int keycode, t_mlx_data *m)
{
	if (keycode == S)
	{
		if (is_wall(m, m->inf->p.x_position
				- (cos(m->inf->p.p_angle * (M_PI / 180)) * (SPEED * 1.5)),
				m->inf->p.y_position
				+ (sin(m->inf->p.p_angle * (M_PI / 180)) * (SPEED * 1.5))))
			return (0);
		m->inf->p.y_position += (sin(m->inf->p.p_angle * (M_PI / 180))
				* (SPEED));
		m->inf->p.x_position -= (cos(m->inf->p.p_angle * (M_PI / 180))
				* (SPEED));
		m->inf->p.y_p_minimap += (sin(m->inf->p.p_angle * (M_PI / 180))
				* (SPEED) * m->inf->percent_h_mini);
		m->inf->p.x_p_minimap -= (cos(m->inf->p.p_angle * (M_PI / 180))
				* (SPEED) * m->inf->percent_v_mini);
	}
	return (1);
}

int	move_a(int keycode, t_mlx_data *m)
{
	if (keycode == A)
	{
		if (is_wall(m, m->inf->p.x_position
				+ (cos((m->inf->p.p_angle - 270) * (M_PI / 180))
					* (SPEED * 1.5)),
				m->inf->p.y_position
				- (sin((m->inf->p.p_angle - 270) * (M_PI / 180))
					* (SPEED * 1.5))))
			return (0);
		m->inf->p.y_position -= (sin((m->inf->p.p_angle - 270)
					* (M_PI / 180)) * SPEED);
		m->inf->p.x_position += (cos((m->inf->p.p_angle - 270)
					* (M_PI / 180)) * SPEED);
		m->inf->p.y_p_minimap -= (sin((m->inf->p.p_angle - 270) * (M_PI / 180))
				* SPEED * m->inf->percent_h_mini);
		m->inf->p.x_p_minimap += (cos((m->inf->p.p_angle - 270) * (M_PI / 180))
				* SPEED * m->inf->percent_v_mini);
	}
	return (1);
}

int	move_d(int keycode, t_mlx_data *m)
{
	if (keycode == D)
	{
		if (is_wall(m, m->inf->p.x_position
				- (cos((m->inf->p.p_angle + 90) * (M_PI / 180))
					* (SPEED * 1.5)),
				m->inf->p.y_position
				+ (sin((m->inf->p.p_angle + 90) * (M_PI / 180))
					* (SPEED * 1.5))))
			return (0);
		m->inf->p.y_position += (sin((m->inf->p.p_angle + 90)
					* (M_PI / 180)) * SPEED);
		m->inf->p.x_position -= (cos((m->inf->p.p_angle + 90)
					* (M_PI / 180)) * SPEED);
		m->inf->p.y_p_minimap += (sin((m->inf->p.p_angle + 90) * (M_PI / 180))
				* SPEED * m->inf->percent_h_mini);
		m->inf->p.x_p_minimap -= (cos((m->inf->p.p_angle + 90) * (M_PI / 180))
				* SPEED * m->inf->percent_v_mini);
	}
	return (1);
}

int	move(int keycode, t_mlx_data *m)
{
	if (keycode == ESC)
	{
		printf("You closed the game using ESC key !");
		mlx_destroy_window(m->mlx_ptr, m->wind_ptr);
		exit(0);
	}
	if (!move_w(keycode, m) || !move_s(keycode, m)
		|| !move_a(keycode, m) || !move_d(keycode, m))
		return (0);
	if (keycode == LEFT)
		m->inf->p.p_angle += 2;
	if (keycode == RIGHT)
		m->inf->p.p_angle -= 2;
	if (m->inf->p.p_angle > 360)
		m->inf->p.p_angle = 2;
	if (m->inf->p.p_angle < 0)
		m->inf->p.p_angle = 358;
	render3d(m);
	return (0);
}
