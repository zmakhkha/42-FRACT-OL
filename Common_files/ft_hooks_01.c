/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks_01.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 15:26:31 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/02/04 23:05:12 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_des_build(t_vars *vars)
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
	if (keycode == 123)
		vars -> tr_x -= .01;
	else if (keycode == 124)
		vars -> tr_x += .01;
	else if (keycode == 125)
		vars -> tr_y += .01;
	else if (keycode == 126)
		vars -> tr_y -= .01;
	mlx_destroy_image(vars -> mlx, vars -> img.img);
	ft_des_build(vars);
	return (0);
}
