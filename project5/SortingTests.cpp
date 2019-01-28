// Xuejin Gao
// Tiziana Ligorio
// Project 5 sorts and their algorithm

#include <iostream>
using namespace std;

#include <cmath>
#include "SortingTests.hpp"

#include <cstdlib>

void generateRandomArray(int values[], size_t size){
	for(size_t i = 0; i < size; i++){
		values[i] = rand() % 1000;
	}
}

void generateAscendingArray(int values[], size_t size){
	for(size_t i = 0; i < size; i++){
		values[i] = i;
	}
}

void generateDescendingArray(int values[], size_t size){
	for (size_t i = size; i > 0; i--)
	{
		values[size - i] = i; 
	}
}

void generateLastTenRandomArray(int values[], size_t size){
	for(size_t i = 0; i < size - 10; i++)
		values[i] = i;
	for(size_t i = size - 10; i < size; i++)
		values[i] = rand() % 1000;
}

void generateFewRandomArray(int values[], size_t size){
	for(size_t i = 0; i < size; i++)
		values[i] = i;
	for(size_t i = 0; i < size/10; i++)
		values[rand() % size] = rand() % size;
}

void selectionSort(int a[], size_t size){
	int min_index;
	for(int i = 0; i < size-1; i++){
		min_index = i;
		for(int j = i+1; j < size; j++){
    		if(a[j] < a[min_index]){
    			min_index = j;
    		}
		}
		if(min_index!=i){
			swap(a[min_index],a[i]);
		}
	}
// 	int current = a[0];
// 	int position = 0;
// 	for(int i = position; i < size; i++){
// 		if(current > a[i])
// 			current = i;
// 		// swap(a, current, position);
// 		swap(a[current], a[position]);
// 		position++;
// 		current = a[position];
// 	}
}

void insertionSort(int a[], size_t size){
  	for(int i = 1; i < size; i++){
    	int j = i;
    	while(j > 0 && a[j-1] > a[j]){
    		swap(a[j], a[j-1]);
    		j--;
    	}

	}
	// int current = a[0];
	// for(int i = 0; i < size; i++){
	// 	for (int j = i + 1; j < size; j++){
	// 		if(a[i] > a[j]){
	// 			// current = a[j];
	// 			// swap(a, current, j);
	// 			swap(a[i], a[j]);
	// 		}
	// 	}
	// }
}

void merge(int a[], int from, int to, int mid){
  int i,j,k;
  int leftArr = mid - from + 1;
  int rightArr = to - mid;
  int *L = new int[leftArr];
  int *R = new int [rightArr];
  for (int i = 0; i < leftArr; i++){
    L[i] = a[from + i];
  }
  for(int j = 0; j < rightArr; j++){
    R[j] = a[mid + 1 + j];
  }
  i = 0;
  j = 0;
  k = from;
  while( i < leftArr && j < rightArr){
    if(L[i] <= R[j]){
      a[k] = L[i];
      i++;
    }
    else{
      a[k] = R[j];
      j++;
    }
    k++;
  }
  while(i < leftArr){
    a[k] = L[i];
    i++;
    k++;
  }
  while(j < rightArr){
    a[k] = R[j];
    j++;
    k++;
  }


	// int arrCount = 0;
	// int *L = new int[mid - from + 1];
	// for(int i = from; i <= mid; i++){
	// 	L[arrCount] = a[i];
	// 	arrCount++;
	// }

	// arrCount = 0;
	// int *R = new int[to - mid];
	// for(int i = mid + 1; i <= to; i++){
	// 	R[arrCount] = a[i];
	// 	arrCount++;
	// }

	// int current1 = 0;
	// int current2 = 0;
	// for(int i = from; i <= to; i++){
	// 	if(current1 == mid - from + 1){
	// 		for(current2; current2 < to - mid; current2++){
	// 			a[i] = R[current2];
	// 			i++;
	// 		}
	// 	}
	// 	else if(current2 == to - mid){
	// 		for(current1; current1 < mid - from + 1; current1++){
	// 			a[i] = L[current1];
	// 			i++;
	// 		}
	// 	}
	// 	else if(L[current1] < R[current2]){
	// 		a[i] = L[current1];
	// 		current1++;
	// 	}
	// 	//(R[current2] < L[current1])
	// 	else{
	// 		a[i] = R[current2];
	// 		current2++;
	// 	}
	// }
}

void mergeSort(int a[], int from, int to){
	if(from >= to){
		return;
	}
	else{
		int middle = ceil((from + to)/2);
		mergeSort(a, from, middle);
		mergeSort(a, middle + 1, to);

		merge(a, from, to, middle);
	}
}

// void merge(int a[], int from, int to, int mid){
// 	int arrCount = 0;
// 	int arr1[mid - from + 1];
// 	for(int i = from; i <= mid; i++){
// 		arr1[arrCount] = a[i];
// 		arrCount++;
// 	}

// 	arrCount = 0;
// 	int arr2[to - mid];
// 	for(int i = mid + 1; i <= to; i++){
// 		arr2[arrCount] = a[i];
// 		arrCount++;
// 	}

// 	int current1 = 0;
// 	int current2 = 0;
// 	for(int i = from; i <= to; i++){
// 		if(current1 == mid - from + 1){
// 			for(current2; current2 < to - mid; current2++){
// 				a[i] = arr2[current2];
// 				i++;
// 			}
// 		}
// 		else if(current2 == to - mid){
// 			for(current1; current1 < mid - from + 1; current1++){
// 				a[i] = arr1[current1];
// 				i++;
// 			}
// 		}
// 		else if(arr1[current1] < arr2[current2]){
// 			a[i] = arr1[current1];
// 			current1++;
// 		}
// 		//(arr2[current2] < arr1[current1])
// 		else{
// 			a[i] = arr2[current2];
// 			current2++;
// 		}
// 	}
// }

// void swap(int a[], int x, int y){
// 	int temp = a[x];
// 	a[x] = a[y];
// 	a[y] = temp;
// }

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


