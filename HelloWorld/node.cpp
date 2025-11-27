#include "node.h"

Node::Node()
{
	ID = { 0,0 };
	position = { 0,0 };
}

Node::Node(int x, int y)
{
	ID = { x,y };
	position = ID * 20;
}

Play::Vector2f Node::GetPosition()
{
	return position;
}

int Node::GetState()
{
	return state;
}

void Node::SetState(int newState)
{
	state = newState;
}

bool Node::GetBlocked()
{
	return blocked;
}

void Node::SetBlocked(bool block)
{
	blocked = block;
}

void Node::SetValues(float parentValue, Play::Vector2f goal)
{
	valueSofar = parentValue + 1;
	valueLeft = abs(position.x - goal.x) + abs(position.y - goal.y);
	valueTotal = valueSofar + valueLeft;
}

void Node::ResetNode()
{
	valueSofar = NULL;
	valueLeft = NULL;
	valueTotal = NULL;
	parent = NULL;
	state = 0;
	blocked = false;
}

float Node::GetValueSofar()
{
	return valueSofar;
}

float Node::GetValueLeft()
{
	return valueLeft;
}

float Node::GetValueTotal()
{
	return valueTotal;
}
