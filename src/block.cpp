#include "block.h"
#include "src/position.h"
#include <raylib.h>

Block::Block() {
    cell_size      = 30;
    rotation_state = 0;
    colors         = GetCellColors();
}

void Block::Draw() {
    std::vector<Position> tiles = cells[rotation_state];
    for (Position item : tiles) {
        DrawRectangle(item.col * cell_size + 1, item.row * cell_size + 1, cell_size - 1, cell_size - 1, colors[id]);
    }
}
