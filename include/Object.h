#pragma once

#define STONE_N '#'
#define CORAL_N '*'
#define PREY_N 'F'
#define PREDATOR_N 'S'

class Cell;

class Object
{
private:
	static unsigned int count_object;
	static unsigned int count_stone;
	static unsigned int count_coral;
	static unsigned int count_prey;
	static unsigned int count_predactor;
	char  name;
public:
	Cell * cell;	
	// Массив ячеек океана
	Cell **cells;
	bool must_die;
	Object(Cell * c, Cell **cells, char n);
	virtual ~Object();
	void setCell(Cell *);
	virtual void live() = 0; //Жизнь объекта
	char getName();
	void set_must_die();
	bool get_must_die();
	static unsigned int getCountObject();
	static unsigned int getCountStone();
	static unsigned int getCountCoral();
	static unsigned int getCountPrey();
	static unsigned int getCountPredator();
};
