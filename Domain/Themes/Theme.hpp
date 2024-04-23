#pragma once
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Theme
{
private:
	string name;
	double price;
	vector<string> theme_list;
public:
	Theme();
	Theme(string tname, double tprice);
	virtual ~Theme();

	string getName() { return name; };
	void setName(string Sname) { name = Sname; };
	double getPrice() { return price; };

	string toString();
};