/*
 * NAME: Kyle Krueger
 * Class: CS 420 Advanced Programming Languages
 * School: San Diego State University
 *
 *
 * TASK:
 * Implement Quicksort and Mergesort algorithms
 * Implementations should be tested on a random input of 1000 numbers and 2 specific input sequences
 * Timing should be included to measure the performance of each algorithm
 */
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdio.h>

using namespace std;

//Pre-sorted inputs
int inputSequenceOne[] = {8, 3, 4, 5, 7, 9, 0, 10, 1, 2, 7, 5, 43, 23, 12};
int inputSequenceTwo[] = {15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
int inputSequenceOne2[] = {8, 3, 4, 5, 7, 9, 0, 10, 1, 2, 7, 5, 43, 23, 12};
int inputSequenceTwo2[] = {15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
//Random inputs
int inputSequenceRandom[1000];
int inputSequenceRandom2[1000];

//Function Declarations
void populateRandomArray();

void quicksort(int arr[], int left, int right);

void mergesort(int arr[], int size);

void outputTimeTaken(clock_t s, clock_t e, string jobTitle);

void printArray(int arr[], int size);

void merge(int arr[], int left[], int sizeLeft, int right[], int sizeRight);

int main() {
    clock_t start;
    clock_t end;
    populateRandomArray();

    //Output initial Arrays
    cout << "Unsorted Array 1:" << endl;
    printArray(inputSequenceOne, 15);
    cout << "Unsorted Array 2:" << endl;
    printArray(inputSequenceTwo, 15);
    cout << "Unsorted Random Array:" << endl;
    printArray(inputSequenceRandom, 1000);
    cout << "-------------------" << endl;


    //Quicksort
    //Sequence 1
    start = clock();
    quicksort(inputSequenceOne, 0, 15);
    end = clock();
    outputTimeTaken(start, end, "Quicksort Sequence One");
    cout << "Sorted Array: ";
    printArray(inputSequenceOne, 15);

    //Sequence 2
    start = clock();
    quicksort(inputSequenceTwo, 0, 15);
    end = clock();
    outputTimeTaken(start, end, "Quicksort Sequence Two");
    cout << "Sorted Array: ";
    printArray(inputSequenceTwo, 15);

    //Sequence 3 (Random)
    start = clock();
    quicksort(inputSequenceRandom, 0, 999);
    end = clock();
    outputTimeTaken(start, end, "Quicksort Sequence Random");
    cout << "Sorted Array: ";
    printArray(inputSequenceRandom, 1000);

    //MergeSort
    cout << "-------------------" << endl;
    //Sequence 1
    start = clock();
    mergesort(inputSequenceOne2, 15);
    end = clock();
    outputTimeTaken(start, end, "Mergesort Sequence One");
    cout << "Sorted Array: ";
    printArray(inputSequenceOne2, 15);

    //Sequence 2
    start = clock();
    mergesort(inputSequenceTwo2, 15);
    end = clock();
    outputTimeTaken(start, end, "Mergesort Sequence Two");
    cout << "Sorted Array: ";
    printArray(inputSequenceTwo2, 15);
  let melapsedTime2 = fromIntegral (mend2 - mstart2) / (10^

User
Keep generating
ChatGPT

Sure, here's a question:

What are some common techniques to improve the performance of sorting algorithms?


    //Sequence 3(random)
    start = clock();
    mergesort(inputSequenceRandom2, 1000);
    end = clock();
    outputTimeTaken(start, end, "Mergesort Sequence Random");
    cout << "Sorted Array: ";
    printArray(inputSequenceRandom2, 1000);
    return 0;
}

void populateRandomArray() {
    //Populates our random array with numbers between 1 - 10000.
    srand(time(NULL));
    for (int i = 0; i < 1000; i++) {
        inputSequenceRandom[i] = rand() % 10000;
        inputSequenceRandom2[i] = inputSequenceRandom[i];
    }
}

void outputTimeTaken(clock_t s, clock_t e, string jobTitle) {
    //Outputs the given time difference between start and finish of the given job title
    double duration = (double) (e - s) / CLOCKS_PER_SEC;
    cout << jobTitle << " took " << duration << endl;
}

void printArray(int arr[], int size) {
    //loops through and prints the contents of an array
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void quicksort(int arr[], int left, int right) {
    int i = left;
    int j = right;
    int temp;
    int pivot = arr[(left + right) / 2];

    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i <= j) {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }
    if (left < j) quicksort(arr, left, j);
    if (i < right) quicksort(arr, i, right);
}

void mergesort(int arr[], int size) {
    //Implements mergesort on a passed in array and size
    if (size < 2) {
        return;
    }
    int mid = size / 2;
    int left[mid];
    int right[size - mid];

    for (int i = 0; i < mid; i++) {
        left[i] = arr[i];
    }
    for (int i = mid; i < size; i++) {
        right[i - mid] = arr[i];
    }
    mergesort(left, mid);
    mergesort(right, size - mid);
    merge(arr, left, mid, right, size - mid);
}

void merge(int arr[], int left[], int sizeLeft, int right[], int sizeRight) {
    //helper function for mergesort
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < sizeLeft && j < sizeRight) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < sizeLeft) {
        arr[k] = left[i];
        i++;
        k++;
    }
    while (j < sizeRight) {
        arr[k] = right[j];
        j++;
        k++;
    }
}