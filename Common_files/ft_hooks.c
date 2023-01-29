/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 15:26:31 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/01/29 16:51:01 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"


int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 53)
		ft_close(keycode, vars);
	return (0);
}

int	mouse_hook(int keycode, int x, int y, t_vars *a)
{
	t_vars *vars = (t_vars *)a;
	(void)x;
	(void)y;

	if (keycode == 5)
		vars->scale /= .9;
	if (keycode == 4)
		vars->scale *= .9;
	mlx_destroy_image(a->mlx, a->img.img);
	ft_mandelbrot(&vars);
	return (0);
}

int	destroy(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	ft_print_error("Successfully Destroyed", 0);
	return (0);
}

void	ft_close(int keycode, t_vars *vars)
{
	if (keycode == 53)
		mlx_destroy_window(vars->mlx, vars->win);
	ft_print_error("Successfully Destroyed", 0);
}
