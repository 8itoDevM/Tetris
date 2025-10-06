#pragma once
#include <vector>
#include "raylib.h"

class Grid{
public:
    Grid();
    void Initialize();
    void PrintGrid();
    void Draw();
    bool IsCellOutside(int row, int column);
    bool IsCellEmpry(int row, int column);
    int grid[20][10];
private:
    int numRows;
    int numCols;
    int cellSize;
    std::vector<Color> colors;
};