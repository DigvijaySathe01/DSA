#include "SortingAlgorithms.h"
#include <vector>
#include <cassert>

//-----------------------------------------------------------------------------

void SortingAlgorithms::BubbleSort(int arr[], const int size)
{
    // Outer loop for each pass
    for (int i = 0; i < size - 1; ++i)
    {bool isSorted = true; // Flag to check if the array is already sorted

        // Inner loop for comparing adjacent elements
        for (int j = 0; j < size - 1 - i; ++j)
        {
            if (arr[j] > arr[j + 1]) // Swap if elements are out of order
            {
                isSorted = false;
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }

        // Break out early if no swaps occurred
        if (isSorted)
            break;
    }
}

//-----------------------------------------------------------------------------

void SortingAlgorithms::InsertionSort(int arr[], const int size)
{
    for (int i = 1; i < size; ++i)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >=0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

//-----------------------------------------------------------------------------

void SortingAlgorithms::SelectionSort(int arr[], const int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        int minIndex = i;
        for (int j = i + 1; j < size; ++j)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex =  j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

//-----------------------------------------------------------------------------

void SortingAlgorithms::mergeHelper(int arr[], int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int k = 0;
    std::vector<int> temp(high - low + 1);
    
    while (i <= mid && j <=high)
    {
        if (arr[i] < arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid)
    {
        temp[k++] = arr[i++];

    }

    while (j <= high)
    {
        temp[k++] = arr[j++];
    }

    for (int index = 0; index < k; ++index)
    {
        arr[low + index] = temp[index];
    }
}

//-----------------------------------------------------------------------------

void SortingAlgorithms::MergeSort(int arr[], const int low, const int high)
{
    if (low < high)
    {
        int mid = low + (high - low) / 2;
        MergeSort(arr, low, mid);
        MergeSort(arr, mid + 1, high);
        mergeHelper(arr, low, mid, high);
    }
}

//-----------------------------------------------------------------------------

int SortingAlgorithms::getPivotIndexHelper(int arr[], int low, int high)
{
    int i = low + 1;
    int j = high;

    while ( i <= j)
    {
        while (i <= high && arr[i] <= arr[low])
        {
            ++i;
        }

        while (j >= low  && arr[j] > arr[low])
        {
            --j;
        }

        if (i < j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
    return j;
}

//-----------------------------------------------------------------------------

void SortingAlgorithms::QuickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivoteIndex = getPivotIndexHelper(arr, low, high);
        QuickSort(arr, low, pivoteIndex - 1);
        QuickSort(arr, pivoteIndex + 1, high);
    }
}

//-----------------------------------------------------------------------------

int SortingAlgorithms::getMaximunHelper(int arr[], int size)
{
    // Ensure that the array is not empty
    assert(size > 0 && "Size of the array is zero!!!");

    int max = arr[0];
    for (int i = 1; i < size; ++i)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    return max;
}

//-----------------------------------------------------------------------------

void SortingAlgorithms::CountSort(int arr[], int size)
{
    int max = getMaximunHelper(arr, size); 

    // Create and initialize the count array
    int* countArray = new int[max + 1](); 

    for (int i = 0; i < size; ++i)
    {
        ++countArray[arr[i]];
    }

    int j = 0;
    for (int i = 0; i <= max; ++i)
    {
        while (countArray[i] > 0)
        {
            arr[j++] = i; 
            --countArray[i];
        }
    }

    delete[] countArray; 
}

//-----------------------------------------------------------------------------

