
#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Date {
	friend ostream& operator<<(ostream&, const Date&);
		
	public:
		//constructor
		Date();
		Date(int year, int month, int day);
		Date(const Date&);
		
		//setters
		void setDay( int);
		void setMonth(int);
		void setYear(int);
		void setDate(int, int, int);
		void setDate(const Date&);
		//overloading
		bool operator<(const Date& d) const;
		bool operator==(const Date &d)const;
		bool operator<=(const Date& d)const;
		bool operator>=(const Date& d)const;
		//getters
		const int& getDay() const;
		const int& getMonth() const;
		const int& getYear() const;
		string getMonthName() const;
		
		//other
		void incDate();
		void addDays(int);
		bool lessThan(const Date& d) const;
		bool equals(const Date& d) const;
		void print() const;
	
	private:
		//functions
		int getMaxDay() const;	
	
		//variables
		int day;
		int month;
		int year;
	
};
#endif
