#pragma once
#include<iostream>
#include <initializer_list>
#include<exception>

template<
	class T,
	std::size_t N
> struct TArray {
	using value_type = T;
	using size_type = size_t;
	using iterator = value_type *;
	using const_iterator = const value_type *;
	using reference = value_type&;
	using const_reference = const value_type&;

	value_type Arr[N];

	TArray() = default;
	~TArray() = default;

	TArray(std::initializer_list<T> arr) : TArray()
	{
		size_type i = 0;
		for (auto & v : arr) {
			Arr[i] = v;
			++i;
		}
	}

	reference at(const size_type index) {
		if (CorrectIndex(index))
			return Arr[index];
	}

	const_reference at(const size_type index) const{
		if (CorrectIndex(index))
			return Arr[index];
	}

	reference operator[](size_type index) {
		return Arr[index];
	}

	const_reference operator[](size_type index) const{
		return Arr[index];
	}

	reference front(){
		if (CheckForEmpty())
			return Arr[0];
	}

	const_reference front() const{
		if (CheckForEmpty())
			return Arr[0];
	}

	reference back() {
		if (CheckForEmpty())
			return Arr[N - 1];
	}

	const_reference back() const{
		if (CheckForEmpty())
			return Arr[N - 1];
	}

	T* data() throw() {
		return Arr;
	}

	const T* data() const throw(){
		return Arr;
	}

	iterator begin() throw(){
		return Arr;
	}

	iterator end() throw(){
		return Arr + N;
	}

	bool empty() const throw(){
		return size() == 0;
	}

	size_type size() const throw(){
		return N;
	}

	size_type max_size() const throw() {
		return N;
	}

	void fill(const value_type & value) {
		for (size_type i = 0; i < N; ++i)
			Arr[i] = value;
	}

	void swap(TArray<T, N> & b) throw(){
		std::swap(Arr, b.Arr);
	}

	bool operator== (const TArray<T, N> & b) const {
		size_type sizeArr1 = size();
		size_type sizeArr2 = b.size();
		if (sizeArr1 != sizeArr2)
			return false;
		for (size_type i = 0; i < sizeArr1; ++i) {
			if (Arr[i] != b.Arr[i])
				return false;
		}
		return true;
	}
		
	bool operator<(const TArray & b) const {
		size_type sizeArr1 = size();
		size_type sizeArr2 = b.size();
		size_type i = 0;
		while (i < sizeArr1 && i < sizeArr2) {
			if (Arr[i] < b.Arr[i]) return true;
			if (Arr[i] > b.Arr[i]) return false;
			++i;
		}
		if (sizeArr1 < sizeArr2)
			return true;
		else
			return false;
	}

private:
	bool CheckForEmpty() const {
		if (!this->empty())
			return true;
		else
			throw std::length_error("Errow! Arr is empty!");
	}

	bool CorrectIndex(size_type index) const {
		if (index >= 0 && index < N )
			return true;
		else
			throw std::out_of_range("Errow! Enter incorrect index!");
	}
};

template<class T, std::size_t N>
void swap(TArray<T, N> & a, TArray<T, N> & b) {
	a.swap(b);
}

template<class T, std::size_t N>
bool operator!= (const TArray<T, N> & a, const TArray<T, N> & b) {
	if (a == b)
		return false;
	else
		return true;
}

template<class T, std::size_t N>
bool operator> (const TArray<T, N> & a, const TArray<T, N> & b) {
	if (a == b || a < b)
		return false;
	else
		return true;
}

template<class T, std::size_t N>
bool operator>= (const TArray<T, N> & a, const TArray<T, N> & b) {
	if (a == b || a > b)
		return true;
	else
		return false;
}

template<class T, std::size_t N>
bool operator<= (const TArray<T, N> & a, const TArray<T, N> & b) {
	if (a == b || a < b)
		return true;
	else
		return false;
}