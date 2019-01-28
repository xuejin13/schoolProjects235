// Name: Xuejin Gao (the beast)
// Class: CSCI 235
// Professor: Tiziana Ligorio
// Description: Playlist cpp

#include <iostream>
#include <vector>
using namespace std;

#include "PlayList.h"

PlayList::PlayList(){}

PlayList::PlayList(const Song& a_song){
	playlist_.add(a_song);
}

int PlayList::getNumberOfSongs() const{
	return playlist_.getCurrentSize();
}

bool PlayList::isEmpty() const{
	return playlist_.isEmpty();
}

bool PlayList::addSong(const Song& new_song){
	return playlist_.add(new_song);
}

bool PlayList::removeSong(const Song& a_song){
	return playlist_.remove(a_song);
}

void PlayList::clearPlayList(){
	playlist_.clear();
}

void PlayList::displayPlayList() const{
	vector<Song> arr = playlist_.toVector();
	// for(Song song : arr){
	// 	cout << "* Title: " << song.getTitle() << 
	// 	" * Author: " << song.getAuthor() <<
	// 	" * Album: " << song.getAlbum() <<
	// 	" *";
	// }

	for(size_t i = 0; i < arr.size(); i++){
		cout << "* Title: " << arr.at(i).getTitle() << 
		" * Author: " << arr.at(i).getAuthor() <<
		" * Album: " << arr.at(i).getAlbum() <<
		" *" << endl;
	}
	cout << "End of playlist" << endl;
}



