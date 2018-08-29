#include <iostream>
#include "Ocean.h"
#include <cstdlib>
#include <time.h>
#include <termios.h>
#include <unistd.h>
#include <fstream>


//Объявляем глобальную переменную (которая в common.h external)
rapidjson::Document g_data;

//парсим файл конфига .jsonS
//и данные передаем в глобальную переменную g_data
//из которой все классы получат свои данные
Ocean::Ocean(const char *fileName)
{
	std::ifstream ifs(fileName);
	rapidjson::IStreamWrapper isw(ifs);
	g_data.ParseStream(isw);
	ifs.close();

	size_x = g_data["Ocean"]["size_x"].GetInt();
	size_y = g_data["Ocean"]["size_y"].GetInt();
	
	srand(time(nullptr));
	maxCount = size_x * size_y;
	this->count = 0;

	cells = new Cell*[size_y];
	for (size_t i = 0; i < size_y; i++)
	{
		cells[i] = new Cell[size_x];
		for (size_t j = 0; j < size_x; j++)
			cells[i][j].init(Pair{ j, i }, this);
	}

	int count = g_data["Ocean"]["count"].GetInt();
	int cStone = g_data["Ocean"]["countStone"].GetInt();
	int cCoral = g_data["Ocean"]["countCoral"].GetInt();
	int cPrey = g_data["Ocean"]["countPrey"].GetInt();
	int cPredator = g_data["Ocean"]["countPredator"].GetInt();
	addObjects(count);
	addObjects(cStone, ObjType::STONE);
	addObjects(cCoral, ObjType::CORAL);
	addObjects(cPrey, ObjType::PREY);
	addObjects(cPredator, ObjType::PREDATOR);
}

Ocean::~Ocean()
{
	for (size_t i = 0; i < size_y; i++)
		delete[] cells[i];
	delete[] cells;
	for (auto item = stuff.begin(); item != stuff.end(); ++item)
		delete *item;
}

//распечатать океан
void Ocean::print() const
{
	for (size_t i = 0; i < size_y; i++)
	{
		for (size_t j = 0; j < size_x; j++)
			std::cout << 
				(cells[i][j].getObject() ? 
				 (char) cells[i][j].getObject()->getName() : '.');
		std::cout << std::endl;
	}
}

//выдать функцию рождения по типу объекта
//лямбда функции наше все:))
Object* (*Ocean::getObjType(ObjType objType)) (Cell *)
{
	Object* (*obj) (Cell *);
	switch (objType)
	{
		case ObjType::STONE :
			obj = [](Cell *cell) -> Object*
			{ return new Stone(cell); };
			break;
		case ObjType::CORAL :
			obj = [](Cell *cell) -> Object*
			{ return new Coral(cell); };
			break;
		case ObjType::PREY :
			obj = [](Cell *cell) -> Object*
			{ return new Prey(cell); };
			break;
		case ObjType::PREDATOR :
			obj = [](Cell *cell) -> Object*
			{ return new Predator(cell); };
			break;		
	}
	return obj;
}

//создать объект по координате и функции рождения
void Ocean::addObject(Pair crd, Object* (*obj) (Cell *))
{
	if (crd.x < size_x && crd.y < size_y)
	{
		Object *born = obj(&cells[crd.y][crd.x]);
		cells[crd.y][crd.x].setObject(born);
		stuff.insert(born);
		this->count++;
	}
}

//создать объекты по количеству (случайная координата)
void Ocean::addObjects(int count)
{
	unsigned int n[4]{ 0, 0, 0, 0 };
	while (count > 0 && this->count < maxCount)
	{
		unsigned char x = rand() % 4;
		n[x]++;
		count--;
	}
	addObjects(n[0], ObjType::STONE);
	addObjects(n[1], ObjType::CORAL);
	addObjects(n[2], ObjType::PREY);
	addObjects(n[3], ObjType::PREDATOR);
}

//создать объекты по количеству и типу (случайная координата)
void Ocean::addObjects(int count, ObjType objType)
{
	Object* (*obj) (Cell *);
	obj = getObjType(objType);

	while (count > 0 && this->count < maxCount)
	{
		size_t x = rand() % size_x;
		size_t y = rand() % size_y;
		if (cells[y][x].getObject())
			continue;
		else
		{
			addObject(Pair{x,y}, obj);
			count--;
		}	
	}
}

//создать объект по координате и типу объекта
void Ocean::addObjects(Pair crd, ObjType objType)
{
	Object* (*obj) (Cell *);
	obj = getObjType(objType);
	addObject(crd, obj);
}

//уничтожить объект
void Ocean::delObject(Object *obj)
{
	stuff.erase(obj);
	count--;
}

//добавить объект в список умерших
void Ocean::setDelObject(Object *obj)
{
	stuffDie.insert(obj);
}

//добавить план в очередь рождения
void Ocean::setBornObject(Cell *cell, ObjType objType)
{
	stuffBorn.insert(std::pair<Cell*, ObjType>(cell, objType));
}

//выдать случайную соседнюю ячейку, включая ее саму
Cell* Ocean::getCell(Pair crd)
{
	coord_t x = crd.x + rand() % 3 - 1;
	coord_t y = crd.y + rand() % 3 - 1;
	if (x >= size_x || y >= size_y)
		return &cells[crd.y][crd.x];
	else
		return &cells[y][x];
}

//жизнь океана
void Ocean::run()
{
	while (1)
	{
		system("clear");
		print();

		//проверка на окончание эмуляции
		if (isEnd()) 
		{
			return;
		}

		//задержка скорости эмуляции
		clock_t now = clock();
		while (clock() < now + CLOCKS_PER_SEC / 100);

		//каждый объект живет
		for (auto obj : stuff)
		{
			if (obj != nullptr && obj->isLive())
			{
				obj->live();

				//объект отходился
				obj->setLive(false);
			}
		}

		//уничтожаем все что должно быть уничтожено
		while (!stuffDie.empty())
		{
			std::set<Object *>::iterator it = stuffDie.begin();
			Object *o = *it;
			stuffDie.erase(o);
			o->kill();
		}

		//создаем все что должно быть рождено
		while (!stuffBorn.empty())
		{
			std::map<Cell *, ObjType>::iterator it = stuffBorn.begin();
			Cell *c = it->first;
			ObjType o = it->second;
			stuffBorn.erase(it);
			c->bornObject(o);
		}

		//все существующие объекты готовы к жизни
		for (auto obj : stuff)
			obj->setLive(true);
	}
	
}

//проверка условий окончания эмуляции океана
//1. только один тип объектов
//2. вся живность, кроме кораллов вымерла
//3. нажата клавиша 'ESC'
bool Ocean::isEnd()
{
	unsigned int n[4]{ 0, 0, 0, 0 };
	for (auto obj : stuff)
	{
		switch (obj->getType())
		{
			case ObjType::STONE :
				n[0]++;
				break;
			case ObjType::CORAL :
				n[1]++;
				break;
			case ObjType::PREY :
				n[2]++;
				break;
			case ObjType::PREDATOR :
				n[3]++;
				break;		
		}
	}

	for (auto i : n)
		if (i == count) return true;
	if (n[2] == 0 && n[3] == 0) return true;

	termios oldt, newt;
	int ch;
	tcgetattr( STDIN_FILENO, &oldt );
	newt = oldt;
	newt.c_lflag &= ~( ICANON | ECHO );
	newt.c_cc[VTIME] = 0;
    newt.c_cc[VMIN] = 0;
	tcsetattr( STDIN_FILENO, TCSANOW, &newt );
	ch = getchar();
	tcsetattr( STDIN_FILENO, TCSANOW, &oldt );
	if (ch == 27) return true;

	return false;
}
