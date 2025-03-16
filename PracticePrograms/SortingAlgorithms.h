#pragma once
class SortingAlgorithms
{
	//Helper function for merge sort to merge two sorted array
	static void mergeHelper(int arr[], const int low, const int mid, const int high);

	//Function to get pivote element index for quick sort algorithm
	static int getPivotIndexHelper(int arr[], int low, int high);

	//Helper function for count sort to get maximum element of the array
	static int getMaximunHelper(int arr[], int size);

public:

	//Function to sort an array using bubble sort algorithm
	static void BubbleSort(int arr[], const int size);

	//Function to sort an array using insertion sort algorithm
	static void InsertionSort(int arr[], const int size);

	//Function to sort an array using selection sort algorithm
	static void SelectionSort(int arr[], const int size);

	//Function to sort an array using merger sort algorithm
	static void MergeSort(int arr[],const int low,const int high);

	//Function to sort an array using quick sort algorithm
	static void QuickSort(int arr[], int low, int high);

	//Function to sort an array using count sort algorithm
	static void CountSort(int arr[], int size);

};

