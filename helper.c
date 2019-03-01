/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melalj <melalj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 07:42:31 by melalj            #+#    #+#             */
/*   Updated: 2019/01/22 20:12:12 by melalj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	reverse_util(t_dir *curr, t_dir *prev, t_dir **head)
{
	t_dir *next;

	if (!head)
		return ;
	if (!curr->next)
	{
		*head = curr;
		curr->next = prev;
		return ;
	}
	next = curr->next;
	curr->next = prev;
	reverse_util(next, curr, head);
}

void	home_dir(char *dir, char *options)
{
	DIR				*dr;
	struct dirent	*de;
	t_dir			*lst_dr;

	lst_dr = NULL;
	if ((dr = opendir(dir)))
	{
		while ((de = readdir(dr)) != NULL)
			add_dr(&lst_dr, ft_pathjoin(dir, de->d_name), de);
		sort_list(&lst_dr, compare_strings, 0);
		if (options[S] == 'S')
			sort_list(&lst_dr, compare_size, 0);
		else if (options[t] == 't')
			sort_list(&lst_dr, compare_time, 0);
		if (options[l] == 'l')
			print_total_l(lst_dr, options);
		r_or_rr(lst_dr, options);
		closedir(dr);
	}
	else
		a_file(dir, options);
}

void	r_handler(t_dir *list, char *options)
{
	t_dir	*tmp;

	tmp = list;
	while (tmp != NULL)
	{
		if ((options[a] != 'a' && tmp->name[0] == '.')
			|| (ft_strequ(tmp->name, ".")) || (ft_strequ(tmp->name, "..")))
			;
		else if (is_dir(tmp->path))
		{
			ft_putendl(tmp->path);
			home_dir(tmp->path, options);
		}
		else if (errno == 13)
		{
			ft_putendl(tmp->path);
			ft_putstr("ft_ls: ");
			ft_putstr(tmp->name);
			ft_putstr(": ");
			ft_putendl(strerror(errno));
			ft_putchar('\n');
		}
		tmp = tmp->next;
	}
}

void	ft_checkdir_iter(t_dir *current, int i, char *options)
{
	if (current->err != 'y')
	{
		if (i > 1 && is_dir(current->name))
		{
			ft_putstr(current->name);
			ft_putendl(":");
		}
		home_dir(current->name, options);
	}
}

int		iter_args(t_dir *args, char *options, int i)
{
	t_dir		*current;

	current = args;
	if (current != NULL)
	{
		sort_list(&current, compare_strings, 0);
		i += not_found(&current);
		if (options[S] == 'S')
			sort_list(&current, compare_size, 0);
		else if (options[t] == 't')
			sort_list(&current, compare_time, 0);
		if (options[r] == 'r')
			reverse_util(current, NULL, &current);
		while (current)
		{
			ft_checkdir_iter(current, i, options);
			current = current->next;
		}
	}
	else if (i == 0)
		home_dir(".", options);
	return (--i);
}
