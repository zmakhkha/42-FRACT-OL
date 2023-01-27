/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 21:28:09 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/01/27 16:54:10 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "../libft/libft.h"
# include <mlx.h>
# include <libc.h>

typedef struct t_m_data {
	int		x;
	int		y;
	int		n;
	int		color;
	int		m_iter;
	int		height;
	int		width;
	double	scale;
	double	o_re;
	double	n_re;
	double	o_im;
	double	n_im;
	double	c_re;
	double	c_im;
}			t_mdata;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		ft_close(int keycode, t_vars *vars);
int			key_hook(int keycode, t_vars *vars);
int			destroy(t_vars *vars);

#endif