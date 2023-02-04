/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 15:26:31 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/02/04 18:58:51 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void ft_des_build(t_vars *vars)
{
	if (!(vars -> type))
		ft_mandelbrot(&vars);
	else if (vars -> type == 1)
		ft_julia(&vars);
}

void	increase_m_iter(int keycode, t_vars *vars)
{
	(void)vars;
	if (keycode == 69)
		vars -> m_iter += 10;
	else if (keycode == 78)
		vars -> m_iter -= 10;
	mlx_destroy_image(vars -> mlx, vars -> img.img);
	ft_des_build(vars);
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 53)
		ft_close(keycode, vars);
	else if (keycode == 0)
	{
		vars -> color_t = 1;
		mlx_destroy_image(vars -> mlx, vars -> img.img);
		ft_des_build(vars);
	}
	increase_m_iter(keycode, vars);
	key_arrow(keycode, vars);
	return (0);
}

int	key_arrow(int keycode, t_vars *vars)
{
	(void)vars;
	(void)keycode;

	if (keycode == 123)
		vars -> new_x -= 10;
	else if (keycode == 124)
		vars -> new_x += 10;
	else if (keycode == 125)
		vars -> new_y += 10;
	else if (keycode == 126)
		vars -> new_y -= 10;
	mlx_destroy_image(vars -> mlx, vars -> img.img);
	ft_des_build(vars);
	return (0);	
}

int	mouse_move(int x, int y, t_vars *vars)
{
	(void)vars;
	(void)x;
	(void)y;
	if ((vars -> l_mouse % 2) && 0 < x && x < vars -> width && 0 < y && y < vars -> height)
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
