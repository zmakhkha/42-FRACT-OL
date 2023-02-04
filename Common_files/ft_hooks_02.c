/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks_02.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 23:04:12 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/02/04 23:05:50 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	mouse_move(int x, int y, t_vars *vars)
{
	(void)vars;
	(void)x;
	(void)y;
	if ((vars -> l_mouse % 2) && 0 < x && x \
	< vars -> width && 0 < y && y < vars -> height)
	{
		vars -> j_a = x * vars ->x_scale;
		vars -> j_b = y * vars ->y_scale;
	}
	ft_des_build(vars);
	return (0);
}

int	mouse_hook(int keycode, int x, int y, t_vars *vars)
{
	if (keycode == L_MOUSECLK)
		vars -> l_mouse ++;
	if (keycode == ON_MOUSEUP)
	{
		vars -> tr_x = vars -> tr_x + (x * vars ->x_scale);
		vars -> tr_y = vars -> tr_y + (y * vars ->y_scale);
		vars -> x_scale /= 0.5;
		vars -> y_scale /= 0.5;
		vars->m_iter -= 20;
	}
	if (keycode == 4)
	{
		vars -> x_scale *= 0.5;
		vars -> y_scale *= 0.5;
		vars -> tr_x = vars -> tr_x - (x * vars ->x_scale);
		vars -> tr_y = vars -> tr_y - (y * vars ->y_scale);
		vars->m_iter += 20;
	}
	mlx_destroy_image(vars -> mlx, vars -> img.img);
	if (!(vars -> type))
		ft_mandelbrot(&vars);
	else if (vars -> type == 1)
		ft_julia(&vars);
	return (0);
}
