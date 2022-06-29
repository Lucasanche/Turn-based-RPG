#include "stdafx.h"
#include "Map.h"

Map::Map() : _view(sf::FloatRect(200, 300, 300, 250))
{
    _music = true;
    bufferPelea.loadFromFile("musicaMap.wav");
    musicaPelea.setBuffer(bufferPelea);
    musicaPelea.setVolume(30);
    _backTexture.loadFromFile("map.png");
    std::ifstream openfile("Mapa.txt");

    if(openfile.is_open()){

    while(!openfile.eof()){
            std::string str;
            openfile>>str;
            char x= str[0], y= str[2];
            if(!isdigit(x)||!isdigit(y)){
                tempMap.push_back(sf::Vector2i(-1, -1));
            }

            tempMap.push_back(sf::Vector2i(x-'0', y-'0'));
            if(openfile.peek()=='\n'){
                map.push_back(tempMap);
                tempMap.clear();
            }

        }
        map.push_back(tempMap);
    }
}

int Map::update(DyvirMap& DyvirMap, sf::RenderWindow& window, DyvirFight& dyvir, Enemy& enemy)
{

    BrickTiles taux;
    int x=0, iaux, jaux, win=0;
    DyvirMap.update(taux);
    for (int i=0; i<map.size(); i++){
    for(int j=0; j<map[i].size(); j++){
        if(map[i][j].x==0 || map[i][j].y==0){

            tile.update(j, i, map[i][j].x, map[i][j].y);
            window.draw(tile);
        if(DyvirMap.isCollision(tile)){
                    taux=tile;
                    x=map[i][j].x;
                    iaux=i;
                    jaux=j;
                    //DyvirMap.setCollide(true);
        }
        //else {DyvirMap.setCollide(false);}
            }
        }
    }

    if(DyvirMap.isCollision(taux)&&x==0){
        DyvirMap.setCollide();
    }
    if(DyvirMap.isCollision(taux)&&x==1){
        DyvirMap.setCollide();
        while(enemy.getIsAlive()&&dyvir.getIsAlive()){

            window.clear();
            fight.update(dyvir, enemy, window);
            window.display();
        }
        if (!enemy.getIsAlive()){
                map[iaux][jaux].x=9;
                map[iaux][jaux].y=9;
                win++;
                    }
        if (!dyvir.getIsAlive()){
             window.close();
             std::cout << "Cagaste fuego";
             system("pause");
        }
    }

    _view.setCenter(DyvirMap.getPosition());
    window.setView(_view);
    window.draw(DyvirMap);

    return 1;
}





