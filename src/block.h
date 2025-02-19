#pragma once
#include <vector>
#include <map>
#include "position.h"
#include "colors.h"

class Block {
public:
    Block();
    void Draw();
    void Move(int rows, int cols);
    void SetDefaultOffset(int rows, int cols);
    std::vector<Position> GetCellPositions();

    int id;
    Position spawn_pos = Position(0, 3); // default spawn pos
    std::map<int, std::vector<Position>> cells;

private:
    int cell_size;
    int rotation_state;
    int row_offset;
    int col_offset;
    std::vector<Color> colors;
};
