#include "SquareEnemy.h"
#include <GL/glut.h>

SquareEnemy::SquareEnemy(float x, float y, float size, const Color& color)
    : Enemy(x, y, size, color) {}

void SquareEnemy::update() {
    // Hareket yok şimdilik
}

void SquareEnemy::draw() const {
    glColor3f(color.r, color.g, color.b);
    glBegin(GL_QUADS);
    glVertex2f(x - size / 2, y - size / 2);
    glVertex2f(x + size / 2, y - size / 2);
    glVertex2f(x + size / 2, y + size / 2);
    glVertex2f(x - size / 2, y + size / 2);
    glEnd();
}

bool SquareEnemy::isDestroyed() const {
    return false; // Vurulma mekaniği yok
}