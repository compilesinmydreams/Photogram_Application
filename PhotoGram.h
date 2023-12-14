#ifndef PHOTOGRAM_H
#define PHOTOGRAM_H

#include <iostream>
#include <string>
#include "defs.h"
#include "Array.h"
#include "Criteria.h"
#include "Album.h"
#include "MediaFactory.h"
#include "View.h"
using namespace std;


class PhotoGram{
  public:
    PhotoGram();
    ~PhotoGram();
    int printAlbums(View& view);
    void displayAlbum(int index, View&);
    int printPhotos(View& view);
    void displayPhoto(int index, View& view);
    void addAlbum(const string&, const string&);
    void addToAlbum(int index, Array<Photo*>& photos);
    void uploadPhoto(const string& title);
    void deleteAlbum(int index);
    void getPhotos(const Criteria& criteria, Array<Photo*>& photos)const;
  private:
    Array<Album*> albums;
    Array<Photo*> masterList;
    MediaFactory* media;
};
#endif
