#pragma once
#ifndef Session_H
#define Session_H
#include "../Sessions/ISession.h"
#include <string>
#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;
#pragma once
class Session : public ISession
{
private:
	string date;
	string SessionID;
	double TimeTaken;
	string GameTheme;
	vector<Player> players;

	void gameController();
	int rollDice();//rolls 2 die, returns number 2-12
	string getTokenOption(vector<string>& tokenOptions);

public:
	Board* GameBoard;
	User SessionUser;
	bool authenticated = false;

	Session();
	~Session();

	void initiatePlayers(int num_players);
	void setTheme(string theme);
	void StartSession();
};

#endif
