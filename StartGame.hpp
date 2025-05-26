#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace sf;

void StartGame();

namespace {
const int H = 17;
const int W = 142;

float offsetX = 0;
float offsetY = 0;

String TileMap[H] = {
"000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000P000000000000",
"0                                                                                                                                P           0",
"0                                                                                                                                P           0",
"0                   w                                  w                   w                                               w     P           0",
"0                                      w                                                        w                                P           0",
"0                                                                                                                                P           0",
"0                      c                                                                                                         P           0",
"0                                                                       r                                                        P           0",
"0                                                                      rrr                                         q             P           0",
"0                                                                     rrrrr                                                      P           0",
"0               c    kckck                                           rrrrrrr                                                     P           0",
"0                                      t0                           rrrrrrrrr                                                    P           0",
"0G                                     00              t0          rrrrrrrrrrr                                                   P           0",
"0           d    g       d             00              00         rrrrrrrrrrrrr                                                  P           0",
"PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP",
"PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP",
"PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP",
};
}
