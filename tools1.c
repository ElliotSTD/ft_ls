/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melalj <melalj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 16:40:50 by hhadraou          #+#    #+#             */
/*   Updated: 2019/01/22 20:08:26 by melalj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_total_l(t_dir *temp, char *options)
{
	int			total;
	struct stat	fstat;
	int			c;

	total = 0;
	c = 0;
	while (temp != NULL)
	{
		if (options[a] != 'a' && temp->name[0] == '.')
		{
			temp = temp->next;
			continue;
		}
		c++;
		lstat(temp->path, &fstat);
		total += (int)fstat.st_blocks;
		temp = temp->next;
	}
	if (c == 0)
		return ;
	if (total > 0)
		ft_put2endl("total ", total);
	else
		ft_put2endl("total ", 0);
}

void	set_uid_perms(struct stat fstat)
{
	if ((fstat.st_mode & S_IXUSR) && (fstat.st_mode & S_ISUID))
		ft_putchar('s');
	else if (!(fstat.st_mode & S_IXUSR) && (fstat.st_mode & S_ISUID))
		ft_putchar('S');
	else
		ft_putchar((fstat.st_mode & S_IXUSR) ? 'x' : '-');
}

void	set_gid_perms(struct stat fstat)
{
	if ((fstat.st_mode & S_IXOTH) && (fstat.st_mode & S_ISGID))
		ft_putchar('s');
	else if (!(fstat.st_mode & S_IXOTH) && (fstat.st_mode & S_ISGID))
		ft_putchar('S');
	else
		ft_putchar((fstat.st_mode & S_IXOTH) ? 'x' : '-');
}

void	set_stickybit_perms(struct stat fstat)
{
	if ((fstat.st_mode & S_IXOTH) && (fstat.st_mode & S_ISVTX))
		ft_putchar('t');
	else if (!(fstat.st_mode & S_IXOTH) && (fstat.st_mode & S_ISVTX))
		ft_putchar('T');
	else
		ft_putchar((fstat.st_mode & S_IXOTH) ? 'x' : '-');
}

void	r_or_rr(t_dir *lst_dr, char *options)
{
	if (options[r] == 'r')
		reverse_util(lst_dr, NULL, &lst_dr);
	print_list(lst_dr, options);
	if (options[R] == 'R')
		r_handler(lst_dr, options);
	list_free(&lst_dr);
}
