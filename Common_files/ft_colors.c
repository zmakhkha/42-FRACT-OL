/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 12:31:15 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/02/01 15:16:38 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <math.h>

void	ft_color_mandelbrot(t_vars *data)
{
	if (data -> n < data -> m_iter)
			data -> color = 0x5D3891 * log(data -> n * .35);
	else
		data->color = 0x000000;
	my_mlx_pixel_put(&(data -> img), data -> x, data -> y, data ->color);
}
