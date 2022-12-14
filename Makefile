CC = gcc

PATH_MLX = ./minilibx-linux/

CFLAGS = -D BUFFER_SIZE=40 -Wall -Wextra -Werror

NAME =	so_long

DIR_INC = -I ./includes/

SRCS =	so_long.c \
		GNL/get_next_line.c \
		init_size_and_image.c \
		ft_split.c \
		initmap2.c \
		moves.c \
		parsing.c \
		initialisation_struct.c \
		parsing2.c \
		pathfinding2.c \
		libft.c \
		free.c \
		free_image.c \
		ft_printf/ft_convert2.c \
		ft_printf/ft_convert.c \
		ft_printf/ft_printf.c \
		ft_printf/ft_printf_utils.c \

SRCS_DIR = ./srcs

DIR_OBJ = 	obj

OBJS = $(addprefix $(DIR_OBJ)/, ${SRCS:.c=.o})

DEPS = $(OBJS:.o=.d)

-include $(DEPS)

all:	${NAME}

${NAME}: ${OBJS}
		${CC} $(DIR_INC) ${OBJS} -o ${NAME} -L $(PATH_MLX) -lmlx -lX11 -lXext

$(DIR_OBJ)/%.o: $(SRCS_DIR)/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(DIR_INC) -c -o $@ $< -MMD -g

clean:
		rm -rf ${DIR_OBJ}

fclean: clean
		rm -f ${NAME}

re: fclean all

.PHONY:	all clean fclean re