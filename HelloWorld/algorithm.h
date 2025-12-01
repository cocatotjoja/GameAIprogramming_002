#pragma once
#include <vector>
#include "node.h"

class Algorithm
{
private:
	std::vector<Node*> opened;
	std::vector<Node*> closed;

public:
	void aStar(Node** map1, int width, int height, Play::Vector2f goal);
	void Breadth(Node** map1, int width, int height, Play::Vector2f goal);
	void Depth(Node** map1, int width, int height, Play::Vector2f goal);

};
