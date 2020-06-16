# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anime <anime@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/24 14:08:46 by whybread          #+#    #+#              #
#    Updated: 2020/06/10 22:36:32 by anime            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HEAD = ./
OBJ_DIR = ./obj
INC_DIR = ./
SRC_DIR = ./

SRC =  ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
		ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c \
		ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c \
		ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_atoi.c \
		ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
		ft_isprint.c ft_toupper.c ft_tolower.c ft_memalloc.c \
		ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c \
		ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c \
		ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c \
		ft_strsplit.c ft_itoa.c ft_itoa_base.c ft_putchar.c ft_putstr.c \
		ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c \
		ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstdelone.c \
		ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_strupcase.c \
		ft_strlowcase.c ft_strcapitalize.c ft_str_is_alpha.c ft_str_is_numeric.c \
		ft_max.c ft_swap.c ft_free_mem_2d.c ft_abs.c ft_min.c get_next_line.c \
		ft_bubble_sort.c ft_strjoin_with.c ft_strcmp_lower.c \
		ft_printf.c input_info.c type_execution.c type_execution_part2.c \
		all_for_int_uint.c ft_itoa_printf.c show_int_uint.c \
		ft_uitoa_printf.c conversion.c all_for_octa.c \
		show_octa.c all_for_hex.c show_hex.c all_for_pointer_and_percent.c \
		show_pointer.c all_for_char_string.c bonus_functions.c \
		all_for_float.c show_float.c show_float_part2.c

FLAGS = -Wall -Werror -Wextra

HEADERS_LIST = 	libft.h \
				get_next_line.h \
				ft_printf.h

HEADERS = $(addprefix $(INC_DIR)/, $(HEADERS_LIST))

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

INCLUDES = -I $(INC_DIR)

all : $(NAME)

$(NAME): obj_mkdir $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	@echo "\033[34mCOMPILING\033[0m" $< 
	@gcc $(FLAGS) -o $@ -c $< $(INCLUDES)

obj_mkdir:
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -rf $(OBJ) $(OBJ_DIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
