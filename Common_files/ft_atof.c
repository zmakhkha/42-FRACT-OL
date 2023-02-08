/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 18:30:34 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/02/08 16:35:50 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Common_files/header.h"

void	ft_free_it(char **a)
{
	int	i;

	i = -1;
	while (a[++i])
		free(a[i]);
	free(a);
}

static void	test_int(char **a)
{
	if (!a[0] || !a[1])
		ft_print_menu();
	ft_isnumber(a[0]);
	ft_isnumber(a[1]);
}

double	ft_atof(char *str)
{
	char		**res_str;
	long long	res_1;
	long long	res_2;
	double		res_f;
	int			p;

	res_str = ft_split(str, '.');
	test_int(res_str);
	res_1 = ft_atoi(res_str[0]);
	if (res_1 < 0)
		res_1 *= -1;
	if (!res_str[1])
		ft_print_menu();
	res_2 = ft_atoi(res_str[1]);
	p = ft_strlen(res_str[1]);
	res_f = res_1 + (res_2 * ft_pow(10, -p));
	if (res_str[0][0] == '-')
		res_f *= -1;
	ft_free_it(res_str);
	return (res_f);
}
