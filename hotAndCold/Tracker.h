#pragma once


using namespace std;
class Tracker
{
public:
	double hot[7] = {};
	double cold[7] = {};
	double hotGoal = 80.0;
	double coldGoal = 11.0;
	double monthHot[4] = { 0, 0, 0, 0 };
	double monthCold[4] = { 0, 0, 0, 0 };
	double yearlyHot[13] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	double yearlyCold[13] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	double lifeTimeCold[130] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	double lifeTimeHot[130] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	double monthsHotGoalWasHit[52] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	double monthsColdGoalWasHit[52] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	//addHot and addCold are the only functions that have parameters
	//simply takes the input and stores into a text file 
	void addHot(double num);
	void addCold(double num);
	//checks and resets:
	//checks see if the array is full, and if so, calls the reset, which resets all values to zero
	void checkYear();
	void resetYear();
	void resetMonth();
	void checkMonth();
	void resetWeek();
	//hott and Coldd Goal:
	//adds all values in the arrays hot and cold. if goals are reached, program notifies user
	void hottGoal();
	void colddGoal();
	//week counter: adds a one everytime a goal is hit 
	void hotWeekCounter();
	void coldWeekCounter();
	//clock, my favorite function in the program.  Uses seconds passed since Jan 1, 1970
	void clock();
	// spacer: built for UX design
	void spacer();
	//nextWeek, Month, and Year:
	// all very similar.  nextWeek, just like Hott and Cold Goal, adds the values from hot and cold
	// and sends the sum to another text file that holds monthHot or monthCold
	void nextWeek();
	// nextMonth adds all values from monthHot or monthCold and sends the sum to either yearlyHot or yearlyCold
	void nextMonth();
	//nextYear adds all values from yearlyHot or Cold and sends the sum to either lifetimeHot or Cold
	void nextYear();
	Tracker();
};

