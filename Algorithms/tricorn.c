/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:12:35 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/02/10 14:16:25 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../Common_files/header.h"

void	ft_put_pixel_t_corn(t_vars **d)
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
		data -> n_re = ft_pow(data -> o_re, 2) - \
			ft_pow(data ->o_im, 2) + data ->c_re;
		data -> n_im = -2 * (data -> o_re * data -> o_im) + data ->c_im;
		if (ft_pow(data -> n_re, 2) + ft_pow(data -> n_im, 2) >= 4)
			break ;
	}
	ft_color(data);
}

int	ft_t_corn(t_vars **d)
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
			ft_put_pixel_t_corn(&data);
	}
	mlx_put_image_to_window(data -> mlx, data -> win, data -> img.img, 0, 0);
	return (1);
}

void	main_t_corn(void)
{
	t_vars	*data;

	data = (t_vars *)malloc(sizeof(t_vars));
	data -> type = 3;
	ft_mlx_initiate_window(data, 1000, 1000, "Tricorn set");
	ft_t_corn(&data);
	ft_mlx_wait(data);
	free (data);
}
