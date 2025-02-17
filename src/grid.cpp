#include "grid.h"
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

std::vector<Color> Grid::GetCellColors() {
    Color darkGrey = {26, 31, 40, 255};
    Color green    = {47, 230, 23, 255};
    Color red      = {232, 18, 18, 255};
    Color orange   = {226, 116, 17, 255};
    Color yellow   = {237, 234, 4, 255};
    Color purple   = {166, 0, 247, 255};
    Color cyan     = {21, 204, 209, 255};
    Color blue     = {13, 64, 216, 255};

    return {darkGrey, green, red, orange, yellow, purple, cyan, blue};
}

void Grid::Draw() {
    for (int row = 0; row < num_rows; row++) {
        for (int col = 0; col < num_cols; col++) {
            int cell_val = grid[row][col];
            DrawRectangle(col * cell_size + 1, row * cell_size + 1, cell_size - 1, cell_size - 1, colors[cell_val]);
        }
    }
}
