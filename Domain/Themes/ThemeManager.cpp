#include "../../Domain/Themes/ThemeManager.hpp"
using namespace std;

ThemeManager::ThemeManager() {
	theme_list["Default"] = true;
	theme_list["Google"] = false;
	theme_list["Microsoft"] = false;
}
ThemeManager::ThemeManager(map<string, bool> themes) {
	theme_list = themes;
}
ThemeManager::~ThemeManager() {

}

vector<string> ThemeManager::getThemeNames() {
	vector<string> theme_names;
	for (std::map<string, bool>::iterator it = theme_list.begin(); it != theme_list.end(); ++it) {
		theme_names.push_back(it->first);
	}
	return theme_names;
		
}
vector<string> ThemeManager::getPurchasableThemeNames() {
	vector<string> theme_names;
	for (std::map<string, bool>::iterator it = theme_list.begin(); it != theme_list.end(); ++it) {
		if(it->second == false)
			theme_names.push_back(it->first);
	}
	return theme_names;

}
vector<string> ThemeManager::getAvailableThemeNames() {
	vector<string> theme_names;
	for (std::map<string, bool>::iterator it = theme_list.begin(); it != theme_list.end(); ++it) {
		if (it->second == true)
			theme_names.push_back(it->first);
	}
	return theme_names;

}

void ThemeManager::viewAvailableThemes() {

	for (int i = 0; i < getAvailableThemeNames().size(); i++) {
		cout << i + 1 << ") " << getAvailableThemeNames()[i] << endl;
	}

}
void ThemeManager::viewPurchasableThemes() {

	for (int i = 0; i < getPurchasableThemeNames().size(); i++) {
		cout << i + 1 << ") " << getPurchasableThemeNames()[i] << " \t\t$4.99" << endl;
	}

}

void ThemeManager::addTheme(string Sname) {
	theme_list[Sname] = false;
}
void ThemeManager::setTheme(string Sname) {
	theme_list[Sname] = true;
}