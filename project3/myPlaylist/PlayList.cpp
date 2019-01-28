#include "PlayList.h"
#include "Song.h"
#include "LinkedSet.h"
#include <iostream>
#include <vector>
// #include "PlayList.h"
// #include <iostream>
// #include "LinkedSet.h"
// #include "Node.h"
// #include <string>



PlayList::PlayList(){
	tail_ptr_ = nullptr;
}

PlayList::PlayList(const Song& a_song) : LinkedSet(){
	// LinkedSet<Song>();
	Node<Song>* song_node = new Node<Song>(a_song);
	tail_ptr_ = song_node;
	head_ptr_ = song_node; 
	// song_node
}

// PlayList::~PlayList(){
// 	unloop();
// }

PlayList::PlayList(const PlayList& a_play_list) : LinkedSet(a_play_list){
	tail_ptr_ = getPointerToLastNode();
} // copy constructor

bool PlayList::add(const Song& new_song){
	if(!contains(new_song)){
		Node<Song>* newSong = new Node<Song>(new_song);
		tail_ptr_->setNext(newSong);
		tail_ptr_ = newSong;
		return true;
		// tail_ptr_->setITem(new_song);
	}
	return false;
}

// bool PLayList::remove(const Song& a_song) override{
// 	if(contains(a_song)){
// 		Node<Song>* previous_ptr;
// 		Node<Song>* songPtr = getPointerTo(a_song, previous_ptr);
// 		if()
// 	}
// 	return false;
// }

Node<Song>* PlayList::getPointerToLastNode() const{
	if(head_ptr_ == nullptr)
		return nullptr;
	Node<Song>* pointer = head_ptr_;
	bool nullFound = false;
	while(!nullFound){
		if(pointer->getNext() == nullptr)
			nullFound = true;
		else
			pointer = pointer->getNext();
	}
	return pointer;

}

Node<Song>* PlayList::getPointerTo(const Song& target, Node<Song>*& previous_ptr) const{
	if(!contains(target))
		return nullptr;
	Node<Song>* pointerAt = head_ptr_;
	previous_ptr = nullptr;
	bool foundTarget = false;
	while(!foundTarget){
		if(pointerAt->getItem() == target)
			return pointerAt;
		else{
			previous_ptr = pointerAt;
			pointerAt = pointerAt->getNext();
		}
	}
	return nullptr;
}




