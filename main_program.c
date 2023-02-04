/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:10:40 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/02/04 23:01:38 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Common_files/header.h"

int	main(int n, char **v)
{
	float	a;
	float	b;

	a = 0;
	b = 0;
	if (n == 1)
		ft_print_error("Error", 1);
	else
	{
		if (!ft_strncmp(v[1], "-m", 2) || !ft_strncmp(v[1], "-M", 2))
			main_madelbrot();
		else if (!ft_strncmp(v[1], "-j", 2) || !ft_strncmp(v[1], "-J", 2))
		{
			if (n == 4)
			{
				a = ft_atof(v[2]);
				b = ft_atof(v[3]);
				main_julia(a, b);
			}
		}
	}
}
