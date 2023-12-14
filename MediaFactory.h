#ifndef MEDIAFACTORY_H
#define MEDIAFACTORY_H

#include <iostream>
#include <string>
#include "Album.h"
#include "Criteria.h"

using namespace std;

class MediaFactory {
		
	public:
		// create a Song 
		Photo* uploadPhoto(const string& title);

		// create an Album
		Album* createAlbum(const string& title, const string& description);

		// create Criteria
		Criteria* dateCriteria(const Date& start, const Date& end);
		Criteria* categoryCriteria(const string& category);
		Criteria* dateAndCatCriteria(const Date& start, const Date& end, const string& cat);

	private:
		Date toDate(const string&);
	
};
#endif
