#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <string>

using namespace std;
int main()
{
srand(time(NULL));
string card[36] = { "11K","6K","7K","8K","9K","10K","2K","3K","4K",		"11B","6B","7B","8B","9B","10B","2B","3B","4B",		"11C","6C","7C","8C","9C","10C","2C","3C","4C",		"11P","6P","7P","8P","9P","10P","2P","3P","4P" };
string blacklist[36] = { "0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0" };

for (int i = 0; i <= 35; i++)
{
	string temp;
		temp = card[i];
		int x = rand() % (36-i) +i;
	card[i] = card[x];
	card[x] = temp;
}

for (int i = 0; i <= 35; i++)
	{
		std::cout << " "<<card[i];
	}
system("pause");
	return 0;
}
	