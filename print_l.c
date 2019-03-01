/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_l.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhadraou <hhadraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 13:44:13 by hhadraou          #+#    #+#             */
/*   Updated: 2019/01/21 22:16:11 by hhadraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_l(t_dir *lst_dr, t_env abbah, char *options)
{
	t_dir		*temp;
	struct stat	fstat;

	temp = lst_dr;
	lstat(temp->path, &fstat);
	ft_permissions(temp, fstat);
	spacer(ft_itoa(fstat.st_nlink), abbah.n_link, 'p');
	ft_putstr(" ");
	spacer(ft_strdup(getpwuid(fstat.st_uid)->pw_name), abbah.usr, 's');
	ft_putstr(" ");
	spacer(ft_strdup(getgrgid(fstat.st_gid)->gr_name), abbah.grp, 's');
	spacer(ft_itoa(fstat.st_size), abbah.size, 'p');
	ft_putstr(" ");
	temp->time = fstat.st_mtime;
	get_time(fstat, temp, options);
}

void	ft_permissions(t_dir *temp, struct stat fstat)
{
	ssize_t	attr;
	acl_t	acl;

	acl = acl_get_link_np(temp->path, ACL_TYPE_EXTENDED);
	attr = listxattr(temp->path, NULL, 0, XATTR_NOFOLLOW);
	if (S_ISLNK(fstat.st_mode))
		ft_putchar('l');
	else if (S_ISDIR(fstat.st_mode))
		ft_putchar('d');
	else
		ft_putchar('-');
	ft_putchar((fstat.st_mode & S_IRUSR) ? 'r' : '-');
	ft_putchar((fstat.st_mode & S_IWUSR) ? 'w' : '-');
	set_uid_perms(fstat);
	ft_putchar((fstat.st_mode & S_IRGRP) ? 'r' : '-');
	ft_putchar((fstat.st_mode & S_IWGRP) ? 'w' : '-');
	set_gid_perms(fstat);
	ft_putchar((fstat.st_mode & S_IROTH) ? 'r' : '-');
	ft_putchar((fstat.st_mode & S_IWOTH) ? 'w' : '-');
	set_stickybit_perms(fstat);
	if (acl || attr)
		get_attr(attr, acl);
	else
		ft_putchar(' ');
}

char	*get_user(struct stat fstat)
{
	char			*str;
	struct passwd	*pw;
	struct group	*gr;

	pw = getpwuid(fstat.st_uid);
	gr = getgrgid(fstat.st_gid);
	str = ft_strjoin(ft_strjoin(pw->pw_name, "  "), gr->gr_name);
	return (ft_strjoin(str, "  "));
}

void	get_time(struct stat fstat, t_dir *temp, char *options)
{
	char	buff[13];
	char	*str;
	char	buf[64];
	size_t	len;

	(void)fstat;
	str = ctime(&temp->time);
	ft_memcpy(buff, &str[4], 12);
	buff[12] = '\0';
	ft_putstr(buff);
	ft_putstr(" ");
	if (S_ISLNK(fstat.st_mode))
	{
		if (options[G] == 'G')
			ft_putstr(ANSI_COLOR_MAGENTA);
		ft_putstr(temp->name);
		if (options[G] == 'G')
			ft_putstr(ANSI_COLOR_RESET);
		ft_putstr(" -> ");
		len = readlink(temp->path, buf, 64);
		buf[len] = '\0';
		ft_putstr(buf);
	}
}

void	init_z(t_env *emm)
{
	emm->n_link = 0;
	emm->grp = 0;
	emm->size = 0;
	emm->usr = 0;
}
