# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppoursaf <ppoursaf@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/07 06:03:49 by ppoursaf          #+#    #+#              #
#    Updated: 2017/07/09 10:23:39 by ppoursaf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC_PATH = ./libft/

MINILIBX_PATH = ./minilibx_macos

SRCS_FDF = main.c
FLAGS =  -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME):
	@clear
	@echo " ____________________________________________ "
	@echo "|                                            |"
	@echo "|                     FDF                    |"
	@echo "|                     ~~~                    |"
	@echo "| __________________________________________ |"
	@echo "|                                            |"
	@echo "|                 Make Minilix               |"
	@echo "|                  __________                |"
	@echo "|                                            |"
	@echo "|                                            |"
	@echo "|____________________________________________|"
	@make -C $(MINILIBX_PATH) > /dev/null
	@sleep 1
	@clear
	@echo " ____________________________________________ "
	@echo "|                                            |"
	@echo "|                     FDF                    |"
	@echo "|                     ~~~                    |"
	@echo "| __________________________________________ |"
	@echo "|                                            |"
	@echo "|                  Make Libft                |"
	@echo "|                  __________                |"
	@echo "|               ________________             |"
	@echo "|                                            |"
	@echo "|____________________________________________|"
	@make -C $(SRC_PATH) > /dev/null
	@sleep 1
	@clear
	@echo " ____________________________________________ "
	@echo "|                                            |"
	@echo "|                     FDF                    |"
	@echo "|                     ~~~                    |"
	@echo "| __________________________________________ |"
	@echo "|                                            |"
	@echo "|                  Compliling                |"
	@echo "|                  __________                |"
	@echo "|               ________________             |"
	@echo "|           ________________________         |"
	@echo "|____________________________________________|"
	@gcc  -o $(NAME) $(FLAGS) ./minilibx_macos/libmlx.a ./libft/libft.a $(SRCS_FDF) > /dev/null
	@sleep 1
	@clear
	@echo " ____________________________________________ "
	@echo "| _______        ____________        _______ |"
	@echo "| _________    ________________    _________ |"
	@echo "| _________    _____D O N E____    _________ |"
	@echo "| _______        ____________        _______ |"
	@echo "|____________________________________________|"

clean:
	@make clean -C $(SRC_PATH) > /dev/null

fclean: clean
	@/bin/rm -f $(NAME) > /dev/null
	@/bin/rm -f ./libft/libft.a > /dev/null

re: fclean all
