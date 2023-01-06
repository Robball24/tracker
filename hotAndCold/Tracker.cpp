#include "Tracker.h"
#include <iostream>
#include <fstream>
#include <set>
#include <iomanip>



void Tracker::spacer() {
	for (int i = 0; i < 2; i++) {
		cout << setw(50) << "*" << "                  " << "*" << "\n";
	}
}

void Tracker::addCold(double num) {
	ofstream fileOut("trackerOutput.txt", ios::app);
	for (double i: "trackerOutput.txt") {
		if (i == 0) {
			i = num;
			num = 0;
			fileOut << i << " ";
		}

	}
	fileOut.close();
}


void Tracker::addHot(double num) {
	ofstream fileOut("trackerInput.txt", ios::app);
	for (double j: "trackerInput.txt") {
		if (j == 0) {
			j = num;
			num = 0;
			fileOut << j << " ";
		}
	}
	
	fileOut.close();
}


void Tracker::resetWeek() {
	hotWeekCounter();
	coldWeekCounter();
	ofstream fileOutt("trackerInput.txt");
	ofstream fileOut("trackerOutput.txt");
	for (double i: "trackerInput.txt") {
		i = 0.0;
	}
	for (double j : "trackerOutput.txt") {
		j = 0.0;
	}

	fileOutt.close();
	fileOut.close();
}

void Tracker::resetMonth() {
	ofstream resetHot("monthlyHot.txt");
	ofstream resetCold("monthlyCold.txt");

	for (double i : "monthlyHot.txt") {
		i = 0.0;
	}
	for (double j : "monthlyCold.txt") {
		j = 0.0;
	}

	resetHot.close();
	resetCold.close();
}

void Tracker::checkMonth() {
	ifstream checkMonthlyHot("monthlyHot.txt");
	ifstream checkMonthlyCold("monthlyCold.txt");

	for (double i : monthHot) {
		if (monthHot[0] != 0 && monthHot[1] != 0 && monthHot[2] != 0 && monthHot[3] != 0) {
			nextMonth();
			resetMonth();
		}
	}

	for (double j : monthCold) {
		if (monthCold[0] != 0 && monthCold[1] != 0 && monthCold[2] != 0 && monthCold[3] != 0) {
			nextMonth();
			resetMonth();
		}
	}
}

void Tracker::checkYear() {
	ifstream checkHot("yearlyHot.txt");
	ifstream checkCold("yearlyCold.txt");

	for (double i : yearlyHot) {
		if (i != 0) {
			nextYear();
			resetYear();
		}
	}

	for (double j : yearlyCold) {
		if (j != 0) {
			nextYear();
			resetYear();
		}
	}
}

void Tracker::resetYear() {
	ofstream resetHot("yearlyHot.txt");
	ofstream resetCold("yearlyCold.txt");
	for (double i : "yearlyHot.txt") {
		i = 0.0;
	}
	for (double j : "yearlyCold.txt") {
		j = 0.0;
	}

	resetHot.close();
	resetCold.close();
}

//need to fix this.  some weeks, people may have 0 minutes on one or the other.  Keeping this as is would mean
// the computer would not track the zero week, but overwrite it with the next week that a time is recorded
// possibly add a function that adds a null character or something if no values are recorded


void Tracker::hottGoal() {
	ifstream fileIn("trackerInput.txt");
	
	double hott = 0.0;
	
	// trying to use a counter to control the switching of months instead of a timer.  Should work because
	// i'm just tracking 4 weeks at a time and calling that a month. 
	
	
	for (double j : hot) {
		fileIn >> j;
		hott += j;
		
	}
	
	cout << "\n" << setw(64) << "Total heat this week: " << hott << " minutes" << "\n";
	
	if (hott >= hotGoal) {
		cout << setw(67) << "Hot Goal Reached" << "\n";
	}
	else {
		cout << setw(43) << (hotGoal - hott) << " minutes of heat left this week." << "\n";
	}
	

	fileIn.close();
}


void Tracker::colddGoal() {
	ifstream fileIn("trackerOutput.txt");
	ofstream colddGoalCounter("weeksColdGoalWasReached.txt", ios::app);
	
	double coldd = 0.0;
	

	for (double i : cold) {
		fileIn >> i;
		coldd += i;
	}
	cout << "\n" << setw(65) << "Total cold this week: " << coldd << " minutes" << "\n";

	if (coldd >= coldGoal) {
		cout << setw(67) << "Cold Goal Reached" << "\n";
		colddGoalCounter << 1 << " ";
	}
	else {
		cout << setw(43) << (coldGoal - coldd) << " minutes of cold left this week." << "\n";
	}

	
	colddGoalCounter.close();
	fileIn.close();
	}

void Tracker::coldWeekCounter() {
	ifstream fileIn("trackerOutput.txt");
	ofstream colddGoalCounter("weeksColdGoalWasReached.txt", ios::app);

	double coldd = 0.0;


	for (double i : cold) {
		fileIn >> i;
		coldd += i;
	}
	
	if (coldd >= coldGoal) {
		colddGoalCounter << 1 << " ";
	}

	colddGoalCounter.close();
	fileIn.close();
}

void Tracker::hotWeekCounter() {
	ifstream fileIn("trackerInput.txt");
	ofstream hottGoalCounter("weeksHotGoalWasReached", ios::app);
	double hott = 0.0;

	for (double j : hot) {
		fileIn >> j;
		hott += j;

	}

	if (hott >= hotGoal) {
		hottGoalCounter << 1 << " ";
	}


	fileIn.close();
	hottGoalCounter.close();

}


void Tracker::clock() {
	time_t current_time;
	time(&current_time);
	//int days = current_time / 86400;
	int year = 31536000;
	int month = 2419200;
	int week = 604800;
	int day = 86400;
	double hour = 3600;
	int remainingSec = (current_time % week) - 21600;
	int daysFromReset = 0;
	string daysOfWeek[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
	string dayOfWeek = "";
	
	checkMonth();

	if (remainingSec >= 0 && remainingSec <= 86400) {
		dayOfWeek = daysOfWeek[4];
		daysFromReset = 3;
	}
	if (remainingSec > 86400 && remainingSec <= day * 2) {
		dayOfWeek = daysOfWeek[5];
		daysFromReset = 2;
	}
	if (remainingSec > 172800 && remainingSec <= day * 3) {
		dayOfWeek = daysOfWeek[6];
		daysFromReset = 1;
		
	}
	if (remainingSec > 259000 && remainingSec < day * 4) {
		dayOfWeek = daysOfWeek[0];
		daysFromReset = 7;
		nextWeek();
	}
	
	if (remainingSec > 345600 && remainingSec < day * 5) {
		dayOfWeek = daysOfWeek[1];
		daysFromReset = 6;
		
	}
	if (remainingSec > 432000 && remainingSec < day * 6) {
		dayOfWeek = daysOfWeek[2];
		daysFromReset = 5;
		
	}
	if (remainingSec > 518400 && remainingSec < day * 7) {
		dayOfWeek = daysOfWeek[3];
		daysFromReset = 4;
	}
	
	//cout << remainingSec << "\n";

	//i think this is the error in time, in seconds, that i was off. results in 21600

	//cout << hour * 2.25 + (hour * 4) << "\n";
	
	cout << setw(60) << "Today is " << dayOfWeek << "\n";
	if (dayOfWeek != "Saturday") {
		cout << setw(45) << "You have " << daysFromReset
			<< " days to complete your weekly goals!"
			<< "\n";
	} else cout << setw(78) << "This is the last day to hit your goals." << "\n";

	spacer();
	hottGoal();

	spacer();
	colddGoal();

	spacer();
	cout << "\n";
}

void Tracker::nextWeek() {
	ifstream coldIn("trackerOutput.txt");
	ifstream hotIn("trackerInput.txt");
	ofstream hotOut("monthlyHot.txt", ios::app);
	ofstream coldOut("monthlyCold.txt", ios::app);
	double hotNum = 0;
	double coldNum = 0;

	for (double i : cold) {
		coldIn >> i;
		coldNum += i;
	}

	for (double i : "monthlyCold.txt") {
		if (i == 0) {
			coldOut << " " << coldNum << " ";
			coldNum = 0;
		}
	}

	for (double l : hot) {
		hotIn >> l;
		hotNum += l;
	}

	for (double l : "monthlyHot.txt") {
		if (l == 0) {
			l = hotNum;
			hotOut << " " << l << " ";
			hotNum = 0;
		}
	}

	coldIn.close();
	hotIn.close();
	coldOut.close();
	hotOut.close();

	resetWeek();

}
// not sure if this is better or worse than having the functions split like hottGoal and 
// addHot.  This takes the functionality of both and puts it into one function for the month.
// may end up biting me in the ass

void Tracker::nextMonth() {
	ifstream coldIn("monthlyCold.txt");
	ifstream hotIn("monthlyHot.txt");
	ifstream percentHotIn("weeksHotGoalWasReached.txt");
	ifstream percentColdIn("weeksColdGoalWasReached.txt");
	ofstream hotOut("yearlyHot.txt", ios::app);
	ofstream coldOut("yearlyCold.txt", ios::app);
	double hotNum = 0;
	double coldNum = 0;
	double hotHit = 0;
	double coldHit = 0;

	for (double i : monthCold) {
		coldIn >> i;
		coldNum += i;
	}

	for (double i : "yearlyCold.txt") {
		if (i == 0) {
			coldOut << coldNum << " ";
			coldNum = 0;
		}
	}

	for (double i : monthsColdGoalWasHit) {
		percentColdIn >> i;
		coldHit += i;
		cout << coldHit / 52;
	}

	for (double l : monthHot) {
		hotIn >> l;
		hotNum += l;
	}

	for (double l : "yearlyHot.txt") {
		if (l == 0) {
			l = hotNum;
			hotOut << l << " ";
			hotNum = 0;
		}
	}
	for (double l : monthsHotGoalWasHit) {
		percentHotIn >> l;
		hotHit += l;
		cout << hotHit / 52;
	}


	coldIn.close();
	hotIn.close();
	coldOut.close();
	hotOut.close();
}

void Tracker::nextYear() {
	ifstream coldIn("yearlyCold.txt");
	ifstream hotIn("yearlyHot.txt");
	ofstream hotOut("lifetimeHot.txt", ios::app);
	ofstream coldOut("lifetimeCold.txt", ios::app);
	double hotNum = 0;
	double coldNum = 0;

	for (double i : yearlyCold) {
		coldIn >> i;
		coldNum += i;
	}

	for (double i : "lifetimeCold.txt") {
		if (i == 0) {
			coldOut << coldNum << " ";
			coldNum = 0;
		}
	}

	for (double l : yearlyHot) {
		hotIn >> l;
		hotNum += l;
	}

	for (double l : "lifetimeHot.txt") {
		if (l == 0) {
			l = hotNum;
			hotOut << l << " ";
			hotNum = 0;
		}
	}


	coldIn.close();
	hotIn.close();
	coldOut.close();
	hotOut.close();
}

Tracker::Tracker() {
	for (double i: cold) {
		i = 0.0; 
	}
	for (double j: hot) {
		j = 0.0;
	}
	hotGoal = 80.0;
	
	coldGoal = 11.0;
}

//add a manual reset for weeks, months, and years in case the current system doesn't work