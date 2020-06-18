#include "header.h"

void mx_disp_map(int w, int h, char **map) {

    for (int i = 0; i < h; i++) {
    	for (int j = 0; j < w; j++)
    		mvaddch(i, j, map[i][j]); 
    }
}
