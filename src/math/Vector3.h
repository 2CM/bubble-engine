#pragma once

#include <iostream>

class Vector3 {
    public:
        int x = 0;
        int y = 0;
        int z = 0;

        Vector3() {}

        Vector3(int x, int y, int z) {
            this->x = x;
            this->y = y;
            this->z = z;
        }

        Vector3 operator+(const Vector3& v){
            return Vector3(x + v.x, y + v.y, z + v.z);
        }

        void operator+=(const Vector3& v){
            x += v.x;
            y += v.y;
        }
};

std::ostream &operator<<(std::ostream &os, Vector3 const &m) { 
    return os << "(" << m.x << ", " << m.y << ", " << m.z << ")";
}