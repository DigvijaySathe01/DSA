#include "LinearQueue.h"
#include <cassert>
#include <iostream>

//-----------------------------------------------------------------------------

LinearQueue::LinearQueue(size_t size)
{
    assert(size > 0 && "Queue size must be greater than 0");

    m_size = size;
    m_arr = new int[m_size];
    m_front = 0;
    m_rear = 0;
}

//-----------------------------------------------------------------------------

bool LinearQueue::IsEmpty() const
{
    return m_front == m_rear;
}

//-----------------------------------------------------------------------------

bool LinearQueue::IsFull() const
{
    return m_rear == m_size;
}

//-----------------------------------------------------------------------------

bool LinearQueue::Enqueue(int value)
{
    if (IsFull())
    {
        assert(false && "Cannot enqueue the value in queue, queue is already full!!!");
        return false;
    }

    m_arr[m_rear++] = value;
    return true;
}

//-----------------------------------------------------------------------------

int LinearQueue::Dequeue()
{
    if (IsEmpty())
    {
        assert(false && "Cannot dequeue an element from the queue, queue is empty!!!");
        return -1;
    }

    int ans = m_arr[m_front++];
    if (m_front == m_rear)
    {
        m_front = m_rear = 0;
    }

    return ans;
}

//-----------------------------------------------------------------------------

size_t LinearQueue::Size() const
{
    return m_rear - m_front;
}

//-----------------------------------------------------------------------------

int LinearQueue::Front() const
{
    if (IsEmpty())
    {
        assert(false && "Cannot get front element from the queue, queue is empty!!!");
        return -1;
    }
    return m_arr[m_front];
}

//-----------------------------------------------------------------------------

int LinearQueue::Rear() const
{
    if (IsEmpty())
    {
        assert(false && "Cannot get rear element from the queue, queue is empty!!!");
        return -1;
    }

    return m_arr[m_rear - 1];
}

//-----------------------------------------------------------------------------

void LinearQueue::Print() const
{
    if (IsEmpty())
    {
        std::cout << "Queue is empty!!\n";
        return ;
    }

    for (size_t index = m_front; index < m_rear; ++index)
    {
        std::cout << m_arr[index]<<" ";
    }
    std::cout << "\n";
}

//-----------------------------------------------------------------------------

LinearQueue::~LinearQueue()
{
    delete[] m_arr;
}

//-----------------------------------------------------------------------------
