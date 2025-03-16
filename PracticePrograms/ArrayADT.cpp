#include "ArrayADT.h"

//-----------------------------------------------------------------------------

ArrayADT::ArrayADT() : m_size(0), m_capacity(2) 
{
    m_array = new int[m_capacity] {};
}

//-----------------------------------------------------------------------------

ArrayADT::ArrayADT(int size, int capacity) : m_size(size), m_capacity(capacity)
{
    assert(capacity >= size && "size should be less or equal to capacity");

    m_array = new int[m_capacity] {};
}

//-----------------------------------------------------------------------------

void ArrayADT::reallocate() 
{
    m_capacity *= 2;
    int* newArray = new int[m_capacity] {};
    for (int index = 0; index < m_size; ++index) {
        newArray[index] = m_array[index];
    }
    delete[] m_array;
    m_array = newArray;
}

//-----------------------------------------------------------------------------

bool ArrayADT::Insertion(int index, int value) 
{
    if ((m_size + 1) > m_capacity)
        reallocate();

    if (index > m_size)
        return false;

    for (int i = m_size - 1; i >= index; --i) {
        m_array[i + 1] = m_array[i];
    }
    m_array[index] = value;
    ++m_size;
    return true;
}

//-----------------------------------------------------------------------------

void ArrayADT::Display() const 
{
    for (int index = 0; index < m_size; ++index) {
        std::cout << m_array[index] << " ";
    }
    std::cout << std::endl;
}

//-----------------------------------------------------------------------------

bool ArrayADT::Delete(int index) 
{
    if (index < 0 || index >= m_size) {
        return false;
    }
    for (int i = index; i < m_size - 1; ++i) {
        m_array[i] = m_array[i + 1];
    }
    --m_size;
    return true;
}

//-----------------------------------------------------------------------------

int ArrayADT::LinearSearch(int value) const 
{
    for (int index = 0; index < m_size; ++index) {
        if (m_array[index] == value)
            return index;
    }
    return -1;
}

//-----------------------------------------------------------------------------

int ArrayADT::BinarySearch(int value) const 
{
    int low = 0, high = m_size - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (m_array[mid] == value) {
            return mid;
        }
        else if (m_array[mid] < value) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return -1;
}

//-----------------------------------------------------------------------------

ArrayADT::~ArrayADT() 
{
    delete[] m_array;
}

//-----------------------------------------------------------------------------
