#include "Level.h"

Level::Level() : enemySpeed(1.0f) {
    spawnEnemies();
}

void Level::spawnEnemies() {
    enemies.clear();
    for (int i = 0; i < 20; ++i) {
        float x = 50 + (i % 10) * 60;
        float y = 500 - (i / 10) * 60;
        enemies.push_back(std::make_unique<SquareEnemy>(x, y, 30.0f, Color(1.0f, 0.0f, 0.0f)));
    }
}

void Level::update() {
    for (auto& enemy : enemies)
        enemy->update();
}

void Level::draw() const {
    for (const auto& enemy : enemies)
        enemy->draw();
}

std::vector<std::unique_ptr<Enemy>>& Level::getEnemies() {
    return enemies;
}