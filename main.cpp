#include "raylib.h"
#include "game.h"

double lastUpdateTime = 0;

bool EventTriggered(double interval){
    double currentTIme = GetTime();
    if(currentTIme - lastUpdateTime >= interval){
        lastUpdateTime = currentTIme;
        return true;
    }
    return false;
}

/*
    gcc {NOME_DO_ARQUIVO.cpp} -lraylib

    ls -l

    ./a.out

    g++ main.cpp grid.cpp position.cpp colors.cpp block.cpp blocks.cpp game.cpp -lraylib -o tetris

*/

int main(void)
{
    Color darkblue = {44, 44, 127, 255};
    InitWindow(300, 600, "Tetris");
    SetTargetFPS(60);

    Game game = Game();

    while (!WindowShouldClose())
    {
        game.HandleInput();
        if(EventTriggered(0.35)){
            game.MoveBlockDown();
        }
        BeginDrawing();
        ClearBackground(darkblue);
        game.Draw();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}