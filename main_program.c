/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:10:40 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/02/01 20:10:40 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Common_files/header.h"

int	main(int n, char **v)
{
	(void)v;
	if (n == 1)
		ft_print_error("Error", 1);
	else
	{
		if (!ft_strncmp(v[1], "-m", 2) || !ft_strncmp(v[1], "-M", 2))
			main_madelbrot();
		else if (!ft_strncmp(v[1], "-j", 2) || !ft_strncmp(v[1], "-J", 2))
			main_julia();
	}
}
