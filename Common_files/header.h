/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:28:41 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/02/10 14:20:06 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "../libft/libft.h"
# include <mlx.h>
# include<math.h>
# include<stdlib.h>

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
	int			type;
	int			color_t;
	float		j_a;
	float		j_b;
	int			l_mouse;
	int			new_x;
	int			new_y;
	int			play;
}				t_vars;

# define ON_MOUSEUP 5
# define ON_MOUSEDW 4
# define L_MOUSECLK 1
# define K_PRESS 2
# define ON_DESTROY 17
# define BTN_PRESS 4
# define M_NOTIFY 6

void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		ft_close(int keycode, t_vars *vars);
void		ft_color(t_vars *data);
int			ft_mandelbrot(t_vars **d);
void		ft_put_pixel_mandelbrot(t_vars **d);
void		ft_initiate_mandelbrot(t_vars **d, int height, int width);
void		ft_initiate_window(t_vars *data);
void		ft_mlx_wait(t_vars *data);

void		main_mandelbrot(void);
void		ft_julia(t_vars **d);
void		main_julia(float a, float b);

int			mouse_hook(int keycode, int x, int y, t_vars *a);
int			key_hook(int keycode, t_vars *vars);
int			destroy(t_vars *vars);
void		ft_put_info(t_vars *data);
void		main_b_ship(void);
int			ft_b_ship(t_vars **d);

int			mouse_move(int x, int y, t_vars *vars);
int			key_arrow(int keycode, t_vars *vars);
void		ft_des_build(t_vars *vars);
void		increase_m_iter(int keycode, t_vars *vars);
void		ft_mlx_initiate_window(t_vars *data, int width, \
			int height, char *t);
double		ft_pow(double a, int p);
void		ft_color_b_ship(t_vars *data);
void		ft_print_menu(void);
double		ft_atof(char *str);
void		ft_free_it(char **a);
void		ft_isnumber(char *number);
void		main_t_corn(void);
int			ft_t_corn(t_vars **d);
void		ft_put_pixel_t_corn(t_vars **d);

#endif
