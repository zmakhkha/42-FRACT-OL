/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:10:40 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/02/08 13:47:17 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Common_files/header.h"

void	f(void)
{
	system("leaks fract");
}

int	main(int n, char **v)
{
	atexit(f);
	if (n == 1)
		ft_print_menu();
	else if (n == 2)
	{
		if (!ft_strncmp(v[1], "-m", 3) || !ft_strncmp(v[1], "-M", 3))
			main_mandelbrot();
		else if (!ft_strncmp(v[1], "-b", 3) || !ft_strncmp(v[1], "-B", 2))
			main_b_ship();
		else
			ft_print_menu();
	}
	else if (!ft_strncmp(v[1], "-j", 2) || !ft_strncmp(v[1], "-J", 2))
	{
		if (n == 4)
			main_julia(ft_atof(v[2]), ft_atof(v[3]));
		else
			ft_print_menu();
	}
	else
		ft_print_menu();
}
