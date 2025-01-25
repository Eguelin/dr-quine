# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/24 18:08:39 by eguelin           #+#    #+#              #
#    Updated: 2025/01/25 17:23:42 by eguelin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re test retest

# **************************************************************************** #
#                                   Variable                                   #
# **************************************************************************** #

NAME		= Dr_Quine
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
#                                     Rules                                    #
# **************************************************************************** #

all: $(NAME)

$(NAME):
	$(MAKE) -C Colleen
	$(MAKE) -C Grace
	$(MAKE) -C Sully

clean:
	$(MAKE) -C Colleen clean
	$(MAKE) -C Grace clean
	$(MAKE) -C Sully clean
	$(PRINT) $(CLEAN_MSG)

fclean:
	$(MAKE) -C Colleen fclean
	$(MAKE) -C Grace fclean
	$(MAKE) -C Sully fclean
	$(PRINT) $(FULL_CLEAN_MSG)

re: fclean all

test: all
	$(MAKE) -C Colleen test
	$(MAKE) -C Grace test
	$(MAKE) -C Sully test

retest: fclean test
