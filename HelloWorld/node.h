#pragma once
#include "Play.h"

class Node
{
private:
	Play::Vector2f ID;
	Play::Vector2f position;
	float valueSofar = NULL;
	float valueLeft = NULL;
	float valueTotal = NULL;
	Play::Vector2f parent = ID;
	
	// Unchecked = 1, Opened = 2, Closed = 3, Path = 4
	int state = 1;
	bool blocked = false;

public:
	Node();
	Node(int x, int y);

	Play::Vector2f GetPosition();
	bool IsBlocked();
	int GetState();
	void SetState(int newState);
	void SetBlocked(bool block);
	void SetValues(float parentValue, Play::Vector2f goal);
	void SetParent(Play::Vector2f parentNode);
	Play::Vector2f GetParent();
	void ResetNode();
	float GetValueSofar();
	float GetValueLeft();
	float GetValueTotal();

};
