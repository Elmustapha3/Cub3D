# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maneddam <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/30 10:53:41 by eej-jama          #+#    #+#              #
#    Updated: 2023/08/04 19:06:25 by maneddam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CFLAGS = -Wall -Wextra -Werror

FT_SRC = \
ft_atoi.c   ft_isalpha.c ft_isdigit.c  ft_strchr.c  ft_strjoin.c ft_strncmp.c ft_substr.c\



FT_BONUS_SRC = \
ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c \
ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstclear_bonus.c ft_lstmap_bonus.c


OBJ = $(FT_SRC:.c=.o)
BONUS_OBJ = $(FT_BONUS_SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar -rc $(NAME) $(OBJ)

bonus: $(BONUS_OBJ)
	@ar -rc $(NAME) $(BONUS_OBJ)


clean:
	@rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

