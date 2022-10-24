# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xrodrigu <xrodrigu@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/16 20:52:25 by xrodrigu          #+#    #+#              #
#    Updated: 2022/10/24 02:34:31 by xrodrigu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libft.a

BONUS = .bonus

SRC_DIR = src

OBJ_DIR = .obj

DEP_DIR = .dep

#colors
#N = no color text reset
#G = green
#R = red
N = \033[0m
G = \033[0;32m
R = \033[0;31m


SRC = ft_bzero.c		ft_isalpha.c	ft_isprint.c 	ft_memcpy.c \
	  ft_strchr.c		ft_strlcpy.c 	ft_strnstr.c 	ft_toupper.c \
	  ft_calloc.c 		ft_isascii.c	ft_memchr.c 	ft_memmove.c \
	  ft_strdup.c 		ft_strlen.c  	ft_strrchr.c	ft_atoi.c \
	  ft_isalnum.c 		ft_isdigit.c 	ft_memcmp.c 	ft_memset.c \
	  ft_strlcat.c 		ft_strncmp.c 	ft_tolower.c 	ft_substr.c \
	  ft_putchar_fd.c	ft_putstr_fd.c 	ft_putendl_fd.c ft_putnbr_fd.c \
	  ft_striteri.c		ft_strmapi.c 	ft_itoa.c 		ft_strjoin.c \
	  ft_strtrim.c		ft_split.c

SRC_BONUS = ft_lstnew.c			ft_lstadd_front.c	ft_lstsize.c \
			ft_lstlast.c		ft_lstadd_back.c 	ft_lstdelone.c \
			ft_lstclear.c		ft_lstiter.c		ft_lstmap.c


OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

OBJ_BONUS = $(addprefix $(OBJ_DIR)/, $(SRC_BONUS:.c=.o))


DEP = $(addprefix $(DEP_DIR)/, $(SRC:.c=.d))

DEP_BONUS = $(addprefix $(DEP_DIR)/, $(SRC_BONUS:.c=.d))


MAKEFILE = Makefile

AR = ar -rcs

CFLAGS = -Wall -Wextra -Werror -W #-Ofast -O3 -fsanitize=address -g3

DEP_FLAGS = -MT $@ -MMD -MP

INCLUDE = -Iinclude/

RM = rm -f

RM_DIR = rm -rf


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(MAKEFILE)
	@mkdir -p $(dir $@) $(DEP_DIR)/
	@$(CC) $(CFLAGS) $(DEP_FLAGS) $(INCLUDE) -c $< -o $@
	@mv $(patsubst %.o, %.d, $@) $(DEP_DIR)/

all: 
	@$(MAKE) $(NAME)


$(NAME): $(OBJ)
	@$(AR) $(NAME) $(OBJ)
	@echo "$(G)[LIBFT]->Objects and dependencies created.$(N)"
	@echo "$(G)[LIBFT]->Library created.$(N)"


$(BONUS): $(OBJ) $(OBJ_BONUS)
	@touch $@
	@$(AR) $(NAME) $(OBJ) $(OBJ_BONUS)
	@echo "$(G)[LIBFT]->Objects and dependencies created.$(N)"
	@echo "$(G)[LIBFT]->Library with bonus created.$(N)"


bonus: 
	@$(MAKE) $(BONUS)


clean:
	@$(RM_DIR) $(OBJ_DIR) $(DEP_DIR)
	@echo "$(G)[LIBFT]->Objects directory $(R)deleted$(N) $(G)successfully.$(N)"
	@echo "$(G)[LIBFT]->Dependencies directory $(R)deleted$(N) $(G)successfully.$(N)"


fclean: 
	@$(MAKE) clean
	@$(RM) $(NAME) $(BONUS)
	@echo "$(G)[LIBFT]->All files cleaned!$(N)"


re: 
	@$(MAKE) fclean 
	@$(MAKE) all


-include $(DEP)
-include $(DEP_BONUS)

.PHONY: all clean fclean re bonus
