# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xrodrigu <xrodrigu@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/16 20:52:25 by xrodrigu          #+#    #+#              #
#    Updated: 2022/11/16 16:25:08 by xrodrigu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libft.a

SRC_DIR = src

IS_DIR = is

MATH_DIR = math

MEM_DIR = mem

PUTFD_DIR = put_fd

STR_DIR = str

TO_DIR = to

OBJ_DIR = .obj

DEP_DIR = .dep


#colors
DEL_LINE =  \033[2K
NC =		\033[0m
BLACK = 	\033[0;30m
RED = 		\033[0;31m
GREEN = 	\033[0;32m
YELLOW = 	\033[0;33m
BLUE = 		\033[0;34m
PURPLE = 	\033[0;35m
CYAN =	 	\033[0;36m
WHITE = 	\033[0;37m


IS_SRC =	ft_isalnum.c		ft_isalpha.c		ft_isascii.c \
			ft_isdigit.c		ft_isprint.c

MATH_SRC =	ft_absval.c			ft_atoi.c			ft_itoa.c \
			ft_ltoa_base.c		ft_ltoa.c			ft_nbrlen_base.c \
			ft_nbrlen.c			ft_unsignedlen_base.c \
			ft_unsignedlen.c	ft_unsignedtoa_base.c \
			ft_unsignedtoa.c

MEM_SRC =	ft_bzero.c			ft_calloc.c			ft_memchr.c \
			ft_memcmp.c			ft_memcpy.c			ft_memmove.c \
			ft_memset.c

PUTFD_SRC =	ft_putchar_fd.c		ft_putendl_fd.c		ft_putnbr_fd.c \
			ft_putstr_fd.c

STR_SRC =	ft_split.c			ft_strdup.c			ft_strjoin.c \
	  		ft_strlcpy.c		ft_strmapi.c		ft_strnstr.c \
	 		ft_strtrim.c		ft_strchr.c			ft_striteri.c \
	  		ft_strlcat.c  		ft_strlen.c			ft_strncmp.c \
			ft_strrchr.c		ft_substr.c

TO_SRC =	ft_tolower.c		ft_toupper.c


SRCS += $(addprefix $(SRC_DIR)/$(IS_DIR)/, $(IS_SRC))
SRCS += $(addprefix $(SRC_DIR)/$(MATH_DIR)/, $(MATH_SRC))
SRCS += $(addprefix $(SRC_DIR)/$(MEM_DIR)/, $(MEM_SRC))
SRCS += $(addprefix $(SRC_DIR)/$(PUTFD_DIR)/, $(PUTFD_SRC))
SRCS += $(addprefix $(SRC_DIR)/$(STR_DIR)/, $(STR_SRC))
SRCS += $(addprefix $(SRC_DIR)/$(TO_DIR)/, $(TO_SRC))

OBJ = $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(basename $(SRCS))))

DEP = $(addprefix $(DEP_DIR)/, $(addsuffix .d, $(basename $(SRCS))))


MAKEFILE = Makefile

AR = ar -rcs

CFLAGS = -Wall -Wextra -Werror -W #-Ofast -O3 -fsanitize=address -g3

DEP_FLAGS = -MT $@ -MMD -MP

INCLUDE = -Iinclude/

RM = rm -f

RM_DIR = rm -rf


$(OBJ_DIR)/%.o: %.c $(MAKEFILE)
	@mkdir -p $(dir $@) $(dir $(subst $(OBJ_DIR)/, $(DEP_DIR)/, $@))
	@printf "${DEL_LINE}\r${CYAN}[LIBFT]compiling... $@${NC}"
	@$(CC) $(CFLAGS) $(DEP_FLAGS) $(INCLUDE) -c $< -o $@
	@mv $(patsubst %.o, %.d, $@) $(dir $(subst $(OBJ_DIR)/, $(DEP_DIR)/, $@))


all:
	@$(MAKE) $(NAME)


$(NAME): $(OBJ)
	@printf "${DEL_LINE}\r${GREEN}[LIBFT]->Objects and dependencies compiled.${NC}\n"
	@$(AR) $(NAME) $(OBJ)
	@printf "${DEL_LINE}\r${GREEN}[LIBFT]->Library created.${NC}\n"


clean:
	@$(RM_DIR) $(OBJ_DIR) $(DEP_DIR)
	@printf "${GREEN}[LIBFT]->Objects directory ${RED}deleted ${GREEN}successfully.${NC}\n"
	@printf "${GREEN}[LIBFT]->Dependencies directory ${RED}deleted ${GREEN}successfully.${NC}\n"


fclean:
	@$(MAKE) clean
	@$(RM) $(NAME)
	@printf "${GREEN}[LIBFT]->All files cleaned!${NC}\n"


re:
	@$(MAKE) fclean
	@$(MAKE) all


-include $(DEP)

.PHONY: all clean fclean re
