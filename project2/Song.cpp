// Name: Xuejin Gao (the beast)
// Class: CSCI 235
// Professor: Tiziana Ligorio
// Description: Song cpp 

#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "Song.h"
// template<class ItemType>
Song::Song(){}

// template<class ItemType>
Song::Song(
	const string& title, 
	const string& author, 
	const string& album){

	title_ = title;
	author_ = author;
	album_ = album;
}

// template<class ItemType>
// sets the title of a song
void Song::setTitle(string title){
	title_ = title;
}

// template<class ItemType>
// sets the author of a song
void Song::setAuthor(string author){
	author_ = author;
}

// template<class ItemType>
// sets the album of a song
void Song::setAlbum(string album){
	album_ = album;
}

// post: method for a song
// return string, thats a title for a song
string Song::getTitle() const{
	return title_;
}

// post: method for a song
// return string, thats a author for a song
string Song::getAuthor() const{
	return author_;
}

// post: method for a song
// return string, thats a album for a song
string Song::getAlbum() const{
	return album_;
}

bool operator==(const Song& lhs, const Song& rhs){
	bool title = lhs.getTitle() == rhs.getTitle();
	bool author = lhs.getAuthor() == rhs.getAuthor();
	bool album = lhs.getAlbum() == rhs.getAlbum();
	return title && author && album;
}
