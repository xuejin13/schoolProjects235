/*
Author: JiaLe Qiu
Course: CSCI-235 Fall 2018
Instructor: Tiziana Ligorio
Assignment: Project 3

This is the implementation of "PlayList.h".
*/
#include <iostream>
#include <vector>
using namespace std;

#include "PlayList.h"

PlayList::PlayList(){
	tail_ptr_ = nullptr;
} //default constructor

PlayList::PlayList(const Song& a_song) {
	
	Node<Song>* songNode = new Node<Song>;
	songNode->setItem(a_song);
	item_count_++;
	tail_ptr_ = songNode;
	head_ptr_ = songNode;
} //parameterized constructor

PlayList::PlayList(const PlayList& a_play_list_): LinkedSet(a_play_list_) {
	//LinkedSet<Song>:: LinkedSet(a_play_list_);
	item_count_ = a_play_list_.item_count_;
	tail_ptr_ = getPointerToLastNode();
} //copy constructor;

Node<Song>* PlayList:: getPointerToLastNode() const
{
	//traverse the chain
	//get to the end, which would be == nullptr
	Node<Song>* curPtr = head_ptr_;
	
	if (head_ptr_ == nullptr) {
		return curPtr;
	}

	while ((*curPtr).getNext() != nullptr)  //traverse the chain until
	{					//it gets to last node.
		curPtr = (*curPtr).getNext();
	} //end while when the next pointer is a nullptr.
	
	return curPtr;

}

PlayList::~PlayList() {
	unloop();
	clear();
} //end destructor

bool PlayList:: add(const Song& new_song) { //override. ADD AT END OF CHAIN.
	Node<Song>* new_node_ptr = new Node<Song>;//(new_song);
	new_node_ptr->setItem(new_song);
	Node<Song>* cur_ptr = head_ptr_;

	if (!contains(new_song)) { //check if 'new_song' is a duplicate
	//cout << new_song.getTitle() << endl;
		if (head_ptr_ == nullptr) {
			tail_ptr_ = new_node_ptr;
			head_ptr_ = new_node_ptr;
			item_count_++;
		}
		else {	//if not empty

			//while ((*cur_ptr).getNext() != nullptr) {
			//	cur_ptr = (*cur_ptr).getNext();
			//}  traverse the chain until we get to one node before 			     tail_ptr_

			(*tail_ptr_).setNext(new_node_ptr);
			tail_ptr_ = new_node_ptr;
			
			item_count_++;
			//(*new_node_ptr).setNext(tail_ptr_); or 				  "setNext(nullptr);" ???
		}
	}
	else {
		return false;
	}
	return false;

}  //shall I create a last node with nullptr? since new_song replaces nullptr.

Node<Song>* PlayList:: getPointerTo(const Song& target, 
					Node<Song>*& previous_ptr) const 
{
	bool found = false;
	//previous_ptr = nullptr; already declared in function remove.

	Node<Song>* currentPtr = head_ptr_;

	while(!found && (currentPtr != nullptr)) {
		if (target == (*currentPtr).getItem()){ //==(currentPtr->getItem)
			found = true;
		}
		else {
			previous_ptr = currentPtr;
			currentPtr = (*currentPtr).getNext();
			
		}
	}

	if (found == false) {
		previous_ptr = nullptr;
		currentPtr = nullptr;
		return currentPtr;
	}
	return currentPtr;
}

bool PlayList:: remove(const Song& a_song) { //override
	Node<Song>* previous_ptr = head_ptr_;
	Node<Song>* entryNodePtr = getPointerTo(a_song, previous_ptr);

	//problem removing first song
	
	if (contains(a_song)) {
		if ((head_ptr_ != nullptr) && (entryNodePtr != nullptr)) {
			(*previous_ptr).setNext((*entryNodePtr).getNext());
			//setting previous_ptr to point to the next node of 				  entryNodePtr.
			//Now, we are gonna delete entryNodePtr.
			
			delete entryNodePtr;	// deletes what's stored in 							   currentPtr's 
			entryNodePtr = nullptr;	// memory address.
			item_count_--;
		}
		return true;
	}
	return false;
}

void PlayList:: loop() {
	(*tail_ptr_).setNext(head_ptr_);
}

void PlayList:: unloop() {
	(*tail_ptr_).setNext(nullptr);
}

void PlayList::displayPlayList() {
	vector<Song> arr = toVector();
	
	for(size_t i = 0; i < arr.size(); i++){
		cout << "* Title: " << arr.at(i).getTitle() <<
		" * Author: " << arr.at(i).getAuthor() <<
			" * Album: " << arr.at(i).getAlbum() <<
		" *" << endl;
	}
	cout << "End of playlist" << endl;
}   //end displayPlayList




