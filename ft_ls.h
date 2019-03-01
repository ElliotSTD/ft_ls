/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhadraou <hhadraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 03:06:16 by melalj            #+#    #+#             */
/*   Updated: 2019/01/21 00:21:39 by hhadraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <pwd.h>
# include <grp.h>
# include <sys/xattr.h>
# include <sys/acl.h>
# include <time.h>
# include <locale.h>
# include <errno.h>
# define ANSI_COLOR_RED     "\x1b[31m"
# define ANSI_COLOR_GREEN   "\x1b[32m"
# define ANSI_COLOR_YELLOW  "\x1b[33m"
# define ANSI_COLOR_BLUE    "\x1b[34m"
# define ANSI_COLOR_MAGENTA "\x1b[35m"
# define ANSI_COLOR_CYAN    "\x1b[36m"
# define ANSI_COLOR_RESET   "\x1b[0m"

typedef struct		s_dir
{
	char			*name;
	time_t			time;
	char			*path;
	struct s_dir	*next;
	char			err;
	char			type;
	int				size;
}					t_dir;

typedef struct		s_env
{
	int				n_link;
	int				usr;
	int				grp;
	int				size;
}					t_env;

enum {R, r, t, l, a, G, S};
char				*options_fill(char *arg, char *options);
void				usage(char c);
t_dir				*new_dr(char *path, struct dirent *de);
void				add_dr(t_dir **lst_dr, char *path, struct dirent *de);
void				print_list(t_dir *lst_dr, char *options);
char				*ft_pathjoin(char *dir, char *file);
void				sort_list(t_dir **head, int (*cmp)(t_dir, t_dir), int done);
void				reverse(t_dir **head);
void				reverse_util(t_dir *curr, t_dir *prev, t_dir **head);
void				home_dir(char *dir, char *options);
void				r_handler(t_dir *list, char *options);
void				list_free(t_dir	**list);
void				ad_name(t_dir **lst_dr, char *name);
t_dir				*name_dr(char *name);
int					iter_args(t_dir *args, char *options, int i);
int					is_dir(char *dir);
int					not_found(t_dir **list);
void				print_l(t_dir *lst_dr, t_env len, char *options);
void				print_total_l(t_dir *temp, char *options);
void				ft_permissions(t_dir *temp, struct stat fstat);
char				*get_user(struct stat fstat);
void				get_time(struct stat fstat, t_dir *temp, char *options);
int					compare_strings(t_dir d1, t_dir d2);
int					compare_time(t_dir d1, t_dir d2);
int					a_file(char *dir, char *options);
char				*basename(char *dir);
t_dir				*new_file(char *path, char *name);
void				add_file(t_dir **lst_dr, char *path, char *name);
void				print_name(t_dir *file, char *options);
void				spacer(char *s, int spaces, char mode);
void				len_finder(t_dir *lst_dr, char *options, t_env *len);
void				init_z(t_env *emm);
void				set_uid_perms(struct stat fstat);
void				set_gid_perms(struct stat fstat);
void				set_stickybit_perms(struct stat fstat);
void				r_or_rr(t_dir *lst_dr, char	*options);
int					compare_size(t_dir d1, t_dir d2);
int					ft_numlen(unsigned long long number);
void				init_lst(t_dir **t1, t_dir **t2);
void				ft_put2endl(char *s, int nb);
ssize_t				get_attr(ssize_t attr, acl_t acl);
#endif
