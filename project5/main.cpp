#include <iostream>
using namespace std;

#include "SortingTests.hpp"

void printArr(int arr[], size_t size){
	for(size_t i = 0; i < size; i++)
		cout << arr[i] << endl;
}

int main(){

	// int arr[6] = {50, 24, 13, 13,1,40};
	int arr[20];

	generateRandomArray(arr, 20);
	printArr(arr, 20);

	// generateAscendingArray(arr, 6);
	// printArr(arr, 6);

	// generateDescendingArray(arr, 6);
	// printArr(arr, 6);

	// generateLastTenRandomArray(arr, 20);
	// printArr(arr, 20);

	// generateFewRandomArray(arr, 20);
	// printArr(arr, 20);


	// selectionSort(arr, 20);
	insertionSort(arr, 20);
	// mergeSort(arr, 0, 19);
	// mergeSort(arr, 0, 5);
	// merge(arr, 0, 3, 1);
	cout << "Sorted: " << endl;
	for(int i = 0; i < 19; i++)
		cout << arr[i] << endl;
	return 0;
}
