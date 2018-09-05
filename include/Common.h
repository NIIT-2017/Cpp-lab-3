#pragma once

// Для хранения констант

typedef size_t coord_t;

// Структура для хранения координат
struct Pair
{
	coord_t x;	
	coord_t y; 
};

// Коды завершения основного цикла программы Ocean.run()
enum run_end
{
	ALL_LIVING_DIE = 1,
	PREY_WIN,
	PREDATOR_WIN,
	BED_CONFIG_FILE
} ;


extern size_t STONE_SIZE;
extern size_t CORAL_SIZE;
extern size_t PREY_SIZE;
extern size_t PREDATOR_SIZE;

// Размер океана
extern size_t Y_MAX;	// y
extern size_t X_MAX;	// x

					// Количество циклов жизни камня
extern size_t STONE_LIVE_TIME;

// Время размножения корралов
extern size_t CORAL_REPRODUCTION_TIME;

// Время жизни рыбы
extern size_t PREY_LIVING_TIME;

// Время размножения рыбы
extern size_t PREY_REPRODUCTION;

// Время жизни хищникрв
extern size_t PREDATOR_LIVING_TIME;

// Время размножения хищников
extern size_t PREDATOR_REPRODUCTION;