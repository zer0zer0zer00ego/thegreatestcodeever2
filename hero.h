#ifndef HERO_H
#define HERO_H
#include "map.h"
#include "map.h"
#include <stdlib.h>

#include "map.h"
#include <stdlib.h>

typedef struct {
    int x, y;
    int health;
    int gold;
    int inventory_size;  // Размер инвентаря
    char **inventory;    // Массив указателей на названия предметов
} Hero;

// Прототипы функций
void init_hero(Hero *hero);
void move_hero(Hero *hero, const char *direction, Map map);
void print_hero_status(const Hero *hero);
void add_item(Hero *hero, const char *item);
void use_item(Hero *hero, const char *item_name);
void free_inventory(Hero *hero);
#endif