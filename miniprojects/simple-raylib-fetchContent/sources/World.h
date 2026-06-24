#pragma once
#include <vector>
#include <raylib.h>

enum MatId : int;

struct WorldPixel {
    MatId matId;
};

class World {
public:
    World();
    void Update();
    void Draw();
private:
    using WorldInternals = std::vector<std::vector<WorldPixel>>;

    Texture2D tex;
    static constexpr int height = 2;
    static constexpr int width = 2;
    WorldInternals world;
    std::vector<Color> colors = {};
};
