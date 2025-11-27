#define PLAY_IMPLEMENTATION
#define PLAY_USING_GAMEOBJECT_MANAGER
#include "Play.h"
#include "node.h"

int DISPLAY_WIDTH = 600;
int DISPLAY_HEIGHT = 600;
int DISPLAY_SCALE = 2;

// Create Node arrays
Node nodes1[16][16];
Node nodes2[16][16];
Node nodes3[26][25];

int currentMap = 1;


// The entry point for a PlayBuffer program
void MainGameEntry( PLAY_IGNORE_COMMAND_LINE )
{
	switch (currentMap)
	{
	case 1:
		//Setup array 1
		for (int i = 0; i < 16; i++)
		{
			for (int j = 0; j < 16; j++)
			{
				nodes1[i][j] = Node(i, j);
			}
		}
		// Setup Map 1
		{
			for (int i = 0; i < 16; i++)
			{
				nodes1[i][0].SetBlocked(true);
				nodes1[i][15].SetBlocked(true);
				nodes1[15][i].SetBlocked(true);
				nodes1[0][i].SetBlocked(true);
			}
			for (int i = 3; i < 6; i++)
			{
				for (int j = 8; j < 13; j++)
				{
					nodes1[i][j].SetBlocked(true);
				}
			}
			for (int i = 9; i < 12; i++)
			{
				for (int j = 6; j < 10; j++)
				{
					nodes1[i][j].SetBlocked(true);
				}
			}
			nodes1[10][5].SetBlocked(true);
			nodes1[11][5].SetBlocked(true);

			for (int i = 3; i < 8; i++)
			{
				nodes1[i][2].SetBlocked(true);
			}
			nodes1[4][3].SetBlocked(true);
			nodes1[5][3].SetBlocked(true);
			nodes1[6][3].SetBlocked(true);
			nodes1[5][4].SetBlocked(true);

			nodes1[11][12].SetBlocked(true);
			nodes1[12][12].SetBlocked(true);
			nodes1[11][13].SetBlocked(true);
			nodes1[12][13].SetBlocked(true);
		}
		break;
	case 2:
		// Setup array 2
		for (int i = 0; i < 16; i++)
		{
			for (int j = 0; j < 16; j++)
			{
				nodes2[i][j] = Node(i, j);
			}
		}
		// Setup Map 2
		{
			for (int i = 0; i < 16; i++)
			{
				nodes2[i][0].SetBlocked(true);
				nodes2[i][15].SetBlocked(true);
				nodes2[15][i].SetBlocked(true);
				nodes2[0][i].SetBlocked(true);
			}

			nodes2[1][5].SetBlocked(true);

			for (int i = 2; i < 16; i++)
			{
				if (i != 4 && i != 10)
				{
					nodes2[2][i].SetBlocked(true);
				}
			}

			nodes2[3][3].SetBlocked(true);
		
			for (int i = 3; i < 16; i++)
			{
				if (i != 7 && i != 13)
				{
					nodes2[4][i].SetBlocked(true);
				}
			}

			nodes2[5][1].SetBlocked(true);
			nodes2[5][5].SetBlocked(true);
			nodes2[5][8].SetBlocked(true);

			for (int i = 1; i < 16; i++)
			{
				if (i != 4 && i != 14)
				{
					nodes2[6][i].SetBlocked(true);
				}
			}

			nodes2[7][2].SetBlocked(true);
			nodes2[7][12].SetBlocked(true);
			nodes2[7][13].SetBlocked(true);

			for (int i = 2; i < 16; i++)
			{
				if (i != 7 && i != 11 && i != 14)
				{
					nodes2[8][i].SetBlocked(true);
				}
			}

			nodes2[9][2].SetBlocked(true);
			nodes2[9][12].SetBlocked(true);
			nodes2[9][13].SetBlocked(true);

			for (int i = 9; i < 12; i++)
			{
				nodes2[i][6].SetBlocked(true);
			}

			for (int i = 10; i < 15; i++)
			{
				nodes2[i][4].SetBlocked(true);
				nodes2[i][8].SetBlocked(true);
				nodes2[i][10].SetBlocked(true);
			}

			nodes2[10][2].SetBlocked(true);
			nodes2[12][2].SetBlocked(true);
			nodes2[13][2].SetBlocked(true);
			nodes2[13][1].SetBlocked(true);

			nodes2[14][12].SetBlocked(true);
			nodes2[13][14].SetBlocked(true);
			nodes2[10][13].SetBlocked(true);

			nodes2[12][12].SetBlocked(true);
			nodes2[12][13].SetBlocked(true);
			nodes2[12][14].SetBlocked(true);

		}
		break;
	case 3:
		// Setup array 3
		for (int i = 0; i < 26; i++)
		{
			for (int j = 0; j < 25; j++)
			{
				nodes3[i][j] = Node(i, j);
			}
		}
		// Setup Map 3
		{
			for (int i = 0; i < 26; i++)
			{
				nodes3[i][0].SetBlocked(true);
				nodes3[i][24].SetBlocked(true);
			}
			for (int i = 0; i < 25; i++)
			{
				nodes3[0][i].SetBlocked(true);
				nodes3[25][i].SetBlocked(true);
			}

			nodes3[1][15].SetBlocked(true);
			nodes3[2][15].SetBlocked(true);
			nodes3[1][18].SetBlocked(true);

			nodes3[3][21].SetBlocked(true);
			nodes3[3][15].SetBlocked(true);
			nodes3[3][14].SetBlocked(true);
			nodes3[3][13].SetBlocked(true);

			nodes3[6][23].SetBlocked(true);
			nodes3[6][22].SetBlocked(true);
			nodes3[6][20].SetBlocked(true);

			nodes3[4][9].SetBlocked(true);

			for (int i = 3; i < 7; i++)
			{
				nodes3[i][18].SetBlocked(true);
			}
			for (int i = 6; i < 13; i++)
			{
				nodes3[i][13].SetBlocked(true);
				nodes3[i][19].SetBlocked(true);
			}
			for (int i = 1; i < 8; i++)
			{
				if (i != 2)
				{
					nodes3[8][i].SetBlocked(true);
				}
			}

			nodes3[12][12].SetBlocked(true);
			nodes3[12][20].SetBlocked(true);

			for (int i = 12; i < 18; i++)
			{
				nodes3[i][11].SetBlocked(true);
			}
			for (int i = 9; i < 20; i++)
			{
				nodes3[i][6].SetBlocked(true);
			}

			nodes3[15][14].SetBlocked(true);
			nodes3[16][15].SetBlocked(true);
			nodes3[16][14].SetBlocked(true);
			nodes3[16][12].SetBlocked(true);

			nodes3[16][1].SetBlocked(true);
			nodes3[16][2].SetBlocked(true);
			nodes3[16][3].SetBlocked(true);
		
			nodes3[18][5].SetBlocked(true);
			nodes3[18][4].SetBlocked(true);

			nodes3[17][20].SetBlocked(true);
			nodes3[18][20].SetBlocked(true);

			nodes3[20][22].SetBlocked(true);
			nodes3[21][22].SetBlocked(true);
		
			nodes3[21][13].SetBlocked(true);
			nodes3[22][13].SetBlocked(true);
		
			nodes3[19][14].SetBlocked(true);
			nodes3[19][16].SetBlocked(true);

			nodes3[20][11].SetBlocked(true);
			nodes3[21][11].SetBlocked(true);
			nodes3[22][11].SetBlocked(true);
			nodes3[24][11].SetBlocked(true);

			for (int i = 16; i < 25; i++)
			{
				nodes3[i][17].SetBlocked(true);
			}
			for (int i = 20; i < 25; i++)
			{
				nodes3[i][4].SetBlocked(true);
			}
			for (int i = 7; i < 13; i++)
			{
				nodes3[19][i].SetBlocked(true);
			}
		}
		break;
	default:
		break;
	}


	Play::CreateManager( DISPLAY_WIDTH, DISPLAY_HEIGHT, DISPLAY_SCALE );
}

// Called by PlayBuffer every frame (60 times a second!)
bool MainGameUpdate( float elapsedTime )
{
	Play::ClearDrawingBuffer( Play::cWhite );
	Play::DrawDebugText( { DISPLAY_WIDTH / 2, DISPLAY_HEIGHT / 2 }, "Hello World!" );

	//Update array
	switch (currentMap)
	{
	case 1:
		// Update nodes1
		break;
	case 2:
		// Update nodes2
		break;
	case 3:
		// Update nodes3
		break;
	default:
		break;
	}
	
	// Draw map
	switch (currentMap)
	{
	case 1:
		// Draw array for map 1
		for (int i = 0; i < 16; i++)
		{
			for (int j = 0; j < 16; j++)
			{
				if (nodes1[i][j].GetBlocked())
				{
					Play::DrawRect(nodes1[i][j].GetPosition() + Play::Vector2f{ 1,1 }, nodes1[i][j].GetPosition() + Play::Vector2f{ 18,18 }, Play::cRed, true);
				}
				else
				{
					Play::DrawRect(nodes1[i][j].GetPosition() + Play::Vector2f{ 1,1 }, nodes1[i][j].GetPosition() + Play::Vector2f{ 18,18 }, Play::cCyan, true);
				}
			}
		}
		break;
	case 2:
		// Draw array for map 2
		for (int i = 0; i < 16; i++)
		{
			for (int j = 0; j < 16; j++)
			{
				if (nodes2[i][j].GetBlocked())
				{
					Play::DrawRect(nodes2[i][j].GetPosition() + Play::Vector2f{ 1,1 }, nodes2[i][j].GetPosition() + Play::Vector2f{ 18,18 }, Play::cRed, true);
				}
				else
				{
					Play::DrawRect(nodes2[i][j].GetPosition() + Play::Vector2f{ 1,1 }, nodes2[i][j].GetPosition() + Play::Vector2f{ 18,18 }, Play::cCyan, true);
				}
			}
		}
		break;
	case 3:
		// Draw array for map 3
		for (int i = 0; i < 26; i++)
		{
			for (int j = 0; j < 25; j++)
			{
				if (nodes3[i][j].GetBlocked())
				{
					Play::DrawRect(nodes3[i][j].GetPosition() + Play::Vector2f{ 1,1 }, nodes3[i][j].GetPosition() + Play::Vector2f{ 18,18 }, Play::cRed, true);
				}
				else
				{
					Play::DrawRect(nodes3[i][j].GetPosition() + Play::Vector2f{ 1,1 }, nodes3[i][j].GetPosition() + Play::Vector2f{ 18,18 }, Play::cCyan, true);
				}
			}
		}
		break;
	default:
		break;
	}


	Play::PresentDrawingBuffer();
	return Play::KeyDown( KEY_ESCAPE );
}

// Gets called once when the player quits the game 
int MainGameExit( void )
{
	Play::DestroyManager();
	return PLAY_OK;
}

