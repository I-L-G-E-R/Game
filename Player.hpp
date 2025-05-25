#include <SFML/Graphics.hpp>

using namespace sf;

class PLAYER {
public:
    PLAYER(Texture &image);

    void update(float time);

    void Collision(int num);
};
