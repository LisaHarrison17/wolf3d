NAME	=	wolf3d.a
HEADER	=	wolf3d.h
COMP	=	gcc
FLAGS	=	-Wall -Werror -Wextra
LIB_DIR = 	libft/
SRC 	= 	controls.c \
			read_file.c \
			render.c

all:		$(NAME)

$(NAME):
			@make -C ./libft/
			@$(COMP) -c $(SRC) $(FLAGS)
			@ar rcs $(NAME) *.o
			@ranlib $(NAME)
			@$(COMP) -o wolf3d wolf3d.c $(NAME) -lmlx -framework OpenGL -framework AppKit -L ./libft/ -lft
			@echo "-- WOLF3D COMPILED --"

%.o:		$(HEADER)

clean:
			@/bin/rm -rf *.o
			@/bin/rm -rf ./libft/*.o

fclean: 	clean
			@/bin/rm -rf $(NAME)
			@/bin/rm -rf wolf3d
			@/bin/rm -rf ./libft/*.a
			@echo "-- CLEARED --"

re: fclean all

.PHONY: $(NAME), all, clean, fclean, re