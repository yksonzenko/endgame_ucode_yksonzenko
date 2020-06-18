#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <ncurses.h>
#include <time.h>

#define LEVEL_SECONDS 60
#define WHITE_BLUE 1
#define GREEN 2
#define PURPLE 3
#define DARK_BLUE 4
#define WHITE 5

typedef struct s_player {
    int x;
    int y;
    char ch;
} t_player;

typedef struct s_counters {
    int lives_left;
    int total_score;
    int timer;
    time_t start;
} t_counters;

typedef struct s_game {
    char **map;
    t_counters *cnt;
    t_player *p1;
    int lvl;
} t_game;

char *mx_strnew(const int size);
char **mx_file_to_arr(const char *filename);
void mx_add_tasks(char **map);
void mx_add_apples(char **map);
char *mx_strcpy(char *dst, const char *src);
void mx_disp_map(int w, int h, char **map);
void mx_control(t_game *game, char c);
void mx_set_player_pos(t_player *player, int x, int y);
void mx_set_lvl_2(t_game *game);
bool mx_update(t_game* game, char c);
void mx_add_tasks_01(char **map);
void mx_add_apples_01(char **map);
void mx_end_game(t_game *game);
void mx_draw_objs(t_game *game);
t_game* mx_init_game(const char *start_map);
int mx_random_number(int min_num, int max_num);
void mx_add_objects(char **map, char ch, int quantity);
void mx_render(t_game *game);
char mx_menu_screan(void);
char mx_end_screan(void);

#endif
