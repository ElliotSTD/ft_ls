# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hhadraou <haitamehadraoui@gmail.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/08 14:31:41 by hhadraou          #+#    #+#              #
#    Updated: 2018/10/23 07:09:45 by hhadraou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ./*.c

FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) :
	gcc -c $(FLAGS) $(SRC)
	ar rc $(NAME) *.o

clean : 
	/bin/rm -f *.o

fclean : clean
	/bin/rm -f $(NAME)

re : fclean all
