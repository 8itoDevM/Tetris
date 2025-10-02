#include "raylib.h"
#include "grid.h"
#include "blocks.cpp"

/*
    gcc {NOME_DO_ARQUIVO.cpp} -lraylib

    ls -l

    ./a.out

    g++ main.cpp grid.cpp position.cpp colors.cpp block.cpp blocks.cpp -lraylib -o tetris

*/

int main(void)
{
    Color darkblue = {44, 44, 127, 255};
    InitWindow(300, 600, "Tetris");
    
    Grid grid = Grid();

    TBlock block = TBlock();

    grid.PrintGrid();

    SetTargetFPS(3);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(darkblue);
        grid.Draw();
        block.Draw();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}