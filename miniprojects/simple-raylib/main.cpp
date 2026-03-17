#include <raylib.h>
#include "sources/Simulation.h"

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "simple pixel world");
    SetTargetFPS(60);

    Simulation mainInstance{};

    while (!WindowShouldClose())
    {
        mainInstance.Update();

        BeginDrawing();
        mainInstance.Draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}