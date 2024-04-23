#pragma once
#include "Tile.hpp"
#include "../Card/Card.hpp"

class ActionTile : public Tile
{
	Card drawnCard;
public:
	string description;
	ActionTile(string name, int pos) : Tile(name, pos) {};
	~ActionTile() {};
};
