#include <iostream>

using namespace std;

void swap(int[], int, int);
int partition(int[], int, int);
void recQuickSort(int[], int, int);
void quickSort(int[], int);
int binarySearch(int[], int, int, int);




int main() {
	const int SIZE = 10;
	int arr[SIZE] = { 10,3,30,6,14,9,19,1,23,4 };

	int pos, searcher;

	cout << "Please enter a number to be searched: ";
	cin >> searcher;

	quickSort(arr, SIZE);
	for (int a = 0; a < SIZE; a++) {
		cout << arr[a] << " ";
	}
	cout << endl;

	pos = binarySearch(arr, searcher, 0, SIZE);

	if (pos != -1) {
		cout << searcher << " is found at position " << pos << endl;
	}

	else {
		cout << searcher << " is not in the array." << endl;
	}



	return 0;

}








void swap(int arr[], int first, int second) {
	int temp;

	temp = arr[first];
	arr[first] = arr[second];
	arr[second] = temp;
}

int partition(int arr[], int first, int last) {
	int pivot;
	int smallIndex;

	swap(arr, first, (last+first)/2);

	/*cout << "partition" << endl;
	for (int a = 0; a < 10; a++) {
		cout << arr[a] << " ";
	}
	cout << endl;*/

	pivot = arr[first];
	smallIndex = first;

	for (int index = first + 1; index <= last; index++) {
		if (arr[index] < pivot) {
			smallIndex++;
			swap(arr, smallIndex, index);
		}
	}

	swap(arr, first, smallIndex);
	return smallIndex;

}

void recQuickSort(int arr[], int first, int last) {
	int pivotLoc;

	if (first < last) {
		pivotLoc = partition(arr, first, last);
		recQuickSort(arr, pivotLoc + 1, last);
		recQuickSort(arr, first, pivotLoc - 1);
	}

}

void quickSort(int arr[], int length) {
	recQuickSort(arr, 0, length-1);
}


int binarySearch(int arr[], int search, int first, int last) {
	int mid = 0;

	mid = (first + last) / 2;

	if (first > last) {
		//cout << "no found";
		return -1;
	}
	else if (arr[mid] == search) {
		//cout << "found";
		return mid;
	}
	else {

		if (arr[mid] > search) {
			//last = mid - 1;
			binarySearch(arr, search, first, mid-1);
		}
		else {
			//first = mid + 1;
			binarySearch(arr, search, mid+1, last);
		}
	}

		
	/*if(found) {
		return mid;
	}
	else {
		return -1;
	}*/
}

/*
1 3 4 6 9 10 14 19 23 30
122 is not in the array.

1 3 4 6 9 10 14 19 23 30
19 is found at position 7

*/