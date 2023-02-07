/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks_02.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 23:04:12 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/02/07 16:54:34 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	mouse_move(int x, int y, t_vars *data)
{
	(void)data;
	(void)x;
	(void)y;
	if ((data -> l_mouse % 2) && 0 < x && x \
	< data -> width && 0 < y && y < data -> height)
	{
		data -> j_a = x * data ->x_scale;
		data -> j_b = y * data ->y_scale;
	}
	if ((data -> play % 5) && 0 < x && x \
		< data -> width && 0 < y && y < data -> height)
		mouse_hook(4, x, y, data);
	ft_des_build(data);
	return (0);
}

int	mouse_hook(int keycode, int x, int y, t_vars *data)
{
	if (keycode == L_MOUSECLK)
		data -> l_mouse ++;
	if (keycode == ON_MOUSEUP)
	{
		data -> tr_x = data -> tr_x + (x * data ->x_scale);
		data -> tr_y = data -> tr_y + (y * data ->y_scale);
		data -> x_scale *= 2;
		data -> y_scale *= 2;
		if (data -> m_iter > 25)
			data->m_iter -= 10;
	}
	if (keycode == 4)
	{
		data -> x_scale /= 2;
		data -> y_scale /= 2;
		data -> tr_x = data -> tr_x - (x * data ->x_scale);
		data -> tr_y = data -> tr_y - (y * data ->y_scale);
		data->m_iter += 10;
	}
	mlx_destroy_image(data -> mlx, data -> img.img);
	ft_des_build(data);
	return (0);
}
