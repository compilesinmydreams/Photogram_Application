#include "PhotoGram.h"


PhotoGram::PhotoGram(){
  media = new MediaFactory();
}

PhotoGram::~PhotoGram(){
  for(int i=0;i<albums.size();i++){
    delete albums[i];
  }
  for(int i=0;i<masterList.size();i++){
    delete masterList[i];
  }
  delete media;
}

void PhotoGram::addAlbum(const string& title, const string& description){
  albums+=media->createAlbum(title, description);
}

void PhotoGram::addToAlbum(int index, Array<Photo*>& photos){
  for(int i = 0; i<photos.size();i++){
    albums[index]->addPhoto(photos[i]);
  }
}

void PhotoGram::uploadPhoto(const string& title){
  masterList+=media->uploadPhoto(title);
}

void PhotoGram::deleteAlbum(int index){
  if(index == 0||index>albums.size()){
    cerr<<"Ind not in range.";
  }
  albums-=albums[index];
}


void PhotoGram::getPhotos(const Criteria& criteria, Array<Photo*>& photos)const{
  int index = 0; 
  while(index<masterList.size()){
    if(criteria.matches(*masterList[index])){
      photos+=masterList[index];
    }
    index++;
  }
  
}

int PhotoGram::printAlbums(View& view){
  view.printAlbums(albums);
  return albums.size();
}
void PhotoGram::displayAlbum(int index, View& view){

  if(index<0||index>albums.size()){
    cerr<<"Index out of bounds!";
  }
  view.displayAlbum(*albums[index]);
}
int PhotoGram::printPhotos(View& view){
  view.printPhotos(masterList); 
  return masterList.size();
}
void PhotoGram::displayPhoto(int index, View& view){

  if(index<0||index>masterList.size()){
    cerr<<"Ind out of bounds!";
  }
  view.displayPhoto(*masterList[index]);
}
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
  
