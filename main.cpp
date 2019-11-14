/*
Author: Devin Leigh
Date: 11/13
Program: class project, media database using multiple classes
 */


#include <iostream>
#include <vector>
#include <cstring>
#include "media.h"
#include "movie.h"
#include "game.h"
#include "music.h"

using namespace std;

void add(vector<Media*>* media){ //add media to vector
  char input[12];
  cout << "What media would you like to add (movie, game, music)? ";
  cin.get(input, 12);
  cin.clear();
  cin.ignore(1000, '\n');
  if(strcmp(input, "movie") == 0){ //if input is movie
    Movie* movie = new Movie(); //creates new movie object
    cout << "Enter title: ";
    cin.get(movie->getTitle(), 50);
    cin.clear();
    cin.ignore(1000, '\n');
    cout << "Enter year: ";
    cin >> *movie->getYear();
    cin.clear();
    cin.ignore(1000, '\n');
    cout << "Enter director: ";
    cin.get(movie->getDirector(), 20);
    cin.clear();
    cin.ignore(1000, '\n');
    cout << "Enter runtime (minutes): ";
    cin >> *movie->getRuntime();
    cin.clear();
    cin.ignore(1000, '\n');
    cout << "Enter rating: ";
    cin >> *movie->getRating();
    cin.clear();
    cin.ignore(1000, '\n');
    media->push_back(movie); //adds movie to media vector
  }else if(strcmp(input, "game") == 0){ //if input is game
    Game* game = new Game();//new Game object
    cout << "Enter title: ";
    cin.get(game->getTitle(), 50);
    cin.clear();
    cin.ignore(10000, '\n');
    cout << "Enter year: ";
    cin >> *game->getYear();
    cin.clear();
    cin.ignore(10000,'\n');
    cout << "Enter publisher: ";
    cin.get(game->getPublisher(), 20);
    cin.clear();
    cin.ignore(10000, '\n');
    cout << "Enter rating: ";
    cin >> *game->getRating();
    cin.clear();
    cin.ignore(10000, '\n');
    media->push_back(game); //add game to the media vector
  }else if(strcmp(input, "music") == 0){ //if input is music
    Music* music = new Music(); //new Music object
    cout << "Enter title: ";
    cin.get(music->getTitle(), 50);
    cin.clear();
    cin.ignore(10000, '\n');
    cout << "Enter year: ";
    cin >> *music->getYear();
    cin.clear();
    cin.ignore(10000,'\n');
    cout << "Enter musician: ";
    cin.get(music->getMusician(), 20);
    cin.clear();
    cin.ignore(10000, '\n');
    cout << "Enter length (minutes): ";
    cin >> *music->getLength();
    cin.clear();
    cin.ignore(10000, '\n');
    cout << "Enter label: ";
    cin.get(music->getLabel(), 20);
    cin.clear();
    cin.ignore(10000, '\n');
    media->push_back(music); //add music to the media vector
  }else{
    cout << "Type of media not supported" << endl;
  }
}

void search(char* title, vector<Media*>* media){ //search for media by title
  vector<Media*>::iterator i;//create iterator for media array
  for(i = media->begin(); i != media->end(); ++i){ //for loop through iterator
    if(strcmp(title, (*i)->getTitle()) == 0){ 
      cout << endl << "Title: " << (*i)->getTitle() << endl;//print title
      cout << "Year: " << *(*i)->getYear() << endl;//print year
      if((*i)->getType() == 0){//if the type return 0 it is a Movie
	//print out the specific fields
	cout << "Director: " << dynamic_cast<Movie*>(*i)->getDirector() << endl;//dynamic cast the *i to a movie
	cout << "Runtime: " << *dynamic_cast<Movie*>(*i)->getRuntime() << endl;
	cout << "Rating: " << *dynamic_cast<Movie*>(*i)->getRating() << endl << endl;
      }else if((*i)->getType() == 1){//if the type returns a 1 than it is a game
	cout << "Publisher: " << dynamic_cast<Game*>(*i)->getPublisher() << endl;
	cout << "Rating: " << *dynamic_cast<Game*>(*i)->getRating() << endl << endl;
      }else if((*i)->getType() == 2){//if the type returns a 2 than it is music
	cout << "Musician: " << dynamic_cast<Music*>(*i)->getMusician() << endl;
	cout << "Length: " << *dynamic_cast<Music*>(*i)->getLength() << endl;
	cout << "Label: " << dynamic_cast<Music*>(*i)->getLabel() << endl << endl;
      }
    }
  }
}

void del(char* title, vector<Media*>* media){ //delete by title
  char input[5];//char for yes or no
  //same as search
  vector<Media*>::iterator i; //iterator through media
  for(i = media->begin(); i != media->end(); ++i){//for loop through the media array
    if(strcmp(title, (*i)->getTitle()) == 0){
      cout << endl << "Title: " << (*i)->getTitle() << endl;
      cout << "Year: " << *(*i)->getYear() << endl;
      if((*i)->getType() == 0){
	cout << "Director: " << dynamic_cast<Movie*>(*i)->getDirector() << endl;
	cout << "Runtime: " << *dynamic_cast<Movie*>(*i)->getRuntime() << endl;
	cout << "Rating: " << *dynamic_cast<Movie*>(*i)->getRating() << endl << endl;
      }else if((*i)->getType() == 1){
	cout << "Publisher: " << dynamic_cast<Game*>(*i)->getPublisher() << endl;
	cout << "Rating: " << *dynamic_cast<Game*>(*i)->getRating() << endl << endl;
      }else if((*i)->getType() == 2){
	cout << "Musician: " << dynamic_cast<Music*>(*i)->getMusician() << endl;
	cout << "Length: " << *dynamic_cast<Music*>(*i)->getLength() << endl;
	cout << "Label: " << dynamic_cast<Music*>(*i)->getLabel() << endl << endl;
      }
  
      cout << "Do you want to delete this item? 'yes' or 'no': ";
      cin.get(input, 5); //yes or no into the input cstring
      cin.clear();
      cin.ignore(10000, '\n');
      if(strcmp(input, "yes") == 0){//if input is yes
	delete *i; //delete the object
	i = media->erase(i); //delete the memory in the media array
	return;
      }
    }
  }
}

void search(int year, vector<Media*>* media){ //search for media by year
  vector<Media*>::iterator i;//create iterator for media array
  for(i = media->begin(); i != media->end(); ++i){ //for loop through iterator
    if(year == *(*i)->getYear()){ 
      cout << endl << "Title: " << (*i)->getTitle() << endl;//print title
      cout << "Year: " << *(*i)->getYear() << endl;//print year
      if((*i)->getType() == 0){//if the type return 0 it is a Movie
	//print out the specific fields
	cout << "Director: " << dynamic_cast<Movie*>(*i)->getDirector() << endl;//dynamic cast the *i to a movie
	cout << "Runtime: " << *dynamic_cast<Movie*>(*i)->getRuntime() << endl;
	cout << "Rating: " << *dynamic_cast<Movie*>(*i)->getRating() << endl << endl;
      }else if((*i)->getType() == 1){//if the type returns a 1 than it is a game
	cout << "Publisher: " << dynamic_cast<Game*>(*i)->getPublisher() << endl;
	cout << "Rating: " << *dynamic_cast<Game*>(*i)->getRating() << endl << endl;
      }else if((*i)->getType() == 2){//if the type returns a 2 than it is music
	cout << "Musician: " << dynamic_cast<Music*>(*i)->getMusician() << endl;
	cout << "Length: " << *dynamic_cast<Music*>(*i)->getLength() << endl;
	cout << "Label: " << dynamic_cast<Music*>(*i)->getLabel() << endl << endl;
      }
    }
  }
}

void del(int year, vector<Media*>* media){ //delete by title
  char input[5];//char for yes or no
  //same as search
  vector<Media*>::iterator i; //iterator through media
  for(i = media->begin(); i != media->end(); ++i){//for loop through the media array
    if(year == *(*i)->getYear()){
      cout << endl << "Title: " << (*i)->getTitle() << endl;
      cout << "Year: " << *(*i)->getYear() << endl;
      if((*i)->getType() == 0){
	cout << "Director: " << dynamic_cast<Movie*>(*i)->getDirector() << endl;
	cout << "Runtime: " << *dynamic_cast<Movie*>(*i)->getRuntime() << endl;
	cout << "Rating: " << *dynamic_cast<Movie*>(*i)->getRating() << endl << endl;
      }else if((*i)->getType() == 1){
	cout << "Publisher: " << dynamic_cast<Game*>(*i)->getPublisher() << endl;
	cout << "Rating: " << *dynamic_cast<Game*>(*i)->getRating() << endl << endl;
      }else if((*i)->getType() == 2){
	cout << "Musician: " << dynamic_cast<Music*>(*i)->getMusician() << endl;
	cout << "Length: " << *dynamic_cast<Music*>(*i)->getLength() << endl;
	cout << "Label: " << dynamic_cast<Music*>(*i)->getLabel() << endl << endl;
      }
  
      cout << "Do you want to delete this item? 'yes' or 'no': ";
      cin.get(input, 5); //yes or no into the input cstring
      cin.clear();
      cin.ignore(10000, '\n');
      if(strcmp(input, "yes") == 0){//if input is yes
	delete *i; //delete the object
	i = media->erase(i); //delete the memory in the media array
	return;
      }
    }
  }
}

int main()
{
  bool exit = false;//run condition
  vector<Media*> mediaArray;
  char input[7]; //input for action decision
  char input2[50]; //title input
  int input3; //year input
  while(!exit){//running loop
    cout << "Do you want to add, search, delete, or exit:";
    cin.get(input, 7); //gets input for first decition
    cin.clear();
    cin.ignore(10000, '\n');
    if(strcmp(input, "add") == 0){//if input is add
      add(&mediaArray); 
    }else if(strcmp(input, "search") == 0){//if input is search
      cout << "Do you want to enter a year or a title?:";
      cin.get(input, 7);//stores what function of search should be run in cstring
      cin.clear();
      cin.ignore(10000, '\n');
      if(strcmp(input, "title") == 0){//if title
	cout << "Title: ";
	cin.get(input2, 50);//enter desired title
	cin.clear();
	cin.ignore(10000, '\n');
	search(input2, &mediaArray);//search using cstring search
      }else if(strcmp(input, "year") == 0){//if year
	cout << "Year: ";
	cin >> input3;//enter desired year
	cin.clear();
	cin.ignore(10000, '\n');
	search(input3, &mediaArray);//search using int search
      }
    }else if(strcmp(input, "delete") == 0){//if input is delete
      cout << "Do you want to enter a year or a title?:";
      cin.get(input, 7);//
      cin.clear();
      cin.ignore(10000, '\n');
      if(strcmp(input, "title") == 0){
	cout << "Title: ";
	cin.get(input2, 50);
	cin.clear();
	cin.ignore(10000, '\n');
	del(input2, &mediaArray);//deletes using title del
      }else if(strcmp(input, "year") == 0){
	cout << "Year: ";
	cin >> input3;
	cin.clear();
	cin.ignore(10000, '\n');
	del(input3, &mediaArray);//deletes using int del
      }
    }
    else if(strcmp(input, "exit") == 0){//if input is exit
      exit = true; //stop the run loop
    }
    else{ //if none
      cout << "Cannot tell what you are looking for." << endl;
    }
  }
  return 0; //end program
}
