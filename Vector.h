#ifndef VECTOR_THREE_H
#define VECTOR_THREE_H

class Vector3
{
public:
    float x, y, z;

    Vector3(){}
    Vector3(const Vector3 &obj) : x(obj.x), y(obj.y), z(obj.z) {} 
    Vector3(float nx, float ny, float nz) : x(nx), y(ny), z(nz) {}

    Vector3& operator=(const Vector3 &rhs) { x = rhs.x; y = rhs.y; z = rhs.z; return *this; }
    bool operator==(const Vector3 &rhs) const { return x == rhs.x && y == rhs.y && z == rhs.z; }

};

#endif /* VECTOR_THREE_H */
