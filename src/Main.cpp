#include "stdafx.h"
#include "DyvirFight.h"
#include "Fight.h"
#include "Cursor.h"
#include "Menu.h"
#include "Map.h"
#include "DyvirMap.h"
#include "EnemyFactory.h"
#include "SaveGame.h"
#include <stdlib.h> 


//TODO: ver si puedo implementar esta función - Lucas
//bool waitSeconds(int sec, int passed) {
//	static bool _flag = true;
//	static int initial = 0;
//	if (_flag) {
//		initial = passed;
//		_flag = false;
//	}
//	if (passed - initial < sec) {
//		return false;
//	}
//	else {
//		_flag = true;
//		return true;
//	}
//}

int main() {
	srand(time(0));
	setlocale(LC_CTYPE, "Spanish"); 
	int numero = 0;
	std::cout << "daño" << std::endl;
	sf::RenderWindow window(sf::VideoMode(800, 700), "Proyectazo");
	window.setFramerateLimit(60);
	sf::Texture backTexture;
	sf::Sprite background;
	background.setTextureRect({ 0,0,800,700 });
	//menu inicio
	Menu* menu = new Menu(float(window.getSize().x), float(window.getSize().y));
	//PRUEBA: se supone que esto se ve reflectado en el menufight.
	AbilityFactory aux;
	//dyvir.setAbility1(aux.createEarthArmor());

	Map map(window);
	DyvirMap dyvirMap;
	sf::Event event;
	int option = 0;
	int optionFight = 0;
	int win = 0;
	system("pause");
	while (window.isOpen()) {
		setlocale(LC_CTYPE, "Spanish");
		while (window.pollEvent(event)) {
			window.clear();
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
		window.clear();
		switch (option) {
		case 0:
			menu->update();
			backTexture.loadFromFile("./Textures/Backgrounds/MenuInicio.jpg");
			background.setTexture(backTexture);
			window.draw(background);
			window.draw(*menu);
			option = menu->getOption();
			if (option != 0) {
				delete menu;
				menu = nullptr;
			}
			break;
		case 1:
			map.update(dyvirMap, window);
			break;
		case 2:
			break;
		case 3:
			window.close();
			break;
		}
		window.display();
	}
	return 0;
}