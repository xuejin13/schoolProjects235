// Name: Xuejin Gao (the beast)
// Class: CSCI 235
// Professor: Tiziana Ligorio
// Description: Playlist Interface

#ifndef PLAYLIST_H
#define PLAYLIST_H
#include <string>
#include <vector>

// included program that allows the playlist to work
#include "Set.h"
#include "Song.h"

//class
class PlayList{
	private:
    	Set<Song> playlist_;
	public:
		PlayList();
		PlayList(const Song& a_song);
		int getNumberOfSongs() const;
		bool isEmpty() const;
		bool addSong(const Song& new_song);
		bool removeSong(const Song& a_song);
		void clearPlayList();
		void displayPlayList() const;
};
//end class
#endif /* SET_INTERFACE_H_ */

