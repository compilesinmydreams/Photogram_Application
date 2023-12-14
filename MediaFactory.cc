
#include "MediaFactory.h"
#include <fstream>
#include <sstream>
#include <limits>

Date MediaFactory::toDate(const string& d){
    stringstream ss;
    ss<<d;
    int year, month, day;
    ss>>year>>month>>day;
    return Date(year, month, day);
}

// 'upload' a photo 
Photo* MediaFactory::uploadPhoto(const string& t){
    ifstream mediaFile;
    mediaFile.open("media/photos.txt");
    string temp, title, date, description, category;
    stringstream content;

    // We are assuming there is at least one record.
    // TBH not a great assumption to make
    cout<<"Searching for photo title: "<<t<<endl;
    while( getline(mediaFile, title)){
        if (t == title){
            getline(mediaFile, category);
            getline(mediaFile, date);
            getline(mediaFile, temp);
            while (temp!="!!endrecord!!"){
                content<<temp<<endl;
                getline(mediaFile, temp);
            }
            mediaFile.close();
            return new Photo(title, category, toDate(date), content.str());
        }

        // wrong title, advance to next photo
        while (temp!="!!endrecord!!"){
            getline(mediaFile, temp);
        }
    }

    mediaFile.close();
    return nullptr;
}

// create Criteria
Criteria* MediaFactory::dateCriteria(const Date& start, const Date& end){
  Date_Criteria* newD = new Date_Criteria(start, end);
  return newD;

}
Criteria* MediaFactory::categoryCriteria(const string& cat){

  Cat_Criteria* newCat = new Cat_Criteria(cat);
  return newCat;

}
Criteria* MediaFactory::dateAndCatCriteria(const Date& start, const Date& end, const string& cat){
  CandD_Criteria* newDC = new CandD_Criteria(start, end, cat);
  return newDC;
}

Album* MediaFactory::createAlbum(const string& title, const string& description){
  Album* newAlbum = new Album(title, description);
  return newAlbum;
}
