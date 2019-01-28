#include "PlayList.h"
#include "Song.h"
#include "LinkedSet.h"
#include <iostream>
#include <vector>
using namespace std;

PlayList::PlayList(){
  tail_ptr_ = new Node<Song>();
}


PlayList::PlayList(const Song& a_song){
  //create a new node for a_song and have tail_ptr_ and head_ptr_ point to it
  head_ptr_ = new Node<Song>(a_song);
  tail_ptr_ = head_ptr_;
  item_count_++;
}

PlayList::PlayList(const PlayList& a_play_list){
  Node<Song>* temp = a_play_list.head_ptr_;  // Points to nodes in original chain
  head_ptr_ = temp;
  tail_ptr_ = head_ptr_;
  item_count_++;

  if (temp == nullptr)
     head_ptr_ = nullptr;  // Original Set is empty
  else
  {
     // Copy first node
     head_ptr_ = new Node<Song>();
     head_ptr_->setItem(temp->getItem());

     // Copy remaining nodes
     Node<Song>* new_chain_ptr = head_ptr_;      // Points to last node in new chain
     temp = temp->getNext();     // Advance original-chain pointer

     while (temp != nullptr)
     {
        // Get next item from original chain
        Song nextItem = temp->getItem();

        // Create a new node containing the next item
        Node<Song>* new_node_ptr = new Node<Song>(nextItem);

        // Link new node to end of new chain
        new_chain_ptr->setNext(new_node_ptr);

        // Advance pointer to new last node
        new_chain_ptr = new_chain_ptr->getNext();

        // Advance original-chain pointer
        temp = temp->getNext();
     }  // end while

     new_chain_ptr->setNext(nullptr);  // Flag end of chain
  }  // end if
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
  Node<Song> *last_node = new Node<Song>(tail_ptr_->getItem(),tail_ptr_->getNext());
    while(last_node->getNext() != nullptr){
      last_node->setItem(last_node->getNext()->getItem());
      last_node->setNext(last_node->getNext());
    }
  return last_node;
}
Node<Song>*PlayList::getPointerTo(const Song& target, Node<Song>*& previous_ptr) const{
  //unlike in LinkedSet which looks at the first node, we're looking for the previous one
  //therefore we need to look at the position of the node
  bool found = false;
  Node<Song>*cur_ptr = head_ptr_;
  int position = 0;
  while(!found && (cur_ptr != nullptr)){
    if (position <= 1){
      previous_ptr = head_ptr_;
    }
    else{
      previous_ptr = previous_ptr->getNext();
    }
    //this is the same as LinkedSet

    if(target == cur_ptr->getItem()){
      found = true;
    }
    else{
      cur_ptr = cur_ptr->getNext();
    }
    position++;
  }
  return cur_ptr;
}
bool PlayList::add(const Song& new_song) {
  //create a new node for song
  Node<Song>*last = new Node<Song>(new_song);
  /*
  //last-> ;
  last->getPointerToLastNode(tail_ptr_);
  tail_ptr_= last;
  */
  tail_ptr_->setNext(last);
  tail_ptr_ = tail_ptr_->getNext();
  item_count_ += 1;
  return true;
}
bool PlayList::remove(const Song& a_song){
    //post: previous_ptr is null if target is not in PlayList or if target is the
    Node<Song>*prev_ptr = new Node<Song>();
    Node<Song>*node_to_delete_ptr = getPointerTo(a_song,prev_ptr);
    // first node, otherwise it points to the node preceding target
    bool canremoveitem = !isEmpty() && (node_to_delete_ptr != nullptr);
    // return: either a pointer to the node containing target
    if(canremoveitem){
      //If this is first node
      if (node_to_delete_ptr == head_ptr_) {
  			head_ptr_ = head_ptr_->getNext();
  		}
      //if it's the last node
      else if (node_to_delete_ptr == tail_ptr_) {
        tail_ptr_ = prev_ptr;
        prev_ptr->setNext(nullptr);
      }
      //if its in the middle
      else {
        prev_ptr->setNext( node_to_delete_ptr->getNext() );
      }
      // or the null pointer if the target is not in the PlayList.
      node_to_delete_ptr->setNext(nullptr);
  		delete node_to_delete_ptr;
  		node_to_delete_ptr = nullptr;
  		item_count_--;
    }
    return canremoveitem;
}

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
  vector<Song>arr_song = toVector();
  for(int i = 0; i < getCurrentSize(); i++){
  cout << "* Title: " <<  arr_song[i].getTitle() << " * Author: " << arr_song[i].getAuthor() << " * Album: " << arr_song[i].getAlbum() << " * " << endl;
	}

	cout << "End of playlist\n" << endl;

}
