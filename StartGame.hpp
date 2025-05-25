#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace sf;

void StartGame();

static float offsetX = 0;
static float offsetY = 0;

const int H = 17;
const int W = 142;

static String TileMap[H];
