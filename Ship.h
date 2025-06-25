#pragma once
#include "BulletPool.h"
#include "Color.h"

class Ship {
private:
    float x, y;
    float width, height;
    Color color;
    BulletPool* bulletPool;

public:
    Ship(float x, float y, float width, float height, const Color& color, BulletPool* pool);

    void draw() const;
    void moveLeft(float step);
    void moveRight(float step);

    void shoot();

    float leftGunX() const;
    float rightGunX() const;
    float gunY() const;
};