/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 21:28:09 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/02/01 15:19:33 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "../libft/libft.h"
# include <mlx.h>
# include <libc.h>

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_vars {
	t_data		img;
	void		*mlx;
	void		*win;
	int			x;
	int			y;
	int			n;
	int			color;
	int			m_iter;
	int			height;
	int			width;
	double		tr_x;
	double		tr_y;
	double		scale;
	double		o_re;
	double		n_re;
	double		o_im;
	double		n_im;
	double		c_re;
	double		c_im;
	double		x_scale;
	double		y_scale;
}				t_vars;

void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		ft_close(int keycode, t_vars *vars);
void		ft_color_mandelbrot(t_vars *data);
int			ft_mandelbrot(t_vars **d);
void		ft_put_pixel_mandelbrot(t_vars **d);
void		ft_initiate_mandelbrot(t_vars **d, int height, int width);
void		ft_initiate_window(t_vars *data);
void		ft_mlx_wait(t_vars *data);

int			mouse_hook(int keycode, int x, int y, t_vars *a);
int			key_hook(int keycode, t_vars *vars);
int			destroy(t_vars *vars);

#endif