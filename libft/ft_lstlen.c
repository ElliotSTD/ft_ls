/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melalj <melalj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 14:26:21 by melalj            #+#    #+#             */
/*   Updated: 2018/10/25 21:38:04 by melalj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstlen(t_list **alst)
{
	t_list	*current;
	int		i;

	i = 0;
	current = *alst;
	while (current != 0)
	{
		i++;
		current = current->next;
	}
	return (i);
}
