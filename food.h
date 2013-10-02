#pragma once
#include "e:\programming\sfml-2.1\include\sfml\graphics\rectangleshape.hpp"
class food
{
public:
	sf::RectangleShape foodPiece;
	food(float width, float height);
	food(void);
	~food(void);
};

