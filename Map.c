#include <stdio.h>
#include "map.h"  // подключаем свой заголовок
#define ROWS 6
#define COLS 24

char map[ROWS][COLS];
void map_spawn() {
    const char* map[6] = {
        "###################################",
        "#                                 #",
        "#                                 #",
        "#                                 #",
        "#                                 #",
        "###################################",


    };

    size_t map_len = sizeof(map)/sizeof(map[0]);

    for (size_t i = 0; i < map_len; i++) {
        printf("%s\n", map[i]);
    }
}




