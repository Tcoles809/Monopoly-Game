#pragma once
#include <string>

using namespace std;

class Tile
{

private:
	string name;
	int position;

public:
	Tile();
	Tile(string pname, int pos);
	string getName() { return name; };
	void setPosition(int pos) { position = pos; }
	int getPosition() { return position; };
};

