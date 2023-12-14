#include <iostream>
#include "Photo.h"

using namespace std;

Photo::Photo(const string& title, const string& category, const Date& date, const string& content):title(title),category(category),date(date),content(content){}

bool Photo::equals(const string& title) const
{
    if(this->title==title){
    	return true;
    }
    return false;
}

const Date& Photo:: getDate () const {
   return this->date;
}
        
const string& Photo:: getCategory () const {
   return this->category;
}

void Photo::print(ostream& os) const
{
    os << "Title: " << title <<" Category: " << category << " Date: " << date << endl;
}

void Photo::display(ostream& os) const
{
    print(os);
    os << "Content: " << content <<endl;
}

ostream& operator<<(ostream& os, const Photo& photo)
{
    photo.print(os);
    return os;
}

