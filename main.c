#include "map.h"
#include "hero.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Функция для разбора команды
void parse_command(char *input, char **command, char **argument) {
    *command = strtok(input, " ");  // Теперь принимаем изменяемую строку
    *argument = strtok(NULL, " ");
}

// Функция приведения к нижнему регистру
void to_lower(char *str) {
    for(int i = 0; str[i] != '\0'; i++) {
        str[i] = tolower(str[i]);
    }
}

int main() {
    Map game_map;
    Hero player;

    init_map(game_map);
    init_hero(&player);

    // Добавляем начальные предметы в инвентарь
    add_item(&player, "potion");
    add_item(&player, "key");

    char input[100];
    char *command;
    char *argument;


    int turn_count = 0;  // Счетчик ходов

    while(1) {
        printf("Commands: north, south, east, west, status, quit, use <nazvaniye predmeta>\n");
        printf("Dostupniye predmeti: potion, key\n");
        printf("\n----------------------------------------\n");
        printf("Move count: %d\n", turn_count);  // Вывод текущего хода
        draw_map(game_map, player.x, player.y);

        printf("\n");
        printf("Vvedite commandu: ");
        turn_count++;
        if (scanf("%99s", input) != 1) {
            printf("Oshibka vvoda!\n");
            while (getchar() != '\n');
            continue;
        }








        // Очищаем остаток буфера
        while (getchar() != '\n');

        // Приводим команду к нижнему регистру
        to_lower(input);

        // Разбираем команду
        parse_command(input, &command, &argument);

        if(strcmp(command, "quit") == 0) {
            printf("Poka!\n");
            break;
        }


        // Обработка движения
        if(strcmp(command, "north") == 0 ||
           strcmp(command, "south") == 0 ||
           strcmp(command, "west") == 0 ||
           strcmp(command, "east") == 0) {
            move_hero(&player, command, game_map);
        }

        if(strcmp(command, "status") == 0) {
            print_hero_status(&player);
        }

        // Обработка команды use
        if(strcmp(command, "use") == 0) {
            if (argument != NULL) {
                use_item(&player, argument);
            } else {
                printf("Otsutstvuet argument commandi use\n");
            }

        }

        if(game_map[player.y][player.x] == 'E') {
            printf("Blya nu ti molodets!\n");
            break;
        }
    }

    // Освобождаем память инвентаря при выходе
    free_inventory(&player);

    return 0;
}