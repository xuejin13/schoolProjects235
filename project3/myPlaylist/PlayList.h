//Xuejin Gao
//Tiziana Ligorio

#ifndef PLAYLIST_H
#define PLAYLIST_H

// #pragma once
#include <iostream>
#include <string>
#include "LinkedSet.h"
#include "Song.h"

class PlayList : public LinkedSet<Song> {
	private:
		Node<Song>* tail_ptr_;
		Node<Song>* getPointerToLastNode() const;
		Node<Song>* getPointerTo(const Song& target, Node<Song>*& previous_ptr) const;
	public:
		PlayList();
		PlayList(const Song& a_song);
		~PlayList();
		PlayList(const PlayList& a_play_list); // copy constructor
		bool add(const Song& new_song) override;
		bool remove(const Song& a_song) override;
		void loop();    
   		void unloop();
   		void displayPlayList();
};

#include "PlayList.cpp"
#endif
