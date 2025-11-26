#pragma once
#include "Play.h"

class Node
{
private:
	Play::Vector2f position;
	float valueSofar = NULL;
	float valueLeft = NULL;
	float valueTotal = NULL;
	Node* parent = NULL;
	int state = 0;

public:
	Node();
	Node(int x, int y, float parentValue);

	Play::Vector2f GetPosition();
	int GetState();
	void SetValues(float parentValue, Play::Vector2f goal);
	float GetValueSofar();
	float GetValueLeft();
	float GetValueTotal();

};
