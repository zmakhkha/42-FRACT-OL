/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 12:31:15 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/02/04 23:54:05 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <math.h>

int	ft_test_limits(t_vars *data)
{
	int	a;
	int	b;

	a = data -> x + data -> new_x;
	b = data -> y + data -> new_y;
	if ((0 <= a && a < data -> width) && (0 <= b && b < data -> height))
		return (1);
	return (0);
}

void	ft_color(t_vars *data)
{
	if (data -> color_t && data -> n < data -> m_iter)
			data -> color = 0xFFFFFF * log(data -> n);
	else if (!(data -> color_t) && data -> n < data -> m_iter)
			data -> color = 0xFFFFFF;
	else
		data->color = 0xB5D5C5;
	if (ft_test_limits(data))
		my_mlx_pixel_put(&(data -> img), data -> x, data -> y, data ->color);
}
