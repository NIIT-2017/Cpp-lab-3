#include "common.h"
#include <cstring>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;
Setting::Setting()
{}
size_t Setting::getFromFile(string &txt)
{
	string line;
	string needtext;
	size_t  result;
	ifstream file("Setting.txt");
	bool flag = true;
	if (file.is_open())
	{
		while (!(file.eof()) && (flag == true))
		{
			getline(file, line);
			int fnd = line.find(txt);
			while ((fnd>0) && (flag == true))
			{
				int first = line.find('=');
				int last = line.find(';');

				needtext = line.substr(first + 2, last - first - 2);
				flag = false;
			}
		}
		stringstream sstream(needtext);
		sstream >> result;
	}
	file.close();
	return result;
}