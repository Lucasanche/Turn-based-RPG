#include "DyvirMap.h"



DyvirMap::DyvirMap()
{

    _texture.loadFromFile("dyvirMap.png");
    _sprite.setTexture(_texture);
    _sprite.setTextureRect({ 0, 0, 184, 170 });
    _sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height);
    _sprite.setScale(0.15, 0.15);
    _sprite.setPosition(200, 200 - _sprite.getGlobalBounds().height);
    _frame = 0;
    Collide=false;

}


void DyvirMap::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(_sprite, states);
}

void DyvirMap::update(BrickTilesq tile)
{
    _frame += 0.1;
    if (_frame >= 5) {
        _frame = 0;
    }
    _sprite.setTextureRect({ int(_frame) * 222, 0, 184, 170 });


    /// MOV
    _velocity = { 0, 0 };
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        _velocity.y = -1;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        _velocity.y = 1;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        _velocity.x = -1;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        _velocity.x = 1;
    }

    ///EVITAR QUE SALGA DE LA PANTALLA!!!!!!!!!!!!!!;;;


    ///QUE MIRE A LOS LADOS
    _sprite.move(_velocity);
    if (_velocity.x < 0) {
        _sprite.setScale(-0.15, 0.15);
    }
    if(_velocity.x > 0) {
        _sprite.setScale(0.15, 0.15);
    }

    ///EVITAR QUE SALGA DE LA PANTALLA;;;
    if(_sprite.getGlobalBounds().left<0){
            _sprite.setPosition(0 + _sprite.getGlobalBounds().width/2, _sprite.getPosition().y);
            std::cout << _sprite.getGlobalBounds().width << std::endl;
        }
    if(_sprite.getGlobalBounds().top<0){
            _sprite.setPosition(_sprite.getPosition().x, 0 + _sprite.getGlobalBounds().height);
        }

    if(_sprite.getGlobalBounds().left+_sprite.getGlobalBounds().width>1550){
            _sprite.setPosition(1550 - _sprite.getGlobalBounds().width/2, _sprite.getPosition().y);
        }
    if(_sprite.getGlobalBounds().top+_sprite.getGlobalBounds().height>1900){
            _sprite.setPosition(_sprite.getPosition().x,1900);
            std::cout << _sprite.getGlobalBounds().height << std::endl;
        }




}

sf::FloatRect DyvirMap::getBounds() const {

    return _sprite.getGlobalBounds();

}

void DyvirMap::setCollide()
{
        if(_velocity.x!=0){ //1
            _sprite.move(-_velocity.x, 0);
            std::cout<<_velocity.x<<std::endl;
            std::cout<<"colisiona x"<<std::endl;

        }
        if(_velocity.y!=0){ //1
            _sprite.move(0, -_velocity.y);
            std::cout<<_velocity.x<<std::endl;
            std::cout<<"colisiona y"<<std::endl;
        }
        std::cout<<"colisiona"<<std::endl;


}


