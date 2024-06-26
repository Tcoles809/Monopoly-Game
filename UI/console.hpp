#pragma once
#include "../Domain/User/IUserInterface.h"
using namespace std;

class ConsoleView: public IUserInterface
{
private:
	Session sess;
public:
	ConsoleView();
	~ConsoleView();
	void displayGame();
	void displayLoginOptions();
	void captureUserLoginInfo(string& un, string& pw);
	void changePassword();
	void createNewUser();
	void authenticateUser();
	void displayChoices();
	void displayThemes();
	void displayPurchaseOptions();
};