# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/18 13:19:02 by cpirlot           #+#    #+#              #
#    Updated: 2018/02/27 10:13:43 by cpirlot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	=  lem-in

CC			= gcc
FLAGS		= -Wall -Werror -Wextra -g
SRC			= main.c parse.c list_utils.c
OBJDIR		= obj
OBJ	= $(addprefix $(OBJDIR)/,$(SRC:.c=.o))
VPATH:=includes/:${VPATH}
VPATH:=src/:${VPATH}

# PROGRESS BAR
T = $(words $(OBJ))
N = 0
C = $(words $N)$(eval N := x $N)
ECHO = "[`expr $C  '*' 100 / $T`%]"

#Colors
_GREY=\x1b[30m
_RED=\x1b[31m
_GREEN=\x1b[32m
_YELLOW=\x1b[33m
_BLUE=\x1b[34m
_PURPLE=\x1b[35m
_CYAN=\x1b[36m
_WHITE=\x1b[37m
_END=\x1b[0m

all: $(NAME)

$(NAME): lib $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) -o $@ -I includes/ -L libft/ -lft
	@echo "\nLem in compilation : $(_CYAN)done$(_END)"

$(OBJDIR)/%.o: %.c
	@mkdir -p obj
	@printf "%-60b\r" "$(ECHO) $(_CYAN) Compiling $@ $(_END)"
	@$(CC) $(FLAGS) -c $< -o $@ -I includes/ -I libft/includes/

lib:
	@make -C libft/
	@echo "\nLibft compilation : $(_CYAN)done$(_END)"

dev: $(NAME)

clean:
	@$(RM) -rf $(OBJDIR)
	@make clean -C libft/
	@echo "clean lem in: $(_CYAN)done$(_END)"

fclean: clean
	@$(RM) -f $(NAME)
	@$(RM) -f resources/players/$(NAME)
	@$(RM) -f resources/$(NAME)
	@make fclean -C libft/
	@echo "fclean lem in: $(_CYAN)done$(_END)"

re:
	@make fclean
	@make
	

.PHONY: all clean fclean re