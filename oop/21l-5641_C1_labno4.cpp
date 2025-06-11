#include<iostream>
#include<Windows.h>
using namespace std;
class Date
{
	int Day;
	int month;
	int Year;
public:
	Date()
	{
		cout << "The default constructor has been called." << endl;
		Day = 1;
		month = 1;
		Year = 1926;
	}
	Date(int date, int month, int year)
	{
		Day = date;
		month = month;
		Year = year;
		Print();

	}
	void Print()
	{
		cout << Day << "/" << month << "/" << Year << endl;
	}
	void independence()
	{
		Day = 14;
		month = 8;
		Year = 2018;
		cout << Day << "/" << month << "/" << Year << endl;
	}
	void input()
	{
		cout << "Enter day: ";
		cin >> Day;
		cout << "Enter month: ";
		cin >> month;
		cout << "Enter year: ";
		cin >> Year;
	}
	void setDay()
	{
		cout << "\nPlease enter day : ";
		cin >> Day;
	}
	void setMonth()
	{
		cout << "\nPlease enter the month : ";
		cin >> month;
	}
	void setYear()
	{
		Year = 2009;
	}
	int getDay()
	{
		return Day;
	}
	int getMonth()
	{
		return month;
	}
	int getYear()
	{
		return Year;
	}
};

int main()
{
	Date Date1;
	Date1.Print();
	Date(1, 1, 2001);
	Date IndependenceDay;
	IndependenceDay.independence();
	Date1.input();
	Date1.Print();
	Date xmasDay;
	xmasDay.setDay();
	xmasDay.setMonth();
	xmasDay.setYear();
	cout << xmasDay.getDay() << "/";
	cout << xmasDay.getMonth() << "/";
	cout << xmasDay.getYear() << endl;
	Date temp;
	temp = xmasDay;
	temp.Print();
	Sleep(-1);
}