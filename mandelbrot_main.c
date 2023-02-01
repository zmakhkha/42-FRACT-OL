/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 19:17:32 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/02/01 15:24:52 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Common_files/header.h"

void	ft_initiate_mandelbrot(t_vars **d, int height, int width)
{
	t_vars	*data;

	data = *d;
	data -> x = -1;
	data -> y = -1;
	data -> n = -1;
	data -> m_iter = 50;
	data -> width = width;
	data -> height = height;
	data -> color = 0x645CBB;
	data -> o_re = 0;
	data -> n_re = 0;
	data -> o_im = 0;
	data -> n_im = 0;
	data -> c_re = 0;
	data -> c_im = 0;
	data -> tr_x = 2.0;
	data -> tr_y = 2.0;
	data -> x_scale = 4.0 / data -> width;
	data -> y_scale = 4.0 / data -> height;
}

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
	ft_color_mandelbrot(data);
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
	return (1);
}

int	main(void)
{
	t_vars	*data;

	data = (t_vars *)malloc(sizeof(t_vars));
	ft_initiate_mandelbrot(&data, 1000, 1000);
	data ->mlx = mlx_init();
	data ->win = mlx_new_window(data -> mlx, data -> width, \
	data -> height, "Mandelbrot Set");
	ft_mandelbrot(&data);
	ft_mlx_wait(data);
	free (data);
}
