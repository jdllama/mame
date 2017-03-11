#include "emu.h"
#include "GameTracker.h"
#include <fstream>
#include <string>
#include <sstream>

void GameTracker::clearStats()
{
}

uint8_t GameTracker::readMemory(uint16_t address)
{
	return memory[address];
}

void GameTracker::setMemoryBase(unsigned char *base)
{
	memory = base;
}