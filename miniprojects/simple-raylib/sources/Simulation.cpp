#include "Simulation.h"

#include <raylib.h>

Simulation::Simulation() {
    Image img{};
    img.data = colors.data();
    img.width = width;
    img.height = height;
    img.mipmaps = 1;
    img.format = PIXELFORMAT_UNCOMPRESSED_R8G8B8A8;
    tex = LoadTextureFromImage(img);
}

void Simulation::Draw() {
    UpdateTexture(tex, colors.data());

    Rectangle src = {0,0,(float)width,(float)height};
    Rectangle dst = {0,0,(float)GetScreenWidth(),(float)GetScreenHeight()};

    DrawTexturePro(tex, src, dst, {0,0}, 0, WHITE);
}

void Simulation::Update() {
    for (int row = 0; row < height; ++row) {
        for (int col = 0; col < width; ++col) {
            colors[row * width + col] = materialToColor[logicWorld[row][col]];
        }
    }
}
