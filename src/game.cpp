#include "game.h"
#include "blocks.cpp"
#include <ctime>
#include <random>
#include <raylib.h>

Game::Game() {
    grid          = Grid();
    blocks        = GetAllBlocks();
    current_block = GetRandomBlock();
    next_block    = GetRandomBlock();
}

Block Game::GetRandomBlock() {
    if (blocks.empty()) {
        blocks = GetAllBlocks();
    }
    srand(time(NULL));
    int random_index = rand() % blocks.size();
    Block block      = blocks[random_index];
    blocks.erase(blocks.begin() + random_index);
    return block;
}

std::vector<Block> Game::GetAllBlocks() {
    return {IBlock(), JBlock(), LBlock(), OBlock(), SBlock(), TBlock(), ZBlock()};
}

void Game::Draw() {
    grid.Draw();
    current_block.Draw();
}

void Game::HandleInput() {
    int key_pressed = GetKeyPressed();
    switch (key_pressed) {
        case KEY_A:
        case KEY_LEFT: MoveBlock(0, -1); break;

        case KEY_D:
        case KEY_RIGHT: MoveBlock(0, 1); break;

        case KEY_S:
        case KEY_DOWN: MoveBlock(1, 0);

        default: break;
    }
}

void Game::MoveBlock(int rows, int cols) {
    current_block.Move(rows, cols);
}

bool Game::IsBlockOutside() {
    std::vector<Position> cells = current_block.GetCellPositions();

    for (Position cell : cells) {
        if (grid.IsCellOutside(cell.row, cell.col)) {
            return true;
        }
    }

    return false;
}
