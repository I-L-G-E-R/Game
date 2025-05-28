#include "Enemy.hpp"

void Enemy::set(Texture &image, int x, int y, Game &game) {
    this->game = &game;
    sprite.setTexture(image);
    rect = FloatRect(x, y, 16, 16);

    dx = 0.05;
    currentFrame = 0;
    life = true;
}

void Enemy::update(float time) {
    rect.left += dx * time;

    Collision();

    currentFrame += time * 0.005;
    if (currentFrame > 2)
        currentFrame -= 2;

    sprite.setTextureRect(IntRect(18 * int(currentFrame), 0, 16, 16));
    if (!life)
        sprite.setTextureRect(IntRect(58, 0, 16, 16));

    sprite.setPosition(rect.left - game->offsetX, rect.top - game->offsetY);
}

void Enemy::Collision() {
    for (int i = rect.top / 16; i < (rect.top + rect.height) / 16; i++) {
        for (int j = rect.left / 16; j < (rect.left + rect.width) / 16; j++) {
            if ((game->TileMap[i][j] == 'P') || (game->TileMap[i][j] == '0')) {
                if (dx > 0) {
                    rect.left = j * 16 - rect.width;
                    dx *= -1;
                } else if (dx < 0) {
                    rect.left = j * 16 + 16;
                    dx *= -1;
                }
            }
        }
    }
}
