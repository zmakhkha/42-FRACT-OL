/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 19:17:32 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/01/25 19:22:53 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Common_files/header.h"

//void	zooomy(int x0, int y0, t_data *s_vars, int fact, int color)
//{
//	int x, v, y_init;
//	int xx0 = x0, yy0 = y0;

//	x = xx0 + fact ;
//	v = yy0 + fact;
//	y_init = yy0;
//	while(xx0 <= x)
//	{
//		yy0 = y_init;
//		while (yy0 <= v)
//		{
//			my_mlx_pixel_put(s_vars,  xx0, yy0, color );
//			yy0++;
//		}
//		xx0++;
//	}
//}

void	ft_mandelbrot(int width, int height)
{
	t_vars	vars;	
	t_data	img;
	int		x, y, n;
	int		max_iter = 50;
	double	ore = 0, oim = 0, nre = 0, nim = 0;
	double	pRe = 0, pIm = 0;
	int		color;
	double c_r = 0;
	double c_i = 0;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, width, height, "Mandelbrot Set");
	img.img = mlx_new_image(vars.mlx, width, height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	x = -1;
	while (++x < width)
	{
		y = -1;
		while (++y < height)
		{
			c_r = (x * 4.0 / width) - 2.0;
			c_i = (y * 4.0/height) - 2.0; 
			
			//pRe = pRe * (4.0 / width) - 2.0;
			//pIm = pIm * (4.0 / height) - 2.0;
			n = -1;
			ore = oim = nre = nim = 0;
			while (++n < max_iter)
			{
				ore = nre;
				oim = nim;
				nre = (ore * ore - oim * oim) +c_r;
				nim = (2 * ore * oim ) + c_i;
				if ((nre * nre + nim * nim) >= 4)
					break ;
			}
			if (n < max_iter)
				my_mlx_pixel_put(&img, x , y ,0xFFFFFF);
			else
				my_mlx_pixel_put(&img, x , y ,0x000000);
		}
		mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	}
	
	mlx_hook(vars.win, 2, 1L<<0, key_hook, &vars);
	mlx_loop(vars.mlx);
}

int	main(void)
{
	ft_mandelbrot(1000, 1000);
}