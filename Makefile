CC := 		gcc

RM := 		rm -rf

CFLAGS := `sdl-config --libs --cflags` -lSDL_image -lSDL_mixer

SRC :=		main.c \
					grid.c \
					check.c \
					bases.c

OBJ := 		$(SRC:.c=.o)

NAME := 	sokoban

all: 			$(NAME)

$(NAME):	$(OBJ)
					$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
					$(RM) $(OBJ)

fclean:		clean
					$(RM) $(NAME)

re:				fclean all
