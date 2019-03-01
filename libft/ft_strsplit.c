/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melalj <melalj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 16:42:33 by melalj            #+#    #+#             */
/*   Updated: 2018/10/22 20:43:14 by melalj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		part_count(const char *s, int c)
{
	int				i;
	unsigned int	p_c;

	if (!s)
		return (0);
	p_c = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			p_c++;
		i++;
	}
	return (p_c);
}

static int		char_part_count(char const *s, char c)
{
	int				i;
	int				pw_c;

	if (!s)
		return (0);
	i = 0;
	pw_c = 0;
	while (s[i] != c && s[i] != '\0')
	{
		pw_c++;
		i++;
	}
	return (pw_c);
}

static int		*place(char const *s, char c)
{
	int			i;
	int			k;
	int			*ad;

	if (!s)
		return (0);
	ad = (int *)malloc(sizeof(int) * (part_count(s, c) + 1));
	if (!ad)
		return (0);
	k = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if ((!ft_isprint(s[i - 1]) || s[i - 1] == c) && s[i] != c)
			ad[k++] = i;
		i++;
	}
	ad[k] = 0;
	return (ad);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**splited;
	int			i[3];
	int			*idx;

	i[0] = part_count(s, c);
	if (!(splited = (char**)malloc((i[0] + 1) * sizeof(char*))))
		return (NULL);
	idx = place(s, c);
	i[1] = 0;
	while (i[1] < i[0])
	{
		i[2] = char_part_count(s + idx[i[1]], c);
		splited[i[1]] = ft_strsub(s, idx[i[1]], i[2]);
		i[1]++;
	}
	splited[i[0]] = 0;
	return (splited);
}
