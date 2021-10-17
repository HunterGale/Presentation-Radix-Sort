#include "sort.h"
#include <stdlib.h>
#include <ctime>
#include <iostream>

using namespace std;

int main() {
	//Creating array of ints range (0 - 999)
	srand(time(NULL));
	int test[20];
	for (int i = 0; i < 20; i++) {
		test[i] = rand() % 1000;
	}
	
	//Output elements of test[]
	cout << "Unsorted Array: " << endl << "[";
	for (int i = 0; i < 20; i++) {
		cout << test[i];
		if (i < 19) {
			cout << ", ";
		}
	}
	cout << "]" << endl;

	//Appling Radix Sort to array
	cout << "Sorting with Radix Sort..." << endl;
	radixSort(test, 20);

	//Output elements of test[] again
	cout << "Sorted Array: " << endl << "[";
	for (int i = 0; i < 20; i++) {
		cout << test[i];
		if (i < 19) {
			cout << ", ";
		}
	}
	cout << "]" << endl;
}