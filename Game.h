#pragma once
#include "Ship.h"
#include "Level.h"
#include "BulletPool.h"

class Game {
private:
    Ship* ship;
    BulletPool bulletPool;
    Level level;

    bool isShooting;
    int fireCooldown;
    int fireTimer;

public:
    Game();
    void init();
    void update();
    void render();
    void handleKeyPress(int key, float step);
    void setShooting(bool value);
    void onTimer();
};