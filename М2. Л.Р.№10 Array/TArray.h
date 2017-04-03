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

	iterator data() throw() {
		return Arr;
	}

	const_iterator data() const throw(){
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