#include "Tile.hpp"

Tile::Tile() {
	name = "";
}
Tile::Tile(string pname, int pos) {
	name = pname;
	position = pos;
}