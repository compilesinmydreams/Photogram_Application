
#include "View.h"
#include <limits>

View::View(){
}

void View::mainMenu(const string* menu, int numOptions, int& choice)
{
  cout << endl;
  cout << "Please make a selection:"<< endl<<endl;
  for (int i = 0; i < numOptions; ++i){
    cout<<"  ("<<i+1<<") "<<menu[i]<<endl;
  }
  cout << "  (0) Exit" << endl<<endl;

  cout << "Enter your selection: ";
  cin >> choice;
  if (choice == 0)
    return;

  while (choice < 0 || choice > numOptions) {
    cout << "Enter your selection: ";
    cin >> choice;
  }
}

void View::printAlbums(const Array<Album*>& albums){
  for (int i = 0; i < albums.size(); ++i){
    cout <<i+1<<": "<< endl << *albums[i] <<endl;
  } 
}

void View::displayAlbum(const Album& album){
    album.display(cout);
}

void View::printPhotos(const Array<Photo*>& photos){
  for (int i = 0; i < photos.size(); ++i){
    cout <<i+1<<": " << endl << *photos[i] <<endl;
  } 
}


void View::displayPhoto(const Photo& photo){
    photo.display(cout);
}

void View::promptChoice(int& choice, int numOptions){

  cout << endl;
  cout << "Enter the number corresponding to your selection"<< endl;
  cout << "or select (0) to exit" << endl;

  cout << "Enter your selection: ";
  cin >> choice;
  if (choice == 0)
    return;

  while (choice < 0 || choice > numOptions) {
    cout << "Enter your selection: ";
    cin >> choice;
  }
  --choice;
}

void View::promptDates(Date& after, Date& before){
    cout<< "All photos after :";
    promptDate(after);
    cout<< "All photos before :";
    promptDate(before);
}

void View::promptDate(Date& date){
    cout <<"Enter year month day, for example 2023 1 31"<<endl;
    int year, month, day;
    cin>>year>>month>>day;
    date.setDate(year, month, day);
}
		
void View::promptCategory(string& category){
    cout <<"Enter category: ";
    cin >> category;
}

void View::promptAlbum(string& title, string& description){
    cout <<"Enter title: ";
    cin >> title;
    cout <<endl<<"Enter description: ";
    cin >> description;
}

void View::promptTitle(string& title){
    cout <<"Enter title: ";
    cin >> title;
}

