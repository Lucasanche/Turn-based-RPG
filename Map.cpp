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

int Map::update(DyvirMap& DyvirMap, sf::RenderWindow& window, DyvirFight& dyvir)
{
    DyvirMap.update();
    for (int i=0; i<map.size(); i++){
        for(int j=0; j<map[i].size(); j++){
            if(map[i][j].x==0 || map[i][j].y==0){
                tile.update(j, i, map[i][j].x, map[i][j].y);
                window.draw(tile);
                if(DyvirMap.isCollision(tile)){
                            _taux=tile;
                            x=map[i][j].x;
                            iaux=i;
                            jaux=j;
                }
            }
        }
    }
    if(DyvirMap.isCollision(_taux)){
        DyvirMap.setCollide();
        if (x == 1) {
            fight.setBoss(dyvir.getWins());
            while (fight.getEnemyIsAlive()  && dyvir.getIsAlive()) {
                window.clear();
                fight.update(dyvir, window);
                window.display();
            }
            if (!fight.getEnemyIsAlive()) {
                map[iaux][jaux].x = 9;
                map[iaux][jaux].y = 9;
                x = 9;
                _taux = tile;
                dyvir.setWins();
            }
            if (!dyvir.getIsAlive()) {
                window.close();
                std::cout << "Cagaste fuego";
                system("pause");
            }
            fight.deleteBoss();
        }
    }

    _view.setCenter(DyvirMap.getPosition());
    window.setView(_view);
    window.draw(DyvirMap);

    return 1;
}





