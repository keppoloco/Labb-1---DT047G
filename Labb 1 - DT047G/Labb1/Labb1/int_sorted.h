// Laboration 1 - Programmeringsmetodik, dt047g
// Timmy Nord (tino1800)
// main.cpp Created 10 Nov, Last edited 19 Nov
// är header för int_sorted med sina klassmedlemmar samt klassmetoder
#pragma once
#ifndef INT_SORTED
#define INT_SORTED
#include "int_buffer.h"
#include <algorithm>
class int_sorted {
public:
	int_sorted() = delete;
	int_sorted(const int* source, size_t size);
	size_t size() const;
	
	// returns the insertion point
	int* insert(int value);

	const int* begin() const;
	const int* end() const;

	int_sorted merge(const int_sorted& merge_with) const;

	int_sorted sort(const int* begin, const int* end);

	void print() const;

private: 
	int_buffer buffer_;
};

#endif