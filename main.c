/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhadraou <hhadraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 21:00:44 by melalj            #+#    #+#             */
/*   Updated: 2019/01/21 00:20:31 by hhadraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int ac, char **av)
{
	int		agn;
	char	*options;
	t_dir	*dr;
	t_dir	*file;

	options = ft_strdup("*******");
	agn = 0;
	while (++agn < ac)
	{
		if (ft_strequ(av[agn], "-"))
			break ;
		if ((av[agn][0] == '-' && av[agn][1] != '-') || av[agn][2] == '-')
			options = options_fill(&av[agn][1], options);
		else
			break ;
	}
	init_lst(&dr, &file);
	agn += ft_strequ(av[agn], "--") ? 1 : 0;
	while (agn < ac)
		is_dir(av[agn]) ? ad_name(&dr, av[agn++]) : ad_name(&file, av[agn++]);
	iter_args(dr, options, iter_args(file, options, 1));
	list_free(&file);
	list_free(&dr);
	free(options);
	return (0);
}

char	*options_fill(char *arg, char *opt)
{
	char *options;

	options = opt;
	while (*arg)
	{
		if (*arg == 'R')
			opt[R] = 'R';
		else if (*arg == 'a')
			opt[a] = 'a';
		else if (*arg == 'r')
			opt[r] = 'r';
		else if (*arg == 'l')
			opt[l] = 'l';
		else if (*arg == 't')
			opt[t] = 't';
		else if (*arg == 'G')
			opt[G] = 'G';
		else if (*arg == 'S')
			opt[S] = 'S';
		else
			usage(*arg);
		arg++;
	}
	return (options);
}

void	init_lst(t_dir **t1, t_dir **t2)
{
	*t1 = NULL;
	*t2 = NULL;
}

void	ft_put2endl(char *s, int nb)
{
	ft_putstr(s);
	ft_putnbr(nb);
	ft_putchar('\n');
}

ssize_t	get_attr(ssize_t attr, acl_t acl)
{
	if (attr > 0)
		ft_putchar('@');
	if (acl != NULL)
		ft_putchar('+');
	acl_free(acl);
	return (0);
}
