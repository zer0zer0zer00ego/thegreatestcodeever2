cmake_minimum_required(VERSION 3.10)
project(thegreatestcodeever)

set (CMAKE_C_STANDARD 99)


add_executable(
        ${PROJECT_NAME}
        main.c
        ClearMap.c
        Map.c
        Map.h
        config.h
        hero.h
        hero.c
        dungeon.h
)