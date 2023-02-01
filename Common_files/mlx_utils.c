/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 23:14:37 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/02/01 15:26:11 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	ft_close(int keycode, t_vars *vars)
{
	if (keycode == 53)
		mlx_destroy_window(vars->mlx, vars->win);
	ft_print_error("Successfully Destroyed", 0);
	free (vars);
}

int	destroy(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	ft_print_error("Successfully Destroyed", 0);
	free (vars);
	return (0);
}

void	ft_initiate_window(t_vars *data)
{
	data ->img.img = mlx_new_image(data -> mlx, data -> width, data -> height);
	data ->img.addr = mlx_get_data_addr(data -> img.img, \
		&(data ->img.bits_per_pixel), \
	&(data -> img.line_length), &(data ->img.endian));
}

void	ft_mlx_wait(t_vars *data)
{
	mlx_hook(data -> win, 2, 1L << 5, key_hook, data);
	mlx_hook(data -> win, 17, 1L << 0, destroy, data);
	mlx_hook(data -> win, 4, 1L << 7, mouse_hook, data);
	mlx_loop(data -> mlx);
}
