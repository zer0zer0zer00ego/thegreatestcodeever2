#include <stdio.h>
#include <string.h>
#include "Map.h"


int main() {

    char command[64];  // буфер для ввода
    int move_count = 0;  // счётчик ходов

    printf("Hello the wanderer\n");

    printf("If you want start write 'Play' and anything else for close game");

    // Считываем ввод пользователя
  fgets(command, sizeof(command), stdin);


// запуск игры менюшка

    if (strcmp(command, "Play\n") == 0 ||
        strcmp(command, "play\n") == 0 ||
            strcmp(command, "PLAY\n") == 0) {


        map_spawn();


    } else {
        printf("Bye, gamer\n");

    }



    return 0;






    return 0;





};

