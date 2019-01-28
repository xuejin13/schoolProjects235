// Name: Xuejin Gao (the beast)
// Class: CSCI 235
// Professor: Tiziana Ligorio
// Description: Set cpp

#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "Set.h"

// constructor
template<class ItemType>
Set<ItemType>::Set(){
	item_count_ = 0;
	max_items_ = DEFAULT_SET_SIZE;
}

//return the size of the set
template<class ItemType>
int Set<ItemType>::getCurrentSize() const{
	return item_count_;
}

// return a boolean, if it is empty
template<class ItemType>
bool Set<ItemType>::isEmpty() const{
	return item_count_ == 0;
}

//return bool if it completed the add
template<class ItemType>
bool Set<ItemType>::add(const ItemType& newEntry){
	if(getIndexOf(newEntry) != -1)
		return false;
	if(item_count_ < max_items_){
		items_[item_count_] = newEntry;
		item_count_++;
		return true;
	}
	return false;
}

template<class ItemType>
bool Set<ItemType>::remove(const ItemType& anEntry){
	// int location = getIndexOf(anEntry);
	// if(location == -1)
	// 	return false;
	// bool first = false;
	// for(int i = 0; i < max_items_; i++)
	int located_index = getIndexOf(anEntry);
	bool can_remove_item = !isEmpty() && (located_index > -1);
	if (can_remove_item)
		{
		item_count_--;
		items_[located_index] = items_[item_count_];
		} // end if
	return can_remove_item;
}

template<class ItemType>
void Set<ItemType>::clear(){
	item_count_ = 0;
}

template<class ItemType>
bool Set<ItemType>::contains(const ItemType& anEntry) const{
	return getIndexOf(anEntry) > -1;
}

template<class ItemType>
vector<ItemType> Set<ItemType>::toVector() const{
	vector<ItemType> bag_contents;
	for (int i = 0; i < item_count_; i++)
		bag_contents.push_back(items_[i]);

 return bag_contents;
}

template<class ItemType>
int Set<ItemType>::getIndexOf(const ItemType& target) const{
	for(int i = 0; i < item_count_; i++)
		if(items_[i] == target)
			return i;
	return -1;
}

