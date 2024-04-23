#include "Board.hpp"

void Board::setActionTiles()
{
	hasActionTile[0] = true;//go
	hasActionTile[2] = true;//com chest
	hasActionTile[4] = true;//income tax
	hasActionTile[7] = true;//chance
	hasActionTile[10] = true;//jail
	hasActionTile[17] = true;//comm chest
	hasActionTile[20] = true;//free
	hasActionTile[22] = true;//chance
	hasActionTile[30] = true;//jail
	hasActionTile[33] = true;//c chest
	hasActionTile[36] = true;//chance
	hasActionTile[38] = true;//lux tax
}

Board::Board()
{
	number_of_tiles = 40;
	hasActionTile.resize(40);
	for (int i = 0; i < hasActionTile.size(); i++)
		hasActionTile[i] = false;
	setActionTiles();

}

void Board::startGame(string theme) {
	initiateBoard(theme);

}

void Board::initiateBoard(string theme) {
	string theme_prop_path = "../../TechServices/Persistence/ThemeList/" + theme + ".txt";
	fstream f;
	f.open(theme_prop_path);
	string line;

	vector<PropertyTile> property_tiles;
	while (!f.eof())
	{
		getline(f, line);
		if (line == "Themename:")
		{
			getline(f, line);
		}
		else if (line == "Token:")
		{
			for (int i = 0; i < 4; ++i)
			{
				string token;
				getline(f, token);
				tokens.push_back(token);
			}
		}
		else if (line == "Property:")
		{
			for (int i = 0; i < 28; ++i)
			{
				string property_name;
				getline(f, property_name);
				property_tiles.push_back(PropertyTile(property_name, -1));
			}
		}
		else if (line == "Price:")
		{
			for (int i = 0; i < 28; ++i)
			{
				string price;
				getline(f, price);
				property_tiles[i].setPrice(stof(price));
			}
		}
	}//end file processing
	//assuming tokens, and property tiles are set properly

	//build board from action and property tiles
	board_tiles.resize(number_of_tiles);

	//generate action tiles
	vector<ActionTile> action_tiles = generateActionTiles();


	//put the actions tiles in their proper locations
	for (int i = 0; i < board_tiles.size(); i++)
	{
		if (hasActionTile[i] == true)
		{
			board_tiles[i] = action_tiles.front();
			action_tiles.erase(action_tiles.begin());
		}
		else
		{
			board_tiles[i] = property_tiles.front();
			property_tiles.erase(property_tiles.begin());
		}
	}

	//set the tile positions
	for (int i = 0; i < board_tiles.size(); i++)
		board_tiles[i].setPosition(i);
}

vector<ActionTile> Board::generateActionTiles()
{
	vector<ActionTile> action_tiles;

	action_tiles.push_back(ActionTile("Go", 0));
	action_tiles.push_back(ActionTile("Community Chest", 2));
	action_tiles.push_back(ActionTile("Income Tax", 4));
	action_tiles.push_back(ActionTile("Chance", 7));
	action_tiles.push_back(ActionTile("Jail", 10));
	action_tiles.push_back(ActionTile("Community Chest", 17));
	action_tiles.push_back(ActionTile("Free Parking", 20));
	action_tiles.push_back(ActionTile("Chance", 22));
	action_tiles.push_back(ActionTile("Go to Jail", 30));
	action_tiles.push_back(ActionTile("Community Chest", 33));
	action_tiles.push_back(ActionTile("Chance", 36));
	action_tiles.push_back(ActionTile("Luxury Tax", 38));

	return action_tiles;
}

vector<string> Board::getTokens()
{
	vector<string> tokensTemp;

	for (auto i : tokens)
		tokensTemp.push_back(i);

	return tokensTemp;
}

Tile Board::getTileAt(int pos)
{
	return board_tiles[pos];
}

bool Board::isActionTile(int pos)
{
	return hasActionTile[pos];
}




