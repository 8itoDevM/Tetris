#include "raylib.h"
#include "game.h"
#include "colors.h"
#include <iostream>

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
    InitWindow(500, 620, "Tetris");
    SetTargetFPS(60);

    Font font = LoadFontEx("Basic5.ttf", 64, 0, 0);

    Color color = Color();
    Game game = Game();

    while (!WindowShouldClose())
    {
        game.HandleInput();
        if(EventTriggered(0.35)){
            game.MoveBlockDown();
        }
        BeginDrawing();
        ClearBackground(darkBlue);
        
        char scoreText[10];
        sprintf(scoreText, "%d", game.score);
        Vector2 textSize = MeasureTextEx(font, scoreText, 20, 2);

        DrawTextEx(font, "Score", {365, 15}, 20, 2, WHITE);

        DrawRectangleRounded({320, 55, 170, 60}, 0.4, 6, lightBlue);
        DrawTextEx(font, scoreText, {320 + (170 - textSize.x)/2, 75}, 20, 2, WHITE);
        

        DrawTextEx(font, "Next", {370, 175}, 20, 2, WHITE);
        DrawRectangleRounded({320, 215, 170, 180}, 0.4, 6, lightBlue);

        if(game.gameOver){
            DrawTextEx(font, "GAME OVER", {330, 450}, 20, 2, WHITE);
        }

        game.Draw();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}