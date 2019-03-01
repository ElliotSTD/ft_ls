/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhadraou <hhadraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 03:46:53 by melalj            #+#    #+#             */
/*   Updated: 2019/01/22 19:57:05 by hhadraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_dir	*new_dr(char *path, struct dirent *de)
{
	t_dir	*new_dr;

	if (!(new_dr = (t_dir *)malloc(sizeof(t_dir))))
		return (NULL);
	new_dr->path = ft_strdup(path);
	de->d_name[ft_strlen(de->d_name)] = '\0';
	new_dr->name = ft_strdup(de->d_name);
	new_dr->type = de->d_type;
	new_dr->next = NULL;
	return (new_dr);
}

void	add_dr(t_dir **lst_dr, char *path, struct dirent *de)
{
	t_dir	*current;

	current = *lst_dr;
	if (current == NULL)
		*lst_dr = new_dr(path, de);
	else
	{
		while (current->next)
			current = current->next;
		current->next = new_dr(path, de);
	}
	free(path);
}

void	print_list(t_dir *lst_dr, char *options)
{
	t_dir			*current;
	t_env			len;

	current = lst_dr;
	if (options[l] == 'l' && is_dir(current->path) && !options[r])
		print_total_l(current, options);
	while (current)
	{
		if (options[a] != 'a' && basename(current->name)[0] == '.')
		{
			current = current->next;
			continue;
		}
		if (options[l] == 'l')
		{
			init_z(&len);
			len_finder(lst_dr, options, &len);
			print_l(current, len, options);
		}
		print_name(current, options);
		ft_putchar('\n');
		current = current->next;
	}
}

t_dir	*name_dr(char *name)
{
	t_dir	*new_dr;

	if (!(new_dr = (t_dir *)malloc(sizeof(t_dir))))
		return (NULL);
	new_dr->name = ft_strdup(name);
	new_dr->path = ft_strdup(name);
	new_dr->next = NULL;
	return (new_dr);
}

void	ad_name(t_dir **lst_dr, char *name)
{
	t_dir	*current;

	current = *lst_dr;
	if (current == NULL)
		*lst_dr = name_dr(name);
	else
	{
		while (current->next)
			current = current->next;
		current->next = name_dr(name);
	}
}
