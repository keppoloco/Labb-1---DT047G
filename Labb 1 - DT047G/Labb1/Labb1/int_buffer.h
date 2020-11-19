// Laboration 1 - Programmeringsmetodik, dt047g
// Timmy Nord (tino1800)
// main.cpp Created 10 Nov, Last edited 19 Nov
// är header för int_buffer med sina klassmedlemmar samt klassmetoder
#pragma once
#ifndef INT_BUFFER_H
#define INT_BUFFER_H
#include <memory>
#include <iostream>

class int_buffer {
public:

	explicit int_buffer(size_t size);

	int_buffer(const int* source, size_t size);

	// copy construct
	int_buffer(const int_buffer& rhs);

	// move construct
	int_buffer(int_buffer&& rhs) noexcept;

	// copy assign
	int_buffer& operator =(const int_buffer& rhs);

	// move assign
	int_buffer& operator =(int_buffer&& rhs) noexcept;

	int& operator [](size_t index);

	const int& operator[](size_t index) const;

	size_t size() const;

	int* begin();

	int* end();

	const int* begin() const;

	const int* end() const;

	~int_buffer();

private:
	int* startPtr;
	int* endPtr;
	void swap(int_buffer& rhs);
};
#endif