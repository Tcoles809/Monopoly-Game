#include "Player.hpp"

Player::Player(string inToken) {
	token = inToken;
	position = 0;
	money = 1500;

}
Player::~Player() {
}
void Player::addProperty(Tile propertyTile) {
	owned_property.push_back(propertyTile);
}



/////////////////////////////////////////////////////////////
//this is bad mkay
Tile Player::getProperty(string name) {
	for (int index = 0; index < owned_property.size(); index++) {
		if (owned_property[index].getName() == name) {
			return owned_property[index];
		}
	}
	return owned_property[0];//array out of bounds possibility
}
/////////////////////////////////////////////////////////////////

int Player::getPosition() {
	return position;
}
void Player::setPosition(int pos) {
	position = pos;
}

int Player::move(int steps)
{
	position += steps;
	position %= boardsize;
	return position;
}
