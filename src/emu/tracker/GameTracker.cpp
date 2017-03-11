#include "emu.h"
#include "GameTracker.h"
#include <fstream>
#include <string>
#include <sstream>

void GameTracker::setStat(std::string name, uint32_t value)
{
	stats[name] = value;
}

uint32_t GameTracker::getStat(std::string name)
{
	return stats[name];
}

void GameTracker::clearStat(std::string name)
{
	if(stats.count(name))
	{
		stats.erase(name);
	}
}

void GameTracker::clearStats()
{
	stats.clear();
}

void GameTracker::setMemoryBase(uint8_t *base)
{
	memory = base;
}

uint8_t GameTracker::readMemory(uint16_t address)
{
	return memory[address];
}

void GameTracker::writeMemory(uint16_t address, uint8_t value)
{
	memory[address] = value;
}

void GameTracker::buildJSON()
{
	std::map<std::string, uint32_t>::iterator i;
	std::map<std::string, uint32_t>::iterator last = stats.end();
	--last;
	// Reset our JSON string.
	json.str("");
	
	json << "{\n";
		for(i = stats.begin(); i != stats.end(); i++)
		{
			if(i != last)
			{
				json << '"' << i->first << '"' << " : " << i->second << ',' << "\n";				
			}
			else
			{
				json << '"' << i->first << '"' << " : " << i->second << "\n";			
			}
		}
	json << "}\n";
}

void GameTracker::writeFile(std::string name)
{
	std::ofstream file;
	file.open(name.c_str());
	file << json.str().c_str();
	file.close();
}