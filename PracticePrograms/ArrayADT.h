#include <iostream>
#include <cassert>

class ArrayADT {
private:
    int m_size{};
    int m_capacity{};
    int* m_array;

    void reallocate();

public:

    //Default Constructor
    ArrayADT();

    //Paramerized constructor 
    ArrayADT(int size, int capacity);

    //Function to insert an element in the array at given index
    bool Insertion(int index, int value);
    
    //Function to display the array
    void Display() const;

    //Function to delete an element at given index
    bool Delete(int index);

    //Function to search an element with linear search method
    int LinearSearch(int value) const;

    //Function to search an element with binary search method
    int BinarySearch(int value) const;

    //Destructor
    ~ArrayADT();
};


