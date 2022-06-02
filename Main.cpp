#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "DyvirFight.h"
#include "dragonAzul.h"
#include "Fight.h"
#include "Cursor.h"


int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Proyectazo");
    window.setFramerateLimit(60);
    sf::Texture backTexture;
    //backTexture.loadFromFile("fondo.png");
    sf::Sprite background;
    int turno=0;


    Fight fight;
    Cursor cursorFight;
    dragonAzul enemy;
    DyvirFight dyvir;
    bool bpelea = true;
    sf::SoundBuffer bufferPelea;
    bufferPelea.loadFromFile("musicaPelea.wav");
    sf::Sound musicaPelea;
    musicaPelea.setBuffer(bufferPelea);
    musicaPelea.setVolume(30);
    int timer = 60 * 10;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        /*    if (timer < 0) {
                if (pelea) {
                    musicaPelea.play();
                    pelea = false;
                    timer = 60 * 24;
                }
            }*/
        //while (dyvir.getIsAlive()) {
            window.clear();
            fight.update(backTexture, dyvir, enemy);
            if (!dyvir.getIsAlive()) {
                dyvir.Die();

            }
            background.setTexture(backTexture);
            cursorFight.update();
            window.draw(background);
            //window.draw(cursorFight);
            window.draw(enemy);
            window.draw(dyvir);
            window.display();





        //if (!juan.getIsAlive()) {
            //FUNCION DE GANASTE Y KABOOM
        //}
        //david.setHP(0);
        //if (!david.getIsAlive()) {
            ///FUNCION DE PERDISTE
        //}


    }
    return 0;
}

        /*while (dyvir.getIsAlive()) {
            window.clear();
            if (turno%2==0){
                wait=true;
                while (wait){
                    attack=fight.menu();
                    wait=fight.update(backTexture, dyvir, enemy, attack);
                    window.clear();
                    background.setTexture(backTexture);
                    window.draw(background);
                    window.draw(enemy);
                    window.draw(dyvir);
                    window.display();

                }
            }
            if (turno%2!=0){
                fight.update(backTexture, dyvir, enemy);
                window.clear();
                background.setTexture(backTexture);
                window.draw(background);
                attack=fight.menu();
                window.draw(enemy);
                window.draw(dyvir);
                window.display();
            }
            if (!dyvir.getIsAlive()) {
                dyvir.Die();
            }
            if (!enemy.getIsAlive()) {
                enemy.Die();
            }
            turno++;

        }*/


