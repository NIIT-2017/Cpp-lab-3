#pragma once

// ��� �������� ��������

typedef size_t coord_t;

// ��������� ��� �������� ���������
struct Pair
{
	coord_t x;	
	coord_t y; 
};

// ���� ���������� ��������� ����� ��������� Ocean.run()
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

// ������ ������
extern size_t Y_MAX;	// y
extern size_t X_MAX;	// x

					// ���������� ������ ����� �����
extern size_t STONE_LIVE_TIME;

// ����� ����������� ��������
extern size_t CORAL_REPRODUCTION_TIME;

// ����� ����� ����
extern size_t PREY_LIVING_TIME;

// ����� ����������� ����
extern size_t PREY_REPRODUCTION;

// ����� ����� ��������
extern size_t PREDATOR_LIVING_TIME;

// ����� ����������� ��������
extern size_t PREDATOR_REPRODUCTION;