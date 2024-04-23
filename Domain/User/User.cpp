#include "User.hpp"
User::User()
{
	username = "";
	password = "";
	membership = false;
	pSess = NULL;
}

User::~User()
{
}

//existing user
User::User(string _username, string _password)
{
	username = _username;
	password = _password;
	membership = false;
	try {
		readProfile();
	}
	catch (exception & ex)
	{
		throw ex;
	}
	_profile = UserProfile(username);
	history = Progress(username);
}

void User::readProfile()
{
	string profile_path = "../../TechServices/Persistence/User_Profiles/" + username + ".txt";
	ifstream file(profile_path);
	string _username = "";
	string _password = "";
	bool _membership = false;
	if (!file.is_open())
		throw invalid_argument("Invalid Username.\n");
	else
	{
		string line = "";
		//get USER NAME
		getline(file, line);
		size_t found = line.find("\\");
		if (found != string::npos)
		{
			found += 2;
			_username = line.substr(found, line.size() - 1);
		}
		//get password
		getline(file, line);
		found = line.find("\\");
		if (found != string::npos)
		{
			found += 2;
			_password = line.substr(found, line.size() - 1);
		}

		//get theme identifiers
		while (getline(file, line)) 
		{
			found = line.find("\\");
			string theme_id = line;
			if (found != string::npos)
			{
				found += 2;
				theme_id = line.substr(found, line.size() - 1);
				UserThemes.setTheme(theme_id);
			}
		}

		if (username != _username)
			throw invalid_argument("Username does not match argument in profile.\n");
		if (password != _password)
			throw invalid_argument("Password is not correct!\n");
		//Close file
		file.close();
	}
}
// New User
bool User::getMembership() {
	return membership;
}

void User::setUsername(string _username)
{
	username = _username;
}
void User::setPassword(string _password)
{
	password = _password;
}

string User::getUsername() {
	return username;
}

bool User::createOrder(string purchaseItemID) {

	//making payment
	pSess->setOrderID(pSess->CreateOrder(purchaseItemID));
	if (pSess->getOrderID() != "") {
		if (makePayment()) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			Log(purchaseItemID+" Subscription Purchased!");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			UserThemes.setTheme(purchaseItemID);
			_profile.update_Theme(purchaseItemID);
			Sleep(1000);
		}
	}
	return true;
}

bool User::makePayment()
{

	pSess->CreatePayment();
	pSess->SetPaymentInfo();
	pSess->AuthorizePaymentInfo();
	cout << "Confirm purchase by pressing 'Enter'. (Payment not yet completed.)";
	cin.ignore();
	if (cin.get() == '\n') {
		pSess->AuthorizePaymentForOrder(pSess->getOrderID());
		pSess->CapturePaymentForOrder(pSess->getOrderID());
		return true;
	}
	else
		return false;
}


void User::changePassword(string new_pw)
{
	_profile.change_password(new_pw);
}

void User::viewProgress()
{
	try {
		history = Progress(username);
		history.print_results();
	}
	catch (exception & ex)
	{
		cerr << ex.what() << endl;
		cerr << "New Profile?\n" << endl;
	}
}

vector<string> User::getOptions() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	cout << "Welcome, " << username << "." << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	vector<string> options;
	options.push_back("1) Start Game");
	options.push_back("2) Select a Theme");
	options.push_back("3) Purchase a Theme");
	options.push_back("4) Change Password");
	options.push_back("5) Logout");
	return options;
}

void User::newProfile(string _username, string _password)
{
	_profile = UserProfile(_username);
	if(!_profile.new_profile(_username, _password))
		throw invalid_argument("Error creating the file\n");
	//SETTING THE USERNAME, PASSWORD, AND INITIALIZING THE HISTORY
	setUsername(_username);
	setPassword(_password);
	history = Progress(username);
	Sleep(1000);
	system("CLS");
}

bool User::setOrderID(string sub)
{
	system("CLS");

	if (IS_PAYPAL)
		pSess = new Paypal();
	else
		pSess = new Visa();
	//setting order id
	pSess->setOrderID(sub);
	//capture payment info
	CapturePaymentInfo();
	return true;
}
void User::viewThemes() {
	UserThemes.viewAvailableThemes();
}
void User::viewPurchasableThemes() {
	UserThemes.viewPurchasableThemes();
}
vector<string> User::getThemes() {
	return UserThemes.getAvailableThemeNames();
}
vector<string> User::getPurchasableThemes() {
	return UserThemes.getPurchasableThemeNames();
}
void User::CapturePaymentInfo()
{
	system("CLS");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	cout << "Please enter Payment Info: " << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	string fname, lname, creditNum, secureCode, expDate;
	cout << "F Name: ";
	cin >> fname;
	cout << "L Name: ";
	cin >> lname;
	cout << "CC#: ";
	cin >> creditNum;
	cout << "CRV#: ";
	cin >> secureCode;
	cout << "Exp Date: ";
	cin >> expDate;

	if (pSess->setCreditInfo(fname, lname, creditNum, secureCode, expDate))
	{
		system("CLS");
		createOrder(pSess->getOrderID());
	}
}

bool User::updateTheme(string newTheme)
{
	if (_profile.update_Theme(newTheme))
		return true;
	else
		return false;
}
