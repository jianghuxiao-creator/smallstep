#include <iostream>
#include <string>
using namespace std;
bool isRunnian(int year);
int main(){
	loop:
	int year;
	int month;
	int day;
	string season;
	cout << "please input year and month:";
	cin >> year;
	cin >> month;
	if (isRunnian(year)){
		cout << year << " 年是闰年" << endl;
	}else{
		cout << year << " 年是平年" << endl;
	}
	switch (month){
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12: day = 31;break;
		case 2: if (isRunnian(year)){
			day = 29;			
		}else {
			day = 28;
		} break;
		case 4:
		case 6:
		case 9:
		case 11: day = 30; break;
		default : cout << " wrong number inputing.";
		
	}
	cout << month << "  month has " << day << " days." << endl;
	switch((month - 1) / 3){
		case 0: season = "spring"; break;
		case 1: season = "summer"; break;
		case 2: season = "fall"; break;
		case 3: season = "winter"; break;
		default : cout << "wrong number inputing" << endl;
	}
	cout << "This season is " << season <<"."<< endl << endl;
	
	goto loop;
	return 0;
} 

bool isRunnian(int year){
	if ((0 == year % 400) || ((0 == year % 4) && (0 != year % 100))){		
		return true;
	}else{
		return false;	
	}

}

