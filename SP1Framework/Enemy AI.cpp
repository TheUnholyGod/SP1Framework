//
//#include "AI Pathfinding.h"
//
//extern SGameChar	g_sChar;
//extern Enemy	g_sEnemy;
//extern COORD c;
//extern int g_CurrentLevel;
//int height = 0;
//int width = 0;
//
//char txt[100][100];
//
//char GetLevel(int x, int y)
//{
//	return txt[height][width];
//}

//void Enemy::EnemyMove(int playerY, int playerX)
//{
//	
//	RandomDirection();
//	
//}
//void Enemy::AIPathfinding(bool PassableDirection[4])
//{
//	int good = 0;
//	char EmptySpace[4] = { '-', '-', '-', '-' };
//	for (int i = 0; i < 4; ++i)
//	{
//		dir = directions[i];
//		if (PassableDirection[i] && EnemyCollision() == false && dir != dirOpp)
//		{
//			EmptySpace[good] = dir;
//			++good;
//		}
//	}
//	if (good == 0)
//	{
//		RandomDirection();
//	}
//	else
//	{
//		dir = EmptySpace[rand() % good];
//		ChangePos();
//	}
//
//}
//void Enemy::RandomDirection()
//{
//	GetOpposite();
//	
//	do
//	{
//		do
//		{
//			dir = directions[rand() % 4];
//		} while (dir == dirOpp);
//	} while (EnemyCollision() == true);
//	
//	ChangePos();
//
//}
//
//bool Enemy::EnemyCollision()
//{
//	int levelnumber = 1;
//
//	ifstream file;
//
//	if (levelnumber == 1)
//		file.open("Level_1.txt");
//	if (levelnumber == 2)
//		file.open("Level_2.txt");
//	if (levelnumber == 3)
//		file.open("Level_3.txt");
//	if (levelnumber == 4)
//		file.open("Level_4.txt");
//	if (levelnumber == 5)
//		file.open("Level_5.txt");
//	if (levelnumber == 6)
//		file.open("Level_6.txt");
//
//	COORD c;
//	if (file.is_open())
//	{
//		while (height < 25)
//		{
//			while (width < 80)
//			{
//				file >> txt[width][height];
//				width++;
//			}
//			width = 0;
//			height++;
//		}
//		file.close();
//	}
//	switch (dir)
//	{
//	case 'a':
//		if (g_sEnemy.m_eLocation.X == 0 || strchr(no_collision, GetLevel(y, x - 1)))
//		{
//			return false;
//		}
//		break;
//	case 'd':
//		if (g_sEnemy.m_eLocation.X == width - 1 || strchr(no_collision, GetLevel(y, x + 1)))
//		{
//			return false;
//		}
//		break;
//	case 'w':
//		if (strchr(no_collision, GetLevel(y - 1, x)))
//		{
//			return false;
//		}
//		break;
//	case 's':
//		if (strchr(no_collision, GetLevel(y + 1, x)))
//		{
//			return false;
//		}
//		break;
//		
//	}
//	return true;
//}
//
//void Enemy::GetOpposite()
//{
//	if (dirOld == 'a')
//	{
//		dirOpp = 'd';
//	}
//	if (dirOld == 'd')
//	{
//		dirOpp = 'a';
//	}
//	if (dirOld == 'w')
//	{
//		dirOpp = 's';
//	}
//	if (dirOld == 's')
//	{
//		dirOpp = 'w';
//	}
//}
//void Enemy::ChangePos()
//{
//	if (dir == 'a') {
//		if (g_sEnemy.m_eLocation.X == 0) 
//		{
//			g_sEnemy.m_eLocation.X = width - 1;
//		}
//		else {
//			--g_sEnemy.m_eLocation.X;
//		}
//	}
//	if (dir == 'd') {
//		if (g_sEnemy.m_eLocation.X == width - 1) 
//		{
//			g_sEnemy.m_eLocation.X = 0;
//		}
//		else {
//			++g_sEnemy.m_eLocation.X;
//		}
//	}
//	if (dir == 'w') {
//		--g_sEnemy.m_eLocation.Y;
//	}
//	if (dir == 's') {
//		++g_sEnemy.m_eLocation.Y;
//	}
//
//}



