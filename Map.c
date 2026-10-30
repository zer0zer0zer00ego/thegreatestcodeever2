#include "map.h"
#include <stdio.h>

void init_map(Map map) {
    static const char initial_map[MAP_HEIGHT][MAP_WIDTH] = {
        "##################",
        "#                #",
        "#                #",
        "#                #",
        "#######          #",
        "#                #",
        "#                #",
        "#            #####",
        "#####            #",
        "#########E########"
    };

    for(int i = 0; i < MAP_HEIGHT; i++) {
        for(int j = 0; j < MAP_WIDTH; j++) {
            map[i][j] = initial_map[i][j];
        }
    }
}

void draw_map(const Map map, int hero_x, int hero_y) {
    for(int i = 0; i < MAP_HEIGHT; i++) {
        for(int j = 0; j < MAP_WIDTH; j++) {
            if(i == hero_y && j == hero_x) {
                printf("@");  // Символ героя
            } else {
                printf("%c", map[i][j]);
            }
        }
        printf("\n");
    }
}

bool is_valid_position(int x, int y) {
    return (x >= 0 && x < MAP_WIDTH &&
            y >= 0 && y < MAP_HEIGHT);
}

bool can_move(Map map, int x, int y) {
    return is_valid_position(x, y) && map[y][x] != '#';
}