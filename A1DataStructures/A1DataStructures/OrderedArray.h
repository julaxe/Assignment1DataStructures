#include "Array.h"

#pragma once
#include "Array.h"

template<class T>
class OrderedArray : public Array<T>
{
public:
	OrderedArray(int size, bool duplicateData, int growBy = 1) : Array<T>(size, growBy)
	{
		m_duplicateData = duplicateData;
	}

	void push(T val) override
	{
		assert(this->m_array != NULL);
		
		// if duplicateData = true -> allows duplicate data in the array
		if(!m_duplicateData)
		{
			for (int i = 0; i < this->m_numElements; i++)
			{
				if (this->m_array[i] == val)
				{
					return;
				}
			}
		}

		// Check for more space in the array
		if (this->m_numElements >= this->m_maxSize)
		{
			this->Expand();
		}

		int i, k;
		// Step 1: Find the index to insert val
		for (i = 0; i < this->m_numElements; i++)
		{
			if (this->m_array[i] > val)
			{
				break;
			}
		}

		// Step 2: Shift everything to the right of the index forward by one
		for (k = this->m_numElements; k > i; k--)	// Moving backwards through the array starting at m_numElements
		{
			this->m_array[k] = this->m_array[k - 1];
		}

		// Step 3: Insert val into index
		this->m_array[i] = val;

		this->m_numElements++;

	}

	int search(T searchKey) override
	{
		assert(this->m_array != NULL);

		// Helper variables
		int lowerBound = 0;
		int upperBound = this->m_numElements - 1;
		int current = 0;

		while (1)	// <-- Replaced with recursion
		{
			current = (lowerBound + upperBound) >> 1; // Preview of Bitwise operations. Divides by 2

			// Binary search steps:
			// Step 1: Check if the middle is the value we are looking for
			if (this->m_array[current] == searchKey)
			{
				// Found the item in the middle of the array. Return the index
				return current;
			}
			// Step 2: Check that we've exhausted all options. Can't find the item
			else if (lowerBound > upperBound)
			{
				return -1;
			}
			else
			{
				// Step 3: Check which half of the array the value is in
				if (this->m_array[current] < searchKey)
				{
					lowerBound = current + 1;
				}
				else
				{
					upperBound = current - 1;
				}
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
private:
	bool m_duplicateData;
};