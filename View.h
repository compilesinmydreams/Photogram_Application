#ifndef VIEW_H
#define VIEW_H

#include <iostream>
#include <string>
#include "Album.h"
//#include "PhotoGram.h"

using namespace std;

class View {
		
	public:
		View();
    		void mainMenu(const string* menu, int numItems, int& choice);
		void printAlbums(const Array<Album*>& albums);
		void displayAlbum(const Album&);

		void printPhotos(const Array<Photo*>& photos);
		void displayPhoto(const Photo&);

		// print albums and ask for selection to display
		void promptChoice(int& choice, int numOptions);
        	void promptDates(Date& before, Date& after);
		void promptCategory(string& category);
		void promptAlbum(string& title, string& description);
		void promptTitle(string& title);

	private:
		void promptDate(Date& date);

		
	
};
#endif
