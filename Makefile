# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hhadraou <hhadraou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/13 08:54:25 by hhadraou          #+#    #+#              #
#    Updated: 2019/01/18 15:57:49 by hhadraou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRC = main.c\
sort.c\
print_l.c\
tools1.c\
tools2.c\
tools3.c\
tools4.c\
list_dir.c\
helper.c

OBJ = $(SRC:.c=*.o)

all : $(NAME)

$(NAME) :
		make re -C ./libft
		make clean -C ./libft
		gcc -Wall -Wextra -Werror -c $(SRC)
		gcc $(OBJ) libft/libft.a -o $(NAME)

clean :
		/bin/rm -f *.o

fclean : clean
		/bin/rm -f $(NAME)

re : fclean all clean