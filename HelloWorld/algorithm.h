#pragma once
#include <vector>
#include <queue>
#include <stack>
#include "node.h"

class Algorithm
{
private:
	std::vector<Node*> opened;
	std::vector<Node*> closed;

	std::queue<Node*> openedBFS;
	std::queue<Node*> closedBFS;

	std::stack<Node*> openedDFS;
	std::stack<Node*> closedDFS;

	bool found = false;
	bool addStart = true;

	int ShouldAdd(Node** map1, int x, int y, int corner, int width, int height);
	void AddNode(Node** map1, Play::Vector2f parentID, int parentXplus, int parentYplus, float addValue, int corner, float parentValue, int width, int height, Play::Vector2f goal);

public:
	void aStar(Node** map1, int width, int height, Play::Vector2f start, Play::Vector2f goal, int* runtime);
	void Breadth(Node** map1, int width, int height, Play::Vector2f start, Play::Vector2f goal, int* runtime);
	void Depth(Node** map1, int width, int height, Play::Vector2f start, Play::Vector2f goal, int* runtime);
	void Dijkstra(Node** map1, int width, int height, Play::Vector2f start, Play::Vector2f goal, int* runtime);
};
