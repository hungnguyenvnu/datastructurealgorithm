#include "Passenger.h"

// default constructor
Passenger::Passenger() 
{ 
	name = "--NO NAME--";
	mealPref = NO_PREF;
	isFreqFlyer = false;
	freqFlyerNo = "NONE";
}

// constructor given member values
Passenger::Passenger(const std::string& nm, MealType mp, const std::string& ffn) 
{
	name = nm;
	mealPref = mp;
	isFreqFlyer = (ffn != "NONE"); // true only if ffn given
	freqFlyerNo = ffn;
}

// copy constructor
Passenger::Passenger(const Passenger& pass) 
{
	name = pass.name;
	mealPref = pass.mealPref;
	isFreqFlyer = pass.isFreqFlyer;
	freqFlyerNo = pass.freqFlyerNo;
}