#include "emu.h"
#include "GameTracker.h"
#include <fstream>
#include <string>
#include <sstream>

void GameTracker::clearStats()
{
	//	stats.clear();
	return;
}

uint8_t GameTracker::readMemory(uint16_t address)
{
	return memory[address];
}

void GameTracker::setMemoryBase(uint8_t *base)
{
	memory = base;
}