#pragma once
#include "e:\programming\sfml-2.1\include\sfml\graphics\rectangleshape.hpp"
#include "e:\programming\sfml-2.1\include\sfml\graphics\transformable.hpp"
#include <list>
class snakeBody
{
public:
	std::list<sf::RectangleShape *> body;
	sf::RectangleShape *head;
	
	snakeBody(float size, float startX, float startY);
	~snakeBody(void);

	void addPiece(int direction);
	
	void setSize(float size);
	void setLength(int length);
	
	float getSize();	
	int getLength();

private:
	float size;
	int length;
	


};

