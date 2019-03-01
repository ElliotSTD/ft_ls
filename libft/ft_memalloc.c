/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melalj <melalj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 02:56:37 by melalj            #+#    #+#             */
/*   Updated: 2018/10/15 16:24:28 by melalj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t len)
{
	unsigned char	*mem_space;
	size_t			i;

	mem_space = malloc(len);
	if (!mem_space)
		return (NULL);
	i = 0;
	while (i < len)
	{
		mem_space[i] = 0;
		i++;
	}
	return (mem_space);
}
