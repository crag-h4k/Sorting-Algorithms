#include <cctype>       // Provides toupper
#include <iostream>     // Provides cout and cin
#include <cstdlib>      // Provides EXIT_SUCCESS
#include <cstring>
#include <ctime>
#include "Sort.h"  // With value_type defined as an int

using namespace std;

void printArray(Sort s);

int main()
{
	int loopCount = 100;
	int secToMil= 1000;
	Sort s(10000);
	int size = s.getSize();

	//GET APPROX TIME IT TAKES TO INIT
	clock_t start = clock();
	s.init_array();
	clock_t end = clock();
	float resetTime = (static_cast<float>(end - start) / CLOCKS_PER_SEC * secToMil);

	start = clock();
	for (int i = 0; i < loopCount; i++){
		s.init_array();
		s.insertionSort();
	}
	end = clock();
	float insertionTime = ((static_cast<float>(end - start) / CLOCKS_PER_SEC * secToMil) / loopCount) - resetTime;

	start = clock();
	for (int i = 0; i < loopCount; i++){
		s.init_array();
		s.mergeSort();
	}
	end = clock();
	float mergeTime = ((static_cast<float>(end - start) / CLOCKS_PER_SEC * secToMil) / loopCount) - resetTime;

	start = clock();
	for (int i = 0; i < loopCount; i++){
		s.init_array();
		s.selectionSort();
	}
	end = clock();
	float selectionTime = ((static_cast<float>(end - start) / CLOCKS_PER_SEC * secToMil) / loopCount) - resetTime;

	start = clock();
	for (int i = 0; i < loopCount; i++){
		s.init_array();
		s.quickSort();
	}
	end = clock();
	float quickTime = ((static_cast<float>(end - start) / CLOCKS_PER_SEC * secToMil) / loopCount) - resetTime;

	cout << "Merge Sort: " << mergeTime << " milliseconds" << endl;
	cout << "Insertion Sort: " << insertionTime << " milliseconds" << endl;
	cout << "Selection Sort: " << selectionTime << " milliseconds" << endl;
	cout << "Quick Sort: " << quickTime << " milliseconds" << endl;
	//printArray(s);
	system("pause");

	return EXIT_SUCCESS;
}

void printArray(Sort s){
	cout << s;

}
