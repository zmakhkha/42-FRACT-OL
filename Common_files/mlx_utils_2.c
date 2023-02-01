/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:21:48 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/02/01 19:05:53 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"


void	ft_initiate_window(t_vars *data)
{
	data ->img.img = mlx_new_image(data -> mlx, data -> width, data -> height);
	data ->img.addr = mlx_get_data_addr(data -> img.img, \
		&(data ->img.bits_per_pixel), \
	&(data -> img.line_length), &(data ->img.endian));
}

void	ft_mlx_initiate_window(t_vars *data, int width, int height, char *t)
{
	ft_initiate_mandelbrot(&data, width, height);
	data ->mlx = mlx_init();
	data ->win = mlx_new_window(data -> mlx, data -> width, \
	data -> height, t);
}

void	ft_put_info(t_vars *data)
{
	mlx_string_put(data -> mlx, data -> win, 50, 50, 0xFFFFFF, \
	ft_strjoin("n :", ft_itoa(data -> n)));
}