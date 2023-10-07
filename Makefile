NAME = cub3D
CFLAGS = -Wall -Wextra -Werror 
CC = @clang
FT_SRC = mandatory/cub3d.c mandatory/parsing/parsing.c mandatory/parsing/utils.c mandatory/parsing/infos.c mandatory/parsing/error.c mandatory/parsing/floorDetails.c\
mandatory/parsing/ceilingDetails.c mandatory/parsing/infos1.c mandatory/parsing/utils1.c mandatory/parsing/mapDetails.c mandatory/parsing/playerDetails.c mandatory/parsing/reformMap.c\
mandatory/raycasting/raycasting.c mandatory/raycasting/utils.c mandatory/raycasting/utils2.c mandatory/raycasting/casting.c\
mandatory/raycasting/p_mvmnt.c mandatory/raycasting/render_3d.c  mandatory/raycasting/utils3.c \
get_next_line/get_next_line_utils.c get_next_line/get_next_line.c \
libft/ft_strchr.c libft/ft_strdup.c libft/ft_strlen.c libft/ft_strjoin.c libft/ft_strcmp.c libft/ft_isdigit.c\
libft/ft_atoi.c libft/ft_split.c libft/ft_substr.c  libft/ft_calloc.c


FT_SRC_bonus = bonus/cub3d.c bonus/parsing/parsing.c bonus/parsing/utils.c bonus/parsing/infos.c bonus/parsing/error.c bonus/parsing/floorDetails.c\
bonus/parsing/ceilingDetails.c bonus/parsing/infos1.c bonus/parsing/utils1.c bonus/parsing/mapDetails.c bonus/parsing/playerDetails.c bonus/parsing/reformMap.c\
bonus/raycasting/raycasting.c bonus/raycasting/utils.c bonus/raycasting/utils2.c bonus/raycasting/casting.c\
bonus/raycasting/p_mvmnt.c bonus/raycasting/render_3d.c  bonus/raycasting/minimap.c bonus/raycasting/utils3.c \
get_next_line/get_next_line_utils.c get_next_line/get_next_line.c \
libft/ft_strchr.c libft/ft_strdup.c libft/ft_strlen.c libft/ft_strjoin.c libft/ft_strcmp.c libft/ft_isdigit.c\
libft/ft_atoi.c libft/ft_split.c libft/ft_substr.c


OBJ = $(FT_SRC:.c=.o)

OBJ_bonus = $(FT_SRC_bonus:.c=.o)

all: $(NAME)


$(NAME): $(OBJ)
	@make -C costumizing/
	@$(CC) $(CFLAGS) $(OBJ) -g -Lmlx_Linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

bonus : $(OBJ_bonus)
	@make -C costumizing/
	@$(CC) $(CFLAGS) $(OBJ_bonus) -Lmlx_Linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

clean:
	@rm -f $(OBJ) $(OBJ_bonus)
	@make -C libft clean

fclean: clean
	@make -C costumizing/ mse7
	@rm -f $(NAME)

re: fclean all
