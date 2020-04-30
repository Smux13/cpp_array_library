#ifndef ARRAY_H_
#define ARRAY_H_

#include <cstddef>
#include <exception>
//#include <stdexcept>
#include <initializer_list>
#include <assert.h>
#include <math.h>

template <typename T, std::size_t size_value>
class Array
{
protected:
	T m_array[size_value];
public:
	Array() = default;

	Array(const std::initializer_list<T> &list);

	T& operator[](std::size_t index);
	const T& operator[](std::size_t index) const;

	T& at(std::size_t index);
	const T& at(std::size_t index) const;

	T& front();
	const T& front() const;

	T& back();
	const T& back() const;

	T* const data();
	const T* const data() const;

	T* const begin();
	const T* const cbegin() const;
	T* const end();
	const T* const cend() const;

	T* const rbegin();
	const T* const crbegin() const;
	T* const rend();
	const T* const crend() const;

	bool empty() const;

	std::size_t size() const;

	std::size_t max_size() const;

	void fill(const T &value);

	void swap(Array &other);
};

template <typename T, std::size_t size_value>
Array<T, size_value>::Array(const std::initializer_list<T> &list)
{
	if (list.size() > size_value)
		throw std::invalid_argument(
				"Too many initializers for the Array object");

	fill(static_cast<T>(0));

	int i{};
	for (const T &value : list)
	{
		m_array[i] = value;

		++i;
	}
}

template <typename T, std::size_t size_value>
T& Array<T, size_value>::operator[](std::size_t index)
{
	return m_array[index];
}

template <typename T, std::size_t size_value>
const T& Array<T, size_value>::operator[](std::size_t index) const
{
	return m_array[index];
}

template <typename T, std::size_t size_value>
T& Array<T, size_value>::at(std::size_t index)
{
	if (index >= size_value)
		throw std::out_of_range(
			(
				std::string(__FILE__) + ":" +
				std::to_string(__LINE__) + ":" +
				typeid(*this).name() + "::" +
				std::string(__FUNCTION__) +
				": index (which is " + std::to_string(index) +
				") >= size_value (which is " + std::to_string(size_value) + ")"
			).c_str()
		);

	return m_array[index];
}

template <typename T, std::size_t size_value>
const T& Array<T, size_value>::at(std::size_t index) const
{
	if (index >= size_value)
		throw std::out_of_range(
			(
				std::string(__FILE__) + ":" +
				std::to_string(__LINE__) + ":" +
				typeid(*this).name() + "::" +
				std::string(__FUNCTION__) +
				": index (which is " + std::to_string(index) +
				") >= size_value (which is " + std::to_string(size_value) + ")"
			).c_str()
		);

	return m_array[index];
}

template <typename T, std::size_t size_value>
T& Array<T, size_value>::front()
{
	// Calling this function on an empty
	// array is undefined, so we don't check the index
	return m_array[0];
}

template <typename T, std::size_t size_value>
const T& Array<T, size_value>::front() const
{
	// Calling this function on an empty
	// array is undefined, so we don't check the index
	return m_array[0];
}

template <typename T, std::size_t size_value>
T& Array<T, size_value>::back()
{
	// Calling on an empty array causes undefined behavior
	return m_array[size_value-1];
}

template <typename T, std::size_t size_value>
const T& Array<T, size_value>::back() const
{
	// Calling on an empty array causes undefined behavior
	return m_array[size_value-1];
}

template <typename T, std::size_t size_value>
T* const Array<T, size_value>::data()
{
	if (empty())
		return nullptr;

	return m_array;
}

template <typename T, std::size_t size_value>
const T* const Array<T, size_value>::data() const
{
	if (empty())
		return nullptr;

	return m_array;
}

template <typename T, std::size_t size_value>
T* const Array<T, size_value>::begin()
{
	if (size() == 0)
		return m_array + size_value;

	return m_array;
}

template <typename T, std::size_t size_value>
const T* const Array<T, size_value>::cbegin() const
{
	if (size() == 0)
		return m_array + size_value;

	return m_array;
}

template <typename T, std::size_t size_value>
T* const Array<T, size_value>::end()
{
	return m_array + size_value;
}

template <typename T, std::size_t size_value>
const T* const Array<T, size_value>::cend() const
{
	return m_array + size_value;
}

template <typename T, std::size_t size_value>
T* const Array<T, size_value>::rbegin()
{
	return m_array + (size_value - 1);
}

template <typename T, std::size_t size_value>
const T* const Array<T, size_value>::crbegin() const
{
	return m_array + (size_value - 1);
}

template <typename T, std::size_t size_value>
T* const Array<T, size_value>::rend()
{
	return m_array - 1;
}

template <typename T, std::size_t size_value>
const T* const Array<T, size_value>::crend() const
{
	return m_array - 1;
}

template <typename T, std::size_t size_value>
bool Array<T, size_value>::empty() const
{
	return !size_value;
}

template <typename T, std::size_t size_value>
std::size_t Array<T, size_value>::size() const
{
	return size_value;
}

template <typename T, std::size_t size_value>
std::size_t Array<T, size_value>::max_size() const
{
	return size_value;
}

template <typename T, std::size_t size_value>
void Array<T, size_value>::fill(const T &value)
{
	for (std::size_t i{}; i < size_value; ++i)
		m_array[i] = value;
}

template <typename T, std::size_t size_value>
void Array<T, size_value>::swap(Array &other)
{
	// Only Array with the same size
	// can be used as argument, so don't need to check the length

	Array temporary{other};

	for (std::size_t i{}; i < size_value; ++i)
		other[i] = m_array[i];

	for (std::size_t i{}; i < size_value; ++i)
		m_array[i] = temporary[i];
}

template <typename T, std::size_t size_value>
bool operator==(const Array<T, size_value> &a1, const Array<T, size_value> &a2)
{
	// Don't need to check length, this
	// function only accepts arrays with
	// the same template arguments (and with the same size)

	for (std::size_t i{}; i < a1.size(); ++i)
		if (a1[i] != a2[i])
			return false;

	return true;
}

/*-------------------------------------------------------------------

Template class specialization
There needs to be a specialization
for boolean values, because these are stored differently than other values

-------------------------------------------------------------------*/
/*
template <std::size_t size_value>
class Array<bool, size_value>
{
public:
	struct BoolPack
	{
		uint8_t i0:1;
		uint8_t i1:1;
		uint8_t i2:1;
		uint8_t i3:1;
		uint8_t i4:1;
		uint8_t i5:1;
		uint8_t i6:1;
		uint8_t i7:1;
	};
protected:
	// This stores the number of items in
	// the array, the number of bool values = m_arraySize * 8, because
	// 8 array values are stored in 1 element
	std::size_t m_arraySize;
	BoolPack *m_array;
public:
	Array();

	Array(const std::initializer_list<bool> &list);

	~Array();

	bool& operator[](std::size_t index);

	bool operator[](std::size_t index) const;

	//bool& at(std::size_t index);
	//const bool& at(std::size_t index) const;

	//bool& front();
	//const bool& front() const;

	//bool& back();
	//const bool& back() const;

	//bool* const data();
	//const bool* const data() const;

	//bool* const begin();
	//const bool* const cbegin() const;
	//bool* const end();
	//const bool* const cend() const;

	//bool* const rbegin();
	//const bool* const crbegin() const;
	//bool* const rend();
	//const bool* const crend() const;

	//bool empty() const;

	std::size_t size() const;

	//std::size_t max_size() const;

	void fill(bool value);

	//void swap(Array<bool, size_value> &other);
};

template <std::size_t size_value>
Array<bool, size_value>::Array()
	: m_arraySize{static_cast<std::size_t>(ceil(size_value/8.0))},
	  m_array{new BoolPack[m_arraySize]}
	{
	}

template <std::size_t size_value>
Array<bool, size_value>::Array(const std::initializer_list<bool> &list)
	: Array()
{
	fill(false);

	int i{};
	for (bool& item : list)
	{
		operator[](i) = 0;

		++i;
	}
}

template <std::size_t size_value>
Array<bool, size_value>::~Array()
{
	delete[] m_array;
}

template <std::size_t size_value>
bool Array<bool, size_value>::operator[](std::size_t index) const
{
	// The index of the element in the array
	int elementIndex{index/8};
	// The index of the bit in the element
	int bitIndex{index%8};

	std::cout << "Element: " << elementIndex << ", Bit: " << bitIndex << '\n';

	BoolPack &currentElement{m_array[elementIndex]};

	switch(index % 8)
	{
		case 0: return currentElement.i0;
		case 1: return currentElement.i1;
		case 2: return currentElement.i2;
		case 3: return currentElement.i3;
		case 4: return currentElement.i4;
		case 5: return currentElement.i5;
		case 6: return currentElement.i6;
		case 7: return currentElement.i7;
		default:;
	}
}


template <std::size_t size_value>
bool& Array<bool, size_value>::operator[](std::size_t index)
{
	// The index of the element in the array
	int elementIndex{index/8};
	// The index of the bit in the element
	int bitIndex{index%8};

	std::cout << "Element: " << elementIndex << ", Bit: " << bitIndex << '\n';

	//BoolPack &currentElement{};

	switch(index % 8)
	{
		case 0: return m_array[elementIndex].i0;
		case 1: return m_array[elementIndex].i1;
		case 2: return m_array[elementIndex].i2;
		case 3: return m_array[elementIndex].i3;
		case 4: return m_array[elementIndex].i4;
		case 5: return m_array[elementIndex].i5;
		case 6: return m_array[elementIndex].i6;
		case 7: return m_array[elementIndex].i7;
		default:;
	}
}

template <std::size_t size_value>
std::size_t Array<bool, size_value>::size() const
{
	return size_value;
}

template <std::size_t size_value>
void Array<bool, size_value>::fill(bool value)
{
	for (std::size_t i{}; i < size_value; ++i)
		operator[](i) = value;
}
*/
#endif /* ARRAY_H_ */
