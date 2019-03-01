/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melalj <melalj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 19:18:24 by melalj            #+#    #+#             */
/*   Updated: 2018/10/19 22:34:53 by melalj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*c_s;
	char	*s_s;

	if (!s)
		return (0);
	c_s = (char *)malloc(len + 1);
	if (!c_s)
		return (0);
	s_s = c_s;
	while (len)
	{
		*c_s = s[start];
		start++;
		len--;
		c_s++;
	}
	*c_s = '\0';
	return (s_s);
}
