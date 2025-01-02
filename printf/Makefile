# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agraille <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/21 10:28:37 by agraille          #+#    #+#              #
#    Updated: 2025/01/02 08:38:46 by agraille         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
CFLAGS=-Wall -Wextra -Werror
HEADER = include/ft_printf.h
SRC = src/ft_printf.c src/ft_itoa.c src/ft_print_valid.c src/ft_print_hexa.c src/ft_print_ptr.c

OBJ_DIR = obj
OBJ	= $(addprefix $(OBJ_DIR)/,$(SRC:%.c=%.o))
NAME = ft_printf.a

all: $(NAME)

$(OBJ_DIR)/%.o: %.c Makefile include/*.h
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	
$(NAME): $(OBJ) $(HEADER)
	ar rcs $(NAME) $(OBJ)

%.o: %.c include/ft_printf.h
	@$(CC) $(CFLAGS) -I . -c $< -o $@

clean :
	@rm -rf $(OBJ) $(OBJ_DIR)/

fclean :
	@rm -rf $(NAME) $(OBJ) $(OBJ_DIR)/

re : fclean all

.PHONY : all re fclean clean bonus
