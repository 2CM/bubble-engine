#pragma once

#include <iostream>

class Vector2 {
    public:
        int x = 0;
        int y = 0;

        Vector2() {}

        Vector2(int xPos, int yPos) {
            x = xPos;
            y = yPos;
        }

        Vector2 operator+(const Vector2& v){
            return Vector2(x+v.x,y+v.y);
        }

        void operator+=(const Vector2& v){
            x += v.x;
            y += v.y;
        }
};

std::ostream &operator<<(std::ostream &os, Vector2 const &m) { 
    return os << "(" << m.x << ", " << m.y << ")";
}