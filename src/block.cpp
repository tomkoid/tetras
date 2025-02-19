#include "block.h"
#include "src/position.h"
#include <raylib.h>
#include <vector>

Block::Block() {
    this->cell_size      = 30;
    this->rotation_state = 0;
    this->colors         = GetCellColors();
    this->row_offset     = 0;
    this->col_offset     = 0;

    Move(spawn_pos.row, spawn_pos.col);
}

void Block::Draw() {
    std::vector<Position> tiles = GetCellPositions();
    for (Position item : tiles) {
        DrawRectangle(item.col * cell_size + 1, item.row * cell_size + 1, cell_size - 1, cell_size - 1, colors[id]);
    }
}

void Block::Move(int rows, int cols) {
    row_offset += rows;
    col_offset += cols;
}

void Block::SetDefaultOffset(int rows, int cols) {
    this->spawn_pos = Position(rows, cols);
    row_offset      = rows;
    col_offset      = cols;
}

std::vector<Position> Block::GetCellPositions() {
    std::vector<Position> tiles = cells[rotation_state];
    std::vector<Position> moved_tiles;

    for (Position item : tiles) {
        Position new_pos = Position(item.row + row_offset, item.col + col_offset);
        moved_tiles.emplace_back(new_pos);
    }

    return moved_tiles;
}
