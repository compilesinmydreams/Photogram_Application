#ifndef ALBUMCREATOR_H
#define ALBUMCREATOR_H

#include <iostream>
#include <string>
#include "PhotoGram.h"
#include "View.h"
#include "MediaFactory.h"

using namespace std;

class AlbumCreator {
		
	public:
				
		void launch();
	
	private:
		void initFromFile();
		void addAlbum();
		void deleteAlbum();
		void printAlbums();
		void displayAlbum();
		void printPhotos();
		void displayPhoto();
		void getPhotosByDate(); 
		void getPhotosByCat(); 
		void getPhotosByCandD(); 
		void printCurrentPhotoList(); 
		void displayCurrentPhotoList(); 
		void addToAlbum();
		View view;
		PhotoGram pg;
		MediaFactory mf;
		Array<Photo*> currentPhotos;
		static const string menu[12];

	
};
#endif