/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhadraou <hhadraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 11:45:39 by melalj            #+#    #+#             */
/*   Updated: 2019/01/16 16:22:05 by hhadraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *con;

	if (!s1 || !s2)
		return (0);
	con = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!con)
		return (0);
	con = ft_strcpy(con, s1);
	con = ft_strcat(con, s2);
	con[ft_strlen(con)] = '\0';
	return (con);
}
