#include "PlayList.h"
#include "Song.h"
#include "LinkedSet.h"
#include <iostream>
#include <vector>
using namespace std;

PlayList::PlayList(){
  tail_ptr_ = nullptr;
}


PlayList::PlayList(const Song& a_song){
  //create a new node for a_song and have tail_ptr_ and head_ptr_ point to it
  Node<Song>* song_node = new Node<Song>(a_song);
  tail_ptr_ = song_node;
  head_ptr_ = song_node; 
  item_count_++;
  //song_node = nullptr;
  // delete song_node;
}

PlayList::PlayList(const PlayList& a_play_list) : LinkedSet(a_play_list){
  tail_ptr_ = a_play_list.getPointerToLastNode();
}

PlayList::~PlayList(){
  /*
  //clear function of LinkedBag
  Node<Song>*nodeToDeletePtr = tail_ptr_;
  while(tail_ptr_ != nullptr){
    tail_ptr_ = tail_ptr_->getPointerToLastNode();
    //nodeToDeletePtr->setNext(nullptr);
    delete nodeToDeletePtr;
    nodeToDeletePtr = tail_ptr_;
  }
  item_count_=0;
  */
  delete tail_ptr_;
}

Node<Song>*PlayList::getPointerToLastNode() const{
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

bool PlayList::add(const Song& new_song) {
  if(!contains(new_song)){
		Node<Song>* newSong = new Node<Song>(new_song);
		tail_ptr_->setNext(newSong);
		tail_ptr_ = newSong;
		return true;
		// tail_ptr_->setITem(new_song);
	}
	return false;
}

bool PlayList::remove(const Song& a_song){
  if(contains(a_song)){
    Node<Song>* previous_ptr;
    Node<Song>* selectedSong = getPointerTo(a_song, previous_ptr);
    previous_ptr->setNext(selectedSong->getNext());
    selectedSong->setNext(nullptr);
    delete selectedSong;
    selectedSong = nullptr;
    item_count_--;
  }
  return false;
}
//     //post: previous_ptr is null if target is not in PlayList or if target is the
//     Node<Song>*prev_ptr = new Node<Song>();
//     Node<Song>*node_to_delete_ptr = getPointerTo(a_song,prev_ptr);
//     // first node, otherwise it points to the node preceding target
//     bool canremoveitem = !isEmpty() && (node_to_delete_ptr != nullptr);
//     // return: either a pointer to the node containing target
//     if(canremoveitem){
//       //If this is first node
//       if (node_to_delete_ptr == head_ptr_) {
//   			head_ptr_ = head_ptr_->getNext();
//   		}
//       //if it's the last node
//       else if (node_to_delete_ptr == tail_ptr_) {
//         tail_ptr_ = prev_ptr;
//         prev_ptr->setNext(nullptr);
//       }
//       //if its in the middle
//       else {
//         prev_ptr->setNext( node_to_delete_ptr->getNext() );
//       }
//       // or the null pointer if the target is not in the PlayList.
//       node_to_delete_ptr->setNext(nullptr);
//   		delete node_to_delete_ptr;
//   		node_to_delete_ptr = nullptr;
//   		item_count_--;
//     }
//     return canremoveitem;
// }

void PlayList::loop(){
  //traversing through all the songs
  tail_ptr_->setNext(head_ptr_);
}

void PlayList::unloop(){
  tail_ptr_->setNext(nullptr);
}
/*
bool PlayList::contains(const Song& anEntry)override{
  Node<Song>*new_ptr = new Node<Song>();
  return (getPointerTo(anEntry) != nullptr);
  new_ptr->setNext(nullptr);
  delete new_ptr;
  new_ptr = nullptr;
}
*/

void PlayList::displayPlayList(){
  vector<Song>arr = toVector();
  for(size_t i = 0; i < arr.size(); i++){
  cout << "* Title: " <<  arr_song[i].getTitle() << " * Author: " 
                      << arr_song[i].getAuthor() << " * Album: " 
                      << arr_song[i].getAlbum() << " * " << endl;
	}
	cout << "End of playlist\n" << endl;
}
