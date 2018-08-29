#include "Ocean.h"
#include "Object.h"
#include "Stone.h"
#include "Coral.h"
#include "Prey.h"
#include "Predator.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <stdio.h>
#include <sys/ioctl.h>
#include <sys/select.h>
#include <termios.h>
#include <stropts.h>
int _kbhit();

Ocean::Ocean(const std::string & path)
{
	using namespace std;
	std::ifstream fin;
	fin.open(path);

	if (!fin.is_open())
	{
		cout << "File is not open" << endl;
	}
	
	string param[10];

	unsigned int i{ 0 };
	while (!fin.eof())
	{
		getline(fin, param[i++]);
	}

	global.N = stoi(param[0]);
	global.M = stoi(param[1]);

	global.LIVE_TIME_STONE = stoi(param[2]);
	global.LIVE_TIME_CORAL = stoi(param[3]);
	global.BREED_TIME_CORAL = stoi(param[4]);

	global.LIVE_TIME_PREY = stoi(param[5]);
	global.BREED_TIME_PREY = stoi(param[6]);
	
	global.LIVE_TIME_PREDATOR = stoi(param[7]);
	global.BREED_TIME_PREDATOR = stoi(param[8]);
	global.FOOD_TIME_PREDATOR = stoi(param[9]);
	fin.close();
	
	
	cout << global.N << endl;
	cout << global.M << endl;
	cout << global.LIVE_TIME_STONE << endl;
	cout << global.LIVE_TIME_CORAL << endl;
	cout << global.BREED_TIME_CORAL << endl;
	
	cout << global.LIVE_TIME_PREY << endl;
	cout << global.BREED_TIME_PREY << endl;
	
	cout << global.LIVE_TIME_PREDATOR << endl;
	cout << global.BREED_TIME_PREDATOR << endl;
	cout << global.FOOD_TIME_PREDATOR << endl;
	
	cells = new Cell*[global.N];
	for (unsigned int i = 0; i < global.N; i++)
	{
		cells[i] = new Cell[global.M];
		for (unsigned int j = 0; j < global.M; j++)
			cells[i][j].init(Pair{ j, i }, this);
	}
}

Ocean::~Ocean()
{
	for (unsigned int i = 0; i < global.N; i++)
		delete[] cells[i];
	delete[] cells;
	liveObject.clear();
}

void Ocean::print() const
{
	for (unsigned int i = 0; i < global.N; i++)
	{
		for (unsigned int j = 0; j < global.M; j++)
			std::cout <<
			(cells[i][j].getObject() ?
				cells[i][j].getObject()->getName() : '.');

		std::cout << std::endl;
	}
}
void Ocean::addObjects(int count)
{
	while (count>0)
	{
		unsigned int x = rand() % global.M;
		unsigned int y = rand() % global.N;
		if (cells[y][x].getObject())
			continue;
		else
		{
			Object * born;
			ObjType type = static_cast<ObjType>(rand() % 4);
			switch (type)
			{
			case ObjType::STONE:
				born = new Stone(&cells[y][x]);
				break;
			case ObjType::CORAL:
				born = new Coral(&cells[y][x]);
				break;
			case ObjType::PREY:
				born = new Prey(&cells[y][x]);
				break;
			case ObjType::PREDATOR:
				born = new Predator(&cells[y][x]);
				break;
			}

			cells[y][x].setObject(born);
			liveObject[Pair{ x, y }] = born;
			count--;
		}
	}
}

void Ocean::addObjects(int count, ObjType type)
{
	while (count>0)
	{
		unsigned int x = rand() % global.M;
		unsigned int y = rand() % global.N;
		if (cells[y][x].getObject())
			continue;
		else
		{
			Object * born;
			switch (type)
			{
			case ObjType::STONE:
				born = new Stone(&cells[y][x]);
				break;
			case ObjType::CORAL:
				born = new Coral(&cells[y][x]);
				break;
			case ObjType::PREY:
				born = new Prey(&cells[y][x]);
				break;
			case ObjType::PREDATOR:
				born = new Predator(&cells[y][x]);
				break;
			}

			cells[y][x].setObject(born);
			liveObject[Pair{ x, y }] = born;
			count--;
		}
	}
}

void Ocean::addObject(ObjType type, Pair crd)
{
	if (!cells[crd.y][crd.x].getObject())
	{
		Object * o;
		switch (type)
		{
		case ObjType::STONE:
			o = new Stone(&cells[crd.y][crd.x]);
			break;
		case ObjType::CORAL:
			o = new Coral(&cells[crd.y][crd.x]);
			break;
		case ObjType::PREY:
			o = new Prey(&cells[crd.y][crd.x]);
			break;
		case ObjType::PREDATOR:
			o = new Predator(&cells[crd.y][crd.x]);
			break;
		}
		cells[crd.y][crd.x].setObject(o);
		liveObject[crd] = o;
	}


}

void Ocean::addObject(Object * o, Pair crd)
{
	if (!cells[crd.y][crd.x].getObject())
	{

		cells[crd.y][crd.x].setObject(o);
		if (o != nullptr)
		{
			o->setCell(&cells[crd.y][crd.x]);
			liveObject[crd] = o;
		}
	}
}

void Ocean::updateObject(Object * o, Pair crd)
{
	if (!cells[crd.y][crd.x].getObject())
	{
		cells[crd.y][crd.x].setObject(o);
		if (o != nullptr)
		{
			liveObject[crd] = o;
			o->setCell(&cells[crd.y][crd.x]);
		}
	}
	else
	{
		liveObject.erase(crd);
		cells[crd.y][crd.x].setObject(o);
		if (o != nullptr)
		{
			o->setCell(&cells[crd.y][crd.x]);
			liveObject[crd] = o;
		}
	}
}

void Ocean::removeObj(Object * o)
{
	Pair crd = o->getCell()->getPair();
	liveObject.erase(crd);
	delete o;
	cells[crd.y][crd.x].setObject(nullptr);
}

Object * Ocean::getObject(Pair crd) const
{
	return cells[crd.y][crd.x].getObject();
}

Cell * Ocean::getCell(Pair crd) const
{
	return &cells[crd.y][crd.x];
}


int Ocean::run()
{
	unsigned int end = 0;
	while (1)
	{
		end = isEnd();
		if (end)
			return end;
		std::map<Pair, Object*> tmp = liveObject;
		for (auto obj = tmp.begin(); obj != tmp.end(); obj++)
			if ((liveObject.find((*obj).first)) != liveObject.end() && (liveObject.find((*obj).first))->second == obj->second)
				(*obj).second->live();
		clock_t now = clock();
		while (clock() < now + CLOCKS_PER_SEC/100);
		system("clear");
		print();
	}
}

int Ocean::isEnd() // 1 - нажата Q, 2 - Нет живых объектов, 3 - Остался один вид живых объектов
					// 0 - Всё хорошо
{
	
	if (_kbhit() && toupper(std::cin.get()) == 'Q')
	{	
		//system("cls");
		std::cout << "Good Bye!\n";
		return 1;
	}
	if (liveObject.empty())
	{
		//system("cls");
		std::cout << "The ocean is dead!\n";
		return 2;
	}
	ObjType type = liveObject.begin()->second->getType();
	for (auto obj : liveObject)
		if (obj.second->getType() != type)
			return 0;
			
	//system("cls");
	std::cout << "The ocean has only one kind of living object!\n";
	return 3;
}

Values Ocean::getGlobal()
{
	return global;
}

unsigned int Ocean::getSize()
{
	return liveObject.size();
}

int _kbhit() {
static const int STDIN = 0;
static bool initialized = false;

if (! initialized) {
    // Use termios to turn off line buffering
    termios term;
    tcgetattr(STDIN, &term);
    term.c_lflag &= ~ICANON;
    tcsetattr(STDIN, TCSANOW, &term);
    setbuf(stdin, NULL);
    initialized = true;
}

int bytesWaiting;
ioctl(STDIN, FIONREAD, &bytesWaiting);
return bytesWaiting;
}
