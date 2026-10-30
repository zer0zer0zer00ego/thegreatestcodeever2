#include "hero.h"
#include <stdio.h>
#include <string.h>

#include "map.h"


#include "hero.h"
#include <stdio.h>
#include <string.h>
#include "hero.h"
#include <stdio.h>
#include <string.h>

void move_hero(Hero *hero, const char *direction, Map map) {
    int new_x = hero->x;
    int new_y = hero->y;

    if(strcmp(direction, "north") == 0) {
        new_y--;
    } else if(strcmp(direction, "south") == 0) {
        new_y++;
    } else if(strcmp(direction, "west") == 0) {
        new_x--;
    } else if(strcmp(direction, "east") == 0) {
        new_x++;
    }

    // Проверка границ через указатели
    if (new_x >= 0 && new_x < MAP_WIDTH &&
        new_y >= 0 && new_y < MAP_HEIGHT) {

        // Проверка проходимости через указатель на карту
        if (*(*(map + new_y) + new_x) != '#') {
            hero->x = new_x;
            hero->y = new_y;
        } else {
            printf("nelzya dvigatsya!\n");
        }
        } else {
            printf("predel karti\n");
        }
}






void print_hero_status(const Hero *hero) {
    printf("Здоровье: %d\n", hero->health);
    printf("Золото: %d\n", hero->gold);
    printf("Инвентарь (%d предметов):\n", hero->inventory_size);
    for(int i = 0; i < hero->inventory_size; i++) {
        printf("- %s\n", hero->inventory[i]);
    }
}

void add_item(Hero *hero, const char *item) {
    hero->inventory = realloc(hero->inventory, (hero->inventory_size + 1) * sizeof(char *));
    if (!hero->inventory) {
        printf("Oshibka videleniya!\n");
        return;
    }

    hero->inventory[hero->inventory_size] = strdup(item);
    if (!hero->inventory[hero->inventory_size]) {
        printf("Oshibka kopirovaniya!\n");
        return;
    }

    hero->inventory_size++;
}

void use_item(Hero *hero, const char *item_name) {
    for (int i = 0; i < hero->inventory_size; i++) {
        if (strcmp(hero->inventory[i], item_name) == 0) {
            // Логика использования предмета
            if (strcmp(item_name, "potion") == 0) {
                hero->health += 20;
                printf("Zelye used you othililsya.\n");
            } else if (strcmp(item_name, "key") == 0) {
                printf("Key used!\n");
            }

            // Удаляем использованный предмет
            free(hero->inventory[i]);
            for (int j = i; j < hero->inventory_size - 1; j++) {
                hero->inventory[j] = hero->inventory[j + 1];
            }
            hero->inventory_size--;
            return;
        }
    }
    printf("Predmet ne nayden!\n");
}

void free_inventory(Hero *hero) {
    for (int i = 0; i < hero->inventory_size; i++) {
        free(hero->inventory[i]);
    }
    free(hero->inventory);
}

void init_hero(Hero *hero) {
    hero->x = 1;
    hero->y = 1;
    hero->health = 100;
    hero->gold = 0;
    hero->inventory_size = 0;
    hero->inventory = NULL;
}



void handle_use_command(Hero *hero, const char *item_name) {
    if (strcmp(item_name, "key") == 0) {
        // Логика использования ключа
        printf("Vi ispolzuete kluch\n");
        // Здесь можно добавить эффекты от использования
    } else if (strcmp(item_name, "potion") == 0) {
        // Логика использования зелья
        printf("Vipil zelye\n");
        hero->health += 20;  // Восстановление здоровья
    } else if (strcmp(item_name, "sword") == 0) {
        // Логика использования меча
        printf("Dostal mech\n");
        // Здесь можно добавить эффекты атаки
    } else {
        printf("Neizvestnii predmet: %s\n", item_name);
    }
}