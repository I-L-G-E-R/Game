#pragma once
#include "StartGame.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace sf;

class Player {
public:
    float dx, dy;
    FloatRect rect;
    bool onGround;
    Sprite sprite;
    float currentFrame;

    Player(Texture &image, Game &game);

    void update(float time);
    void Collision(int num);

private:
    Game &game;
};
