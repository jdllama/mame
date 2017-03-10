#include <iostream>
#include <sstream>
#include <map>
#include <fstream>
#include "../emu/emumem.h"

class GameTracker
{
	public:
		std::map<std::string, uint32_t> stats;
		void clearStats();
};