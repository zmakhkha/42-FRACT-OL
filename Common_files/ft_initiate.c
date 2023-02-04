/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initiate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 17:37:06 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/02/05 00:08:18 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"header.h"

void	ft_initiate_2(t_vars **d)
{
	t_vars	*data;

	data = *d;
	data ->new_x = 0;
	data ->new_y = 0;
	data -> play = 0;
}

void	ft_initiate_mandelbrot(t_vars **d, int height, int width)
{
	t_vars	*data;

	ft_initiate_2(d);
	data = *d;
	data -> m_iter = 25;
	data -> color_t = 0;
	data -> x = -1;
	data -> y = -1;
	data -> n = -1;
	data -> width = width;
	data -> height = height;
	data -> o_re = 0;
	data -> n_re = 0;
	data -> o_im = 0;
	data -> n_im = 0;
	data -> c_re = 0;
	data -> c_im = 0;
	data -> l_mouse = 0;
	data -> tr_x = 2.0;
	data -> tr_y = 2.0;
	data -> x_scale = 4.0 / data -> width;
	data -> y_scale = 4.0 / data -> height;
}
