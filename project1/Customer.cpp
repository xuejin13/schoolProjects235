// Xuejin Gao
// Tiziana Ligorio
// CSCI 235
// This is the impementation for all the functions for customer.h


#include <iostream>
using namespace std;

#include "Customer.hpp"
#include "GeniusBar.hpp"

//just define the functions

Customer::Customer(){
    name_ = "";
    defective_device_ = "";
    wait_time_ = 0;
}  
//default constructor

Customer::Customer(string name, string device, int wait_time){
    name_ = name;
    defective_device_ = device;
    wait_time = wait_time;
}
//parameterized constructor

//return: name_
string Customer::getName(){
    return name_;
}

//return: defective_device_
string Customer::getDevice(){
    return defective_device_;
}

//return: wait_time_
int Customer::getWaitTime(){
    return wait_time_;
}

//post: wait_time_ = new_wait_time
void Customer::updateWaitTime(int new_wait_time){
    //updatess the wait time for all of the customers
    wait_time_ = new_wait_time;
}



