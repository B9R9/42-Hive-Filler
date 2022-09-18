# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: briffard <briffard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/03 11:42:00 by briffard          #+#    #+#              #
#    Updated: 2022/09/18 14:23:31 by briffard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = briffard.filler

#COMPILATION
CC		=	gcc
CCFLAGS	=	-Werror -Wextra -Wall
LIB_LFT	=	-L ./libft/ -lft

#INCLUDE
INCL	=	-I ./includes
INCL_LFT=	-I ./libft/includes

#CLEAN & FCLEAN
RM_DIR	=	rm -rf
RM		=	rm	-f

#SOURCE FILES
SRC_DIR	=	./src/
FILES	=	main.c utils.c		\
			malloc_handler.c	\
			exit.c				\
			value_init.c		\
			player_info.c		\
			free_handler.c		\
			get_lines.c			\
			set_map.c			\

#OBJECT FILES
OBJ_DIR			=	./objectFiles/
OBJS		=	$(addprefix $(OBJ_DIR), $(FILES:%.c=%.o))

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CCFLAGS) -o $(NAME) $(OBJS) $(LIB_LFT)

$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CCFLAGS) $(INCL_LFT) $(INCL) -o $@ -c $<

lft:
	@make -sC ./libft/ all

re_lft:
	@make -sC ./libft/ re

clean_lft:
	@make -sC ./libft/ clean

fclean_lft:
	@make -sC ./libft/ fclean

clean:
	@$(RM_DIR) $(OBJ_DIR)
	@echo "Object Files have been deleted"
	@$(RM) *.txt
	@$(RM) *.trace

fclean: clean
	@$(RM) $(NAME)
	@echo "Player file has been deleted"

re: fclean all

.PHONY: all re clean fclean
