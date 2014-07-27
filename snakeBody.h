#pragma once
#include "e:\programming\sfml-2.1\include\sfml\graphics\rectangleshape.hpp"
#include "e:\programming\sfml-2.1\include\sfml\graphics\transformable.hpp"
class snakeBody
{
public:
	struct body {
		sf::RectangleShape *piece;
		struct body *next;
	};
	struct body *head;
	struct body *tail;
	
	snakeBody(float width, float height);
	snakeBody(void);
	~snakeBody(void);

	struct body* addPiece(void);
	
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

