#include "Player.hpp"

Player::Player(Texture &image, Game &game) : game(game) {
    sprite.setTexture(image);
    rect = FloatRect(100, 180, 16, 16);

    dx = dy = 0.1;
    currentFrame = 0;
}

void Player::update(float time) {
    rect.left += dx * time;
    Collision(0);

    if (!onGround)
        dy = dy + 0.0005 * time;
    rect.top += dy * time;
    onGround = false;
    Collision(1);

    currentFrame += time * 0.005;
    if (currentFrame > 3)
        currentFrame -= 3;

    if (dx > 0)
        sprite.setTextureRect(IntRect(112 + 31 * int(currentFrame), 144, 16, 16));
    if (dx < 0)
        sprite.setTextureRect(IntRect(112 + 31 * int(currentFrame) + 16, 144, -16, 16));

    sprite.setPosition(rect.left - game.offsetX, rect.top - game.offsetY);

    dx = 0;
}

void Player::Collision(int num) {
    for (int i = rect.top / 16; i < (rect.top + rect.height) / 16; i++) {
        for (int j = rect.left / 16; j < (rect.left + rect.width) / 16; j++) {
            if ((game.TileMap[i][j] == 'P') || (game.TileMap[i][j] == 'k') ||
                (game.TileMap[i][j] == '0') || (game.TileMap[i][j] == 'r') ||
                (game.TileMap[i][j] == 't')) {
                if (dy > 0 && num == 1) {
                    rect.top = i * 16 - rect.height;
                    dy = 0;
                    onGround = true;
                }
                if (dy < 0 && num == 1) {
                    rect.top = i * 16 + 16;
                    dy = 0;
                }
                if (dx > 0 && num == 0) {
                    rect.left = j * 16 - rect.width;
                }
                if (dx < 0 && num == 0) {
                    rect.left = j * 16 + 16;
                }
            }

            if (game.TileMap[i][j] == 'c') {
                //game.TileMap[i][j]=' ';
            }
        }
    }
}
