#pragma once
#include <string>

using namespace std;

class Card
{

private:
	string cardDescription;
public:
	Card();
	virtual ~Card();
	virtual void executeAction();
};

