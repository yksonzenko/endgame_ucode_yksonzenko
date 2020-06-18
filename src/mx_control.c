#include "header.h"

void mx_control(t_game *game, char c) {

    if(game->cnt->lives_left == 0 || game->cnt->timer == 0) {
        switch(c){
            case 'p':
                clear();
                game->cnt->lives_left = 3;
                game->cnt->total_score = 0;
                game->cnt->timer = LEVEL_SECONDS;
                game->cnt->start = clock();
                    game->p1->x = 28;
                    game->p1->y = 2;
                    game->lvl = 0;
                    game->map = mx_file_to_arr("map_level_00.txt");
                    refresh();
                    for (int i = 0; i < 25; ++i) {
                        for (int j = 0; j < 50; ++j) {
                            if (game->map[i][j] == 't' || game->map[i][j] == '@' || game->map[i][j] == 'B') {
                                game->map[i][j] = ' ';
                            }
                        }
                    }
                    mx_add_objects(game->map, 't', 10);
                    mx_add_objects(game->map, '@', 5);
                    mx_add_objects(game->map, 'B', 1);
            break;
            case 'q':
                clear();
                refresh();
                exit(0);
            break;

        default:
            break;
        }
        
    }
    
         switch(c) {

            case 'w':
                if (game->map[game->p1->y - 1][game->p1->x] == ' '){
                    --game->p1->y;
                } else if (game->map[game->p1->y - 1][game->p1->x] == 't') {
                    game->map[game->p1->y - 1][game->p1->x] = ' ';
                    --game->p1->y;
                    game->cnt->total_score += 10;
                } else if (game->map[game->p1->y - 1][game->p1->x]== '@') {
                    game->map[game->p1->y - 1][game->p1->x] = ' ';
                    --game->p1->y;
                    game->cnt->lives_left -= 1;
                } else if (game->map[game->p1->y - 1][game->p1->x]== 'B') {
                    game->map[game->p1->y - 1][game->p1->x] = ' ';
                    --game->p1->y;
                    game->cnt->lives_left += 1;
                }
                break;
            case 's':
                if (game->map[game->p1->y + 1][game->p1->x]== ' '){
                    ++game->p1->y;

                } else if (game->map[game->p1->y + 1][game->p1->x] == 't'){

                    game->map[game->p1->y + 1][game->p1->x] = ' ';
                    ++game->p1->y;
                    game->cnt->total_score += 10;
                } else if (game->map[game->p1->y + 1][game->p1->x] == '@') {
                    game->map[game->p1->y + 1][game->p1->x] = ' ';
                    ++game->p1->y;
                    game->cnt->lives_left -= 1;
                } else if (game->map[game->p1->y + 1][game->p1->x] == 'B') {
                    game->map[game->p1->y + 1][game->p1->x] = ' ';
                    ++game->p1->y;
                    game->cnt->lives_left += 1;
                }
                break;
            case 'a':
                if (game->map[game->p1->y][game->p1->x - 1]== ' '){
                    --game->p1->x;
                } else if (game->map[game->p1->y][game->p1->x - 1]== 't') {
                    game->map[game->p1->y][game->p1->x - 1] = ' ';
                    --game->p1->x;
                    game->cnt->total_score += 10;
                } else if (game->map[game->p1->y][game->p1->x - 1]== '@') {
                    game->map[game->p1->y][game->p1->x - 1] = ' ';
                    --game->p1->x;
                    game->cnt->lives_left -= 1;
                } else if (game->map[game->p1->y][game->p1->x - 1]== 'B') {
                    game->map[game->p1->y][game->p1->x - 1] = ' ';
                    --game->p1->x;
                    game->cnt->lives_left += 1;
                }
                break;
            case 'd':
                if (game->map[game->p1->y][game->p1->x + 1]== ' '){
                    ++game->p1->x;
                } else if (game->map[game->p1->y][game->p1->x + 1]== 't') {
                    game->map[game->p1->y][game->p1->x + 1] = ' ';
                    ++game->p1->x;
                    game->cnt->total_score += 10;
                } else if (game->map[game->p1->y][game->p1->x + 1]== '@') {
                    game->map[game->p1->y][game->p1->x + 1] = ' ';
                    ++game->p1->x;
                    game->cnt->lives_left -= 1;
                } else if (game->map[game->p1->y][game->p1->x + 1]== 'B') {
                    game->map[game->p1->y][game->p1->x + 1] = ' ';
                    ++game->p1->x;
                    game->cnt->lives_left += 1;
                }
                break;

            default:
                break;
        }
}
