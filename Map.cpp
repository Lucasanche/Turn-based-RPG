#include "stdafx.h"
#include "Map.h"

Map::Map() : _view(sf::FloatRect(200, 300, 300, 250))
{
    _music = true;
    bufferPelea.loadFromFile("musicaMap.wav");
    musicaPelea.setBuffer(bufferPelea);
    musicaPelea.setVolume(30);
    _backTexture.loadFromFile("map.png");
    x = iaux = jaux = win = 0;
    std::ifstream openfile("Mapa.txt");
    _option = 0;

    if(openfile.is_open()){
        std::vector<sf::Vector2i>tempMap;
        while(!openfile.eof()){
            std::string str;
            openfile>>str;
            char x= str[0], y= str[2];
            tempMap.push_back(sf::Vector2i(x-'0', y-'0'));
            if(openfile.peek()=='\n'){
                map.push_back(tempMap);
                tempMap.clear();
            }
        }
        map.push_back(tempMap);
    }
}

void Map::update(DyvirMap& DyvirMap, sf::RenderWindow& window, DyvirFight& dyvir)
{
    //if (sf::Keyboard::isKeyPressed(sf::Keyboard::0)) {
    //    _option = 0;
    //}
    //if (sf::Keyboard::isKeyPressed(sf::Keyboard::1)) {
    //    _option = 1;
    //}
    switch (_option) {

    case 0:
        DyvirMap.update();
        for (int i = 0; i < map.size(); i++) {
            for (int j = 0; j < map[i].size(); j++) {
                if (map[i][j].x == 0 || map[i][j].y == 0) {
                    tile.update(j, i, map[i][j].x, map[i][j].y);
                    window.draw(tile);
                    if (DyvirMap.isCollision(tile)) {
                        _taux = tile;
                        x = map[i][j].x;
                        iaux = i;
                        jaux = j;
                    }
                }
            }
        }
        _view.setCenter(DyvirMap.getPosition());
        window.setView(_view);
        window.draw(DyvirMap);
        if (DyvirMap.isCollision(_taux)) {
            DyvirMap.setCollide();
            if (x == 1) {
                _option = 1;
                fight.setBoss(dyvir.getWins());
                window.clear();
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::I)) {
            _option = 2;
        }
        break;
    case 1:
        fight.update(dyvir, window);
        if (!fight.getEnemyIsAlive()) {
            map[iaux][jaux].x = 9;
            map[iaux][jaux].y = 9;
            x = 9;
            _taux = tile;
            dyvir.setWins();
            _option = 0;
            fight.deleteBoss();
        }
        if (!dyvir.getIsAlive()) {
            window.close();
            std::cout << "Cagaste fuego";
            system("pause");
            _option = 0;
        }
        break;
    case 2:
        //fight.setBoss(dyvir.getWins());
        window.clear();
        std::cout << "ingrese un número del 1" << std::endl;
        std::cin >> _option;
        
    }
}





