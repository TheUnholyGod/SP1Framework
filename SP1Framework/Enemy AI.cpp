
#include "AI Pathfinding.h"

extern SGameChar	g_sChar;
extern AI * AIEnemy;
extern vector<AI *>EnemyArray;
extern int g_CurrentLevel;
extern char map[40][130];
extern double g_dEnemyBounceTime;
extern double g_dElapsedTime;
int height = 0;
int width = 0;

extern bool g_isUpdated;

void AI::xCorridorMove()
{
	{
		do
		{
			dir = xDirections[rand() % 2];
		
			ChangePos();

		} while (AICollision(1) == true);
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

//double AI::wEstimatedDistance(int x, int y, int px, int py)
//{
//	double dx = x - px;
//	double dy = y - py;
//	double dist;
//
//	dist = pow(dx, 2) + pow(dy, 2);
//	dist = sqrt(dist);
//
//	return wDist;
//
//}
//double AI::aEstimatedDistance(int x, int y, int px, int py)
//{
//	double dx = x - px;
//	double dy = y - py;
//	double dist;
//
//	dist = pow(dx, 2) + pow(dy, 2);
//	dist = sqrt(dist);
//
//	return aDist;
//
//}
//double AI::sEstimatedDistance(int x, int y, int px, int py)
//{
//	double dx = x - px;
//	double dy = y - py;
//	double dist;
//
//	dist = pow(dx, 2) + pow(dy, 2);
//	dist = sqrt(dist);
//
//	return sDist;
//
//}
//double AI::dEstimatedDistance(int x, int y, int px, int py)
//{
//	double dx = x - px;
//	double dy = y - py;
//	double dist;
//
//	dist = pow(dx, 2) + pow(dy, 2);
//	dist = sqrt(dist);
//
//	return dDist;
//
//}

void AI::yCorridorMove()
{
	{
		do
		{

			dir = yDirections[rand() % 2];
			
			ChangePos();

		} while (AICollision(1) == true);
	}

}
void AI::RandomDirection()
{
	do
	{

		dir = directions[rand() % 4];
		
		ChangePos();

	} while (AICollision(1) == true);
}

bool AI::AICollision(int levelnumber)
{
	if (dir == 'w')
	{
		//Beep(1440, 30);
		// --------------------------------- UNABLE TO MOVE UP IF ITS NOT ' ' ---------------------------------------------// 
		if (map[AIEnemy->m_eLocation.X][AIEnemy->m_eLocation.Y + 1] == 'W')
		{

			++AIEnemy->m_eLocation.Y;

			return false;
		}

	}
	if (dir == 'a')
	{
		//Beep(1440, 30);
		// --------------------------------- UNABLE TO MOVE LEFT IS ITS NOT ' ' -------------------------------------------//
		if (map[AIEnemy->m_eLocation.X - 1][AIEnemy->m_eLocation.Y] == 'W')
		{

			++AIEnemy->m_eLocation.X;

			return false;
		}

	}
	if (dir == 's')
	{
		//Beep(1440, 30);
		// ---------------------------------- UNABLE TO MOVE DOWN IF ITS NOT ' ' -----------------------------------------//
		if (map[AIEnemy->m_eLocation.X][AIEnemy->m_eLocation.Y - 1] == 'W')
		{
			--AIEnemy->m_eLocation.Y;

			return false;
		}
	}
	if (dir == 'd')
	{
		//Beep(1440, 30);
		// ---------------------------------- UNABLE TO MOVE RIGHT IF ITS NOT ' ' ----------------------------------------//
		if (map[AIEnemy->m_eLocation.X + 1][AIEnemy->m_eLocation.Y] == 'W')
		{

			--AIEnemy->m_eLocation.X;

			return false;
		}
	}
	else
		return true;
	/*if (dir == 'w' && AIEnemy->m_eLocation.X > 0)
	{
		if (map[AIEnemy->m_eLocation.Y - 2][AIEnemy->m_eLocation.X] == (char)178 || map[AIEnemy->m_eLocation.Y - 2][AIEnemy->m_eLocation.X] == (char)219 || map[AIEnemy->m_eLocation.Y - 2][AIEnemy->m_eLocation.X] == (char)254 || map[AIEnemy->m_eLocation.Y - 2][AIEnemy->m_eLocation.X] == (char)220)
			return false;
	}
	if (dir == 'a' && AIEnemy->m_eLocation.Y > 0)
	{
		if (map[AIEnemy->m_eLocation.Y - 1][AIEnemy->m_eLocation.X - 1] == (char)178 || map[AIEnemy->m_eLocation.Y - 1][AIEnemy->m_eLocation.X - 1] == (char)219 || map[AIEnemy->m_eLocation.Y - 1][AIEnemy->m_eLocation.X - 1] == (char)254 || map[AIEnemy->m_eLocation.Y - 1][AIEnemy->m_eLocation.X - 1] == (char)220)
			return false;
	}
	if (dir == 's' && AIEnemy->m_eLocation.X < g_Console.getConsoleSize().X - 1)
	{
		if (map[AIEnemy->m_eLocation.Y][AIEnemy->m_eLocation.X] == (char)178 || map[AIEnemy->m_eLocation.Y][AIEnemy->m_eLocation.X] == (char)219 || map[AIEnemy->m_eLocation.Y][AIEnemy->m_eLocation.X] == (char)254 || map[AIEnemy->m_eLocation.Y][AIEnemy->m_eLocation.X] == (char)220)
			return false;
	}
	if (dir == 'd' && AIEnemy->m_eLocation.Y < g_Console.getConsoleSize().Y - 1)
	{
		if (map[AIEnemy->m_eLocation.Y - 1][AIEnemy->m_eLocation.X + 1] == (char)178 || map[AIEnemy->m_eLocation.Y - 1][AIEnemy->m_eLocation.X + 1] == (char)219 || map[AIEnemy->m_eLocation.Y - 1][AIEnemy->m_eLocation.X + 1] == (char)254 || map[AIEnemy->m_eLocation.Y - 1][AIEnemy->m_eLocation.X + 1] == (char)220)
			return false;
	}
	else
		return true;*/

}

void AI::ChangePos()
{
	bool bEnemySomethingHappened = false;
	if (g_dEnemyBounceTime > g_dElapsedTime)
		return;
	if (dir == 'a')
	{
		bEnemySomethingHappened = true;
		--AIEnemy->m_eLocation.X;
	}

	else if (dir == 'd')
	{
		bEnemySomethingHappened = true;
		++AIEnemy->m_eLocation.X;
	}

	else if (dir == 'w')
	{
		bEnemySomethingHappened = true;
		--AIEnemy->m_eLocation.Y;
	}
	else if (dir == 's')
	{
		bEnemySomethingHappened = true;
		++AIEnemy->m_eLocation.Y;

	}
	if (bEnemySomethingHappened)
	{
		// set the bounce time to some time in the future to prevent accidental triggers
		g_dEnemyBounceTime = g_dElapsedTime + 0.125; // 125ms should be enough
	}

}



