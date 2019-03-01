/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melalj <melalj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 13:46:56 by melalj            #+#    #+#             */
/*   Updated: 2018/10/31 08:43:19 by melalj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcut(char const *s, char c)
{
	char	*cuted;
	int		i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	cuted = ft_strsub(s, 0, i);
	return (cuted);
}
