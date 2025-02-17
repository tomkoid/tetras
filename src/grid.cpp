#include "grid.h"
#include "colors.h"
#include <iostream>

Grid::Grid() {
    num_rows  = 20;
    num_cols  = 10;
    cell_size = 30;
    Initialize();
    colors = GetCellColors();
}

void Grid::Initialize() {
    for (int row = 0; row < num_rows; row++) {
        for (int col = 0; col < num_cols; col++) {
            grid[row][col] = 0;
        }
    }
}

void Grid::Print() {
    for (int row = 0; row < num_rows; row++) {
        for (int col = 0; col < num_cols; col++) {
            std::cout << grid[row][col] << " ";
        }

        std::cout << std::endl;
    }

    std::cout << std::endl;
}

void Grid::Draw() {
    for (int row = 0; row < num_rows; row++) {
        for (int col = 0; col < num_cols; col++) {
            int cell_val = grid[row][col];
            DrawRectangle(col * cell_size + 1, row * cell_size + 1, cell_size - 1, cell_size - 1, colors[cell_val]);
        }
    }
}
