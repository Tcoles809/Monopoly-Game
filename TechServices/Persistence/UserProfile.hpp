#pragma once
#include "IPersistence.hpp"

class UserProfile : public IPersistenceHandler
{
public:
	UserProfile();
	UserProfile(string username);
	~UserProfile();
	bool new_profile(string username, string password);
	bool change_password(string password);
	bool update_Theme(string newTheme);
};