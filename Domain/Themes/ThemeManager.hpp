#pragma once
#include <string>
#include <map>
#include <vector>
#include <iostream>
#include "Theme.hpp"
using namespace std;

class ThemeManager
{
private:
	map<string,bool> theme_list;
	string profile_path;
public:
	ThemeManager();
	ThemeManager(map<string, bool> themes);
	virtual ~ThemeManager();

	vector<string> getThemeNames();
	vector<string> getPurchasableThemeNames();
	vector<string> getAvailableThemeNames();
	void viewAvailableThemes();
	void viewPurchasableThemes();
	void addTheme(string Sname);
	void setTheme(string Sname);
};