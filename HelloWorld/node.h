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
	Node* parent = NULL;
	int state = 0;
	bool blocked = false;

public:
	Node();
	Node(int x, int y);

	Play::Vector2f GetPosition();
	int GetState();
	void SetState(int newState);
	bool GetBlocked();
	void SetBlocked(bool block);
	void SetValues(float parentValue, Play::Vector2f goal);
	void ResetNode();
	float GetValueSofar();
	float GetValueLeft();
	float GetValueTotal();

};
