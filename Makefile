NAME		:= cub3D

CC			:=	cc
CFLAGS		:=	-Wall -Wextra -Werror -g

FILES		:=	angles.c \
				color.c \
				cub_start.c \
				draw.c \
				draw_utils.c \
				extra_func.c \
				hook.c \
				key_handler.c \
				main.c \
				maper.c \
				parse_map.c \
				raycast.c \
				types.c \
				vector.c \
				walls.c \
				more_extra_func.c
SRCS		:=	$(addprefix src/, $(FILES))
OBJS		:=	$(addprefix obj/, $(FILES:.c=.o))

LIBFTDIR	:= lib/libft
MLXDIR		:= lib/MLX42

INCS		:= -Iinc -I$(LIBFTDIR)/inc -I$(MLXDIR)/include/MLX42
LIBS		:= $(LIBFTDIR)/libft.a $(MLXDIR)/build/libmlx42.a -ldl -lglfw -pthread -lm

all: $(NAME)

$(NAME): dir $(OBJS) libft mlx
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

obj/%.o: src/%.c
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

libft:
	make -sC $(LIBFTDIR)

mlx:
	cmake $(MLXDIR) -B $(MLXDIR)/build && make -C $(MLXDIR)/build -j4

dir:
	-mkdir -p obj

clean:
	-rm -r obj
	-make -sC $(LIBFTDIR) clean
	-make -sC $(MLXDIR)/build clean

fclean: clean
	-rm $(NAME)
	-make -sC $(LIBFTDIR) fclean
	-rm -r $(MLXDIR)/build

re: fclean all

.PHONY: all libft mlx dir clean fclean re
