/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melalj <melalj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 15:55:32 by hhadraou          #+#    #+#             */
/*   Updated: 2019/01/19 15:45:58 by melalj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_exist(char *s, char to_find)
{
	while (*s)
	{
		if (*s == to_find)
			return (1);
		s++;
	}
	return (0);
}

void	usage(char c)
{
	ft_putstr("ft_ls : illegal option -- ");
	ft_putchar(c);
	ft_putstr("\nusage: ls [-GRSalrt] [file ...]");
	exit(0);
}

char	*ft_pathjoin(char *dir, char *file)
{
	char *str;
	char *result;

	str = NULL;
	result = NULL;
	if (ft_strequ(dir, "/"))
	{
		result = ft_strjoin(dir, file);
		return (result);
	}
	str = ft_strjoin(dir, "/");
	result = ft_strjoin(str, file);
	free(str);
	return (result);
}

int		is_dir(char *dir)
{
	DIR		*dr;

	if ((dr = opendir(dir)) != NULL)
	{
		closedir(dr);
		return (1);
	}
	return (0);
}

int		not_found(t_dir **lst)
{
	struct stat	fstat;
	t_dir		*current;
	int			counter;

	current = *lst;
	counter = 0;
	while (current)
	{
		if (lstat(current->name, &fstat) == -1)
		{
			ft_putstr("ft_ls: ");
			ft_putstr(current->name);
			ft_putstr(": No such file or directory\n");
			current->err = 'y';
		}
		counter += 1;
		current = current->next;
	}
	return (counter);
}
