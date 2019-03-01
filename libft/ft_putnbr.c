/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melalj <melalj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 05:18:34 by melalj            #+#    #+#             */
/*   Updated: 2018/10/21 14:34:48 by melalj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		if (n == -2147483648)
		{
			n /= 10;
			ft_putnbr(-1 * n);
			ft_putchar('8');
			return ;
		}
		else
		{
			ft_putnbr(-1 * n);
			return ;
		}
	}
	else if (n / 10)
	{
		ft_putnbr(n / 10);
	}
	ft_putchar('0' + (n % 10));
}
