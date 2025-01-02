# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agraille <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/07 08:03:50 by agraille          #+#    #+#              #
#    Updated: 2025/01/02 08:37:18 by agraille         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
CFLAGS=-Wall -Wextra -Werror
HEADER = include/libft.h
SRC = gnl/gnl.c gnl/gnl_utils.c is_check/ft_isalpha.c is_check/ft_isdigit.c is_check/ft_isalnum.c is_check/ft_isascii.c is_check/ft_isprint.c str/ft_strlen.c mem/ft_memset.c to/ft_bzero.c mem/ft_memcpy.c\
	mem/ft_memmove.c str/ft_strlcpy.c str/ft_strlcat.c to/ft_toupper.c to/ft_tolower.c str/ft_strchr.c str/ft_strrchr.c str/ft_strncmp.c mem/ft_memchr.c mem/ft_memcmp.c str/ft_strnstr.c convert/ft_atoi.c calloc/ft_calloc.c str/ft_strdup.c\
	str/ft_substr.c str/ft_strjoin.c str/ft_strtrim.c split/ft_split.c convert/ft_itoa.c fd_print/ft_putchar_fd.c fd_print/ft_putnbr_fd.c fd_print/ft_putstr_fd.c fd_print/ft_putendl_fd.c chain_list/ft_lstnew.c chain_list/ft_lstadd_front.c chain_list/ft_lstsize.c chain_list/ft_lstlast.c\
	chain_list/ft_lstadd_back.c chain_list/ft_lstdelone.c chain_list/ft_lstclear.c chain_list/ft_lstiter.c chain_list/ft_lstmap.c

OBJ_DIR = obj
OBJ	= $(addprefix $(OBJ_DIR)/,$(SRC:%.c=%.o))
NAME = libft.a

all: $(NAME)

$(OBJ_DIR)/%.o: %.c Makefile include/*.h
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	
$(NAME): $(OBJ) $(HEADER)
	ar rcs $(NAME) $(OBJ)

%.o: %.c include/libft.h
	@$(CC) $(CFLAGS) -I . -c $< -o $@

clean :
	@rm -rf $(OBJ) $(OBJ_DIR)/

fclean :
	@rm -rf $(NAME) $(OBJ) $(OBJ_DIR)/

re : fclean all

.PHONY : all re fclean clean bonus
