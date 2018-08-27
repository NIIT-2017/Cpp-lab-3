#include "Ocean.h"
#include "Stone.h"
#include "Coral.h"
#include "Prey.h"
#include "Predator.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>
#include <cstdio> 
#include <stdio.h>  


using namespace std;

Ocean::~Ocean()
{
	for (size_t i = 0; i < N; i++)
		delete[] cells[i];
	delete[] cells;
	
}

bool Ocean::read(char* name) 
{
	ifstream file; 
	file.open(name);

	if (!file.is_open())
	{
		cout << "Ошибка открытия файла" << endl;
		return false;
	}
	
	string s1;
	char *str1, *str2;
	int k=1;

	while (getline(file, s1)) 
	{ 
		if (s1.size()==0) continue;
		
		str1=strtok((char*)s1.c_str(), "=");

		str2 = str1;
		str1 = strtok(NULL, "\n");

	    if (str1 != NULL)
			{
				if (fill(str2, atoi(str1), k) != k)
				{
					cout << "Ошибка чтения данных" << endl;
					return false;
				}	
				k++;
			}
	}

	if (k != 15) { cout << "Недостаточно данных в файле" << endl; return false;}

	file.close(); 

	return true;
}

int Ocean::fill(char *a, int b, int k)
{
	
	if (k == 1 && strcmp(a, "Длина") == 0)
	{
		M = b;
		return k;
	}

	if (k == 2 && strcmp(a, "Ширина") == 0)
	{
		N = b;
		return k;
	}

	if (k == 3 && strcmp(a, "Stone") == 0)
	{
		val.Stone = b;
		return k;
	}

	if (k == 4 && strcmp(a, "Coral") == 0)
	{
		val.Coral = b;
		return k;
	}
	
	if (k == 5 && strcmp(a, "Продолжительность жизни") == 0)
	{
		 val.liveTime1=b;
		return k;
	}

	if (k == 6 && strcmp(a, "Цикл размножения") == 0)
	{
		val.cycle_r1 = b;
		return k;
	}

	if (k == 7 && strcmp(a, "Prey") == 0)
	{
		val.Prey = b;
		return k;
	}

	if (k == 8 && strcmp(a, "Продолжительность жизни") == 0)
	{
		val.liveTime2 = b;
		return k;
	}

	if (k == 9 && strcmp(a, "Время цикла питания") == 0)
	{
		val.hunger2 = b;
		return k;
	}

	if (k == 10 && strcmp(a, "Цикл размножения") == 0)
	{
		val.cycle_r2 = b;
		return k;
	}

	if (k == 11 && strcmp(a, "Predator") == 0)
	{
		val.Predator = b;
		return k;
	}

	if (k == 12 && strcmp(a, "Продолжительность жизни") == 0)
	{
		val.liveTime3 = b;
		return k;
	}

	if (k == 13 && strcmp(a, "Время цикла питания") == 0)
	{
		val.hunger3 = b;
		return k;
	}

	if (k == 14 && strcmp(a, "Цикл размножения") == 0)
	{
		val.cycle_r3 = b;
		return k;
	}

	return 0;
}



void Ocean::print() const
{
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < M; j++)
		{
			std::cout <<
				(cells[i][j].getObject() ?
					cells[i][j].getObject()->getName() : '.');
		}
		std::cout << std::endl;
	}
}
void Ocean::addObjects(int count, int type)
{

	size_t x, y;
	
		while (count > 0)
		{
			 x= rand() % N;
			 y = rand() % M;
			if (cells[x][y].getObject())
				continue;
			else
			{
				createObject(x, y, type);
				count--;
			}
				
		}
}

void Ocean::createObject(size_t x, size_t y, int type)
{
		if (x > 0 && x < N-1 && y > 0 && y < M-1)
		{
			Object *born = nullptr;
			if (type == 1) born = new Stone(&cells[x][y]);
			if (type == 2) born = new Coral(&cells[x][y], &val);
			if (type == 3) born = new Prey (&cells[x][y], &val);
			if (type == 4) born = new Predator(&cells[x][y], &val);

			cells[x][y].setObject(born);
		}
}

void Ocean::run()
{
	char name[200];
	cout << "Введите имя файла настроек" << endl;
	gets_s(name);

	if (!read(name)) return;

	cells = new Cell*[N];
	for (size_t i = 0; i < N; i++)
	{
		cells[i] = new Cell[M];
		for (size_t j = 0; j < M; j++)
			cells[i][j].init(Pair{ j, i }, this);
	}
	
		addObjects(val.Stone, 1);
		addObjects(val.Coral, 2);
		addObjects(val.Prey, 3);
		addObjects(val.Predator, 4);
		
		while (1)
		{
			int type = 0, stone = 0, coral = 0, prey = 0, predator = 0;
			
			oceanLive();

			clock_t now = clock();
			while (clock() < now + CLOCKS_PER_SEC);
			system("cls");

			print();

			for (size_t i = 0; i < N; i++)
			{
				for (size_t j = 0; j < M; j++)
				{
					type = 0;
					if (cells[i][j].getObject())type = cells[i][j].getObject()->getType();

					if (type == 1) stone++;
					if (type == 2) coral++;
					if (type == 3) prey++;
					if (type == 4) predator++;
				}
			}

			if (prey == 0 || predator == 0) break;

			std::cout << "stone=" << stone << "  Coral=" << coral <<
				"  Prey=" << prey << "  Predator=" << predator << std::endl;

			tt++;
		}
	
}

void Ocean::oceanLive() 
{
	int type = 0;
	int *a = nullptr;

	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < M; j++)
		{
			if (cells[i][j].getObject())
			{
				
				type = cells[i][j].getObject()->getType();
				if (type == 2 && tt%cells[i][j].getObject()->getObject(3)==0)
				{
					if (cells[i-1][j].getObject()==nullptr) createObject(i-1, j, 2);
					if (cells[i+1][j].getObject() == nullptr) createObject(i+1, j, 2);
					if (cells[i][j-1].getObject() == nullptr) createObject(i, j-1, 2);
					if (cells[i][j+1].getObject() == nullptr) createObject(i, j+1, 2);
				}

				if (type > 2) objectLive(i, j, type);
				
			}
		}
	}

	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < M; j++)
		{
			if (cells[i][j].getObject())
			{
				cells[i][j].getObject()->live();
				if (cells[i][j].getObject()->getObject(1)==0 || cells[i][j].getObject()->getObject(2) == 0)
					cells[i][j].killMe();
			}
		}
	}
}


void Ocean::objectLive(size_t x, size_t y, int type)
{
	size_t a, b;
	int count=1, liveTime, hunger;

	while (count > 0)
	{
		a = rand() % N;
		b = rand() % M;
		if (cells[a][b].getObject())
		{
			if ((cells[x][y].getObject()->getType() == 3 && cells[a][b].getObject()->getType() == 2)
				|| (cells[x][y].getObject()->getType() == 4 && cells[a][b].getObject()->getType() == 3))
			{
				hunger = cells[x][y].getObject()->getObject(2);
				
				if (type==3)hunger = hunger + 5;
				if (type == 4)hunger = hunger + 15;

				cells[x][y].getObject()->setObject(2, hunger);
				cells[a][b].killMe();

				copy(x, y, a, b);
				count--;
			}
			else
			if (cells[x][y].getObject()->getType() == cells[a][b].getObject()->getType())
			{
				if (tt%cells[x][y].getObject()->getObject(3) == 0) addObjects(1, type);
			}

			continue;
		}
		else
		{
			copy(x, y, a, b);
			count--;
		}

	}
	
}

void Ocean::copy(int x, int y, int a, int b)
{
	int type, liveTime, hunger;
	Object *born = nullptr;
	type = cells[x][y].getObject()->getType();

	if (type == 3) born = new Prey(&cells[a][b], &val);
	if (type == 4) born = new Predator(&cells[x][y], &val);

	cells[a][b].setObject(born);

	liveTime = cells[x][y].getObject()->getObject(1);
	hunger = cells[x][y].getObject()->getObject(2);

	cells[a][b].getObject()->setObject(1, liveTime);
	cells[a][b].getObject()->setObject(2, hunger);
	

	cells[x][y].killMe();
}