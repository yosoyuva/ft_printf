# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/14 15:27:25 by ymehdi            #+#    #+#              #
#    Updated: 2020/05/14 22:10:33 by ymehdi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a

SRC_PATH = ./src/

SRC_NAME =	ft_add_c_to_end_of_s.c\
			ft_check.c\
			ft_funcpy.c\
			ft_get_flag.c\
			ft_get_type_and_flag.c\
			ft_parsing.c\
			ft_printf_c.c\
			ft_printf_d.c\
			ft_printf_i.c\
			ft_printf_p.c\
			ft_printf_percent.c\
			ft_printf_s.c\
			ft_printf_u.c\
			ft_printf.c\
			ft_printf_x.c\

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ_PATH = ./obj/

INC_PATH = ./lib/

OBJ_NAME = $(SRC_NAME:.c=.o)

OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

LDFLAGS = -L./lib/

LIB = ./lib/libft.a

CC = gcc $(CFLAGS)

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@make -C ./lib/
	@echo "\033[34mCreation of $(NAME) ...\033[0m"
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\033[32m$(NAME) created\n\033[0m"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) -o $@ -c $<

clean:
	@make clean -C ./lib/
	@echo "\033[33mRemoval of .o files of $(NAME) ...\033[0m"
	@rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@echo "\033[31mFiles .o deleted\n\033[0m"

fclean: clean
	@make fclean -C ./lib/
	@echo "\033[33mRemoval of $(NAME)...\033[0m"
	@rm -f $(NAME)
	@echo "\033[31mBinary $(NAME) deleted\n\033[0m"

re: fclean all

git:
	@git add .
	@git commit -m "$(NAME)"
	@git push

norme:
	norminette $(SRC)
	norminette $(INC_PATH)*.h

.PHONY: all, clean, fclean, re
