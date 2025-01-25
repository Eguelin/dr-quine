# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/24 18:08:39 by eguelin           #+#    #+#              #
#    Updated: 2025/01/25 18:32:38 by eguelin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re test retest

# **************************************************************************** #
#                                   Variable                                   #
# **************************************************************************** #

NAME		= Colleen
OBJS_DIR	= .objs/
AS			= nasm
AFLAGS		= -f elf64
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
PRINT		= @printf
RM			= rm -fr

# **************************************************************************** #
#                                    Colors                                    #
# **************************************************************************** #

BLACK	= \033[30m
RED		= \033[31m
GREEN	= \033[32m
YELLOW	= \033[33m
BLUE	= \033[34m
PURPLE	= \033[35m
CYAN	= \033[36m
WHITE	= \033[37m
DEFAULT	= \033[0m

# **************************************************************************** #
#                                    Message                                   #
# **************************************************************************** #

COMP_MSG		= "$(GREEN)Compilation $(NAME) $(DEFAULT)done on $(YELLOW)$(shell date +'%Y-%m-%d %H:%M:%S')$(DEFAULT)\n"
BONUS_COMP_MSG	= "$(BLUE)Compilation $(NAME) bonus $(DEFAULT)done on $(YELLOW)$(shell date +'%Y-%m-%d %H:%M:%S')$(DEFAULT)\n"
CLEAN_MSG		= "$(RED)Cleaning $(NAME) $(DEFAULT)done on $(YELLOW)$(shell date +'%Y-%m-%d %H:%M:%S')$(DEFAULT)\n"
FULL_CLEAN_MSG	= "$(PURPLE)Full cleaning $(NAME) $(DEFAULT)done on $(YELLOW)$(shell date +'%Y-%m-%d %H:%M:%S')$(DEFAULT)\n"

# **************************************************************************** #
#                                    Sources                                   #
# **************************************************************************** #

FILES	= Colleen.s

OBJS_FILES	= $(addprefix $(OBJS_DIR), $(FILES:.s=.o))

# **************************************************************************** #
#                                     Rules                                    #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(OBJS_FILES)
	$(CC) $(CFLAGS) $(OBJS_FILES) -o $(NAME)
	$(PRINT) $(COMP_MSG)

$(OBJS_DIR)%.o: %.s | $(OBJS_DIR)
	$(AS) $(AFLAGS) $< -o $@

clean:
	$(RM) $(OBJS_DIR)
	$(PRINT) $(CLEAN_MSG)

fclean: clean
	$(RM) $(NAME)
	$(RM) tmp_$(NAME)
	$(PRINT) $(FULL_CLEAN_MSG)

re: fclean all

$(OBJS_DIR):
	mkdir -p $@

test: all
	$(PRINT) "$(CYAN)Test $(NAME)$(DEFAULT)\n"
	./$(NAME)
	diff $(NAME).s tmp_$(NAME) || true

retest: fclean test
