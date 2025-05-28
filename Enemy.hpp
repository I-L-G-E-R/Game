#pragma once
#include "StartGame.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace sf;

class Enemy {
public:
    float dx, dy;
    FloatRect rect;
    Sprite sprite;
    float currentFrame;
    bool life;

    void set(Texture &image, int x, int y, Game &game);
    void update(float time);
    void Collision();

private:
    Game *game;
};
