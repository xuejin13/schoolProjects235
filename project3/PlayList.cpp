// Author: Xuejin Gao
// Course: CSCI235
// Instructor: Tiziana Ligorio
// Assignment: Project 3

#include "PlayList.h"
#include "Song.h"
#include "LinkedSet.h"
#include <iostream>
#include <vector>
using namespace std;

//constructors
PlayList::PlayList(){
  tail_ptr_ = nullptr;
}

PlayList::PlayList(const Song& a_song){
  Node<Song>* songNode = new Node<Song>;
  songNode->setItem(a_song);
  tail_ptr_ = songNode;
  head_ptr_ = songNode; 
  item_count_++;
}

PlayList::PlayList(const PlayList& a_play_list) : LinkedSet(a_play_list){
  tail_ptr_ = getPointerToLastNode();
  item_count_ = a_play_list.item_count_;
}

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

PlayList::~PlayList(){
  // tail_ptr_ = nullptr;
  // delete tail_ptr_;
  unloop();
  clear();
}

bool PlayList::add(const Song& new_song) {
  if(!contains(new_song)){
    Node<Song>* newSong = new Node<Song>(new_song);
    if(head_ptr_ == nullptr)
      head_ptr_ = newSong;
    tail_ptr_->setNext(newSong);
    tail_ptr_ = newSong;
    item_count_++;
    return true;
  }
  return false;
}

Node<Song>*PlayList::getPointerTo(const Song& target, Node<Song>*& previous_ptr) const{
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

bool PlayList::remove(const Song& a_song){
  if(contains(a_song)){
    Node<Song>* previous_ptr;
    Node<Song>* selectedSong = getPointerTo(a_song, previous_ptr);
    if(previous_ptr == nullptr)
      head_ptr_ = selectedSong->getNext();
    else
      previous_ptr->setNext(selectedSong->getNext());
    selectedSong->setNext(nullptr);
    delete selectedSong;
    selectedSong = nullptr;
    // previous_ptr = nullptr;
    // delete previous_ptr;
    item_count_--;
  }
  return false;
}

void PlayList::loop(){
  //traversing through all the songs
  tail_ptr_->setNext(head_ptr_);
}

void PlayList::unloop(){
  tail_ptr_->setNext(nullptr);
}

void PlayList::displayPlayList(){
  vector<Song>arr = toVector();
  for(size_t i = 0; i < arr.size(); i++){
  cout << "* Title: " <<  arr[i].getTitle() << " * Author: " 
                      << arr[i].getAuthor() << " * Album: " 
                      << arr[i].getAlbum() << " * " << endl;
	}
	cout << "End of playlist\n" << endl;
}
