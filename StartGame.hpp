#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace sf;

class Game {
public:
    static const int H = 17;
    static const int W = 142;

    String TileMap[H] = {
        "000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000P000000000000",
        "0                                                                                                                                P           0",
        "0                                                                                                                                P           0",
        "0                   w                                  w                   w                                               w     P           0",
        "0                                      w                                                        w                                P           0",
        "0                                                                                                                                P           0",
        "0                                                                                                                                P           0",
        "0                                                                       r                                                        P           0",
        "0                                                                      rrr                                         q             P           0",
        "0                                                                     rrrrr                                                      P           0",
        "0               k    kkkkk                                           rrrrrrr                                                     P           0",
        "0                                      t0                           rrrrrrrrr                                                    P           0",
        "0G                                     00              t0          rrrrrrrrrrr                                                   P           0",
        "0           d    g       d             00              00         rrrrrrrrrrrrr                                                  P           0",
        "PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP",
        "PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP",
        "PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP",
    };

    float offsetX = 0;
    float offsetY = 0;

    void run();
};
