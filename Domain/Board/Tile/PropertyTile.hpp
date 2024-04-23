#include "Tile.hpp"

class PropertyTile : public Tile
{
private:
	double price;
	bool owned;
public:
	PropertyTile() : Tile() { owned = false; price = 0; };
	PropertyTile(string name, int pos) : Tile(name, pos) { owned = false; price = 0; };
	~PropertyTile() {};

	void setOwnership(bool newStatus) { owned = newStatus; };
	double sellProperty() { setOwnership(false); return price; };
	void setPrice(float priceValue) { price = priceValue; };
};
