#include "header.h"

void mx_set_lvl_2(t_game *game) { 
    game->map = 0;
    game->map = mx_file_to_arr("resource/map_level_01.txt");
    sleep(1);
    endwin();
}

void mx_end_game(t_game *game) { 
    game->map = 0;
    clear();
    game->map = mx_file_to_arr("resource/map_endgame.txt");
    sleep(1);
    endwin();
}

bool mx_update(t_game* game, char c) {
    if(c == 'q') {
            clear();
            refresh();
            //return false;
            exit(0);
        }
    if (game->cnt->total_score >= 100 && game->lvl == 0 
        && game->p1->x == 54 && game->p1->y == 25) {
        mx_set_lvl_2(game);
        mx_set_player_pos(game->p1, 4, 2);
        game->lvl = 1;
        mx_add_objects(game->map, 't', 10);
        mx_add_objects(game->map, '@', 5);
        mx_add_objects(game->map, 'B', 1);
        game->cnt->start = clock();
        game->cnt->timer = LEVEL_SECONDS;
        game->cnt->lives_left = 3;
        game->cnt->total_score = 0;
    }
    if (game->lvl == 1 && game->cnt->total_score >= 100 
        && game->p1->x == 54 && game->p1->y == 25) {
        mx_end_game(game);
        //exit(0);
    }
    return true;
}
