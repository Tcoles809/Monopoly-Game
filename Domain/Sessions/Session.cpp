#include "Session.hpp"

Session::Session()
{
	authenticated = false;
	SessionUser = User();
	date = "";
	SessionID = "";
	GameBoard = NULL;
	GameTheme = "Default";
	srand(time(NULL));
}

Session::~Session()
{
	delete GameBoard;
}

void Session::StartSession() {

	GameBoard = new Board();

	GameBoard->initiateBoard(GameTheme);

	//cout << "running\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	cout << "Welcome to Monopoly! \n";
	cout << "Current Theme: "<< GameTheme <<endl;
	cout << "How many players are there? (2-4) \n";

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	int num_players;
	cin >> num_players;
	initiatePlayers(num_players);
	system("CLS");

	
	
	//the actual game
	gameController();
	
	//updateProgress(SessionUser.history, GameBoard->testResult);
}

void Session::gameController()
{
	bool endGame = false;

	int movingPlayer = 0;

	do {
		string playerName = players[movingPlayer].getToken();

		//player moves
		int steps = rollDice();
		int pos = players[movingPlayer].move(steps);
		cout << playerName << " rolled " << steps << " steps!\n";

		//print out where player is
		cout << playerName << " is at " << GameBoard->getTileAt(pos).getName() << endl;

		//account for losing players sometime in future, remove from player pool and update numbPlayers

		//next player rolls
		movingPlayer = ++movingPlayer % players.size();
		getchar();//user input wait
		//system("cls");
	} while (!endGame);
}

int Session::rollDice()
{
	return (rand() % 11) + 2;
}

string Session::getTokenOption(vector<string>& tokenOptions)
{
	for (int i = 0; i < tokenOptions.size(); i++)
	{
		cout << i + 1 << ". " << tokenOptions[i] << endl;
	}
	int tokenChoice;
	cin >> tokenChoice;

	//ignore safety for now, maybe come back
	string t = tokenOptions[tokenChoice-1];

	//removes token chosen from the list of tokens available
	tokenOptions.erase(tokenOptions.begin() + (tokenChoice - 1));
	system("CLS");
	return t;
}

void Session::initiatePlayers(int num_players) {
	vector<string> tokenOptions = GameBoard->getTokens();
	int boardsize = GameBoard->size();

	for (int i = 1; i <= num_players; i++) {
		//do token options per player
		string token = getTokenOption(tokenOptions);
		players.push_back(Player(token));
		players[i - 1].setBoardSize(boardsize);
	}
}

void Session::setTheme(string theme) {
	GameTheme = theme;
}
