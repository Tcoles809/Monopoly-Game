#pragma once

#include "../Board/Card/Card.hpp"
#include "../Board/Tile/Tile.hpp"
#include <string>
#include <vector>
#include <iostream>


using namespace std;

class Player
{

private:
	int position;
	vector<Tile> owned_property;
	vector<Card> owned_cards;
	double money;
	string token;
	int boardsize;

public:
	Player(string inToken);
	virtual ~Player();

	virtual void addProperty(Tile propertyTile);
	virtual Tile getProperty(string name);
	virtual int getPosition();
	virtual void setPosition(int pos);
	void setBoardSize(int s) { boardsize = s; }
	int move(int);
	string getToken() { return token; }
};

