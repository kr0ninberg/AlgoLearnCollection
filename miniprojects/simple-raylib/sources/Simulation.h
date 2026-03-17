#include <array>
#include <raylib.h>
#include <unordered_map>

enum MatId {
    NOTHING = 0,
    SAND = 1,
    SOLID = 2,
};

inline std::unordered_map<MatId, Color> materialToColor = {
    {NOTHING, LIGHTGRAY},
    {SAND, YELLOW},
    {SOLID, BLACK}
};

class Simulation { // FIXME do singleton
public:
    Simulation();
    void Update();
    void Draw();

private:
    Texture2D tex;
    static constexpr inline int height = 6;
    static constexpr inline int width = 6;
    std::array<std::array<MatId, width>, height> logicWorld = {{
        {{NOTHING, NOTHING, SAND, SAND, NOTHING, NOTHING}},
        {{NOTHING, NOTHING, SAND, SAND, NOTHING, NOTHING}},
        {{NOTHING, SOLID,   SAND, SAND, NOTHING, NOTHING}},
        {{NOTHING, SOLID,   SAND, SAND, NOTHING, NOTHING}},
        {{NOTHING, SOLID,   NOTHING, NOTHING, SOLID, SOLID}},
        {{SOLID,   SOLID,   SOLID,   SOLID,   SOLID, SOLID}}
    }};
    std::array<Color, height * width> colors = {{}};
};

