#include<iostream>
#include<vector>

template<
	class Key,
	class T,
	class Hash = std::hash<Key>,
	class KeyEqual = std::equal_to<Key>
> class TUnordered_Map {

public:
	using key_type = Key;
	using mapped_type = T;
	using value_type = std::pair<Key, T>;
	using size_type = size_t;
	using hasher = Hash;
	using key_equal = KeyEqual;
	using reference = value_type&;
	using const_reference = const value_type&;
	using bucket_arr = std::vector<value_type>;
	using hash_arr = std::vector<bucket_arr>;

	class TIterator :
		public std::iterator<std::forward_iterator_tag, value_type>
	{
		value_type * Ptr = nullptr;
		hash_arr Arr;
		size_type IndexBucket;
		bool ManyBucket;

		TIterator(value_type * ptr, hash_arr& arr, size_type& numberBucket)
			: Ptr(ptr)
			, Arr(arr)
			, IndexBucket(numberBucket)
			, ManyBucket(true)
		{}

		TIterator(value_type * ptr, size_type& numberBucket)
			: Ptr(ptr)
			, IndexBucket(numberBucket)
			, ManyBucket(false)
		{}

		friend class TUnordered_Map<Key, T, std::hash<Key>, std::equal_to<Key>>;

	public:
		TIterator() = default;

		TIterator& operator=(const TIterator&) = default;

		value_type& operator*() const
		{
			return *Ptr;
		}

		value_type* operator->() const
		{
			return Ptr;
		}

		bool operator != (const TIterator& r)
		{
			if (Ptr->first == r.Ptr->first)
				return false;
			else
				return true;
		}

		bool operator == (const TIterator& r)
		{
			return !(*this != r);
		}

		TIterator& operator ++ ()
		{
			if ((*Ptr) == Arr[IndexBucket].back())
			{
				size_type currentIndex = IndexBucket + 1;
				while (currentIndex < Arr.size() && Arr[currentIndex].empty())
				{
					++currentIndex;
				}
				if (currentIndex < Arr.size())
				{
					IndexBucket = currentIndex;
					Ptr = &Arr[IndexBucket][0];
				}
				else
				{
					++Ptr;
					++IndexBucket;
					return *this;
				}
			}
			else
				++Ptr;
			return *this;
		}
	};

	using iterator = TIterator;
	using const_iterator = const TIterator;
	using local_iterator = TIterator;
	using const_local_iterator = const TIterator;

private:
	hasher Hasher;
	key_equal Equal;
	size_type NumberBucket;
	hash_arr HashArr;

public:
	TUnordered_Map(size_type numberBuckets = 8, const hasher& hash = hasher(), const key_equal& keyEquality = key_equal())
		: NumberBucket(numberBuckets)
		, Hasher(hash)
		, Equal(keyEquality)
	{
		bucket_arr bucket;
		for (size_type i = 0; i < NumberBucket; ++i)
			HashArr.push_back(bucket);
	}

	iterator begin() throw()
	{
		size_type index = 0;
		while (HashArr[index].empty())
		{
			++index;
		}
		iterator it(&HashArr[index][0], HashArr, index);
		return it;
	}

	const_iterator begin() const throw()
	{
		size_type index = 0;
		while (bucketArr.empty())
		{
			++index;
		}
		return TIterator(&HashArr[index][0], HashArr, index);
	}

	iterator end() throw()
	{
		size_type n = NumberBucket - 1;
		value_type* ptr = &HashArr[n].back();
		iterator it(ptr, HashArr, n);
		++it;
		return it;
	}

	const_iterator end() const throw()
	{
		size_type n = NumberBucket - 1;
		value_type* ptr = &HashArr[n].back();
		iterator it(ptr, HashArr, n);
		++it;
		return it;
	}

	bool empty() const throw()
	{
		for (auto i = HashArr.begin(); i != HashArr.end(); ++i)
		{
			if (!i->empty())
				return false;
		}
		return true;
	}

	size_type size() const throw()
	{
		size_type len = 0;
		for (auto i = HashArr.begin(); i != HashArr.end(); ++i)
			len += i->size();
		return len;
	}

	std::pair<iterator, bool> insert(const value_type& value)
	{
		size_type index = Hasher(value.first) % NumberBucket;
		bucket_arr& bucket = HashArr[index];
		for (size_type i = 0; i <bucket.size(); ++i)
		{
			if (Equal(value.first, bucket[i].first))
				return std::pair<iterator, bool>(TIterator(&bucket[i], HashArr, index), false);
		}
		HashArr[index].push_back(value);
		value_type val = value;
		return std::pair<iterator, bool>(TIterator(&val, HashArr, index), true);
	}

	size_type erase(const key_type& key)
	{
		size_type index = Hasher(key) % NumberBucket;
		bucket_arr& bucket = HashArr[index];
		for (auto i = bucket.begin(); i != bucket.end(); ++i)
		{
			if (Equal(key, i->first))
			{

				bucket.erase(i);
				return 1;
			}
		}
		return 0;
	}

	void clear()
	{
		for (size_tupe i = 0; i < NumberBucket; ++i)
		{
			if (!HashArr[i].empty)
				HashArr[i].clear;
		}
	}

	void swap(TUnordered_Map& other) throw()
	{
		std::swap(Hasher, other.Hasher);
		std::swap(Equal, other.Equal);
		std::swap(NumberBucket, other.NumberBucket);
		std::swap(HashArr, other.HashArr);
	}

	mapped_type& at(const key_type& key)
	{
		size_type index = Hasher(key) % NumberBucket;
		for (size_type i = 0; i < HashArr[index].size(); i++)
		{
			if (Equal(key, HashArr[index][i].first))
				return HashArr[index][i].second;
		}
		throw std::out_of_range("Enter incorrect index!");
	}

	const mapped_type& at(const key_type& key) const
	{
		size_type index = Hasher(key) % NumberBucket;
		for (size_type i = 0; i < HashArr[index].size(); ++i)
		{
			if (Equal(key, HashArr[index][i].first))
				return HashArr[index][i].second;
		}
		throw std::out_of_range("Enter incorrect index!");
	}


	iterator find(const key_type& key)
	{
		size_type index = Hasher(key) % NumberBucket;
		bucket_arr& bucket = HashArr[index];
		for (size_type i = 0; i<bucket.size(); ++i)
			if (Equal(key, bucket[i].first))
				return TIterator(&bucket[i], HashArr, index);
		throw std::out_of_range("Enter incorrect index!");
	}


	size_type count(const key_type& key) const
	{
		size_type index = Hasher(key) % NumberBucket;
		bucket_arr bucket = HashArr[index];
		for (size_type i = 0; i<bucket.size(); ++i)
			if (Equal(key, bucket[i].first))
				return 1;
		return 0;
	}

	size_type bucket_count() const
	{
		size_type number = 0;
		for (auto i = HashArr.begin(); i != HashArr.end(); ++i) {
			if (!i->empty())
				++number;
		}
		return number;
	}

	size_type max_bucket_count() const
	{
		return NumberBucket;
	}

	size_type bucket(const key_equal& key) const
	{
		return Hasher(key) % NumberBucket;
	}

	size_type bucket_size(size_type n) const
	{
		return HashArr[n].size();
	}

	mapped_type& operator[](const key_type& key)
	{
		size_type index = Hasher(key) % NumberBucket;
		bucket_arr& bucket = HashArr[index];
		for (size_type i = 0; i < bucket.size(); ++i)
		{
			if (Equal(key, bucket[i].first))
				return bucket[i].second;
		}
		mapped_type data;
		bucket.push_back({key, data});
		return bucket[bucket.size() - 1].second;
	}

	TUnordered_Map& operator=(const TUnordered_Map& other)
	{
		Hasher = other.Hasher;
		Equal = other.Equal;
		HashArr = other.HashArr;
		NumberBucket = other.NumberBucket;
		return *this;
	}
};

template<
	class Key,
	class T,
	class Hash = std::hash<Key>,
	class KeyEqual = std::equal_to<Key>
>
bool operator==(TUnordered_Map<Key, T>& a, TUnordered_Map<Key, T>& b) throw() {
	if (a.size() != b.size())
		return false;
	for (auto i = a.begin(); i != a.end(); ++i) {
		if (a.count(i->first) != b.count(i->first))
			return false;
		if (i->second != b.at(i->second))
			return false;
	}
	return true;
}

template<
	class Key,
	class T,
	class Hash = std::hash<Key>,
	class KeyEqual = std::equal_to<Key>
>
bool operator!=(TUnordered_Map<Key, T>& a, TUnordered_Map<Key, T>& b) throw() {
	return !(a == b);
}