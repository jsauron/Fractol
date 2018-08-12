# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsauron <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/07 23:05:55 by jsauron           #+#    #+#              #
#    Updated: 2018/08/03 23:10:09 by jsauron          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS_DIR = srcs/

SRCS_BASE = ft_atoi.c \
	ft_lstdelone.c ft_putchar.c	ft_strclr.c	ft_strmap.c	ft_strsub.c \
	ft_bzero.c ft_lstiter.c	ft_putchar_fd.c	ft_strcmp.c	ft_strmapi.c ft_strswap.c \
	ft_foreach.c ft_lstmap.c ft_putendl.c ft_strcpy.c ft_strncat.c ft_strtrim.c \
	ft_is_neg.c	ft_lstnew.c	ft_putendl_fd.c	ft_strdel.c	ft_strncmp.c ft_strupcase.c \
	ft_isalnum.c ft_memalloc.c ft_putnbr.c ft_strdup.c ft_strncpy.c	ft_swap.c \
	ft_isalpha.c ft_memccpy.c ft_putnbr_fd.c ft_strequ.c ft_strnequ.c ft_tolower.c \
	ft_isascii.c ft_memchr.c ft_putstr.c ft_striter.c ft_strnew.c ft_toupper.c \
	ft_isdigit.c ft_memcmp.c ft_putstr_fd.c	ft_striteri.c ft_strnstr.c \
	ft_isprint.c ft_memcpy.c ft_range.c	ft_strjoin.c ft_strrchr.c \
	ft_itoa.c ft_memdel.c ft_sort_integer_table.c ft_strlcat.c ft_strrev.c \
	ft_lstadd.c	ft_memmove.c ft_strcat.c ft_strlen.c ft_strsplit.c \
	ft_lstdel.c	ft_memset.c	ft_strchr.c	ft_strlowcase.c	ft_strstr.c \
	s_word.c ft_count.c ft_isspace.c\
	get_next_line.c

SRCS = $(addprefix $(SRCS_DIR), $(SRCS_BASE))

OBJS_DIR = objs/

OBJS = $(addprefix $(OBJS_DIR), $(SRCS_BASE:.c=.o))


FLAGS = -Wall -Wextra -Werror -I includes
CC ?= gcc

all: 
	@$(MAKE) -j $(NAME)

$(NAME): $(OBJS) Makefile
	@ar rsc $@ $(OBJS)
	@echo "\033[38;5;002m Libft made ☑️  \033[0m"

$(OBJS_DIR):
	@mkdir  $@

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c Makefile | $(OBJS_DIR)
	@$(CC) $(FLAGS) -MMD -o $@ -c $<

clean:
	@if [ -d $(OBJS_DIR) ];\
	then \
		rm -rf $(OBJS_DIR);\
		echo clean; \
	fi

fclean: clean
	@if [ -f $(NAME) ];\
	then \
		rm -f $(NAME);\
		echo fclean; \
	fi

re: fclean
	@$(MAKE)

.PHONY: all clean fclean re

-include $(OBJS:.o=.d)
