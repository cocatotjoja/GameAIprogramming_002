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

Play::Vector2f Node::GetID()
{
	return ID;
}

bool Node::IsBlocked()
{
	return blocked;
}

int Node::GetState()
{
	return state;
}

void Node::SetState(int newState)
{
	state = newState;
}

void Node::SetBlocked(bool block)
{
	blocked = block;
}

void Node::SetValues(float parentValue, Play::Vector2f goal)
{
	valueSofar = parentValue;
	valueLeft = abs(position.x - goal.x) + abs(position.y - goal.y);
	valueTotal = valueSofar + valueLeft;
}

void Node::SetParent(Play::Vector2f parentNode)
{
	parent = parentNode;
}

Play::Vector2f Node::GetParent()
{
	return parent;
}

void Node::ResetNode()
{
	valueSofar = NULL;
	valueLeft = NULL;
	valueTotal = NULL;
	parent = ID;
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
