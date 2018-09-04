#include "Ocean.h"
#include "Stone.h"
#include "Coral.h"
#include "Predator.h"
#include "Prey.h"
#include "common.h"
#include "Object.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
Ocean::Ocean()
{
	Setting setting;
	string Rows = "Rows";
	string Columns = "Columns";
	int Row = setting.getFromFile(Rows);
	int Column = setting.getFromFile(Columns);
	cells = new Cell*[Row];
	for (size_t i = 0; i < Row; i++)
	{
		cells[i] = new Cell[Column];
		for (size_t j = 0; j < Column; j++)
			cells[i][j].init(Pair{ j, i }, this);
	}
}

Ocean::~Ocean()
{
	Setting setting;
	string Rows = "Rows";
	string Columns = "Columns";
	size_t Row = setting.getFromFile(Rows);
	size_t Column = setting.getFromFile(Columns);

	for (size_t i = 0; i < Row; i++)
		delete[] cells[i];
	delete[] cells;
	for (auto item = stuff.begin(); item != stuff.end(); ++item)
		delete *item;
}

void Ocean::print() const
{
Setting setting;
	string Rows = "Rows";
	string Columns = "Columns";
	size_t Row = setting.getFromFile(Rows);
	size_t Column = setting.getFromFile(Columns);


	system("cls");
	for (size_t i = 0; i < Row; i++)
	{
		for (size_t j = 0; j < Column; j++)
			cout <<
			(cells[i][j].getObject() ?
				cells[i][j].getObject()->getName() : '.');

		cout <<endl;
	}
}
void Ocean::addObjects(size_t stone_count, size_t coral_count, size_t prey_count, size_t predator_count)
{
	add(stone_count, STONE);
	add(coral_count, CORAL);
	add(prey_count, PREY);
	add(predator_count, PREDATOR);	
}
Cell * Ocean::getCells(const int x, const int y)
{
	Cell* cell = &(cells[y][x]);
	return cell;
}
void Ocean::DeleteObject(Object * obj)
{
	auto i = find(begin(stuff), end(stuff), obj);
	stuff.erase(i);
}
void Ocean::add(size_t count, int type)
{
	while (count)
	{
		Setting setting;
		std::string NumRows = "NumRows";
		std::string NumColumns = "NumColumns";
		size_t Row = setting.getFromFile(NumRows);
		size_t Columns = setting.getFromFile(NumColumns);
		size_t x = rand() % Columns;
		size_t y = rand() % Row;
		if (cells[y][x].getObject())
			continue;
		else
		{
			Object *born;
			switch (type) {
			case 0:
			{
				born = new Stone(&cells[y][x]);
			}
			break;
			case 1:
			{
				born = new Coral(&cells[y][x]);
			}
			break;
			case 2:
			{
				born = new Prey(&cells[y][x]);
			}
			break;
			case 3:
			{ born = new Predator(&cells[y][x]); }
			break;
			default:
				break;
			}
			cells[y][x].setObject(born);
			stuff.push_back(born);
			count--;
		}
	}
}
void Ocean::addObject(Object * obj)
{
	this->stuff.push_back(obj);
}
void Ocean::run()
{
	print();
	int iteracia_num = 0;
	int end;
	bool flag = true;
	cout << "iteration number now = " << iteracia_num << endl;
	unsigned int countRun = this->isEnd();
	if ((countRun == -1) || (countRun == -2)) {
		countRun = 1;
		flag = false;
	}
	while (flag)
	{
		while (countRun)
		{
			iteracia_num++;
			end = stuff.size();
			for (int i = 0; i < end; i++) {
				stuff[i]->live();
				end = stuff.size();
			}
			print();
			cout << "iteration number now = " << iteracia_num << endl;
			countRun--;
			if (this->NoMoreLiveObject())
			{
				countRun = 0;
				flag = false;
			}
		}
		if (flag)  countRun = this->isEnd();
		if ((countRun == -1) || (countRun == -2)) {
			countRun = 1;
			flag = false;
		}
	}
	cout << "end program in iteration number = " << iteracia_num << endl;
}
int Ocean::RunForTest()
{
	print();
	int iteracia_num = 0;
	int end;
	bool flag = true;
	
	cout << "iteration number now = " << iteracia_num << std::endl;
	unsigned int countRun = 1000;
	while (flag)
	{
		while (countRun)
		{
			iteracia_num++;
			end = stuff.size();
			for (int i = 0; i < end; i++) {
				stuff[i]->live();
				end = stuff.size();
			}
			print();
			cout << "iteration number now = " << iteracia_num << endl;
			countRun--;
			if (this->NoMoreLiveObject())
			{
				countRun = 0;
				flag = false;
			}
		}
		if (flag)  countRun = this->isEnd();
		if ((countRun == -1) || (countRun == -2)) {
			countRun = 1;
			flag = false;
		}
	}
	std::cout << "end program in iteration number = " << iteracia_num << std::endl;
	return  100;
}

unsigned int Ocean::isEnd()
{
    std::cout << "Press key Q to Exit"<< std::endl;
    std::cout << "Press number of iterator(+) [1-9]  "<< std::endl;
    cout << "Press Any key to next step"<< endl;
    unsigned int result = -1;
    char num;
    cin.clear();
    num = std::cin.get();
    if (std::cin.peek() != '\n'){
        num = std::cin.get();   
    }
    if (toupper(num) == 'Q')
    {
        std::cout << "End by command from user"<< std::endl;
        return (result = -1);
    }
    if  ((num <='9') && (num >='1'))
    {
        return (result = static_cast<int>(num) - 48);
    }
     if (this->NoMoreLiveObject())
    {
        return (result = -2);
    }
    result = 1;
    return result;
}

bool Ocean::NoMoreLiveObject()
{
    bool result = false;
    size_t Stonecount=0;
    size_t Coralcount=0;
    size_t Preycount=0;
    size_t Predatorcount=0;
    size_t size = stuff.size();
    for (int i=0; i < size ;i++)
    {
        char name = stuff[i]->getName();
        switch (name)
        {
        case STONE_N:
        {
            Stonecount++;
        }
            break;
        case CORAL_N:
        {
            Coralcount++;
        }
            break;
        case PREY_N:
        {
            Preycount++;
        }
            break;
        case PREDATOR_N:
        {
            Predatorcount++;
        }
            break;
        default:
            break;
        }
    }
    if (((Stonecount==size)||(Coralcount==size)) || ((Coralcount + Stonecount)==size))
{
        std::cout << "End becose No More 1LiveOdject"<< std::endl;
        result = true;
        return result;
    }
    else if ((Preycount == 0)  || (Predatorcount==0))
    {
        std::cout << "End becose Somebody Object is dead"<< std::endl;
        result = true;
        return result;
    }
    return result;
}
