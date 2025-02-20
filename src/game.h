#pragma once
#include "grid.h"
#include "block.h"

class Game {
public:
    Game();
    Block GetRandomBlock();
    void Draw();
    void HandleInput();
    void MoveBlock(int rows, int cols);

    Grid grid;

private:
    std::vector<Block> blocks;
    std::vector<Block> GetAllBlocks();
    bool IsBlockOutside();

    Block current_block;
    Block next_block;
};
