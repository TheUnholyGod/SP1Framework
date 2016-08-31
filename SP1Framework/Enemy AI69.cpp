
#include "AI Pathfinding.h"

extern SGameChar	g_sChar;
extern AI	g_sEnemy;
extern int g_CurrentLevel;
vector<double>DistValues;
int height = 0;
int width = 0;

extern bool g_isUpdated;

void AI::AIMove(int playerY, int playerX)
{
	
	RandomDirection();
	
}

void AI::xCorridorMove()
{
	{
		do
		{

			dir = xDirections[rand() % 2];
			AICollision();
			ChangePos();

		} while (AICollision() == true);
	}

}
//void Node::NodeStart()
//{
//	
//}
//void Node::Pathfinding()
//{
//	priority_queue<Node> OpenList;
//	priority_queue<Node> ClosedList;
//	Node Node_Start;
//	Node_Start.NodeX = g_sEnemy.m_eLocation.X;
//	Node_Start.NodeY = g_sEnemy.m_eLocation.Y;
//	Node_Start.f = 0;
//	OpenList.push(Node_Start);
//	
//	while (!OpenList.empty)
//	{
//
//	}
//
//}

//void AI::AIPathfinding()
//{
//	while (g_sEnemy.m_eLocation.X != g_sChar.m_cLocation.X && g_sEnemy.m_eLocation.Y != g_sChar.m_cLocation.Y)
//	{
//		
//		wEstimatedDistance(g_sEnemy.m_eLocation.X, g_sEnemy.m_eLocation.Y - 1, g_sChar.m_cLocation.X, g_sChar.m_cLocation.Y);
//
//		DistValues.push_back(wDist);
//
//
//		sEstimatedDistance(g_sEnemy.m_eLocation.X, g_sEnemy.m_eLocation.Y + 1, g_sChar.m_cLocation.X, g_sChar.m_cLocation.Y);
//
//		DistValues.push_back(sDist);
//
//			aEstimatedDistance(g_sEnemy.m_eLocation.X - 1, g_sEnemy.m_eLocation.Y, g_sChar.m_cLocation.X, g_sChar.m_cLocation.Y);
//
//			DistValues.push_back(aDist);
//
//			dEstimatedDistance(g_sEnemy.m_eLocation.X + 1, g_sEnemy.m_eLocation.Y, g_sChar.m_cLocation.X, g_sChar.m_cLocation.Y);
//
//			DistValues.push_back(dDist);
//				
//				int shortest = *(min(DistValues.begin(), DistValues.end()));
//
//				if (shortest == aDist)
//				{
//					dir = 'a';
//					ChangePos();
//					DistValues.clear();
//				}
//				else if (shortest == dDist)
//				{
//					dir = 'd';
//					ChangePos();
//					DistValues.clear();
//				}
//
//
//			if (shortest == wDist)
//			{
//				dir = 'w';
//				ChangePos();
//				DistValues.clear();
//			}
//
//			else if (shortest == sDist)
//			{
//				dir = 's';
//				ChangePos();
//				DistValues.clear();
//			}
//		
//
//		else if (g_sEnemy.m_eLocation.X == g_sChar.m_cLocation.X && g_sEnemy.m_eLocation.Y == g_sChar.m_cLocation.Y)
//		{
//			break;
//		}
//		
//
//	}
//}

double AI::wEstimatedDistance(int x, int y, int px, int py)
{
	double dx = x - px;
	double dy = y - py;
	double dist;

	dist = pow(dx, 2) + pow(dy, 2);
	dist = sqrt(dist);

	return wDist;

}
double AI::aEstimatedDistance(int x, int y, int px, int py)
{
	double dx = x - px;
	double dy = y - py;
	double dist;

	dist = pow(dx, 2) + pow(dy, 2);
	dist = sqrt(dist);

	return aDist;

}
double AI::sEstimatedDistance(int x, int y, int px, int py)
{
	double dx = x - px;
	double dy = y - py;
	double dist;

	dist = pow(dx, 2) + pow(dy, 2);
	dist = sqrt(dist);

	return sDist;

}
double AI::dEstimatedDistance(int x, int y, int px, int py)
{
	double dx = x - px;
	double dy = y - py;
	double dist;

	dist = pow(dx, 2) + pow(dy, 2);
	dist = sqrt(dist);

	return dDist;

}

void AI::yCorridorMove()
{
	{
		do
		{

			dir = yDirections[rand() % 2];
			AICollision();
			ChangePos();

		} while (AICollision() == true);
	}

}
void AI::RandomDirection()
{
	
		g_isUpdated = false;
		do
		{
			
			dir = directions[rand() % 4];
			AICollision();
			ChangePos();
			
	} while (AICollision() == true);
}

bool AI::AICollision()
{
	g_isUpdated = false;
	char txt[130][25];
	int height = 0;
	int width = 0;
	int levelnumber = 1;
	ifstream file;

	if (levelnumber == 1)
		file.open("CampaignLevels/Level_1.txt");
	if (levelnumber == 2)
		file.open("CampaignLevels/Level_2.txt");
	if (levelnumber == 3)
		file.open("CampaignLevels/Level_3.txt");
	if (levelnumber == 4)
		file.open("CampaignLevels/Level_4.txt");
	if (levelnumber == 5)
		file.open("CampaignLevels/Level_5.txt");
	if (levelnumber == 6)
		file.open("CampaignLevels/Level_6.txt");

	if (file.is_open())
	{
		while (height < 25)
		{
			while (width < 130)
			{
				file >> txt[width][height];
				width++;
			}
			width = 0;
			height++;
		}
		file.close();
	}

	if (dir == 'w')
	{
		//Beep(1440, 30);
		// --------------------------------- UNABLE TO MOVE UP IF ITS NOT ' ' ---------------------------------------------// 
		if (txt[g_sEnemy.m_eLocation.X][g_sEnemy.m_eLocation.Y + 1] == 'W')
		{
			
			--g_sEnemy.m_eLocation.Y;
			
			return false;
		}

	}
	if (dir == 'a')
	{
		//Beep(1440, 30);
		// --------------------------------- UNABLE TO MOVE LEFT IS ITS NOT ' ' -------------------------------------------//
		if (txt[g_sEnemy.m_eLocation.X - 1][g_sEnemy.m_eLocation.Y] == 'W')
		{
			
			++g_sEnemy.m_eLocation.X;
			
			return false;
		}

	}
	if (dir == 's')
	{
		//Beep(1440, 30);
		// ---------------------------------- UNABLE TO MOVE DOWN IF ITS NOT ' ' -----------------------------------------//
		if (txt[g_sEnemy.m_eLocation.X][g_sEnemy.m_eLocation.Y - 1] == 'W')
		{
			
			++g_sEnemy.m_eLocation.Y;
			
			return false;
		}
	}
	if (dir == 'd')
	{
		//Beep(1440, 30);
		// ---------------------------------- UNABLE TO MOVE RIGHT IF ITS NOT ' ' ----------------------------------------//
		if (txt[g_sEnemy.m_eLocation.X + 1][g_sEnemy.m_eLocation.Y] == 'W')
		{
			
			--g_sEnemy.m_eLocation.X;
			
			return false;
		}
	}
	else
		return true;
}
void AI::GetOpp()
{
	g_isUpdated = false;
	if (dir == 'a')
	{
		dir = 'd';
	}
	else if (dir == 'd')
	{
		dir = 'a';
	}
	else if (dir == 'w')
	{
		dir = 's';
	}
	else if (dir == 's')
	{
		dir = 'w';
	}
}
void AI::ChangePos()
{
	g_isUpdated = false;
	if (dir == 'a')
		{
			g_isUpdated = false;
			--g_sEnemy.m_eLocation.X;
			
		}
	
	else if (dir == 'd')
		 {
			 g_isUpdated = false;
			++g_sEnemy.m_eLocation.X;
			
		}
	
	else if (dir == 'w')
	{
		g_isUpdated = false;
		++g_sEnemy.m_eLocation.Y;
		
	}
	else if (dir == 's')
	{
		g_isUpdated = false;
		--g_sEnemy.m_eLocation.Y;
		
	}

}



