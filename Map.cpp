#include "Map.h"
#include<fstream>
#include "DyvirMap.h"

Map::Map() : _view(sf::FloatRect(200, 300, 200, 125))
{
    _music = true;
   // bufferPelea.loadFromFile("musicaMap.wav");
    musicaPelea.setBuffer(bufferPelea);
    musicaPelea.setVolume(30);
    _backTexture.loadFromFile("map.png");
}

void Map::loadMapCol()
{
    DyvirMap d;
    /* if (map[i][j] == 1)
    {
        d.setVelocity({ 0,0 }); }*/
}



void Map::loadMap(sf::RenderWindow& window)
{
    std::ifstream openfile("Mapa.txt");
    sf::Texture tileTexture;
    sf::Sprite tiles;
    int aux;
    DyvirMap d;
    sf::Vector2i map[300][300];
    sf::Vector2i loadCounter = sf::Vector2i(0, 0);
    sf::View _view(sf::FloatRect(200, 300, 200, 125));
    Map map2;


    if (openfile.is_open()) {
        std::string tileLocation;
        openfile >> tileLocation;
        tileTexture.loadFromFile(tileLocation);
        tiles.setTexture(tileTexture);
        while (!openfile.eof()) {
            std::string str;
            openfile >> str;
            char x = str[0], y = str[1];
            if (!isdigit(x) || !isdigit(y)) {
                map[loadCounter.x][loadCounter.y] = sf::Vector2i(-1, -1);
            }

            map[loadCounter.x][loadCounter.y] = sf::Vector2i(x - '0', y - '0');
            if (openfile.peek() != '\n') {
                loadCounter.x++;
            }
            else {
                aux = loadCounter.x;
                loadCounter.x = 0;
                loadCounter.y++;
            }

        }
        loadCounter.y++;
        aux++;
    }

   //sf::RenderWindow window(sf::VideoMode(800, 700, 30), "SFML works!");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        for (int i = 0; i < aux; i++) {
            for (int j = 0; j < loadCounter.y; j++) {
                if (map[i][j].x != -1 && map[i][j].y != -1) {
                    tiles.setPosition(float(i * 30), float(j * 30));
                    tiles.setTextureRect(sf::IntRect(map[i][j].x * 30, map[i][j].y * 30, 30, 30));
                    window.draw(tiles);
                }
            }
        }
        
        d.update();
        _view.setCenter(d.getPosition());
        window.setView(_view);
        window.draw(d);
        window.display();

    }
}

int Map::update(sf::Sprite& background, DyvirMap& DyvirMap, sf::RenderWindow& window)
{
    DyvirMap.update();
    _view.setCenter(DyvirMap.getPosition());
    background.setTexture(_backTexture);
    background.setTextureRect({ 0,0,700,700 });
    background.setScale(4, 4);
    window.setView(_view);
    window.draw(background);
    window.draw(DyvirMap);
    


    return 1;
}






