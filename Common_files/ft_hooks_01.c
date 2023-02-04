/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks_01.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 15:26:31 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/02/05 00:19:25 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_des_build(t_vars *data)
{
	if (!(data -> type))
		ft_mandelbrot(&data);
	else if (data -> type == 1)
		ft_julia(&data);
	else if (data -> type == 2)
		ft_multibrot(&data);
}

void	increase_m_iter(int keycode, t_vars *data)
{
	(void)data;
	if (keycode == 69)
		data -> m_iter += 10;
	else if (keycode == 78)
		data -> m_iter -= 10;
	mlx_destroy_image(data -> mlx, data -> img.img);
	ft_des_build(data);
}

int	key_hook(int keycode, t_vars *data)
{
	if (keycode == 53)
		ft_close(keycode, data);
	else if (keycode == 0)
	{
		data -> color_t = 1;
		mlx_destroy_image(data -> mlx, data -> img.img);
		ft_des_build(data);
	}
	increase_m_iter(keycode, data);
	key_arrow(keycode, data);
	return (0);
}

int	key_arrow(int keycode, t_vars *data)
{
	if (keycode == 123)
		data -> tr_x -= .01;
	else if (keycode == 124)
		data -> tr_x += .01;
	else if (keycode == 125)
		data -> tr_y += .01;
	else if (keycode == 126)
		data -> tr_y -= .01;
	else if (keycode == 35)
		data -> play += 1;
	mlx_destroy_image(data -> mlx, data -> img.img);
	ft_des_build(data);
	return (0);
}
