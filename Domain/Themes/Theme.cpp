#include "../../Domain/Themes/Theme.hpp"
using namespace std;

Theme::Theme()
{
	price = 0.0;
	name = "Default";
}
Theme::Theme(string tname, double tprice)
{
	price  = tprice;
	name = tname;
}
Theme::~Theme()
{
}
