NAME = endgame

SRC = src/main.c \
	src/mx_disp_map.c \
	src/mx_file_to_arr.c \
	src/mx_strcpy.c \
	src/mx_strnew.c \
	src/mx_objects.c \
	src/mx_control.c \
	src/mx_update_levels.c \

SRC_IN = main.c \
	mx_disp_map.c \
	mx_file_to_arr.c \
	mx_strcpy.c \
	mx_strnew.c \
	mx_objects.c \
	mx_control.c \
	mx_update_levels.c \
	
INC = inc/header.h \

INC_IN = header.h

RSC = resource/map_level_00.txt \
	resource/map_level_01.txt \
	resource/map_endgame.txt \

RSC_IN = map_level_00.txt \
	map_level_01.txt \
	map_endgame.txt \

CC = clang
COMPILER = -std=c11 -Wall -Wextra -Werror -Wpedantic -lncurses -o

all: ENDGAME

ENDGAME: $(SRC) $(INC) $(RSC)
	@cp $(SRC) .
	@cp $(INC) .
	@cp $(RSC) .
	@$(CC) $(COMPILER) $(NAME) $(SRC_IN)

uninstall: clean
	@rm -rf $(NAME)

clean:
	@rm -rf $(SRC_IN)
	@rm -rf $(INC_IN)
	@rm -rf $(RSC_IN)

reinstall: uninstall ENDGAME
