/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 12:31:15 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/02/01 20:13:50 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <math.h>

void	ft_color_mandelbrot(t_vars *data)
{
	float	fact;

	fact = .4;
	if (data -> n < data -> m_iter)
			data -> color = 0xFFFFFF * data -> n / data -> m_iter;
	else
		data->color = 0xB5D5C5;
	my_mlx_pixel_put(&(data -> img), data -> x, data -> y, data ->color);
}

void	ft_color_julia(t_vars *data)
{
	float	fact;

	fact = .4;
	if (data -> n < data -> m_iter)
			data -> color = 0xFF0032;
	else
		data->color = 0xFFFFFF;
	my_mlx_pixel_put(&(data -> img), data -> x, data -> y, data ->color);
}