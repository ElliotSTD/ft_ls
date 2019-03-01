/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhadraou <hhadraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 15:57:00 by hhadraou          #+#    #+#             */
/*   Updated: 2019/01/19 18:34:58 by hhadraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		a_file(char *dir, char *options)
{
	t_dir	*file;

	file = NULL;
	if (ft_strequ(strerror(errno), "Permission denied"))
	{
		ft_putstr("ft_ls: ");
		ft_putstr(dir);
		ft_putstr(": Permission denied\n");
	}
	else
	{
		add_file(&file, dir, dir);
		print_list(file, options);
	}
	list_free(&file);
	return (0);
}

void	print_name(t_dir *file, char *options)
{
	struct stat sb;

	if (options[G] == 'G')
	{
		if (file->type == 4)
			ft_putstr(ANSI_COLOR_CYAN);
		else if (file->type == 10)
			ft_putstr(ANSI_COLOR_MAGENTA);
		else if (stat(file->path, &sb) == 0 && sb.st_mode & S_IXUSR)
			ft_putstr(ANSI_COLOR_RED);
	}
	if (options[l] == 'l' && file->type == 10)
	{
		ft_putstr(ANSI_COLOR_RESET);
		return ;
	}
	if ((lstat(file->path, &sb) == 0 && !S_ISLNK(sb.st_mode)) ||
		options[l] != 'l')
		ft_putstr(file->name);
	if (options[G] == 'G')
		ft_putstr(ANSI_COLOR_RESET);
}

int		ft_numlen(unsigned long long number)
{
	int count;

	count = 0;
	while (number > 0)
	{
		count += 1;
		number /= 10;
	}
	return ((count) ? count : 1);
}
