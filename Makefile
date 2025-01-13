# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agraille <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/16 10:58:27 by agraille          #+#    #+#              #
#    Updated: 2025/01/13 23:11:31 by agraille         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC=cc
CFLAGS=-Wall -Wextra -Werror
SRC = src/main.c src/pipex.c src/pipex_utils.c src/exec.c
OBJ_DIR = obj
OBJ	= $(addprefix $(OBJ_DIR)/,$(SRC:%.c=%.o))

LIBFT_DIR = ./libft
LIBFT_A = $(LIBFT_DIR)/libft.a
LIBFT_SRC = $(wildcard $(LIBFT_DIR)/*/*.c)
LIBFT_HEADERS = $(wildcard $(LIBFT_DIR)/include/*.h)
LIBFT_OBJ = $(LIBFT_SRC:.c=.o)
LIBFT_FLAGS = -L$(LIBFT_DIR) $(LIBFT_A)

PRINTF_DIR = ./printf
PRINTF_A = $(PRINTF_DIR)/ft_printf.a
PRINTF_SRC = $(wildcard $(PRINTF_DIR)/*/*.c)
PRINTF_HEADERS = $(wildcard $(PRINTF_DIR)/include/*.h)
PRINTF_OBJ = $(PRINTF_SRC:.c=.o)
PRINTF_FLAGS = -L$(PRINTF_DIR) $(PRINTF_A)

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_A) $(PRINTF_A)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT_FLAGS) $(PRINTF_FLAGS) -o $(NAME)
	@echo "$(GREEN)╔═══════════════════════════╗$(RESET)"
	@echo "$(GREEN)║   Compilation Succes! ✅  ║$(RESET)"
	@echo "$(GREEN)╚═══════════════════════════╝$(RESET)"

$(LIBFT_A): $(LIBFT_SRC) $(LIBFT_HEADERS)
	$(MAKE) -C $(LIBFT_DIR)

$(PRINTF_A): $(PRINTF_SRC) $(PRINTF_HEADERS)
	$(MAKE) -C $(PRINTF_DIR)

$(OBJ_DIR)/%.o: %.c Makefile ./include/pipex.h
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I . -c $< -o $@


clean :
	@rm -rf $(OBJ) $(OBJ_DIR)/
	@$(MAKE) clean -C $(LIBFT_DIR)
	@$(MAKE) clean -C $(PRINTF_DIR)
	@echo "$(GREEN)╔═══════════════════════════╗$(RESET)"
	@echo "$(GREEN)║        Clean OK! 🧽       ║$(RESET)"
	@echo "$(GREEN)╚═══════════════════════════╝$(RESET)"

fclean :
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@$(MAKE) fclean -C $(PRINTF_DIR)
	@rm -rf $(NAME) $(OBJ) $(OBJ_DIR)
	@echo "$(GREEN)╔═══════════════════════════╗$(RESET)"
	@echo "$(GREEN)║        Fclean OK! 🪣       ║$(RESET)"
	@echo "$(GREEN)╚═══════════════════════════╝$(RESET)"

re : fclean all

.PHONY : all re fclean clean
