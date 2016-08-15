#include "loadlevel.h"

string read()
{
	ifstream read("Level_1.txt");
	string str, str1;

	int index = 0;
	if (read.is_open())
	{
		getline(read, str);
		while (read)
		{
			str1 += str;
			getline(read, str);
		}
		//cout << str1 << endl;
		return str1;
	}
}