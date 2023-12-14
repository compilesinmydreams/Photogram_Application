#ifndef PHOTO_H
#define PHOTO_H

#include <string>
#include "Date.h"

using namespace std;

class Photo {
    friend ostream& operator<<(ostream& os, const Photo& photo);
    private:
        string title;
        string content;
        Date date;
        string category;
    
    public:
        Photo ( const string & title , const string & category , const Date & , const string & content );
        bool equals(const string& title) const;
        const Date & getDate () const ;
        const string & getCategory () const ;
        void print(ostream&) const;
        void display(ostream&) const;
	
};

#endif

