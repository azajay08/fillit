# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtissari <mtissari@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/01 20:00:07 by mtissari          #+#    #+#              #
#    Updated: 2022/04/07 18:52:55 by mtissari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY := all re clean fclean make
FILES := main.c 1_verify.c 2_modify.c 3_make_tet.c 4_grid.c 5_solver.c
INCLUDES := . libft/libft.a
FLAGS := -Wall -Wextra -Werror
NAME := fillit
LIBFT := libft/

$(NAME):
	make -C $(LIBFT)
	@gcc $(FLAGS) -I $(INCLUDES) $(FILES) -o $(NAME)

all: $(NAME)

clean:
	make -C $(LIBFT) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT) fclean

re: fclean all
