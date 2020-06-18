#include "header.h"

int seed = 0;  // This variable is required for function mx_random_number()

void mx_add_objects(char **map, char ch, int quantity) {

    int x = 0;
    int y = 0;

    for (int i = 0; i < quantity; i++) {

        y = mx_random_number(2, 26);
        x = mx_random_number(3, 50);

        if (map[y][x] == ' ') {
            map[y][x] = ch;
        }
        else {
            while (map[y][x] != ' ') {
                y = mx_random_number(2, 25);
                x = mx_random_number(3, 50);
            }
            map[y][x] = ch;
        }
    }
}

int mx_random_number(int min_num, int max_num) {
    int result = 0, low_num = 0, hi_num = 0;

    if (min_num < max_num) {
        low_num = min_num;
        hi_num = max_num + 1; // include max_num in output
    } else {
        low_num = max_num + 1; // include max_num in output
        hi_num = min_num;
    }

    srand(time(NULL) + seed);
    result = (rand() % (hi_num - low_num)) + low_num;
    seed += 1;
    return result;
}

void mx_set_player_pos(t_player *player, int x, int y) {
    player->x = x;
    player->y = y;
}

void mx_draw_objs(t_game *game) {
    for(int i = 0; i < 27; i++ ) {
        for(int j = 0; j < 56; j++ ) {
            if (game->map[i][j] == 't') {
                attron(COLOR_PAIR(GREEN));
                attron(A_BOLD);
                mvaddch(i, j, 't');
                attroff(COLOR_PAIR(GREEN));
            }
            if (game->map[i][j] == '@') {
                attron(COLOR_PAIR(PURPLE));
                mvaddch(i, j, '@');
                attroff(COLOR_PAIR(PURPLE));
                attroff(A_BOLD);
            }
            if (game->map[i][j] == 'B') {
                attron(COLOR_PAIR(DARK_BLUE));
                mvaddch(i, j, 'B');
                attroff(COLOR_PAIR(DARK_BLUE));
                attroff(A_BOLD);
            }
        }
    }
}

t_game* mx_init_game(const char *start_map) {
    t_game *game = malloc(sizeof(t_game));
    game->map = mx_file_to_arr(start_map);
    return game;
}
