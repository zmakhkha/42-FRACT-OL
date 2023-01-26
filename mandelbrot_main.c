/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 19:17:32 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/01/26 16:04:46 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Common_files/header.h"

t_mdata	*ft_initiate_mandelbrot(int height, int width)
{
	t_mdata	*data;

	data = (t_mdata *) malloc (sizeof(t_mdata));
	data -> x = -1;
	data -> y = -1;
	data -> n = -1;
	data -> m_iter = 50;
	data -> height = height;
	data -> width = width;
	data -> o_re = 0;
	data -> n_re = 0;
	data -> o_im = 0;
	data -> n_im = 0;
	data -> c_re = 0;
	data -> c_im = 0;
	return (data);
}

void	ft_put_pixel_mandelbrot(t_mdata *data, t_data *img)
{
	data -> c_re = (data -> x) * (4.0 / data -> width) - 2.0;
	data -> c_im = (data -> y) * (4.0 / data -> height) - 2.0;
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
	if (data -> n < data -> m_iter)
		my_mlx_pixel_put(img, data -> x, data -> y, 0xFFFFFF);
	else
		my_mlx_pixel_put(img, data -> x, data -> y, 0x000000);
}

void	ft_mandelbrot(t_vars *vars, t_data *img)
{
	t_mdata	*data;

	data = ft_initiate_mandelbrot(1000, 1000);
	while (++(data -> x) < data ->width)
	{
		data -> y = -1;
		while (++data -> y < data -> height)
		{
			ft_put_pixel_mandelbrot(data, img);
		}
		mlx_put_image_to_window((*vars).mlx, (*vars).win, (*img).img, 0, 0);
	}
	ft_putnbr_fd(data -> y, 1);
	free (data);
}

int	main(void)
{
	t_vars	vars;	
	t_data	img;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1000, 1000, "Mandelbrot Set");
	img.img = mlx_new_image(vars.mlx, 1000, 1000);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
	&img.line_length, &img.endian);
	ft_mandelbrot(&vars, &img);
	mlx_hook(vars.win, 2, 1L << 0, key_hook, &vars);
	mlx_loop(vars.mlx);
}
