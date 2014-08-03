#pragma once
#include "e:\programming\sfml-2.1\include\sfml\graphics\rectangleshape.hpp"
#include "e:\programming\sfml-2.1\include\sfml\graphics\transformable.hpp"
#include <list>
class snakeBody
{
public:
	std::list<sf::RectangleShape *> body;
	
	snakeBody(float width, float height);
	~snakeBody(void);

	void addPiece(void);
	
	void setWidth(float width);
	void setHeight(float height);
	void setLength(int lenght);
	
	float getHeight();
	float getWidth();
	int getLength();

private:
	float width;
	float height;
	int length;
	


};

