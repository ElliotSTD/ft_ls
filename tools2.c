/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhadraou <hhadraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 15:52:02 by hhadraou          #+#    #+#             */
/*   Updated: 2019/01/21 00:06:27 by hhadraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	len_finder(t_dir *lst_dr, char *options, t_env *len)
{
	t_dir		*current;
	struct stat	rstat;
	int			temp;

	current = lst_dr;
	while (current != NULL)
	{
		if (options[a] != 'a' && basename(current->name)[0] == '.')
		{
			current = current->next;
			continue;
		}
		lstat(current->path, &rstat);
		if (len->n_link < (temp = ft_numlen(rstat.st_nlink)))
			len->n_link = temp;
		if (len->usr < (temp = ft_strlen(getpwuid(rstat.st_uid)->pw_name)))
			len->usr = temp;
		if (len->grp < (temp = ft_strlen(getgrgid(rstat.st_gid)->gr_name)))
			len->grp = temp;
		if (len->size < (temp = ft_numlen(rstat.st_size)))
			len->size = temp;
		current = current->next;
	}
}

void	spacer(char *s, int spaces, char mode)
{
	int len;
	int i;

	len = ft_strlen(s) - 1;
	i = spaces - len;
	if (mode == 'p')
		while (i > 0)
		{
			ft_putchar(' ');
			i--;
		}
	ft_putstr(s);
	if (mode == 's')
		while (i > 0)
		{
			ft_putchar(' ');
			i--;
		}
	free(s);
}

void	list_free(t_dir **list)
{
	t_dir	*current;
	t_dir	*freed;

	current = *list;
	while (current)
	{
		free(current->name);
		free(current->path);
		freed = current;
		current = current->next;
		free(freed);
	}
}

t_dir	*new_file(char *path, char *name)
{
	t_dir	*new_dr;

	if (!(new_dr = (t_dir *)malloc(sizeof(t_dir))))
		return (NULL);
	new_dr->name = ft_strdup(name);
	new_dr->path = ft_strdup(path);
	new_dr->next = NULL;
	return (new_dr);
}

char	*basename(char *dir)
{
	char	*b_name;

	b_name = NULL;
	if ((b_name = ft_strrchr(dir, '/')) != NULL)
		return (b_name);
	else
		return (dir);
}
