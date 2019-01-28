#include "SortingTests.hpp"
#include <iostream>
using namespace std;
/*
Name: Angela Lim
Professor: Tiziana Ligorio
Project Description: Implements 3 sorting functions: Insertion, Selction and Merge
*/

void selectionSort(int a[], size_t size){
  //min_index is the smallest element in search
  int min_index;
  //loops through to select elements to go in order
  for(int i = 0; i < size-1; i++){
    //set the min_index as current index
    min_index = i;
    //loops through the rest of the array to find an element smaller than the min_index
    for(int j = i+1; j < size; j++){
      if(a[j] < a[min_index]){
        min_index = j;
      }
    }
    //if current element is not in the right place, swap it
    if(min_index!=i){
    swap(a[min_index],a[i]);
    }
  }
}


void insertionSort(int a[], size_t size){
//searches for correct place of current element
  for(int i = 1; i < size; i++){
    int j = i;
//moves element behind by one index until an element is smaller than the current element
    while(j > 0 && a[j-1] > a[j]){

      swap(a[j], a[j-1]);
      j--;
    }

  }
}
//helper function for  mergeSort
void merge(int theArray[], int first, int mid, int last)
{
  //counter variables
  int i,j,k;

  int leftArr = mid - first + 1;
  int rightArr = last - mid;
  //temp array for left and right halves
  int *L = new int[leftArr];
  int *R = new int [rightArr];
  //copying elements into temp arrays
  for (int i = 0; i < leftArr; i++){
    L[i] = theArray[first + i];
  }
  for(int j = 0; j < rightArr; j++){
    R[j] = theArray[mid + 1 + j];
  }
  //i and j are indexes of their respective temp arrays
  //k is the index for the merged one
  i = 0;
  j = 0;
  k = first;
  //goes through the temp arrays comparing the next two elements
  while( i < leftArr && j < rightArr){
    if(L[i] <= R[j]){
      theArray[k] = L[i];
      i++;
    }
    else{
      theArray[k] = R[j];
      j++;
    }
    k++;
  }
  //copies the rest of the temp arrays
  while(i < leftArr){
    theArray[k] = L[i];
    i++;
    k++;
  }
  while(j < rightArr){
    theArray[k] = R[j];
    j++;
    k++;
  }
}

void mergeSort(int a[], int from, int to){
    if (from < to){
      int mid = (from + to ) / 2;
      mergeSort(a, from, mid);
// Sort right half theArray[mid+1..last]
 mergeSort(a, mid + 1, to);
// Merge the two halves
 merge(a, from, mid, to);
  }
}

void generateRandomArray(int values[], size_t size){
  srand(static_cast<unsigned>(time(0)));
  for(int i=0; i < size; i++){
    values[i] = rand()%size;
    //cout << values[i] << endl;
  }
}
void generateAscendingArray(int values[], size_t size){
  int a;
  for (int i = 0; i < size; i++){
    for(int j = i; j < size; j++){
      if(values[i] > values[j]){
        a = values[i];
        values[i] = values[j];
        values[j] = a;
      }
    }
  }
}
void generateDescendingArray(int values[], size_t size){
  int a;
  for (int i = 0; i < size; i++){
    for(int j = i; j < size; j++){
      if(values[i] < values[j]){
          a = values[i];
          values[i] = values[j];
          values[j] = a;
      }
    }
  }
}

void generateLastTenRandomArray(int values[], size_t size){
  srand(static_cast<unsigned>(time(0)));
  for(int i = 0; i < size; i++){
    if(i < size - 10){
      values[i] = i;
    }
    else{
      values[i] = rand()%size;
    }
  }
}

void generateFewRandomArray(int values[], size_t size){
  srand(static_cast<unsigned>(time(0)));
  for(int i = 0; i < size; i++){
    values[i] = rand()%(size/10);
  }
}




double sortTest(void (*sortingFunction)(int a[], size_t size), int values[], size_t size){
  double run_sum = 0;
  double run_avg;
  for(auto i= 0; i < 10; i++){
    auto start_time = high_resolution_clock().now();
    sortingFunction(values,size);
    auto end_time = high_resolution_clock().now();
    duration<float, micro> runt_time = duration_cast<microseconds>(end_time - start_time);
    run_sum += runt_time.count();
  }
  run_avg = run_sum/10.00;
  return run_avg;
}


double mergeSortTest(int values[], size_t size){
  double run_sum = 0;
  double run_avg;
  for(auto i= 0; i < 10; i++){
    auto start_time = high_resolution_clock().now();
    mergeSort(values,0,size-1);
    auto end_time = high_resolution_clock().now();
    duration<float, micro> runt_time = duration_cast<microseconds>(end_time - start_time);
    run_sum += runt_time.count();
  }
  run_avg = run_sum/10.00;
  return run_avg;
}
