#include <iostream>
#include <sstream>
#include <map>
#include <fstream>
#include "../emu/emumem.h"

class GameTracker
{
	public:
		std::map<std::string, uint32_t> stats;
		unsigned char *memory;
		std::stringstream json;
		void clearStats();
		uint8_t readMemory(uint16_t address);
		void setMemoryBase(unsigned char *base);
};