/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 19:17:32 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/01/29 18:47:25 by zmakhkha         ###   ########.fr       */
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
	data -> height = height;
	data -> width = width;
	data -> color = 0x645CBB;
	data -> o_re = 0;
	data -> n_re = 0;
	data -> o_im = 0;
	data -> n_im = 0;
	data -> c_re = 0;
	data -> c_im = 0;
}

void	ft_put_pixel_mandelbrot(t_vars **d)
{
	t_vars *data = *d;

	data -> c_re = (data -> x) * (data -> scale / data -> width) \
		- data ->scale / 2;
	data -> c_im = (data -> y) * (data -> scale / data -> height) \
		- data -> scale / 2;
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
		data->color = 0xFC7300 * data -> n % 150;
	else
		data->color = 0xFFFFFF;
	my_mlx_pixel_put(&(data -> img), data -> x, data -> y, data ->color);
}

int	ft_mandelbrot(t_vars **d)
{
	t_vars *data = *d;

	data -> x = -1;
	data -> y = -1;
	data ->img.img = mlx_new_image(data -> mlx, data -> width, data -> height);
	data ->img.addr = mlx_get_data_addr(data -> img.img, &(data ->img.bits_per_pixel), \
	&(data -> img.line_length), &(data ->img.endian));
	while (++(data -> x) < data ->width)
	{
		data -> y = -1;
		while (++data -> y < data -> height)
			ft_put_pixel_mandelbrot(&data);
		mlx_put_image_to_window(data -> mlx, data -> win, data -> img.img, 0, 0);
	}
	return (1);
}
int	mouse_hook(int keycode, int x, int y, t_vars *a)
{

	(void)x;
	(void)y;
	t_vars *vars = (t_vars *)a;
	if (keycode == 5)
	{
		vars ->scale /= .8;
		vars -> x = vars -> x + (vars -> width - vars -> x) * vars -> scale;
	}
	if (keycode == 4)
	{
		vars ->scale *= .8;
		vars -> y = vars -> y + (vars -> width - vars -> y) * vars -> scale;
	}
	mlx_destroy_image(vars -> mlx, vars -> img.img);
	ft_mandelbrot(&vars);
	
	return (0);
}


int	main(void)
{
	t_vars *data;

	data = (t_vars *)malloc(sizeof(t_vars));
	ft_initiate_mandelbrot(&data, 750, 750);
	data ->mlx = mlx_init();
	data ->win = mlx_new_window(data -> mlx, data -> width, data -> height, "Mandelbrot Set");

	data -> scale = 4;
	ft_mandelbrot(&data);
	mlx_hook(data -> win, 2, 1L << 5, key_hook, data);
	mlx_hook(data -> win, 17, 1L << 0, destroy, data);
	mlx_hook(data -> win, 4, 1L<<7, mouse_hook, data);
	mlx_loop(data -> mlx);
	//free (data);
}
