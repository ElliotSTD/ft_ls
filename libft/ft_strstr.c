/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melalj <melalj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 22:29:22 by melalj            #+#    #+#             */
/*   Updated: 2018/10/23 03:52:07 by melalj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t i;

	if (*haystack == 0 && *needle == 0)
		return ((char *)haystack);
	while (*haystack != '\0')
	{
		i = 0;
		while (haystack[i] == needle[i]
				&& haystack[i] != '\0' && needle[i] != '\0')
			i++;
		if (i == ft_strlen(needle))
		{
			return ((char *)haystack);
		}
		haystack++;
	}
	return (0);
}
