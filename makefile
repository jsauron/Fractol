# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsauron <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/29 23:58:29 by jsauron           #+#    #+#              #
#    Updated: 2018/09/04 21:11:26 by jsauron          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
 NAME = fractol

 SRCS_DIR = srcs/

 SRC = srcs/main.c \
	srcs/hook.c \
	srcs/drawing.c \
	srcs/error.c \
	srcs/image.c \
	srcs/init.c \
	srcs/init_fractal.c \
	srcs/tools.c \
	srcs/matrice.c \
	srcs/draw_3D.c \
	srcs/threadpool.c \
	srcs/threadpool_helper.c\
	srcs/buddha.c\
	srcs/julia.c \
	srcs/mandelbrot.c\
	srcs/event.c

OBJS = $(SRC:.c=.o)

INCLUDES = includes/

MLX = -L ./minilibx_macos -lmlx -framework OpenGL -framework AppKit

PTHREAD = -l pthread 

DONE = "\033[35m Fractol ready\033[0m"

all: lib $(NAME)

$(NAME):$(OBJS)
	@gcc -fsanitize=address -O3  -Wall -Wextra -Werror -o $(NAME) libft/libft.a $(OBJS) -I $(INCLUDES) $(MLX) $(PTHREAD)
	@echo $(DONE)

lib:
	@make -j -C libft/ libft.a

%.o: %.c $(INCLUDES)fractol.h
	@gcc -O3 -Wall -Wextra -Werror -o $@ -c $<

clean:
	@rm -f $(OBJS) && make -C libft/ clean

fclean: clean
	@rm -f $(NAME) && make -C libft/ fclean

re: fclean 
	@$(MAKE)
.PHONY: all clean fclean re 
