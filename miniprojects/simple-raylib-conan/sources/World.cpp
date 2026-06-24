#include "World.h"

#include <unordered_map>

enum MatId : int {
    NOTHING = 0,
    SAND = 1,
    SOLID = 2,
    WATER = 3,
};

inline std::unordered_map<MatId, Color> materialToColor = {
    {NOTHING, LIGHTGRAY},
    {SAND, YELLOW},
    {SOLID, BLACK},
    {WATER, BLUE}
};

World::World()
    : world({ {{{SAND}, {NOTHING}}}, {{{WATER}, {SOLID}}} })
{
    colors.resize(height * width);
    for (int row = 0; row < height; ++row) {
        for (int col = 0; col < width; ++col) {
            colors[row * width + col] = materialToColor[world[row][col].matId];
        }
    }
    Image img{};
    img.data = colors.data();
    img.width = width;
    img.height = height;
    img.mipmaps = 1;
    img.format = PIXELFORMAT_UNCOMPRESSED_R8G8B8A8;
    tex = LoadTextureFromImage(img);
}

void World::Update() {
}

void World::Draw() {
    UpdateTexture(tex, colors.data());

    Rectangle src = {0,0,(float)width,(float)height};
    Rectangle dst = {0,0,(float)GetScreenWidth(),(float)GetScreenHeight()};

    DrawTexturePro(tex, src, dst, {0,0}, 0, WHITE);
}
