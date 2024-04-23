#pragma once
#include "../User/IUser.h"
using namespace std;

#define IS_PAYPAL true

class User : public IUser
{
	private:
		std::string username;
		std::string password;
		bool membership;
		Payment* pSess;
		UserProfile _profile;

	public:
	  Progress history;
	  ThemeManager UserThemes;

	  User();
	  //previous user
	  User(string, string);
	  //User(const User&);
	  ~User();
	  bool getMembership();
	  string getUsername();
	  void setUsername(string);
	  void setPassword(string);

	  //void encryptPassword(std::string);
	  void readProfile();
	  void newProfile(string username, string password);
	  //void profileWrite();

	  vector<string> getOptions();
	  vector<string> getThemes();
	  void viewProgress();
	  void viewThemes();
	  void viewPurchasableThemes();
	  vector<string> getPurchasableThemes();
	  void changePassword(string newPassword);
	  bool makePayment();
	  bool createOrder(string purchaseItemID);
	  bool setOrderID(string);
	  void CapturePaymentInfo();

	  bool updateTheme(string);
};
