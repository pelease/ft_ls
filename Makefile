# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anime <anime@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/24 14:37:58 by whybread          #+#    #+#              #
#    Updated: 2020/06/11 02:55:36 by anime            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

INC = ./

SRC_DIR = ./src
INC_DIR = ./inc
OBJ_DIR = ./obj
LIBFT_DIR = libft
LIBFT_HEADER = $(LIBFT_DIR)/libft.h
LIBFT = $(LIBFT_DIR)/libft.a
FLAGS = -Wall -Werror -Wextra
#FRAMEWORK = -lmlx -framework OpenGL -framework AppKit
# FRAMEWORK = -L/usr/X11/lib /usr/X11/lib/libmlx.a -lXext -lX11

SRC = 	ft_ls.c \
		utils.c \
		init.c \
		parse_args.c \
		create_file_list.c \
		set_file_info.c		\
		parse_result.c \
		find_sort_type.c \
		free_memory.c

HEADERS_LIST = 	ft_ls.h \
				errors.h \
				
HEADERS = $(addprefix $(INC_DIR)/, $(HEADERS_LIST))
# HEADERS += $(FT_PRINTF_HEADER)
# HEADERS += $(LIBFT_HEADER)

INCLUDES = -I $(INC_DIR) -I $(LIBFT_DIR)

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

all: $(NAME)

$(NAME): obj_mkdir lib $(OBJ)
	@gcc $(FLAGS) $(OBJ) -o $(NAME) $(LIBFT)
	@echo "$(NAME) binary \033[32mcreated\033[0m."

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	@echo "\033[34mCOMPILING\033[0m" $< 
	@gcc $(FLAGS) -o $@ -c $< $(INCLUDES)

obj_mkdir:
	@mkdir -p $(OBJ_DIR)

lib:
	@make -C $(LIBFT_DIR)

clean:
	@rm -rf $(OBJ) $(OBJ_DIR)
	@make clean -C $(LIBFT_DIR)

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C $(LIBFT_DIR)

re: fclean all
