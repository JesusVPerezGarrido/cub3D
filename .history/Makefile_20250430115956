NAME	:=	cub3D

CC			:=	cc
CFLAGS		:=	-Wall -Wextra -Werror -g

FILES		:=	main.c \
				cub_start.c \
				hook.c \
				angles.c \
				raycast.c \
				vector.c \
				color.c \
				draw.c \
				draw_utils.c
SRCS		:=	$(addprefix src/, $(FILES))
OBJS		:=	$(addprefix obj/, $(FILES:.c=.o))

LIBFTDIR	:=	lib/libft
LIBFTINC	:=	$(LIBFTDIR)/inc
LIBFT		:=	$(LIBFTDIR)/libft.a

MLX42DIR	:=	lib/MLX42
MLX42INC	:=	$(MLX42DIR)/include/MLX42
MLX42		:=	$(MLX42DIR)/build/libmlx42.a

LIBS		:=	$(LIBFT) $(MLX42) -ldl -lglfw -pthread -lm

INCS		:=	-Iinc -I$(LIBFTINC) -I$(MLX42INC)
HEADERS		:=	inc/cub3D.h \
				inc/angles.h \
				inc/raycast.h \
				inc/vector.h \
				inc/color.h \
				$(LIBFTINC)/libft.h \
				$(MLX42INC)/MLX42.h

all: $(NAME)

$(NAME): dir libft  mlx42 $(OBJS) $(HEADERS)
	$(CC) $(CFLAGS) $(INCS) $(OBJS) $(LIBS) -o $(NAME)

libft:
	make -sC lib/libft

mlx42:
	cmake $(MLX42DIR) -B $(MLX42DIR)/build && make -sC $(MLX42DIR)/build -j4

dir:
	mkdir -p obj

obj/%.o: src/%.c
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

clean:
	-rm -r obj
	make -sC lib/libft fclean
	rm -r $(MLX42DIR)/build

fclean: clean
	-rm $(NAME)

re: fclean all

.PHONY: all dir clean fclean re
