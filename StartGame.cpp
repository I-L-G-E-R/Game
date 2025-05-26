#include "Enemy.hpp"
#include "Player.hpp"
#include "StartGame.hpp"

using namespace sf;


void StartGame() {

    RenderWindow window(VideoMode(400, 250), "SFML works!");

    Texture tileSet;
    tileSet.loadFromFile("Mario_tileset.png");

    Player Mario(tileSet);
    Enemy enemy;
    enemy.set(tileSet,48*16,13*16);

    Sprite tile(tileSet);

    SoundBuffer buffer;
    buffer.loadFromFile("Jump.ogg");
    Sound sound(buffer);

    Music music;
    music.openFromFile("Mario_Theme.ogg");
    music.play();

    Clock clock;
    Clock hurtClock;
    bool isHurt = false;

    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time/500;

        if (time > 20) time = 20;

        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        if (Keyboard::isKeyPressed(Keyboard::Left))    Mario.dx=-0.1;
        if (Keyboard::isKeyPressed(Keyboard::Right))    Mario.dx=0.1;
        if (Keyboard::isKeyPressed(Keyboard::Up)) if (Mario.onGround) { Mario.dy=-0.27; Mario.onGround=false;  sound.play();}

        Mario.update(time);
        enemy.update(time);

        // Проверка столкновения с врагом
        if (Mario.rect.intersects(enemy.rect))
        {
            if (enemy.life) {
                if (Mario.dy>0) {
                    enemy.dx=0;
                    Mario.dy=-0.2;
                    enemy.life=false;
                }
                else {
                    Mario.sprite.setColor(Color::Red);
                    isHurt = true;
                    hurtClock.restart();
                }
            }
        }


        if (isHurt && hurtClock.getElapsedTime().asSeconds() >= 3.0f)
        {
            isHurt = false;
            Mario.sprite.setColor(Color::White);
        }

        if (Mario.rect.left>200) offsetX = Mario.rect.left-200;

        window.clear(Color(107,140,255));

        for (int i=0; i<H; i++)
            for (int j=0; j<W; j++)
            {
                if (TileMap[i][j]=='P')  tile.setTextureRect(IntRect(143-16*3,112,16,16));
                if (TileMap[i][j]=='k')  tile.setTextureRect(IntRect(143,112,16,16));
                if (TileMap[i][j]=='c')  tile.setTextureRect(IntRect(143-16,112,16,16));
                if (TileMap[i][j]=='t')  tile.setTextureRect(IntRect(0,47,32,95-47));
                if (TileMap[i][j]=='g')  tile.setTextureRect(IntRect(0,16*9-5,3*16,16*2+5));
                if (TileMap[i][j]=='G')  tile.setTextureRect(IntRect(145,222,222-145,255-222));
                if (TileMap[i][j]=='d')  tile.setTextureRect(IntRect(0,106,74,127-106));
                if (TileMap[i][j]=='w')  tile.setTextureRect(IntRect(99,224,140-99,255-224));
                if (TileMap[i][j]=='r')  tile.setTextureRect(IntRect(143-32,112,16,16));
				if (TileMap[i][j]=='q')  tile.setTextureRect(IntRect(96,6,202-95,110-6));
                if ((TileMap[i][j]==' ') || (TileMap[i][j]=='0')) continue;
                tile.setPosition(j*16-offsetX,i*16 - offsetY);
                window.draw(tile);
            }

        window.draw(Mario.sprite);
        window.draw(enemy.sprite);
        window.display();
    }
}
