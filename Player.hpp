#pragma once

using namespace sf;

class Player {
public:

    float dx,dy;
    FloatRect rect;
    bool onGround;
    Sprite sprite;
    float currentFrame;

    Player(Texture &image);

    void update(float time);

    void Collision(int num);
};
