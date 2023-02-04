/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 19:17:32 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/02/04 18:25:39 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Common_files/header.h"

void	ft_put_pixel_mandelbrot(t_vars **d)
{
	t_vars	*data;

	data = *d;
	data -> c_re = ((data -> x * data ->x_scale) - data -> tr_x);
	data -> c_im = ((data -> y * data ->y_scale) - data -> tr_y);
	data -> n_re = 0;
	data -> n_im = 0;
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
	ft_color(data);
}

int	ft_mandelbrot(t_vars **d)
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
			ft_put_pixel_mandelbrot(&data);
	}
	mlx_put_image_to_window(data -> mlx, data -> win, data -> img.img, 0, 0);
	ft_put_info(data);
	return (1);
}

void	main_madelbrot(void)
{
	t_vars	*data;

	data = (t_vars *)malloc(sizeof(t_vars));
	data -> type = 0;
	data -> color_t = 0;
	ft_mlx_initiate_window(data, 1000, 1000, "Mandelbrot set");
	data -> m_iter = 50;
	ft_mandelbrot(&data);
	ft_mlx_wait(data);
	free (data);
}
