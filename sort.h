#ifndef sort_hpp
#define sort_hpp

#include <random>
#include <math.h>  //for pow()

using namespace std;

//Function to find maximum value inside array
int getMax(int array[], int length) {
	int max = array[0];
	for (int i = 1; i < length; i++) {
		if (array[i] > max) {
			max = array[i];
		}
	}
	return max;
}

//Function to count the number of digits in int
int getDigits(int num) {
	int digits = 0;
	while (num > 0) {
		digits++;
		num /= 10;
	}
	return digits;
}

void radixSort(int array[], int length) {
	int max = getMax(array, length);
	int digits = getDigits(max);

	//We have to do a Counting Sort of array[] for each digit in the largest element
	for (int sigDigit = 0; sigDigit < digits; sigDigit++) {
		
		int count[10] = {0};
		int exp = pow(10, sigDigit);
		int* output = new int[length];

		//stores occurances of each digit (0-9) in count[]
		for (int i = 0; i < length; i++) {
			//First let's find the digit we care about at array[i]
			//Ex: Get 10s place in 123 = 2
			int currentDigit = (array[i] / exp) % 10;
			
			count[currentDigit]++;
		}

		//count[] now needs to store positions of digits in output[]
		//But first we subtract 1 from the 0 position so that the resulting
		//sums yield correct positions in the Auxilliary array.
		count[0] -= 1;
		for (int i = 1; i < 10; i++) {
			count[i] += count[i - 1];
		}

		//now we can populate output[]
		//This is stable so order of elements with equal significant digits is preserved
		for (int i = length - 1; i >= 0; i--) {
			//First let's find the digit we care about at array[i]
			//Ex: Get 10s place in 123 = 2
			int currentDigit = (array[i] / exp) % 10;

			//Now we need to store array[i] at its correct position in output[]
			output[count[currentDigit]] = array[i];

			//The next digit of the same value should come before the one we just inserted
			count[currentDigit]--;
		}

		//Finally we copy output to our array
		for (int i = 0; i < length; i++) {
			array[i] = output[i];
		}
		delete[] output;
	}

}


#endif /* sort_hpp */