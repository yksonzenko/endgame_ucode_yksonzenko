#include "header.h"

WINDOW* menuwin;
WINDOW* logowin;


void mx_render(t_game *game) {
    refresh();
    noecho();
    //displayed map and player`s cursor
    attron(COLOR_PAIR(WHITE));
    mx_disp_map(57, 31, game->map);
    attroff(COLOR_PAIR(WHITE));

    attron(COLOR_PAIR(WHITE_BLUE));
    attron(A_BOLD);
    mvaddch(game->p1->y, game->p1->x, 'U');
    attroff(A_BOLD);
    attroff(COLOR_PAIR(WHITE_BLUE));

    mvprintw(29, 23, "Lives: %d", game->cnt->lives_left);
    mvprintw(28, 23, "Total score: %d", game->cnt->total_score);
    mvprintw(27, 23, "Repo close in: | %d |", game->cnt->timer);
    mx_draw_objs(game);
        if (game->cnt->lives_left == 0 || game->cnt->timer == 0) {
            char p = '\0';
            while(p != 'p' /*&& p != 'q'*/) {
                p = getch();
                attron(COLOR_PAIR(WHITE_BLUE));
                attron(A_BOLD);
                mvprintw(11, 13, " Sorry, time`s out. Repo is closed ");
                mvprintw(12, 17, " Wonna retry? (press 'p') ");
                mvprintw(13, 18, " Exit game (press 'q' ) ");
                attroff(COLOR_PAIR(WHITE_BLUE));
                attroff(A_BOLD);
                mx_control(game, p);
            }
        }
}

int main(void) {
        // NCURSES START
        initscr();
        noecho();
        cbreak();
        curs_set(0);
        // get screen size
        int xMax = 0;
        int yMax = 0;
        getmaxyx(stdscr, yMax, xMax);
        char choices[4][12] = {"START", "RULES", "CONTROLS", "QUIT"};
        // create a menu window
        WINDOW* menuwin = newwin(20, 60, yMax/1.9, xMax/3);
        refresh();
        // create logo field
        WINDOW* logowin = newwin(10,100,yMax/3, xMax/3.9);
        refresh();
        //print the logo
        char logo[] = "UU          UU  CCCCCCCCCCCCCC  CCCCCCCCCCCCCC  CCCCCCCCCCC     CCCCCCCCCCCCCC  CCCCCCCCCCC\n UU          UU  UU              UU          UU  UU         UU   UU              UUU     UUU\n UU          UU  UU              UU          UU  UU          UU  UU              UUU      UUU\n UU          UU  UU              UU          UU  UU          UU  CCCCCCCCCCCCCC  CCCCCCCCCC\n UU          UU  UU              UU          UU  UU          UU  UU              CCCCCCCCCCC\n UU          UU  UU              UU          UU  UU         UU   UU              UU        UUU\n CCCCCCCCCCCCCC  CCCCCCCCCCCCCC  CCCCCCCCCCCCCC  CCCCCCCCCCC     CCCCCCCCCCCCCC  UU         UUU ";
        mvwprintw(logowin, 1,1, logo);
        mvwprintw(logowin, 9, 40, "The Game.");
        wrefresh(logowin);
        // Show the menu
        mvwprintw(menuwin, 1, 27, choices[0]);
        mvwprintw(menuwin, 2, 27, choices[1]);
        mvwprintw(menuwin, 3, 27, choices[2]);
        mvwprintw(menuwin, 4, 27, choices[3]);
        wrefresh(menuwin);
        // activate arrow keys
        keypad(menuwin, true);
        // highlight and choose
        int highlight = 0;
        int choice = 0;
        while(1 == 1){
                for(int i = 0; i < 4; i++){
                        if (i == highlight){
                                wattron(menuwin, A_REVERSE);
                                mvwprintw(menuwin, i+1, 27, choices[i]);
                                wattroff(menuwin, A_REVERSE);
                        }
                        if (i != highlight){
                                mvwprintw(menuwin, i+1, 27, choices[i]);
                        }
                }
                choice = wgetch(menuwin);
                switch(choice){
                        case KEY_UP:
                                highlight--;
                                if(highlight == -1){
                                        highlight = 0;
                                }
                                break;
                        case KEY_DOWN:
                                highlight++;
                                if (highlight == 4){
                                        highlight = 3;
                                }
                                break;
                        default:
                                break;
                }
                // Menu works
                if(choices[highlight] == choices[0] && choice == 10){
                        while(1 == 1){
                                werase(menuwin);
                                mx_menu_screan();
                                //wrefresh(menuwin);
                        }
                }
                // RULES OPTION
                if(choices[highlight] == choices[1] && choice == 10){
                        while(1 == 1){
                                werase(menuwin);
                                char rls[] = "                         RULES\n\n The main goal of the game is to complete all\n the tasks and hit the deadline over a specified time.\n\n U - Ucoder/you.\n\n @ - Apple. It is forbidden to eat in the cluster.\n Each time we see you with an apple you lose 1 life.\n\n t - Tasks. Each time you pick up a task you get 10 points.\n\n B - Beta-tester. It is your lucky ticket\n Beta-testers can give you some good advice.\n Every time you talk to a beta-test you get 1 life.\n\n\n             PRESS Q TO GET BACK TO MAIN MENU";
                                mvwprintw(menuwin,1,1,rls);
                                wrefresh(menuwin);
                                char a = 0;
                                a = getchar();
                                if(a == 'q' || a == 'Q'){
                                        werase(menuwin);
                                        break;
                                }
                        }
                }
                // CONTROLS OPTION
                if(choices[highlight] == choices[2] && choice == 10){
                        while(1 == 1){
                                werase(menuwin);
                                char ctrl[] = "\n                         CONTROLS\n\n\n                       W - Move up.\n                       A - Move left.\n                       S - Move down.\n                       D - Move right.\n                       Q - Quit.\n\n\n              PRESS Q TO GET BACK TO MAIN MENU";
                                mvwprintw(menuwin,1,1,ctrl);
                                wrefresh(menuwin);
                                char a = 0;
                                a = getchar();
                                if(a == 'q' || a == 'Q'){
                                        werase(menuwin);
                                        break;
                                }
                        }
                }
                // QUIT OPTION
                if(choices[highlight] == choices[3] && choice == 10){
                        break;
                }
        }
        // NCURSES END
        getch();
        endwin();
        return 0;
}

char mx_menu_screan(void){
    
    t_game *game = mx_init_game("map_level_00.txt");
    
    bool is_game = true;
    time_t curr_time;
    int seconds_passed;
    // Adding tasks
    mx_add_objects(game->map, 't', 10);
    // Adding apples
    mx_add_objects(game->map, '@', 5);
    // activate the keypad to read from this terminal
    mx_add_objects(game->map, 'B', 1);
    keypad(initscr(),TRUE);

    start_color();
    init_pair(1, (231), (32));
    init_pair(2, (35), COLOR_BLACK);
    init_pair(3, (93), COLOR_BLACK);
    init_pair(4, (27), COLOR_BLACK);
    init_pair(5, (231), COLOR_BLACK);
    clear();

    //don't show cursor
    curs_set(0);
    // initialise the x and y positions of the cursor
    game->p1 = malloc(sizeof(t_player));
    game->p1->x = 28;
    game->p1->y = 2;
    game->lvl = 0;

    game->cnt = malloc(sizeof(t_counters));
    // initialize score and lives
    game->cnt->lives_left = 3;
    game->cnt->total_score = 0;
    game->cnt->timer = LEVEL_SECONDS;
    game->cnt->start = clock();

    nodelay(stdscr, TRUE);
    
    char c = '\0';       // input character initialise to null

    while(is_game) {
 
        mx_render(game);
        // read a single character
        c = getch();
        mx_control(game, c);

        is_game = mx_update(game, c);
        curr_time = clock();
        seconds_passed = (curr_time - game->cnt->start) / CLOCKS_PER_SEC;

        game->cnt->timer = LEVEL_SECONDS - seconds_passed - 1;
    }
    free(game->p1);
    free(game->cnt);
    endwin();
    return 0;
    //system("leaks -q endgame");
}
