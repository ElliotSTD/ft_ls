/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstget.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melalj <melalj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 20:06:54 by melalj            #+#    #+#             */
/*   Updated: 2018/10/25 21:46:32 by melalj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstget(t_list *alst, int index)
{
	t_list	*current;

	if (index < 0 || index > ft_lstlen(&alst))
		return (ft_lstnew("error", 6));
	current = alst;
	while (index > 0)
	{
		index--;
		current = current->next;
	}
	return (current);
}
