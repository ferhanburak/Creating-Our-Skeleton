#include "Ship.h"
#include <GL/glut.h>

Ship::Ship(float x, float y, float width, float height, const Color& color, BulletPool* pool)
    : x(x), y(y), width(width), height(height), color(color), bulletPool(pool) {}

void Ship::draw() const {
    glColor3f(color.r, color.g, color.b);
    glBegin(GL_TRIANGLES);
    glVertex2f(x, y + height);
    glVertex2f(x - width / 2, y);
    glVertex2f(x + width / 2, y);
    glEnd();
}

void Ship::moveLeft(float step) {
    x -= step;
    if (x - width / 2 < 0) x = width / 2;
}

void Ship::moveRight(float step) {
    x += step;
    if (x + width / 2 > 800) x = 800 - width / 2;
}

void Ship::shoot() {
    Bullet* bullet = bulletPool->getBullet();
    if (bullet) {
        bullet->activate(x, y + height);
    }
}

float Ship::leftGunX() const { return x - width / 4; }
float Ship::rightGunX() const { return x + width / 4; }
float Ship::gunY() const { return y + height; }