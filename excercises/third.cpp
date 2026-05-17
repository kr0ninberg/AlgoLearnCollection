#define MAGIC_WORDS std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

#ifndef MY_PC
// #define uint unsigned
#endif
#ifdef TESTS
#include <gtest/gtest.h>
#endif

#include <iostream>
//#include <iomanip>
#include <cmath>
// #include <string>
#include <vector>
// #include <tuple>
// #include <stack>
#include <algorithm>
#include <limits>
//#include <iterator>
//#include <memory>
//#include <unordered_map>
//#include <regex>
//#define _USE_MATH_DEFINES
using namespace std;
using namespace std::string_literals;

struct Point
{
    float x = 0.f;
    float y = 0.f;
};

using vec = std::vector<Point>;

void TestPoints(
    const vec& polygon,
    const vec& points,
    vector<int>& result);

bool PointInPolygon(
    const vec& polygon,
    Point point);

int main()
{
    MAGIC_WORDS;
#ifndef TESTS
    // int t; std::cin >> t;
    int t = 1;
    for(; t > 0 ; --t) solve();
#endif
#ifdef TESTS
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
#endif
    return 0;
}

struct BoundingBox
{
    BoundingBox(const vec& polygon)
    {
        minX_ = maxX_ = polygon[0].x;
        minY_ = maxY_ = polygon[0].y;

        for (const auto& p : polygon)
        {
            minX_ = std::min(minX_, p.x);
            maxX_ = std::max(maxX_, p.x);
            minY_ = std::min(minY_, p.y);
            maxY_ = std::max(maxY_, p.y);
        }
    }

    bool Contains(Point point) const
    {
        return point.x >= minX_ && point.x <= maxX_ &&
               point.y >= minY_ && point.y <= maxY_;
    }

private:
    float minX_;
    float maxX_;
    float minY_;
    float maxY_;
};

void TestPoints(
    const vec& polygon,
    const vec& points,
    vector<int>& result)
{
    for (const auto& point : points) {
        result.push_back(PointInPolygon(polygon, point) ? 1 : 0);
    }
}

bool PointOnSegment(Point a, Point b, Point p)
{
    constexpr float eps = 1e-6f;

    float cross = (p.x - a.x) * (b.y - a.y) -
                  (p.y - a.y) * (b.x - a.x);

    if (std::fabs(cross) > eps)
        return false;

    float dot = (p.x - a.x) * (b.x - a.x) +
                (p.y - a.y) * (b.y - a.y);

    if (dot < -eps)
        return false;

    float lenSq = (b.x - a.x) * (b.x - a.x) +
                  (b.y - a.y) * (b.y - a.y);

    return dot <= lenSq + eps;
}


bool PointInPolygon(
    const vec& polygon,
    Point point)
{
    if (polygon.size() < 3)
        return false;

    bool inside = false;
    size_t n = polygon.size();

    for (size_t i = 0, j = n - 1; i < n; j = i++)
    {
        const Point& a = polygon[j];
        const Point& b = polygon[i];

        if (PointOnSegment(a, b, point))
            return true;

        bool intersect =
            ((a.y > point.y) != (b.y > point.y)) &&
            (point.x < (b.x - a.x) * (point.y - a.y) / (b.y - a.y) + a.x);

        if (intersect)
            inside = !inside;
    }

    return inside;
}

#ifdef TESTS

TEST(Basic, Test1){
    // vec v{{0, 10, 5}, {0, 10, 2}, {0, 0, 1}};
    // EXPECT_EQ(calculate(v), 8);
}

#endif
