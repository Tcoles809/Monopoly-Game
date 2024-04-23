#pragma once
#include "../../Domain/Test/Test.hpp"
#include "../../Domain/Test/MemTest.hpp"
#include "../../Domain/Test/FreeTest.hpp"
#include "../../Domain/User/User.hpp"
#include "../Board/Board.hpp"
#include "Player.hpp"
#include <string>
#include <iostream>

using namespace std;
#pragma once
class ISession
{
private:
	string date;
	string SessionID;
	double TimeTaken;
	string GameTheme;
	vector<Player> players;

public:
	Board GameBoard;
	User SessionUser;
	bool authenticated = false;

	virtual void initiatePlayers(int num_players) = 0;
	virtual void setTheme(string theme) = 0;
	virtual void StartSession() = 0;

};
