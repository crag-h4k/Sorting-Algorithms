#include <iostream>
#include <fstream>
#include <cstdlib> // Provides size_t
#include <random>
#include <time.h>

using namespace std;

class Sort
{
public:

	void init_array(){
		srand(time(NULL));
		for (int i = 0; i < size; i++){
			sorting[i] = rand() % size;
		}
	}

	int getSize(){
		return size;
	}
	// this is just for practice and debugging.
	friend ostream& operator<< (ostream& out, const Sort& s)
	{
		for (int i = 0; i < s.size; i++){
			out << s.sorting[i] << "\n";
		}
		return out;
	}

	void quickSort() {
		quickSort(sorting, size);
	}

	void partition(int data[], size_t n, size_t& pivot_index){
		if (n > 1) {
			int pivot = data[0];
			int too_big_index = 1;
			int too_small_index = n - 1;

			while (too_big_index <= too_small_index) {
				if ((too_big_index < n) && (data[too_big_index] <= pivot)){
					too_big_index++;
				}
				if (data[too_small_index] > pivot){
					too_small_index--;
				}
				if (too_big_index < too_small_index){
					int temp = data[too_big_index];
					data[too_big_index] = data[too_small_index];
					data[too_small_index] = temp;
					too_big_index++;
					too_small_index--;
				}
			}

			pivot_index = too_small_index;
			data[0] = data[pivot_index];
			data[pivot_index] = pivot;
		}
	}

	void insertionSort() {
		insertionSort(sorting, size);
	}

	void swap(int& a, int& b){
		int temp = a;
		a = b;
		b = temp;
	}

	void selectionSort() {
		selectionSort(sorting, size);
	}

	void merge(int data[], size_t n1, size_t n2){
		int * temp;
		size_t copied = 0;
		size_t copied1 = 0;
		size_t copied2 = 0;
		size_t i;

		//allocates memory for the temp dynamic array
		temp = new int[n1 + n2];

		//merge elements
		while ((copied1 < n1) && (copied2 < n2)){
			if (data[copied1] < (data + n1)[copied2]){
				temp[copied++] = data[copied1++];
			}
			else{
				temp[copied++] = (data + n1)[copied2++];
			}
		}

		while (copied1 < n1){
			temp[copied++] = data[copied1++];
		}

		while (copied2 < n2){
			temp[copied++] = (data + n1)[copied2++];
		}

		for (i = 0; i < n1 + n2; ++i){
			data[i] = temp[i];
		}

		delete[] temp;
	}

	void mergeSort(){
		mergeSort(sorting, size);
	}

	Sort(int input_size) {
		size = input_size;
		sorting = new int[size];
	}

	~Sort() {
		//delete array;
	}

private:

	int size;
	int* sorting; //edited copy of array, we will reset and resort this one

	void quickSort(int data[], size_t n){
		size_t pivot_index;
		size_t n1;
		size_t n2;

		if (n > 1){
			partition(data, n, pivot_index);

			n1 = pivot_index;
			n2 = n - n1 - 1;

			quickSort(data, n1);
			quickSort((data + pivot_index + 1), n2);
		}
	}

	void insertionSort(int data[], size_t n){
		int temp;
		int j;

		for (int i = 0; i < n; i++){
			j = i;

			while ((j > 0) && data[j] < data[j - 1]){
				temp = data[j];
				data[j] = data[j - 1];
				data[j - 1] = temp;
				j--;
			}
		}
	}

	void selectionSort(int data[], size_t n){
		size_t i, j, index_of_largest;
		int largest;

		if (n == 0) return;

		for (i = n - 1; i > 0; --i){
			largest = data[0];
			index_of_largest = 0;
			for (j = 1; j <= i; ++j){
				if (data[j] > largest){
					largest = data[j];
					index_of_largest = j;
				}
			}
			//still have to write this function!
			swap(data[i], data[index_of_largest]);
		}
	}

	void mergeSort(int data[], size_t n){
		size_t n1; //Size of the first subarray
		size_t n2; //Size of the second subarray

		if (n>1){
			n1 = n / 2;
			n2 = n - n1;

			mergeSort(data, n1);
			mergeSort((data + n1), n2);

			merge(data, n1, n2);
		}
	}
};
