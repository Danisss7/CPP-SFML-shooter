#pragma once

struct Player;
struct Plate;

namespace nmUtils
{
	bool IsBetween(float val, float rangeB, float rangeE);
	bool InOnPlate(Player &player, Plate &plate);
}
