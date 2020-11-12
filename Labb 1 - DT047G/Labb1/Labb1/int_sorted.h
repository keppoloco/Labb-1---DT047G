#pragma once

#ifndef INT_SORTED
#define INT_SORTED

class int_sorted {
public:
	int_sorted(const int* source, size_t size);
	size_t size() const;
	
	// returns the insertion point
	int* insert(int value);

	const int* begin() const;
	const int* end() const;

	int_sorted merge(const int_sorted& merge_with) const;
};


#endif