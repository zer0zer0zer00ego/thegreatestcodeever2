#include <stdio.h>

int main() {
    printf("Hello the wanderer\n");

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




    return 0;





};

