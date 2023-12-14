#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Date.h"

Date::Date(){
	setDate(1901,1,1);
}

Date::Date(int y, int m, int d){
	//cout<<endl<<"in Date ctor"<<endl;
	setDate(y,m,d);
}

Date::Date(const Date& d){
	setDate(d.year,d.month,d.day);
	//cout<<endl<<"in Date COPY ctor"<<endl;
}


//setters
void Date::setDay(int d){
	int max = getMaxDay();
	if (d>max) d=max;
	if (d<1) d=1;
	day = d;
}

void Date::setMonth(int m){
	if (m > 12) m = 12;
	if (m < 1) m = 1;
	month = m;
}

void Date::setYear(int y){
	if (y < 1901) y = 1901;
	year = y;
}

void Date::setDate(int y, int m, int d){
	setMonth(m);
	setDay(d);
	setYear(y);
}

void Date::setDate(const Date& d){
	setDate(d.year, d.month, d.day);
}
//overloaders
bool Date::operator<(const Date& d)const{
	if(year==d.year){
		if(month == d.month)return day<d.day;
		if (month<d.month) return true; 
	}else if(year<d.year)return true;
	return false;
}
bool Date::operator==(const Date &d)const{
 	return (year == d.year && month == d.month && day == d.day);
}
ostream& operator<<(ostream& ost, const Date& d){
	ost << d.getMonthName()<<" "<<d.day<<", "<<d.year;
	return ost;
}
bool Date::operator<=(const Date& d)const{
	return *this<d||*this==d;
}
bool Date::operator>=(const Date& d)const{
	return !((*this==d)||(*this<d));
}
//getters
const int& Date::getDay() const{ return day; }
const int& Date::getMonth() const{ return month; }
const int& Date::getYear() const{ return year; }
string Date::getMonthName() const{
	string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	return months[month-1];
}

//other

bool Date::lessThan(const Date& d) const{
	if (year < d.year) return true;
	if (year > d.year) return false;
	//years are equal
	if (month < d.month) return true;
	if (month > d.month) return false;
	//months are equal
	return (day < d.day);
}

bool Date::equals(const Date& d) const{
	return (year == d.year &&
			month == d.month &&
			day == d.day);
}

void Date::incDate(){
	day += 1;
	if (day > getMaxDay()){
		day = 1;
		month += 1;
	}

	if (month > 12){
		month = 1;
		year += 1;
	}
}

void Date::addDays(int num){
	for (int i = 0; i < num; ++i){
		incDate();
	}
}

void Date::print() const{
	cout << getMonthName()<<" "<<day<<", "<<year;
}


int Date::getMaxDay() const{
	switch(getMonth()){
		case 4:
		case 6:
		case 9:
		case 11: 			return 30;
		case 2:				return 28;
		default:			return 31;
	}
}

