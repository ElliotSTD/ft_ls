/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melalj <melalj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 15:59:13 by melalj            #+#    #+#             */
/*   Updated: 2018/10/13 16:21:33 by melalj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *i_s;

	i_s = (unsigned char *)s;
	while (n)
	{
		if (*i_s == (unsigned char)c)
			return (i_s);
		i_s++;
		n--;
	}
	return (0);
}
