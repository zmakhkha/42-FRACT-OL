/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 21:28:09 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/01/25 12:25:29 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "../libft/libft.h"
#include <mlx.h>
#include <libc.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
} t_data;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		ft_close(int keycode, t_vars *vars);
int			key_hook(int keycode, t_vars *vars);



#endif