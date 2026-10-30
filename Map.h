#ifndef MAP_H
#define MAP_H

#define MAP_WIDTH 20
#define MAP_HEIGHT 10
#include <stdbool.h>

typedef char Map[MAP_HEIGHT][MAP_WIDTH];

void init_map(Map map);
void draw_map(const Map map, int hero_x, int hero_y);
bool is_valid_position(int x, int y);
bool can_move(Map map, int x, int y);


#endif