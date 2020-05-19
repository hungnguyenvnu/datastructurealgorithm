#pragma once
#include <iostream>

enum MealType { NO_PREF, REGULAR, LOW_FAT, VEGETARIAN };

class Passenger
{
private:
	std::string			name;
	MealType			mealPref;
	bool				isFreqFlyer;
	std::string			freqFlyerNo;

public:
	Passenger(); // default constructor
	Passenger(const std::string& nm, MealType mp, const std::string&ffn = "NONE");
	Passenger(const Passenger& pass); // copy constructor
	void print() 
	{
		std::cout << name << " " << mealPref << " " << isFreqFlyer << " " << freqFlyerNo << std::endl;
	}
};

