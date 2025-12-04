#pragma once
#include <vector>
#include "node.h"

class Algorithm
{
private:
	std::vector<Node*> opened;
	std::vector<Node*> closed;
	bool found = false;

	bool IsWithinMap(int x, int y, int width, int height);
	int ShouldAdd(Node** map1, int x, int y, int corner, int width, int height);

public:
	void aStar(Node** map1, int width, int height, Play::Vector2f goal);
	void Breadth(Node** map1, int width, int height, Play::Vector2f goal);
	void Depth(Node** map1, int width, int height, Play::Vector2f goal);

};
