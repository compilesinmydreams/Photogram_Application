objects = main.o View.o AlbumCreator.o PhotoGram.o MediaFactory.o Criteria.o Album.o Photo.o Date.o

a4: $(objects)
	g++ -o a4 $(objects)

main.o: main.cc
	g++ -c main.cc 

View.o: View.h View.cc 
	g++ -c View.cc

AlbumCreator.o: AlbumCreator.h AlbumCreator.cc 
	g++ -c AlbumCreator.cc


PhotoGram.o: PhotoGram.h PhotoGram.cc
	g++ -c PhotoGram.cc

MediaFactory.o: MediaFactory.h MediaFactory.cc
	g++ -c MediaFactory.cc

Criteria.o: Criteria.cc Criteria.h
	g++ -c Criteria.cc

Album.o: Album.cc Album.h
	g++ -c Album.cc
	
Photo.o: Photo.cc Photo.h 
	g++ -c Photo.cc

Date.o: Date.cc Date.h 
	g++ -c Date.cc

clean:
	rm -f a4 *.o	