#include "Ocean.h"
#include "Stone.h"
#include "Coral.h"
#include "Prey.h"
#include "Predator.h"
#include <string>
#include <iostream>
#include <fstream>
#include <ctime>
#include <stdlib.h>

using namespace std;

Ocean::Ocean()
{
	testParam();
	if (getConfigFileIsCorrect() == false)
		return;
	cells = new Cell *[Y_MAX];
	for (size_t i = 0; i < Y_MAX; i++)
	{
		cells[i] = new Cell[X_MAX];
		for (size_t j = 0; j < X_MAX; j++)
		{
			cells[i][j].init(Pair{ j,i }, this);
		}
	}
	config_file_open == true;
	count_step = 0;
}

Ocean::~Ocean()
{
	if(config_file_open == false || correct_config_file == false)
		return;
	for (size_t i = 0; i < Y_MAX; i++)
	{
		for (size_t j = 0; j < X_MAX; j++)
		{

			cells[i][j].killMe();
		}
		delete cells[i];
	}

	delete cells;
}

void Ocean::print() const
{
	if (correct_config_file == false)
		return;
	for (size_t i = 0; i < Y_MAX; i++)
	{
		for (size_t j = 0; j < X_MAX; j++)
		{
			std::cout << (cells[i][j].getObject() ? (cells[i][j].getObject()->getName()) : ' ');
		}
		std::cout << std::endl;
	}
	print_info();
}


// Разные типы объектов
void Ocean::addObject(size_t size_stone, size_t size_coral = 0, size_t size_prey = 0, size_t size_predator = 0)
{
	if (getConfigFileIsCorrect() == false)
		return;
	while (size_stone > 0)
	{
		size_t x = rand() % X_MAX;
		size_t y = rand() % Y_MAX;
		if (cells[y][x].getObject())
			continue;
		else
		{
			Stone *born = new Stone(&cells[y][x], this->cells);
			cells[y][x].setObject(born);
			stuff.push_back(born);
			size_stone--;
		}
	}

	while (size_coral > 0)
	{
		size_t x = rand() % X_MAX;
		size_t y = rand() % Y_MAX;
		if (cells[y][x].getObject())
			continue;
		else
		{
			Coral *born = new Coral(&cells[y][x], this->cells);
			cells[y][x].setObject(born);
			stuff.push_back(born);
			size_coral--;
		}
	}

	while (size_prey > 0)
	{
		size_t x = rand() % X_MAX;
		size_t y = rand() % Y_MAX;
		if (cells[y][x].getObject())
			continue;
		else
		{
			Prey *born = new Prey(&cells[y][x], this->cells);
			cells[y][x].setObject(born);
			stuff.push_back(born);
			size_prey--;
		}
	}

	while (size_predator > 0)
	{
		size_t x = rand() % X_MAX;
		size_t y = rand() % Y_MAX;
		if (cells[y][x].getObject())
			continue;
		else
		{
			Predator *born = new Predator(&cells[y][x], this->cells);
			cells[y][x].setObject(born);
			stuff.push_back(born);
			size_predator--;
		}
	}
}


// Добавляется объект в определенную ячейку
bool Ocean::addObject(Cell * c, Object * ob)
{
	if (getConfigFileIsCorrect() == false)
		return false;
	if (c->getX() >= X_MAX || c->getY() >= Y_MAX)
		return false;
	if (!cells[c->getY()][c->getX()].getObject())
	{
		cells[c->getY()][c->getX()].setObject(ob);
		stuff.push_back(ob);
		return true;
	}
	
	return false;
}

// Переписывает уже имеющийся элемент на другой
bool Ocean::changeObject(Cell * c, Object * ob1, Object * ob2)
{
	if (getConfigFileIsCorrect() == false)
		return false;
	cells[c->getY()][c->getX()].setObject(ob2);
	stuff.erase(find(stuff.begin(), stuff.end(), ob1));   //remove(ob1);
	stuff.push_back(ob2);
	return true;
}

// Заменяет один элемент в океане на другой
bool Ocean::replaseObject(Cell * c, Object * ob)
{
	if (getConfigFileIsCorrect() == false)
		return false;
	if (c->getX() >= X_MAX || c->getY() >= Y_MAX)
		return false;
	if (cells[c->getY()][c->getX()].getObject())
	{
		cells[c->getY()][c->getX()].setObject(ob);
		stuff.push_back(ob);
		return true;
	}
	return false;
}

void Ocean::deleteObject(Cell * c, Object * ob1)
{
	if (getConfigFileIsCorrect() == false)
		return;
	stuff.erase(std::find(stuff.begin(), stuff.end(), ob1));
}

int Ocean::run()
{
	if (getConfigFileIsCorrect() == false)
		return BED_CONFIG_FILE;
	while (1)
	{
		count_step++;
		stuff_buff = stuff;
		for (auto obj : stuff_buff)
		{
			if(obj->getName() == PREDATOR_N)
						obj->live();
		}
		stuff_buff = stuff;
		for (auto obj : stuff_buff)
		{
			if (obj->getName() != PREDATOR_N)
				obj->live();
		}
		clock_t now = clock();
		while (clock() < now + CLOCKS_PER_SEC);
		system("cls");
		print();
		cout << endl;
		if (Object::getCountPrey() == 0 && Object::getCountPredator() == 0)
			return ALL_LIVING_DIE;
		if (Object::getCountPrey() == 0 && Object::getCountPredator() != 0)
			return PREDATOR_WIN;
		if (Object::getCountPrey() != 0 && Object::getCountPredator() == 0)
			return PREY_WIN;
	}
}


void Ocean::print_info() const
{
	if (correct_config_file == false)
		cout << "!!!BED CONFIG FILE!!!" << endl;
	// Выводит число жителе океана
	cout << endl;
	cout << "Size ocean:" << endl;
	cout << "width:   " << X_MAX << endl;
	cout << "length:   " << Y_MAX << endl;
	cout << "size:   " << X_MAX * Y_MAX << endl;
	cout << endl;
	cout << "Object:   " << Object::getCountObject() << endl;
	cout << "Stone:   " << Object::getCountStone() << endl;
	cout << "Coral:   " << Object::getCountCoral() << endl;
	cout << "Prey:   " << Object::getCountPrey() << endl;
	cout << "Predator:   " << Object::getCountPredator() << endl;
	cout << "Ocean step:   " << getCountStep() << endl;
}

bool Ocean::getConfigFileOpen()
{
	return config_file_open;
}


// Возвращяет следующий параметр из файла
size_t Ocean::getNextParam(ifstream * file_config)
{
	string line;
	getline(*file_config, line);
	size_t param = atoi(line.c_str());
	return param;
}

// Инициация океана из файла
Ocean::Ocean(char *Config_file)
{
	ifstream file_config;
	file_config.open(Config_file, ios_base::in);
	if (!file_config.is_open())
	{
		config_file_open = false;
		return;
	}
	else
		config_file_open = true;

	// Считываем параметры
	// Формат такой
	// Y_MAX
	Y_MAX = getNextParam(&file_config);
	// X_MAX
	X_MAX = getNextParam(&file_config);
	// STONE_SIZE
	STONE_SIZE = getNextParam(&file_config);
	// CORAL_SIZE
	CORAL_SIZE = getNextParam(&file_config);
	// PREY_SIZE
	PREY_SIZE = getNextParam(&file_config);
	// PREDATOR_SIZE
	PREDATOR_SIZE = getNextParam(&file_config);
	// CORAL_REPRODUCTION_TIME
	CORAL_REPRODUCTION_TIME = getNextParam(&file_config);
	// PREY_LIVING_TIME
	PREY_LIVING_TIME = getNextParam(&file_config);
	// PREY_REPRODUCTION
	PREY_REPRODUCTION = getNextParam(&file_config);
	// PREDATOR_LIVING_TIME
	PREDATOR_LIVING_TIME = getNextParam(&file_config);
	// PREDATOR_REPRODUCTION
	PREDATOR_REPRODUCTION = getNextParam(&file_config);

	file_config.close();

	testParam();
	if (getConfigFileIsCorrect() == false)
		return;

	cells = new Cell *[Y_MAX];
	for (size_t i = 0; i < Y_MAX; i++)
	{
		cells[i] = new Cell[X_MAX];
		for (size_t j = 0; j < X_MAX; j++)
		{
			cells[i][j].init(Pair{ j,i }, this);
		}
	}
	count_step = 0;
}

size_t Ocean::getCountStep() const
{
	return count_step;
}

bool Ocean::getConfigFileIsCorrect()
{
	return correct_config_file;
}


// Проверка параметров на корректность
bool  Ocean::testParam()
{
	if ((STONE_SIZE + CORAL_SIZE + PREY_SIZE + PREDATOR_SIZE) > Y_MAX * X_MAX)
	{
		correct_config_file = false;
		return false;
	}
	
	else if(Y_MAX == 0 || X_MAX == 0)
		return correct_config_file = false;

	return correct_config_file = true;
}