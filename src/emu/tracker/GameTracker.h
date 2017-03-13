#include <iostream>
#include <sstream>
#include <map>
#include <fstream>
#include "../emu/emumem.h"

class GameTracker
{
	public:
		std::map<std::string, uint32_t> stats;
		uint8_t *memory;
		std::stringstream json;
		std::string _filename = "game.js";

		void setStat(std::string name, uint32_t value);
		uint32_t getStat(std::string name);
		void clearStat(std::string name);
		void clearStats();
		void setMemoryBase(uint8_t *base);
		uint8_t readMemory(uint16_t address);
		void writeMemory(uint16_t address, uint8_t value);
		void buildJSON();
		void registerJSONfile(std::string filename);
		void writeFile();
};