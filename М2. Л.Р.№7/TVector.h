#pragma once
#ifndef __TVECTOR_INCLUDED__
#define __TVECTOR_INCLUDED__
#define _SCL_SECURE_NO_WARNINGS
#include<iostream>


template<typename T>
class TVector
{
public:
	class TIterator :
		public std::iterator<std::random_access_iterator_tag, T>
	{
		T * Ptr = nullptr;

		TIterator(T * p) :
			Ptr(p)
		{ }

		friend class TVector<T>;

	public:
		TIterator() = default;
		TIterator& operator=(const TIterator&) = default;

		T& operator*() const
		{
			return *Ptr;
		}

		T* operator->() const
		{
			return Ptr;
		}

		bool operator != (const TIterator& r)
		{
			return Ptr != r.Ptr;
		}

		bool operator < (const TIterator& r)
		{
			return Ptr < r.Ptr;
		}

		bool operator == (const TIterator& r)
		{
			return !(*this != r);
		}

		TIterator& operator ++ ()
		{
			++Ptr;
			return *this;
		}

		TIterator& operator -- ()
		{
			--Ptr;
			return *this;
		}

		TIterator& operator + (size_t cnt)
		{
			Ptr += cnt;
			return *this;
		}

		TIterator& operator - (size_t cnt)
		{
			Ptr -= cnt;
			return *this;
		}

		size_t operator - (TIterator& cnt)
		{
			size_t rezult = Ptr - cnt.Ptr;
			return rezult;
		}
	};

	using value_type = T;
	using size_type = size_t;
	using iterator = TIterator;
	using reference = value_type&;
	using const_reference = const value_type&;

private:
	value_type * Ptr;
	size_type Count;
	size_type InternalCapacity;
public:
	TVector()
		: Ptr(nullptr)
		, Count(0)
		, InternalCapacity(0)
	{ }

	TVector(size_type capacity)
		: Count(0)
		, InternalCapacity(capacity)
	{
		Ptr = new value_type[InternalCapacity];
	}

	~TVector()
	{
		delete[] Ptr;
	}

	bool empty() const throw()
	{
		return size() == 0;
	}

	size_type size() const throw()
	{
		return Count;
	}

	size_type capacity() const throw()
	{
		return InternalCapacity;
	}

	iterator begin() const throw()
	{
		return TIterator(Ptr);
	}

	iterator end() const throw()
	{
		return TIterator(Ptr + Count);
	}

	void reserve(size_type size)
	{
		if (size < InternalCapacity)
			return;
		value_type* ptr = new value_type[size];
		for (size_type i = 0; i < Count; ++i) {
			ptr[i] = Ptr[i];
		}
		delete[] Ptr;
		Ptr = ptr;
		InternalCapacity = size;
	}

	TVector(const TVector& rhs)
	{
		Count = rhs.Count;
		InternalCapacity = rhs.InternalCapacity;
		Ptr = new value_type[InternalCapacity];
		std::copy(rhs.begin(), rhs.end(), Ptr);
	}

	TVector& operator=(const TVector& rhs)
	{
		if (&rhs == this)
			return *this;
		delete[] Ptr;
		InternalCapacity = rhs.InternalCapacity;
		Count = rhs.Count;
		Ptr = new value_type[InternalCapacity];
		std::copy(rhs.begin(), rhs.end(), Ptr);
		return *this;
	}

	void push_back(const value_type& value)
	{
		if (InternalCapacity == 0)
			reserve(16);
		if (Count < InternalCapacity) {
			Ptr[Count] = value;
			++Count;
		}
		else {
			this->reserve(2 * InternalCapacity);
			Ptr[Count] = value;
			++Count;
		}
	}

	reference at(size_type index)
	{
		if (CorrectIndex(index))
			return Ptr[index];
	}

	value_type at(size_type index) const
	{
		if (CorrectIndex(index))
			return Ptr[index];
	}

	reference operator[](size_type index)
	{
		return Ptr[index];
	}

	const_reference operator[](size_type index) const
	{
		return Ptr[index];
	}

	reference front()
	{
		if (CheckForEmpty())
			return Ptr[0];
	}

	const_reference front() const
	{
		if (CheckForEmpty())
			return Ptr[0];
	}

	reference back()
	{
		if (CheckForEmpty())
			return Ptr[Count - 1];
	}

	const_reference back() const
	{
		if (CheckForEmpty())
			return Ptr[Count - 1];
	}

	void clear()
	{
		Count = 0;
		InternalCapacity = 0;
		delete[] Ptr;
	}

	void pop_back()
	{
		if (CheckForEmpty())
			--Count;
	}

	void swap(TVector& other) throw()
	{
		std::swap(Count, other.Count);
		std::swap(InternalCapacity, other.InternalCapacity);
		std::swap(Ptr, other.Ptr);
	}

	void resize(size_type count, value_type value = value_type())
	{
		if (count == Count)
			return;
		value_type* ptr = new value_type[count];
		if (count < Count)
		{
			iterator it = this->begin() + count;
			std::copy(this->begin(), it, ptr);
		}
		else {
			if (count > InternalCapacity)
				reserve(2 * InternalCapacity);
			std::copy(this->begin(), this->end(), ptr);
			for (size_type i = Count; i < count; ++i) {
				ptr[i] = value;
			}
		}
		delete[] Ptr;
		Ptr = ptr;
		Count = count;
	}

	iterator insert(iterator pos, const value_type& value)
	{
		if (TIterator(Ptr + Count) < pos)
			throw std::out_of_range("Incorrect index!");
		size_type position = pos - this->begin();
		if (Count >= InternalCapacity)
			this->reserve(2 * InternalCapacity);
		for (size_type i = Count - 1; i >= position; --i) {
			Ptr[i + 1] = Ptr[i];
		}
		Ptr[position] = value;
		++Count;
		return pos;
	}

	void insert(iterator pos, size_type count, const value_type& value)
	{
		if (pos > Ptr + Count)
			throw std::out_of_range("Incorrect index!");
		while (Count + count > InternalCapacity)
			this->reserve(2 * InternalCapacity);
		size_type position = pos - Ptr;
		for (size_type i = Count - 1; i >= position; --i) {
			Ptr[i + count] = Ptr[i];
		}
		for (size_type i = position; i < position + count; ++i) {
			Ptr[i] = value;
		}
		Count += count;
	}

	iterator erase(iterator pos)
	{
		size_type position = pos - this->begin();
		if (CheckForEmpty() && CorrectIndex(position)) {
			for (size_type i = position; i < Count - 1; ++i) {
				Ptr[i] = Ptr[i + 1];
			}
			--Count;
		}
		return pos;
	}

	iterator erase(iterator first, iterator last)
	{
		size_type positionFirst = first - this->begin();
		size_type positionLast = last - this->begin();
		size_type number = positionLast - positionFirst;
		if (CheckForEmpty() && CorrectIndex(positionFirst) && CorrectIndex(positionLast)) {
			for (size_type i = positionFirst; i < Count - number; ++i) {
				Ptr[i] = Ptr[i + number];
			}
			Count -= number;
		}
		return first;
	}

private:
	bool CheckForEmpty() const {
		if (!this->empty())
			return true;
		else
			throw std::length_error("Errow! Arr is empty!");
	}

	bool CorrectIndex(size_type index) const {
		if (index >= 0 && index <= Count)
			return true;
		else
			throw std::out_of_range("Enter incorrect index!");
	}
};


#endif // __TVECTOR_INCLUDED__