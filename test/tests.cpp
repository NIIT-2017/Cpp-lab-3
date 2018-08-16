#include "gtest/gtest.h"

#include "Cell.h"
#include "common.h"
#include "Coral.h"
#include "Object.h"
#include "Ocean.h"
#include "Predator.h"
#include "Prey.h"
#include "Stone.h"

#include <unistd.h>
#include <iostream>
#include <fstream>

TEST(lab3, ocean_1)
{
	std::ofstream out("out.txt");
	std::streambuf *coutbuf = std::cout.rdbuf();
	std::cout.rdbuf(out.rdbuf());

	Ocean *ocean = new Ocean("config.json");
	ocean->run();
	delete ocean;
	out.close();

	std::ifstream in("out.txt");
	int size = 0;
    in.seekg(0, std::ios::end);
    size = in.tellg();
	std::cout.rdbuf(coutbuf);
	in.close();
	EXPECT_EQ(1020, size);

	in.open("out.txt");
	bool flag = false;
	int nPredator = 0;
	std::string buff;
	while (std::getline(in, buff))
	{
		for(size_t i = 0; i < buff.size(); i++)
		{
			if (buff[i] != '.' && buff[i] != '\n' && buff[i] != 's')
			{
				flag = true;
				break;
			}
			if (buff[i] == 's') nPredator++;
		}
	}
	EXPECT_FALSE(flag);
	EXPECT_EQ(100, nPredator);
}

TEST(lab3, ocean_2)
{
	std::ofstream out("out2.txt");
	std::streambuf *coutbuf = std::cout.rdbuf();
	std::cout.rdbuf(out.rdbuf());

	Ocean *ocean = new Ocean("config2.json");
	ocean->run();
	delete ocean;
	out.close();

	std::ifstream in("out2.txt");
	int size = 0;
    in.seekg(0, std::ios::end);
    size = in.tellg();
	std::cout.rdbuf(coutbuf);

	in.close();
	EXPECT_EQ(1020, size);

	in.open("out2.txt");
	bool flag = false;
	int nStone = 0;
	int nCoral = 0;
	std::string buff;
	while (std::getline(in, buff))
	{
		for(size_t i = 0; i < buff.size(); i++)
		{
			if (buff[i] != '.' && buff[i] != '\n' && buff[i] != '#' && buff[i] != '*')
			{
				flag = true;
				break;
			}
			if (buff[i] == '#') nStone++;
			if (buff[i] == '*') nCoral++;
		}
	}
	EXPECT_FALSE(flag);
	EXPECT_EQ(50, nStone);
	EXPECT_EQ(50, nCoral);
}

TEST(lab3, ocean_3)
{
	std::ofstream out("out3.txt");
	std::streambuf *coutbuf = std::cout.rdbuf();
	std::cout.rdbuf(out.rdbuf());

	Ocean *ocean = new Ocean("config3.json");
	ocean->run();
	delete ocean;
	out.close();

	std::cout.rdbuf(coutbuf);

	std::ifstream in("out3.txt");
	int size = 0;
    in.seekg(0, std::ios::end);
    size = in.tellg();

	in.close();
	EXPECT_EQ(8160, size);

	in.open("out3.txt");
	int n = 0;
 	std::string buff;
	while (std::getline(in, buff))
	{                               
		std::cout << buff << std::endl;
		n++;
		if (n % 20 == 0) std::cout << std::endl;
	}
	in.close();

	in.open("out3.txt");
	bool flag = false;
	int nStone = 0;
	n = 0;
	while (std::getline(in, buff))
	{
		n++;
		if (n < 141) continue;
		for(size_t i = 0; i < buff.size(); i++)
		{
			if (buff[i] != '.' && buff[i] != '\n' && buff[i] != '#')
			{
				flag = true;
				break;
			}
			if (buff[i] == '#') nStone++;
		}
	}
	EXPECT_FALSE(flag);
	EXPECT_EQ(100, nStone);
}