#pragma once

#include "cell.h"
template <class T>
class iterator
{
private:
	T* ptr;
public:
	iterator(T* Ptr) : ptr(Ptr) {}

	iterator& operator++()
	{
		ptr++;
		return *this;
	}

	iterator& operator++(int)
	{
		iterator itr = *this;
		++(*this);
		return itr;
	}

	iterator& operator+(int val)
	{
		for(int i = 0; i < val; ++i)
			ptr++;
		return *this;
	}

	iterator& operator-(int val)
	{
		for(int i = 0; i < val; ++i)
			ptr--;
		return *this;
	}

	iterator& operator--()
	{
		ptr--;
		return *this;
	}

	iterator& operator--(int)
	{
		iterator itr = *this;
		--(*this);
		return itr;
	}

	T& operator[](int index)
	{
		return *(ptr + index);
	}

	T* operator->()
	{
		return *ptr;
	}

	T& operator*()
	{
		return *ptr;
	}

	bool operator==(const iterator& other) const
	{
		return ptr == other.ptr;
	}

	bool operator!=(const iterator& other) const
	{
		return ptr != other.ptr;
	}
};