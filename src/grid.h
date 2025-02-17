#pragma once

#include <vector>
#include <raylib.h>

class Grid {
public:
    Grid();
    int grid[20][10];
    void Initialize();
    void Draw();
    void Print();

private:
    int num_rows;
    int num_cols;
    int cell_size;
    std::vector<Color> colors;
};
