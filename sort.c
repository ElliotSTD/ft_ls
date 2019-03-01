/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melalj <melalj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 06:25:51 by melalj            #+#    #+#             */
/*   Updated: 2019/01/19 15:40:08 by melalj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	sort_list(t_dir **head, int (*cmp)(t_dir, t_dir), int done)
{
	t_dir	**src;
	t_dir	*temp;
	t_dir	*next;

	while (!done && *head != NULL && (*head)->next != NULL)
	{
		src = head;
		temp = *head;
		next = (*head)->next;
		done = 1;
		while (next)
		{
			if (cmp(*temp, *next) > 0)
			{
				temp->next = next->next;
				next->next = temp;
				*src = next;
				done = 0;
			}
			src = &temp->next;
			temp = next;
			next = next->next;
		}
	}
}

int		compare_strings(t_dir d1, t_dir d2)
{
	return (ft_strcmp(d1.name, d2.name));
}

int		compare_time(t_dir d1, t_dir d2)
{
	struct stat fstat1;
	struct stat fstat2;

	lstat(d1.path, &fstat1);
	lstat(d2.path, &fstat2);
	if (fstat1.st_mtime < fstat2.st_mtime)
		return (1);
	else
		return (0);
}

int		compare_size(t_dir d1, t_dir d2)
{
	struct stat fstat1;
	struct stat fstat2;

	lstat(d1.path, &fstat1);
	lstat(d2.path, &fstat2);
	if (fstat1.st_size < fstat2.st_size)
		return (1);
	else
		return (0);
}

void	add_file(t_dir **lst_dr, char *path, char *name)
{
	t_dir	*current;

	current = *lst_dr;
	if (current == NULL)
		*lst_dr = new_file(path, name);
	else
	{
		while (current->next)
			current = current->next;
		current->next = new_file(path, name);
	}
}
