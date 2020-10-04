#pragma once
#include "Array.h"

template<class T>
class UnorderedArray : public Array<T>
{
public:
	UnorderedArray(int size, int growBy = 1) : Array<T>(size)
	{}
	
	void push(T val) override
	{
		assert(this->m_array != NULL);	// Debugging purposes

		if (this->m_numElements >= this->m_maxSize)
		{
			this->Expand();
		}

		// My array has space for the new value
		this->m_array[this->m_numElements] = val;
		this->m_numElements++;
	}

	int search(T val) override
	{
		assert(this->m_array != NULL);

		// Brute-force search
		for (int i = 0; i < this->m_numElements; i++)
		{
			if (this->m_array[i] == val)
			{
				return i;
			}
		}

		return -1;
	}

	// Overloaded [] operator
	const T& operator[](int index)
	{
		assert(this->m_array != NULL && index < this->m_numElements);
		return this->m_array[index];
	}
};