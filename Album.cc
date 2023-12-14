#include "Album.h"


Album::Album(const string& title , const string& description):title(title), description(description){
}


bool Album::equals(const string& title)const{
  return title==this->title;
}

void Album::addPhoto(Photo* newPhoto){
  photoArray+=newPhoto;
}
Photo* Album::getPhoto(int i)const{
  return photoArray[i];
 }

int Album::size()const{
  return photoArray.size();
}
void Album::print(ostream& ost) const{

  ost<<"Album Title: "<<title<<" Desc: "<<description<<" contains ";
  ost<<photoArray.size()<<" photos."<<endl;
}
void Album::display(ostream& ost) const{
  print(ost);
  for(int i = 0; i<photoArray.size();i++){
    photoArray[i]->display(ost);
  }
}
ostream& operator<<(ostream& ost, const Album& album){
  album.print(ost);
  return ost;
}
