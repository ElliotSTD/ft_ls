/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melalj <melalj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 13:43:35 by melalj            #+#    #+#             */
/*   Updated: 2018/10/25 16:32:01 by melalj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddend(t_list **alst, void *content, size_t content_size)
{
	t_list	*new;
	t_list	*last;

	last = *alst;
	new = ft_lstnew(content, content_size);
	if (last == NULL)
		last = new;
	else
	{
		while (last->next != NULL)
			last = last->next;
		last->next = new;
	}
}
