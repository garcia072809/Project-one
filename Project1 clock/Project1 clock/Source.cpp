/*
Jessy A Garcia 
9SEP2022
CS-210-H7648 Programming Languages 22EW1
*/


#include<iostream>
#include<string>
#include<iomanip>


using namespace std;


//clock variables
int hours12, hours24, minutes, seconds;
string ampm;
//adding hours function
void addHour() {
	hours12 = hours12 + 1;
	//how the clock will adjust
	if (hours12 >= 12) {
		hours12 = hours12 - 12;
		if (ampm == "AM")
			ampm = "PM";
		else
			ampm = "AM";
	}
}
//adding minutes function
void addMinute() {
	minutes = minutes + 1;
	if (minutes > 59) {
		minutes = 0;
		addHour();

	}
}
//second clock
void addSecond() {
	seconds = seconds + 1;
	if (seconds > 59) {
		seconds = 0;
		addMinute();
	}
}

//main function
int main() {
	//variables
	int choice = 0;
	//setting the intial clock timing manually
	hours12 = 10;
	minutes = 58;
	seconds = 59;
	ampm = "PM";
	//wild loop for second clock
	while (1) {
		//second clock
		if (ampm == "PM") {
			hours24 = hours12 + 12;
			if (hours24 >= 24) {
				hours24 = hours24 - 24;
			}
		}
		else {
			hours24 = hours12;
		}
		//printing the clock
		cout << "****************************\t\t****************************\n";
		cout << "* 12-Hour clock            *  \t\t* 24-Hour clock            *\n";
		cout << "* " << setw(2) << setfill('0') << hours12 << ":" << setw(2) << setfill('0') << minutes << ":" << setw(2) << setfill('0') << seconds << " " << ampm << "              *";
		cout << "\t\t* " << setw(2) << setfill('0') << hours24 << ":" << setw(2) << setfill('0') << minutes << ":" << setw(2) << setfill('0') << seconds << " " << "                *\n";
		cout << "****************************\t\t****************************\n";
		//printing the option
		cout << "\n\n****************************\n";
		cout << "* 1-Add one hour *\n";
		cout << "* 2-Add one minutes *\n";
		cout << "* 3-Add one second *\n";
		cout << "* 4-Exit program *\n";
		cout << "****************************\n";
		cout << "Choose and option: ";
		cin >> choice;
		//users input choices
		if (choice == 1) {
			//add an hr function
			addHour();
		}
		else if (choice == 2) {
			//add an min function
			addMinute();
		}
		else if (choice == 3) {
			//add a sec function
			addSecond();
		}
		else if (choice == 4) {
			//lets you exit
			cout << "Exiting program...";
			break;
		}
		else {
			//if inputs inproper entry
			cout << "Invalid input. Try Again...";
		}
	}
}