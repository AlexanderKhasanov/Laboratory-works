#pragma once
#ifndef __BOOLEAN_FUNCTION_INCLUDED__
#define __BOOLEAN_FUNCTION_INCLUDED__

#include <string>
#include <vector>

class boolean_function
{
public:
	using value_type = bool;
	using size_type = size_t;
	using reference = std::vector<value_type>::reference;
	using const_reference = std::vector<value_type>::const_reference;

	using iterator = typename std::vector<value_type>::iterator;
	using const_iterator = typename std::vector<value_type>::const_iterator;

	std::vector<value_type> Vector;

public:

	// возвращает функцию которая равна xn с размерностью dimension
	// пример 1
	// n = 0
	// dimension = 3
	// вернется функция "01010101"
	// пример 2
	// n = 1
	// dimension = 4
	// вернется функция "0011001100110011"
	static boolean_function var(size_t n, size_t dimension)
	{
		boolean_function bf(pow(2, dimension));
		bool change = false;
		for (size_t i = 0; i != pow(2, dimension); i + pow(2, n))
		{
			if (change)
			{
				for (size_t j = 0; j < pow(2, n); ++j)
					bf.Vector[i + j] = 1;
				change = false;
			}
			else
				change = true;
		}
		return bf;
	}

	// тождественный ноль "от dimension переменных"
	static boolean_function zero(size_t dimension)
	{
		return boolean_function(dimension);
	}

	// тождественная единица "от dimension переменных"
	static boolean_function one(size_t dimension)
	{
		//size_t value = pow(2, dimension) - 1;
		//return boolean_function(value, dimension);
		return boolean_function(pow(2, dimension) - 1, dimension);
	}

	static boolean_function from_anf(std::vector<value_type> v)
	{
		boolean_function bf;
		while (v.size() >= 1)
		{
			bf.Vector.push_back(v[0]);
			for (size_t i = 0; i < v.size() - 1; ++i)
			{
				v[i] = v[i] ^ v[i + 1];
			}
			v.pop_back();
		}
		return bf;
	}

	boolean_function() : Vector()
	{}

	// задает фунцию тождественного нуля от n переменных
	boolean_function(size_t n) : Vector(pow(2, n), 0)
	{}

	// задает фунцию от n переменных. значение равно value
	// пример
	// пусть value = 14, т.е. 0...00001110 в двоичной системе
	// а n = 3
	// тогда АНФ boolean_function будет равна x + y + xy + zx + zy + zyx
	boolean_function(unsigned long long value, size_type n)
	{
		unsigned long long len = pow(2, n);
		for (size_t i = 0; i < pow(2, n); ++i)
		{
			size_t x = len & 1;
			Vector.push_back(x);
			len >> 1;
		}
		/*for (size_t i = 0; i < pow(2, n); ++i)
		{
		size_t x = value % 2;
		value /= 2;
		Vector.push_back(x);
		}*/
	}

	// пусть table = "01110000"
	// тогда АНФ boolean_function будет равна x + y + xy + zx + zy + zyx
	boolean_function(const std::string& table)
	{
		if (log2(table.size()) != 2)
			throw std::logic_error("Error! Sets are incomparable!");
		Vector.insert(this->end(), table.begin(), table.end());
	}

	// пусть table = {true, false, false, true};
	// тогда АНФ boolean_function будет равна x + y + 1
	boolean_function(const std::vector<value_type>& table)
	{
		Vector.insert(this->end(), table.begin(), table.end());
		if (log2(table.size()) != 2)
			throw std::logic_error("Error! Sets are incomparable!");
	}

	boolean_function(const std::initializer_list<bool> vars)
	{
		if (log2(vars.size()) != 2)
			throw std::logic_error("Error! Sets are incomparable!");
		Vector.insert(this->end(), vars.begin(), vars.end());
	}

	boolean_function(const boolean_function& table)
	{
		Vector = table.Vector;
	}

	boolean_function& operator=(const boolean_function& rhs)
	{
		if (&rhs == this)
			return *this;
		Vector = rhs.Vector;
		return *this;
	}

	// сложение по модулю 2
	// если разное количество переменных - исключение
	boolean_function& operator += (const boolean_function& rhs)
	{
		if (this->size() != rhs.size())
			throw std::exception("Error! Different length of vectors");
		for (size_t i = 0; i < this->size(); ++i)
		{
			Vector[i] = Vector[i] ^ rhs.Vector[i];
		}
		return *this;
	}

	// конъюнкция
	// если разное количество переменных - исключение
	boolean_function& operator *= (const boolean_function& rhs)
	{
		if (this->size() != rhs.size())
			throw std::exception("Error! Different length of vectors");
		for (size_t i = 0; i < this->size(); ++i)
		{
			Vector[i] = Vector[i] & rhs.Vector[i];
		}
	}

	// дизъюнкция
	// если разное количество переменных - исключение
	boolean_function& operator |= (const boolean_function& rhs)
	{
		if (this->size() != rhs.size())
			throw std::exception("Error! Different length of vectors");
		for (size_t i = 0; i < this->size(); ++i)
		{
			Vector[i] = Vector[i] | rhs.Vector[i];
		}
	}

	// побитовое отрицание
	boolean_function& operator ~ ()
	{
		Vector.flip();
		return *this;
	}

	// true если функции равны
	//  иначе false
	bool operator == (const boolean_function& rhs) const
	{
		if (this->size() != rhs.size())
			return false;
		for (auto i = 0; i < this->size(); ++i)
		{
			if (Vector[i] != rhs[i])
				return false;
		}
		return true;
	}

	// true если одна функция сравнима и больше или равна rhs
	// false если сравнима и меньше rhs
	// logic_error если фунции не сравнимы
	bool operator >= (const boolean_function& rhs) const
	{
		if (!is_comparable(*this, rhs))
			throw std::logic_error("Error! Sets are incomparable!");
		for (size_t i = 0; i < this->size(); ++i)
		{
			if (Vector[i] < rhs[i])
				return false;
			if (Vector[i] > rhs[i])
				return true;
		}
	}

	reference operator[](size_type ind)
	{
		return Vector[ind];
	}

	const_reference operator[](size_type ind) const
	{
		return Vector[ind];
	}

	reference at(size_type ind)
	{
		return Vector.at(ind);
	}

	const_reference at(size_type ind) const
	{
		return Vector.at(ind);
	}

	iterator begin()
	{
		return Vector.begin();
	}

	iterator end()
	{
		return Vector.end();
	}

	const_iterator cbegin() const
	{
		return Vector.cbegin();
	}

	const_iterator cend() const
	{
		return Vector.cend();
	}

	// длина столбца функции
	size_type size() const throw()
	{
		return Vector.size();
	}

	// количество переменных
	size_type dimension() const throw()
	{
		return log2(size());
	}

	// возвращает значение функции
	// пусть boolean_function задает функцию f(x, y, z)
	// тогда функция вернет f(vars[0], vars[1], vars[2])
	bool operator()(const std::vector<bool>& vars) const
	{
		size_t num = 0;
		for (size_t i = 0; i < vars.size(); ++i)
		{
			if(vars[vars.size() - 1 - i])
				num += pow(2, i);
		}
		return Vector[num];
	}
	bool operator()(const std::initializer_list<bool> vars) const 
	{
		size_t num = 0;
		size_t i = 0;
		for (auto &v : vars)
		{
			if (v == true)
				num += pow(2, i);
			++i;
		}
		return Vector[num];
	}


	// T(x1, x2, ..., xN) - текущая функция
	// operator вернет новую функцию, которая равна композиции G = T(fs[0], fs[1], ..., fs[N-1])
	boolean_function operator()(const std::vector<boolean_function>& fs) const;
	boolean_function operator()(const std::initializer_list<boolean_function> vars) const;

	bool is_monotone() const
	{
		size_t dist = this->size()/2;
		while (dist > 0)
		{
			for (size_t i = 0; i < this->size(); i + 2*dist)
			{
				for (size_t j = 0; j < dist; ++j)
				{
					if (Vector[i + j] > Vector[i + j + dist]) 
						return false;
				}
			}
			dist /= 2;
		}
		return true;
	}
	bool is_symmetric() const
	{
		std::vector<value_type> vec;
		for (int i = this->size() - 1; i >= 1; --i)
		{
			vec.push_back(Vector[i]);
		}
		vec.flip();
		return Vector == vec;
	}
	bool is_linear() const
	{
		std::vector<value_type> anff = anf();
		bool check = true;
		size_t ost = 0;
		size_t n = 0;
		for (int i = 0; i < anff.size(); i++)
		{
			ost = 0;
			n = i;
			while (n > 0)
			{
				ost += n % 2;
				n /= 2;
			}
			if (ost >= 1)
			{
				if (anff[i] != 0)
				{
					check = false;
					break;
				}
			}
		}
		return check;
	}

	bool is_T1() const
	{
		return Vector[size() - 1] == 1;
	}

	bool is_T0() const
	{
		return Vector[0] == 0;
	}

	bool is_balanced() const //равновесная ли
	{
		size_t one = 0;
		size_t zero = 0;
		for (auto i = this->cbegin(); i != this->cend(); ++i)
		{
			if (*i == 0)
				++zero;
			else
				++one;
		}
		return zero == one;
	}

	size_t weight() const
	{
		size_t one = 0;
		for (auto i = this->cbegin(); i != this->cend(); ++i)
		{
			if (*i == 1)
				++one;
		}
		return one;
	}

	bool is_functionally_complete_system() const
	{
		if (!is_T0() && !is_T1() && !is_symmetric() && !is_monotone() && !is_linear())
			return true;
		else
			return false;
	}

	// Возвращает АНФ функции
	std::vector<value_type> anf() const
	{
		std::vector<value_type> vec = Vector;
		std::vector<value_type> anff;
		while (vec.size() >= 1)
		{
			anff.push_back(vec[0]);
			for (size_t i = 0; i < vec.size() - 1; ++i)
			{
				vec[i] = vec[i] ^ vec[i + 1];
			}
			vec.pop_back();
		}
		return anff;
	}

private:
	bool is_comparable(const boolean_function& a, const boolean_function& b) const
	{
		if (a.size() != b.size())
			return false;
		bool is_more = false;
		bool is_less = false;
		for (size_t i = 0; i < a.size(); ++i)
		{
			if (a[i] > b[i])
				is_more = true;
			else
				is_less = true;
			if (is_more && is_less)
				return false;
		}
		return true;
	}
};

// пусть boolean_function представляет из себя функцию "01110000"
// тогда get_polynom вернет строку "x0 + x1 + x0x1 + x0x2 + x1x2 + x0x1x2"
std::string get_polynom(const boolean_function&);

boolean_function operator + (const boolean_function& a, const boolean_function& b)
{
	boolean_function bf(a);
	bf += b;
	return bf;
}

boolean_function operator * (const boolean_function& a, const boolean_function& b)
{
	boolean_function bf(a);
	bf *= b;
	return bf;
}

boolean_function operator | (const boolean_function& a, const boolean_function& b)
{
	boolean_function bf(a);
	bf |= b;
	return bf;
}

bool operator != (const boolean_function& a, const boolean_function& b)
{
	return !(a == b);
}

double log2(size_t x)
{
	return log(x) / log(2);
}

#endif // __BOOLEAN_FUNCTION_INCLUDED__
