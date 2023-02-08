/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_it.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 19:15:58 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/02/08 16:09:31 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../Common_files/header.h"

void	ft_isnumber(char *number)
{
	int	i;

	i = 0;
	if (number[0] == '-' || number[0] == '+')
		i++;
	if (!number[i])
	{
		free (number);
		ft_print_menu();
	}
	while (number[i])
	{
		if (!ft_isdigit(number[i]))
		{
			free (number);
			ft_print_menu();
		}
		i++;
	}
}

void	ft_print_menu(void)
{
	write(1, "FRACT-OL\n", ft_strlen("FRACT-OL\n"));
	write(1, "1 : make && make clean\n", ft_strlen("1 : make && make clean\n"));
	write(1, "2 : Choose the fractal that you want\n", \
		ft_strlen("2 : Choose the fractal that you want\n"));
	write(1, "-> ./fract -m : For the Mandelbrot Set\n", \
		ft_strlen("-> ./fract -m : For the Mandelbrot Set\n"));
	write(1, "-> ./fract -j F1 F2 : For the Julia Set\n", \
		ft_strlen("-> ./fract -j C1 C2 : For the Julia Set\n"));
	write(1, "-> ./fract -b : For the Burning Ship Set\n", \
		ft_strlen("-> ./fract -b : For the Burning Ship Set\n"));
	exit(1);
}
