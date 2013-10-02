#pragma once
#include "e:\programming\sfml-2.1\include\sfml\graphics\rectangleshape.hpp"
#include "e:\programming\sfml-2.1\include\sfml\graphics\transformable.hpp"
class snakeBody
{
public:
	sf::RectangleShape bodyPiece;
	snakeBody(float width, float height);
	snakeBody(void);
	~snakeBody(void);
private:
	
//	void addPiece(void);


};

