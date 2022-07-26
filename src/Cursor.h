#pragma once
#ifndef CURSOR_H
#define CURSOR_H


class Cursor : public sf::Drawable
{
private:
	sf::Texture _texture;
	sf::Sprite _sprite;
public:
	Cursor();
	void setPosition(sf::Vector2f);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	sf::Sprite getSprite() { return _sprite; }
};

#endif