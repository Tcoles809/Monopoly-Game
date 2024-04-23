#pragma once
#ifndef BOARD_H
#define BOARD_H
#include "Card/Card.hpp"
#include "Tile/Tile.hpp"
#include "Tile/ActionTile.hpp"
#include "Tile/PropertyTile.hpp"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <msxml.h>


using namespace std;

class Board
{

private:
	int number_of_tiles;
	vector<bool> hasActionTile;//matches size of the board, true where there is an actions tile, false where there is a property tile
	void setActionTiles();
	vector<Tile> board_tiles;
	vector<Card> board_cards;
	vector<string> tokens;

public:
	Board();

	void startGame(string theme);
	virtual void initiateBoard(string theme);
	vector<ActionTile> generateActionTiles();
	vector<string> getTokens();//make sure to return a copy, we will be destroying
	int size() { return number_of_tiles; }
	Tile getTileAt(int pos);
	bool isActionTile(int pos);
};

#endif
