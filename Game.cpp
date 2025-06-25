#include "Game.h"
#include <GL/glut.h>

Game::Game() : bulletPool(50), isShooting(false), fireCooldown(15), fireTimer(0) {
    ship = new Ship(400.0f, 50.0f, 40.0f, 30.0f, Color(0.0f, 1.0f, 1.0f), &bulletPool);
}

void Game::init() {}

void Game::update() {
    if (isShooting && fireTimer <= 0) {
        ship->shoot();
        fireTimer = fireCooldown;
    }
    if (fireTimer > 0) --fireTimer;

    bulletPool.update();
    level.update();
}

void Game::render() {
    ship->draw();
    bulletPool.draw();
    level.draw();
}

void Game::setShooting(bool value) {
    isShooting = value;
}

void Game::handleKeyPress(int key, float step) {
    if (key == GLUT_KEY_LEFT) ship->moveLeft(step);
    else if (key == GLUT_KEY_RIGHT) ship->moveRight(step);
}

void Game::onTimer() {
    update();
    glutPostRedisplay();
    glutTimerFunc(16, [](int value) {
        reinterpret_cast<Game*>(value)->onTimer();
    }, reinterpret_cast<int>(this));
}