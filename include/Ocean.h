#pragma once

#include "Cell.h"
#include "Common.h"
#include <list>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class Ocean
{
private:
	Cell **cells;
	std::list<Object *> stuff;
	std::list<Object *> stuff_buff;
	bool config_file_open;
	bool correct_config_file;
	size_t getNextParam(ifstream * file_config);
	size_t count_step;

public:
	Ocean();
	Ocean(char *Config_file);
	~Ocean();
	void print() const;
	void print_info() const;
	bool addObject(Cell * c, Object * ob);
	void addObject(size_t, size_t, size_t, size_t);
	bool changeObject(Cell * c, Object * ob1, Object * ob2);
	bool replaseObject(Cell * c, Object * ob);
	// Удаление объекта
	void deleteObject(Cell * c, Object * ob1);
	int run();
	bool getConfigFileOpen();
	bool getConfigFileIsCorrect();
	bool testParam();
	size_t getCountStep() const;
};