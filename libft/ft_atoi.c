/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melalj <melalj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 06:40:06 by melalj            #+#    #+#             */
/*   Updated: 2018/10/25 21:56:56 by melalj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_nbr_count(const char *s)
{
	int i;

	i = 0;
	while (ft_isdigit(s[i]))
		i++;
	return (i);
}

int				ft_atoi(const char *str)
{
	int		i;
	int		n;
	int		signe;
	char	*c_str;

	c_str = ft_strtrim(str);
	signe = 1;
	if (*c_str == '-')
	{
		signe = -1;
		c_str++;
	}
	else if (*c_str == '+')
		c_str++;
	i = 0;
	while (*c_str == '0')
		c_str++;
	if (ft_nbr_count(c_str) > 10 && signe == 1)
		return (-1);
	if (ft_nbr_count(c_str) > 10 && signe == -1)
		return (0);
	n = 0;
	while (ft_isdigit(*c_str++))
		n = (n * 10) + *(c_str - 1) - 48;
	return (n * signe);
}
