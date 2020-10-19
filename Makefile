NAME	=	rt

SRC		=	init_sdl.c put_pixel_sdl.c destroy_sdl.c init_cl.c

INCLUDE_DIR = include

$(NAME): all

SRC_FILES = $(addprefix src/, $(SRC))
all:
	@gcc main.c $(SRC_FILES) -I $(INCLUDE_DIR) -L lib -l SDL2 -lSDL2_image -framework OpenCL -o $(NAME)

clean:
	@rm -rf $(NAME)
