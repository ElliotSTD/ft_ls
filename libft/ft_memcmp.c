/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melalj <melalj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 16:47:51 by melalj            #+#    #+#             */
/*   Updated: 2018/10/21 03:27:44 by melalj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *c_s1;
	unsigned char *c_s2;

	c_s1 = (unsigned char *)s1;
	c_s2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (n)
	{
		if (*c_s1 - *c_s2 != 0)
			return (*c_s1 - *c_s2);
		c_s1++;
		c_s2++;
		n--;
	}
	return (0);
}
