#ifndef VECTOR_THREE_H
#define VECTOR_THREE_H

#include<iostream>
#include<math.h>

class Vector3
{
public:
    float x, y, z;

    Vector3(){}
    Vector3(const Vector3 &obj) : x(obj.x), y(obj.y), z(obj.z) {} 
    Vector3(float nx, float ny, float nz) : x(nx), y(ny), z(nz) {}

    Vector3 &operator=(const Vector3 &obj) { x = obj.x; y = obj.y; z = obj.z; return *this; }
    bool operator==(const Vector3 &obj) const { return x == obj.x && y == obj.y && z == obj.z; }
    bool operator!=(const Vector3 &obj) const { return !(x == obj.x && y == obj.y && z == obj.z); }

    void zero() { x = 0; y = 0; z = 0; }
    Vector3 operator-() const { return Vector3(-x, -y, -z); }
    Vector3 operator+(const Vector3& obj) const { return Vector3(x + obj.x, y + obj.y, z + obj.z); }
    Vector3 operator-(const Vector3& obj) const { return Vector3(x - obj.x, y - obj.y, z - obj.z); }
    Vector3 operator*(const float obj) const { return Vector3(x * obj, y * obj, z * obj); }
    Vector3 operator/(const float obj) const { float tmp = 1.0f / obj; return Vector3(x * tmp, y * tmp, z * tmp); }
    Vector3 &operator+=(const Vector3& obj) { *this = *this + obj; return *this; }
    Vector3 &operator-=(const Vector3& obj) { *this = *this - obj; return *this; }
    Vector3 &operator*=(const float obj) 
    { 
        *this = *this * obj; 
        return *this; 
    }
    Vector3 &operator/=(const float obj) { *this = *this / obj; return *this; }

    float operator*(const Vector3& obj) const { return (x * obj.x + y * obj.y + z * obj.z); }

    static inline Vector3 crossProduct(const Vector3& a, const Vector3& b) 
    { 
        return Vector3(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x); 
    }

    inline void normalize() 
    { 
        float tmp = x * x + y * y + z * z;
        if (tmp > 0) {
            float mag = 1 / sqrt(tmp);
            x *= mag;
            y *= mag;
            z *= mag;
        }
    }

    inline float disntance(const Vector3& a, const Vector3& b) 
    { 
        Vector3 tmp = a - b;
        return sqrt(tmp.x * tmp.x + tmp.y * tmp.y + tmp.z + tmp.z);
    }

    void print()
    {
        std::cout << "x : " << x << "\n";
        std::cout << "y : " << y << "\n";
        std::cout << "z : " << z << "\n";
    }
};

#endif /* VECTOR_THREE_H */
