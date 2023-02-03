/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:46:03 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/02/03 21:01:54 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Common_files/header.h"

void	ft_put_pixel_julia(t_vars **d)
{
	t_vars	*data;

	data = *d;
	data -> c_re = data -> j_a;
	data -> c_im = data -> j_b;
	data -> n_re = ((data -> x * data ->x_scale) - data -> tr_x);
	data -> n_im = ((data -> y * data ->y_scale) - data -> tr_y);
	data -> n = -1;
	while (++(data -> n) < data -> m_iter)
	{
		data -> o_re = data -> n_re;
		data -> o_im = data -> n_im;
		data -> n_re = ((data -> o_re) * (data -> o_re) - \
		(data -> o_im) * (data -> o_im)) + data -> c_re;
		data -> n_im = (2 * data -> o_re * data -> o_im) + data -> c_im;
		if ((data -> n_re * data -> n_re + data -> n_im \
		* data -> n_im) >= 4)
			break ;
	}
	ft_color_julia(data);
}

void	ft_julia(t_vars **d)
{
	t_vars	*data;

	data = *d;
	data -> x = -1;
	data -> y = -1;
	ft_initiate_window(data);
	while (++(data -> x) < data ->width)
	{
		data -> y = -1;
		while (++data -> y < data -> height)
			ft_put_pixel_julia(&data);
	}
	mlx_put_image_to_window(data -> mlx, data -> win, data -> img.img, 0, 0);
}

void	main_julia(float a, float b)
{
	t_vars	*data;

	data = (t_vars *)malloc(sizeof(t_vars));
	data -> type = 1;
	ft_mlx_initiate_window(data, 1000, 1000, "Julia set");
	data -> m_iter = 50;
	data -> j_a = a;
	data -> j_b = b;
	data -> m_iter = 500;
	printf("%f\n", data -> j_a);
	printf("%f\n", data -> j_b);
	ft_julia(&data);
	ft_mlx_wait(data);
	free (data);
}