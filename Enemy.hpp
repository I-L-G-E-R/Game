#pragma once

using namespace sf;

class Enemy {
public:
   float dx,dy;
   FloatRect rect;
   Sprite sprite;
   float currentFrame;
   bool life;

   void set(Texture &image, int x, int y);
   void update(float time);
   void Collision();
};
