# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fruiz-ca <fruiz-ca@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/27 11:40:49 by fruiz-ca          #+#    #+#              #
#    Updated: 2023/05/29 10:44:18 by fruiz-ca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= so_long
#CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast
LIBMLX	:= ./lib/MLX42
LIBFT	:= ./lib/libft

HEADERS	:= -I ./include -I $(LIBMLX)/include -I $(LIBFT)
LIBS	:= $(LIBMLX)/libmlx42.a $(LIBFT)/libft.a -ldl -lglfw -pthread -lm
LIBS	:= $(LIBMLX)/libmlx42.a $(LIBFT)/libft.a -lglfw -L /Users/${USER}/.brew/opt/glfw/lib/
SRCS	:= $(shell find ./src -iname "*.c")
OBJS	:= ${SRCS:.c=.o}

all: libft libmlx $(NAME)

libmlx:
	@$(MAKE) -C $(LIBMLX)

libft:
	@$(MAKE) -C $(LIBFT)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -f $(OBJS)
	@$(MAKE) -C $(LIBMLX) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBMLX) fclean

re: clean all

.PHONY: all, clean, fclean, re, libmlx