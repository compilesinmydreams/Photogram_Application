#ifndef ALBUM_H
#define ALBUM_H
#include "Array.h"
#include "Criteria.h"
using namespace std;
class Album{
  friend ostream& operator<<(ostream&, const Album&);
  public:
    Album(const string& title , const string& description);
    bool equals(const string& title)const;
    void addPhoto(Photo* newPhoto);
    Photo* getPhoto(int i)const;
    int size()const;
    void print(ostream&) const;
    void display(ostream&) const;

  private:
    string title, description;
    Array<Photo*> photoArray;
};
#endif
