#ifndef VEC2_H
#define VEC2_H

#include <iostream>
#include <cmath>

class Vec2
{
public:
    Vec2();
    Vec2(float x, float y);
    static Vec2 Add(Vec2 v1, Vec2 v2);
    static Vec2 Sub(Vec2 v1, Vec2 v2);
    static Vec2 Mul(Vec2 v1, int a);
    static float Mag(Vec2 v);
    static Vec2 Unit(Vec2 v);
    static float Dist(Vec2 v1, Vec2 v2);
    static float Inc(Vec2 v1);
    static float Inc(Vec2 v1, Vec2 v2);

    Vec2 RotDeg(float degree);
    Vec2 RotDeg(Vec2 v1, float degree);
    Vec2 RotDeg(Vec2 v1, Vec2 v2, float degree);

    Vec2 RotRad(float rad);
    Vec2 RotRad(Vec2 v1, float rad);
    Vec2 RotRad(Vec2 v1, Vec2 v2, float rad);

    float x;
    float y;

};

#endif // VEC2_H
