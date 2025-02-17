#include <iostream>
#include <raylib.h>
#include "grid.h"
#include "blocks.cpp"

#define PROJECT_NAME "tetras"

int main(int argc, char** argv) {
    if (argc != 1) {
        std::cout << argv[0] << "takes no arguments.\n";
        return 1;
    }
    std::cout << "This is project " << PROJECT_NAME << ".\n";

    Color dark_blue = {44, 44, 127, 255};

    InitWindow(300, 600, "tetras");
    SetTargetFPS(60);
    Grid grid    = Grid();
    LBlock block = LBlock();
    grid.Print();

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(dark_blue);
        grid.Draw();
        block.Draw();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
