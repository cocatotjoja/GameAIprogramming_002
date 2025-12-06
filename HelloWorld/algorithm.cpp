#include "algorithm.h"


//Return 0, if shouldn'd add, returns 1 if unchecked, returns 2 if opened, returns 3 if closed
int Algorithm::ShouldAdd(Node** map1, int x, int y, int corner, int width, int height)
{
	//Chacke if within map
	if (x < width - 1 && x > 0 && y < height -1 && y > 0)
	{
		// Check if blocked
		if (map1[x][y].IsBlocked())
		{
			return 0;
		}
		//Play::DrawDebugText({ 300, 550 }, "In map", Play::cBlack);
		//Check diagonal
		switch (corner)
		{
		case 1:
			if (map1[x+1][y].IsBlocked() || map1[x][y-1].IsBlocked())
			{
				return 0;
			}
			break;
		case 2:
			if (map1[x - 1][y].IsBlocked() || map1[x][y - 1].IsBlocked())
			{
				return 0;
			}
			break;
		case 3:
			if (map1[x + 1][y].IsBlocked() || map1[x][y + 1].IsBlocked())
			{
				return 0;
			}
			break;
		case 4:
			if (map1[x - 1][y].IsBlocked() || map1[x][y + 1].IsBlocked())
			{
				return 0;
			}
			break;
		default:
			break;
		}

		std::string stateStr;
		stateStr = std::to_string(map1[x][y].GetState());
		//Play::DrawDebugText({ 320, 500 }, stateStr.c_str(), Play::cBlack);
		
		// Check state, Unchecked = 1, Opened = 2, Closed = 3
		switch (map1[x][y].GetState())
		{
		case 1:
			//Play::DrawDebugText({ 300, 500 }, "Add", Play::cBlack);
			return 1;
			break;
		case 2:
			return 2;
			break;
		case 3:
			//Play::DrawDebugText({ 300, 500 }, "Add", Play::cBlack);
			return 3;
			break;
		default:
			break;
		}
	}
	else
	{
		return 0;
	}
}

void Algorithm::AddNode(Node** map1, Play::Vector2f parentID, int parentXplus, int parentYplus, float addValue, int corner, float parentValue, int width, int height, Play::Vector2f goal)
{
	switch (ShouldAdd(map1, parentXplus, parentYplus, corner, width, height))
	{
	case 1:
		// Update Value, Parent, and state
		map1[parentXplus][parentYplus].SetValues(parentValue + 1, goal);
		map1[parentXplus][parentYplus].SetParent(parentID);
		map1[parentXplus][parentYplus].SetState(2);

		// Add to open list
		opened.push_back(&(map1[parentXplus][parentYplus]));
		Play::DrawDebugText({ 300, 500 }, "node added to open", Play::cBlack);
		break;
	case 2:
		// Compare and update value and parent if needed
		if (map1[parentXplus][parentYplus].GetValueSofar() < parentValue + 1)
		{
			map1[parentXplus][parentYplus].SetValues(parentValue + 1, goal);
			map1[parentXplus][parentYplus].SetParent(parentID);
		}
		break;
	case 3:
		// If new value is smaller than existing
		if (map1[parentXplus][parentYplus].GetValueSofar() > parentValue + 1)
		{
			// Update Value, Parent, and state
			map1[parentXplus][parentYplus].SetValues(parentValue + 1, goal);
			map1[parentXplus][parentYplus].SetParent(parentID);
			map1[parentXplus][parentYplus].SetState(2);

			// Add to open list
			opened.push_back(&(map1[parentXplus][parentYplus]));

			// Remove from closed list
			for (int i = 0; i < closed.size(); i++)
			{
				if (map1[parentXplus][parentYplus].GetPosition() == closed[i]->GetPosition())
				{
					closed.at(i) = closed.back();
					closed.pop_back();
				}
			}
		}
		Play::DrawDebugText({ 300, 500 }, "node added to open", Play::cBlack);
		break;
	default:
		break;
	}
}

void Algorithm::aStar(Node** map1, int width, int height, Play::Vector2f start, Play::Vector2f goal)
{
	if (found)
	{
		return;
	}
	//Check if opened is empty, if so add the start node
	if (opened.empty())
	{
		int x = start.x / 20;
		int y = start.y / 20;
		opened.push_back(&(map1[1][height-2]));
		map1[x][y].SetValues(0, goal);
		map1[x][y].SetState(2);
		map1[x][y].SetParent(map1[x][y].GetID());

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


	if (opened[smallestID]->GetPosition() == goal)
	{
		
		Play::Vector2f currentID = opened[smallestID]->GetPosition() / 20;
		while (currentID != map1[(int)currentID.x][(int)currentID.y].GetParent())
		{
			map1[(int)currentID.x][(int)currentID.y].SetState(4);
			currentID = map1[(int)currentID.x][(int)currentID.y].GetParent();
		}
		
		found = true;
	}
	else
	{
		Play::Vector2f parentID = opened[smallestID]->GetID();
		float parentValue = opened[smallestID]->GetValueSofar();

		

		// Adjacent nodes

		//map1[(int)parentID.x + 1][(int)parentID.y];
		AddNode(map1, parentID, (int)parentID.x + 1, (int)parentID.y, 1.0f, 0, parentValue, width, height, goal);

		//map1[(int)parentID.x - 1][(int)parentID.y];
		AddNode(map1, parentID, (int)parentID.x - 1, (int)parentID.y, 1.0f, 0, parentValue, width, height, goal);

		//map1[(int)parentID.x][(int)parentID.y + 1];
		AddNode(map1, parentID, (int)parentID.x, (int)parentID.y + 1, 1.0f, 0, parentValue, width, height, goal);

		//map1[(int)parentID.x][(int)parentID.y - 1];
		AddNode(map1, parentID, (int)parentID.x, (int)parentID.y - 1, 1.0f, 0, parentValue, width, height, goal);



		// Diagonal Nodes
		//map1[(int)parentID.x - 1][(int)parentID.y + 1];
		AddNode(map1, parentID, (int)parentID.x - 1, (int)parentID.y + 1, 1.4f, 1, parentValue, width, height, goal);
		
		//map1[(int)parentID.x + 1][(int)parentID.y + 1];
		AddNode(map1, parentID, (int)parentID.x + 1, (int)parentID.y + 1, 1.4f, 2, parentValue, width, height, goal);

		//map1[(int)parentID.x - 1][(int)parentID.y - 1];
		AddNode(map1, parentID, (int)parentID.x - 1, (int)parentID.y - 1, 1.4f, 3, parentValue, width, height, goal);
	
		//map1[(int)parentID.x + 1][(int)parentID.y - 1];
		AddNode(map1, parentID, (int)parentID.x + 1, (int)parentID.y - 1, 1.4f, 4, parentValue, width, height, goal);
		

		// Add currently looked at node to closed list and update its state
		//opened[smallestID]->SetState(3);
		map1[(int)parentID.x][(int)parentID.y].SetState(3);
		closed.push_back(&(map1[(int)parentID.x][(int)parentID.y]));

		// Remove currently looked at node from opened list
		opened.at(smallestID) = opened.back();
		opened.pop_back();
	}
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
