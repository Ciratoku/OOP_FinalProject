#pragma once

template <typename T>
class smart_ptr
{
private:
	T* ptr;
public:
	smart_ptr()
	{
		ptr = nullptr;
	}

	smart_ptr(T* ptr)
	{
		this->ptr = ptr;
	}

	smart_ptr(smart_ptr& obj)
	{
		ptr = obj.ptr;
		obj.ptr = nullptr;
	}

	~smart_ptr()
	{
		delete ptr;
	}

	T& operator*() const
	{
		return *ptr;
	}

	T* operator->() const
	{
		return ptr;
	}

	smart_ptr& operator=(smart_ptr& obj)
	{
		if (&obj == this)
			return *this;
		delete ptr;
		ptr = obj.ptr;
		obj.ptr = nullptr;
		return *this;
	}
};