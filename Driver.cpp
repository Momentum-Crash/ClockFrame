    /*
    *
    * Author: Bradley Decker
    * Date: 9/18/2022
    *
    */

#include <Windows.h>
#include <iostream>
#include <cmath>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <synchapi.h>
#include <fstream>
#include <string>
#include <ctime>
#pragma warning(disable:4996)

//Variables being used
using namespace std;
int myHours, myMinutes, mySeconds, tmpHours;
char userCommand, resetChar;
time_t curr_time = time(NULL);
tm* tm_local = localtime(&curr_time);
string myMeridiam;

//Derviative Variables for time
int currHours = tm_local->tm_hour;
int currMinutes = tm_local->tm_min;
int currSeconds = tm_local->tm_sec;


/*These three functions just add time to adjust the clock forward*/
void AddHour() 
{
	//If handles outside of time formats
	myHours += 1;
	if ((currHours + myHours) > 24)
	{
		myHours -= 24;
	}
	
}

void AddMinute() 
{
	//If handles outside of time formats
	myMinutes += 1;
	if ((currMinutes + myMinutes) > 59)
	{
		myMinutes -= 60;
		AddHour();
	}
	
}

void AddSecond() 
{
	//If handles outside of time formats
	mySeconds += 1;
	if ((currSeconds + mySeconds) > 59)
	{
		mySeconds -= 60;
		AddMinute();
	}
	
}


//Formats the numbers for the clock
void myFormat(int myNum) 
{
	string formatNum = to_string(myNum);
	cout << setfill('0') << setw(2) << right << myNum;
}

//Evaluates to the 12 hour Meridiam time of AM or PM for morning or afternoon
void clockFunction12Hr(int clockHours) 
{
	if (clockHours > 12) {
		myMeridiam = "PM";
	}
	else {
		myMeridiam = "AM";
	}
}

//Blank Lines
void displayBlankFill() 
{
	cout << setfill('*') << setw(26) << right << "";
}

//Displays the User Menu
void displayMenu() 
{
	displayBlankFill();
	cout << endl;
	cout << setfill(' ') << setw(25) << left << "* 1-Add One Hour " << "*" << endl;
	cout << setfill(' ') << setw(25) << left << "* 2-Add One Minute  " << "*" << endl;
	cout << setfill(' ') << setw(25) << left << "* 3-Add One Second  " << "*" << endl;
	cout << setfill(' ') << setw(25) << left << "* 4-Exit Program  " << "*" << endl;
	displayBlankFill();
	cout << endl;
}


//Displays the current time
void myClockFormat(int clockHours, int clockMinutes, int clockSeconds) {
	//Line 1 of Clocks Display
	displayBlankFill();
	cout << "   ";
	displayBlankFill();
	cout << endl;

	//Line 2 of Clocks Display
	cout << setfill('*') << setw(7) << right << "      " << "12-Hour Clock";
	cout << setfill('*') << setw(6) << left << "     ";
	cout << "   " << setfill('*') << setw(7) << right << "      " << "24-Hour Clock";
	cout << setfill('*') << setw(6) << left << "     " << endl;

	//Line 3 of Clocks Display
	cout << setfill('*') << setw(9) << right << "        ";

	//12 Hour Clock Output
	if ((clockHours + myHours) > 12)
	{
		myFormat((clockHours + myHours) - 12);
	}
	else
	{
		myFormat(clockHours + myHours);
	}
	cout << ":"; 
	myFormat(clockMinutes + myMinutes); 
	cout << ":";
	myFormat(clockSeconds + mySeconds);

	//Next line is for checking for AM/PM, the line after is the product of that function.
	clockFunction12Hr(clockHours + myHours);
	cout << myMeridiam;

	cout << setfill('*') << setw(7) << left << "      ";
	cout << "   " << setfill('*') << setw(9) << right << "        ";

	//24 Hour Clock Output
	myFormat(clockHours + myHours);
	cout << ":";
	myFormat(clockMinutes + myMinutes);
	cout << ":";
	myFormat(clockSeconds + mySeconds);

	cout << setfill('*') << setw(9) << left << "        " << endl;
	
	//Line 4 of the Clocks Display
	displayBlankFill();
	cout << "   ";
	displayBlankFill();
	cout << endl;

}


int main()

{

	while (userCommand != '4') {
		
		userCommand = resetChar;
		myClockFormat(currHours, currMinutes, currSeconds);
		displayMenu();
		Sleep(1000);
		AddSecond();
		cin >> userCommand;
		system("CLS");
		try
		{
			if (userCommand == '3') {
				AddSecond();
			}

			else if (userCommand == '2') {
				AddMinute();
			}

			else if (userCommand == '1') {
				AddHour();
			}

			else if (userCommand == '4') {
				cout << "Program Terminated," << endl << "Goodbye.";
				break;
			}

			else {
				throw(userCommand);
			}
		}
		catch (char myInput)
		{
			cout << "Please input a valid option number." << endl;
		}

		

	}
	return 0;
}



