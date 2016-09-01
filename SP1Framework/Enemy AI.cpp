
#include "AI Pathfinding.h"

extern SGameChar	g_sChar;
extern AI * AIEnemy;
extern vector<AI *>EnemyArray;
extern int g_CurrentLevel;
extern char map[40][130];
extern double g_dEnemyBounceTime;
extern double g_dElapsedTime;
extern bool g_isMapLoaded;
int height = 0;
int width = 0;


void AI::xCorridorMove()
{
		do
		{
			dir = xDirections[rand() % 2];
			ChangePos();
			
		} while (AICollision(1) == true);
	
}
//void Node::NodeStart()
//{
//	
//}
//
//
//
//void AI::Pathfinding()
//{
//	priority_queue<Node> OpenList;
//	priority_queue<Node> ClosedList;
//	Node Node_Start;
//	Node_Start.NodeX = AIEnemy->m_eLocation.X;
//	Node_Start.NodeY = AIEnemy->m_eLocation.Y;
//	Node_Start.f = 0;
//	OpenList.push(Node_Start);
//	
//	while (!OpenList.empty)
//	{
//		
//	}
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
	} while (AICollision(g_CurrentLevel) == true);
}

bool AI::AICollision(int levelnumber)
{
	if (dir == 'w' && AIEnemy->m_eLocation.X > 0)
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
		return true;

}

void AI::ChangePos()
{
	bool bEnemySomethingHappened = false;
	if (g_dEnemyBounceTime > g_dElapsedTime)
		return;
	if (dir == 'a')
	{
		if (AICollision(g_CurrentLevel))
		{
			bEnemySomethingHappened = true;
			--AIEnemy->m_eLocation.X;
		}
	}

	else if (dir == 'd')
	{
		
		if (AICollision(g_CurrentLevel))
		{
			bEnemySomethingHappened = true;
			++AIEnemy->m_eLocation.X;
		}
		
	}

	else if (dir == 'w')
	{
		
		if (AICollision(g_CurrentLevel))
		{
			bEnemySomethingHappened = true;
			--AIEnemy->m_eLocation.Y;
		}
		

	}
	else if (dir == 's')
	{
		
		if (AICollision(g_CurrentLevel))
		{
			bEnemySomethingHappened = true;
			++AIEnemy->m_eLocation.Y;
		};
		

	}
	if (bEnemySomethingHappened)
	{
		// set the bounce time to some time in the future to prevent accidental triggers
		g_dEnemyBounceTime = g_dElapsedTime + 0.125; // 125ms should be enough
		g_isMapLoaded = false;
	}

}


