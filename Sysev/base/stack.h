#ifndef __STACK_H__
#define __STACK_H__

using namespace std;

#include<iostream>
const size_t MaxStackSize = 100;

template <class T>
class TStack
{
    T* pMem;
    size_t size;
    int top;
public:
    TStack(size_t _size = 1)
    {
        size = _size;
        top = -1;
        if ((size < 1) || (size > MaxStackSize)) throw size;
        pMem = new T[size];
    }

    ~TStack()
    {
        delete[] pMem;
    }

    void push(T x)
    {
        ++top;
        if (top == size)
        {
            
            size = min(2 * size, MaxStackSize);
            T* new_p = new T[size];
            for (int i = 0; i < size; ++i) new_p[i] = pMem[i];
            swap(new_p, pMem);
            delete[] new_p;
        }

        if (top == size) throw out_of_range("too many elements");

        pMem[top] = x;
    }

    T pop()
    {
        if (top < 0) throw out_of_range("stack is empty");

        T x = pMem[top];
        --top;
        return x;
    }

    T get_top()
    {
        if (top < 0) throw out_of_range("stack is empty");

        return pMem[top];
    }

    bool empty() { return !(top > -1); }
};



#endif
