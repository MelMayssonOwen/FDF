# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: melowen <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/01 00:51:30 by melowen           #+#    #+#              #
#    Updated: 2017/07/08 12:19:18 by mowen            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all: 	
	$(LIBS)
	$(NAME)

LIBMLX = /Users/melowen/projects/Sources/minilibx_macos/Makefile
$(LIBS):
	@make -c$(LIBMLX)
	gcc -o mlx main.c draw.c -lmlx -framework OpenGL framework AppKit -L ../Sources/minilibx_macos/libmlx.a
