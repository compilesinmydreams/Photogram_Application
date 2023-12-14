
#include "AlbumCreator.h"
#include "View.h"
#include <fstream>
#include <vector>

#define MENU_ITEMS 12

const string AlbumCreator::menu[MENU_ITEMS] ={
    "Add Album",
    "Delete Album",
    "Print all Albums",
    "Display Album",
    "Print all photos",
    "Display photo" ,
    "Get photos by date range",
    "Get photos by category",
    "Get photos by date and category",
    "Print current photo list" ,
    "Display current photo list",
    "Add current photo list to Album",
};

void AlbumCreator::launch(){
    initFromFile();
    int choice = -1;

    while (true){
        choice = -1;
        view.mainMenu(menu, MENU_ITEMS, choice);
        if (choice == 0)break;
        switch (choice)
        {   case 1: addAlbum(); break;
            case 2: deleteAlbum(); break;
            case 3: printAlbums(); break;
            case 4: displayAlbum(); break;
            case 5: printPhotos(); break;
            case 6: displayPhoto(); break;
            case 7: getPhotosByDate(); break;
            case 8: getPhotosByCat(); break;
            case 9: getPhotosByCandD(); break;
            case 10: printCurrentPhotoList(); break;
            case 11: displayCurrentPhotoList(); break;
            case 12: addToAlbum(); break;
        }
        
    }

    cout << "Good-bye!"<<endl;
}


/*
Normally something like this would be in your PhotoFactory class, 
so that all this complexity does not hpge to be hard-coded in
your program. We are keeping it simple, and I wrote it for you. 
*/
void AlbumCreator::initFromFile(){
    ifstream photoTitles;
    photoTitles.open("media/phototitles.txt");
    string photoTitle;
    while( getline(photoTitles, photoTitle)){
        pg.uploadPhoto(photoTitle);
    }
    photoTitles.close();

}

void AlbumCreator::addAlbum(){
    string title, desc;
    view.promptAlbum(title, desc);
    pg.addAlbum(title, desc);
}

void AlbumCreator::deleteAlbum(){
    int ind;
    int numChoices = pg.printAlbums(view);
    view.promptChoice(ind, numChoices);
    pg.displayAlbum(ind, view);
    pg.deleteAlbum(ind);
}

void AlbumCreator::printAlbums(){
    cout<<"Printing all Albums: "<<endl;
    pg.printAlbums(view);
}

void AlbumCreator::displayAlbum(){
    int choice = - 1;
    int numChoices = pg.printAlbums(view);
    view.promptChoice(choice, numChoices);
    pg.displayAlbum(choice, view);
}

void AlbumCreator::printPhotos(){
    pg.printPhotos(view);
}
void AlbumCreator::displayPhoto(){
    int choice = - 1;
    int numChoices = pg.printPhotos(view);
    view.promptChoice(choice, numChoices);
    pg.displayPhoto(choice, view);
}

void AlbumCreator::getPhotosByCandD(){
    string cat;
    Date before, after;
    view.promptCategory(cat);
    view.promptDates(after, before);
    const Criteria* crit = mf.dateAndCatCriteria(after, before, cat);
    cout<<*crit<<endl;
    currentPhotos.clear();
    pg.getPhotos(*crit, currentPhotos);
    delete crit;
} 

void AlbumCreator::getPhotosByCat(){
    string cat;
    view.promptCategory(cat);
    const Criteria* crit = mf.categoryCriteria(cat);
    cout<<*crit<<endl;
    currentPhotos.clear();
    pg.getPhotos(*crit, currentPhotos);
    delete crit;
    
} 

void AlbumCreator::getPhotosByDate(){
    Date before, after;
    view.promptDates(before, after);
    const Criteria* crit = mf.dateCriteria(before, after);
    cout<<*crit<<endl;    
    currentPhotos.clear();
    pg.getPhotos(*crit, currentPhotos);
    delete crit;
}


void AlbumCreator::printCurrentPhotoList(){
    cout<<"Photo list size: "<<currentPhotos.size()<<endl;
    view.printPhotos(currentPhotos);
} 

void AlbumCreator::displayCurrentPhotoList(){
    for (int i = 0; i < currentPhotos.size(); ++i){
        view.displayPhoto(*currentPhotos[i]);
    }
}

void AlbumCreator::addToAlbum(){
    int choice = - 1;
    int numChoices = pg.printAlbums(view);
    view.promptChoice(choice, numChoices);
    pg.displayAlbum(choice, view);
    pg.addToAlbum(choice, currentPhotos);
}
