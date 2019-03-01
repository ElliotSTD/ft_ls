/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melalj <melalj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 00:25:50 by melalj            #+#    #+#             */
/*   Updated: 2018/11/09 05:38:24 by melalj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			new_line(char *s)
{
	int		i;
	char	*c_s;

	i = 0;
	c_s = ft_strdup(s);
	while (c_s[i])
	{
		if (c_s[i] == '\n')
			return (1);
		i++;
	}
	free(c_s);
	return (0);
}

t_file		*fd_exist(t_file **lst, int fd)
{
	t_file	*current;

	current = *lst;
	while (current != 0)
	{
		if (current->fd == fd)
			return (current);
		current = current->next;
	}
	return (NULL);
}

t_file		*lstfile_new(const char *content, int fd)
{
	t_file *new;

	if (!(new = (t_file *)malloc(sizeof(t_file))))
		return (NULL);
	new->next = NULL;
	if (!content)
	{
		new->stock = NULL;
		new->fd = fd;
	}
	else
	{
		new->stock = (char *)malloc(ft_strlen(content));
		new->stock = ft_memcpy(new->stock, content, ft_strlen(content));
		new->fd = fd;
	}
	return (new);
}

t_file		*lstfile_add(t_file *head, t_file *new)
{
	t_file *start;

	start = head;
	while (start->next)
		start = start->next;
	start->next = new;
	return (new);
}

int			get_next_line(const int fd, char **text)
{
	static t_file	*lst;
	t_file			*current;
	int				ret;
	char			buff[BUFF_SIZE + 1];

	if (fd < 0 || (read(fd, buff, 0) < 0) || !text)
		return (-1);
	lst = (lst == NULL) ? lstfile_new("", -1) : lst;
	if (!(current = fd_exist(&lst, fd)))
		current = lstfile_add(lst, lstfile_new("", fd));
	ret = read(fd, buff, BUFF_SIZE);
	if (ret == -1)
		return (ret);
	buff[ret] = '\0';
	current->stock = ft_strjoin(current->stock, buff);
	while (!new_line(buff) && (ret = read(fd, buff, BUFF_SIZE)))
	{
		buff[ret] = '\0';
		current->stock = ft_strjoin(current->stock, buff);
	}
	*text = ft_strcut(current->stock, '\n');
	ret = (current->stock[0] == '\0') ? 0 : 1;
	current->stock += ft_strlen(*text) + new_line(current->stock);
	return (ret);
}
