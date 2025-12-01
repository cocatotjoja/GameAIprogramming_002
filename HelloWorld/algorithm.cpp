#include "algorithm.h"


void Algorithm::aStar(Node** map1, int width, int height, Play::Vector2f goal)
{
	//Check if opened is empty, if so add the start node
	if (opened.empty())
	{
		opened.push_back(&(map1[1][height-1]));
		map1[1][height - 1].SetValues(0, goal);
	}
	// Loop through opened nodes and find the smallest one
	int smallestID = 0;
	int smallestValue = 0;
	for (int i = 0; i < opened.size(); i++)
	{
		if (opened[0]->GetValueTotal() < smallestValue)
		{
			smallestID = i;
			smallestValue = opened[0]->GetValueTotal();
		}
	}

	Play::Vector2f parentID = opened[smallestID]->GetPosition() / 20;
	float parentValue = opened[smallestID]->GetValueSofar();

	// For all adjacent nodes
	map1[(int)parentID.x + 1][(int)parentID.y];
	map1[(int)parentID.x - 1][(int)parentID.y];
	map1[(int)parentID.x][(int)parentID.y + 1];
	map1[(int)parentID.x][(int)parentID.y - 1];

	// Diagonally blocked???
	map1[(int)parentID.x + 1][(int)parentID.y + 1];
	map1[(int)parentID.x - 1][(int)parentID.y - 1];
	map1[(int)parentID.x - 1][(int)parentID.y + 1];
	map1[(int)parentID.x + 1][(int)parentID.y - 1];


	// If they are Unchecked add to open and update values
	// If they are Opened update values if relevant
	// If they are closed return to opened and update values if relevant
}

void Algorithm::Breadth(Node** map1, int width, int height, Play::Vector2f goal)
{
}

void Algorithm::Depth(Node** map1, int width, int height, Play::Vector2f goal)
{

	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			opened.push_back(&(map1[x][y]));
		}
	}

}
