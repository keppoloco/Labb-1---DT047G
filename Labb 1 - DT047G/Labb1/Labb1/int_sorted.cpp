// Laboration 1 - Programmeringsmetodik, dt047g
// Timmy Nord (tino1800)
// main.cpp Created 10 Nov, Last edited 19 Nov
// definitioner av int_sorteds metoder
#include "int_sorted.h"
int_sorted::int_sorted(const int* source, size_t size) : buffer_(nullptr, 0)
{
	if (size > 1)
	{
		buffer_ = sort(source, source+size).buffer_;
	}
	else
	{
		buffer_ = int_buffer(source, size);
	}
}

void int_sorted::print() const {
	for (const int* i = buffer_.begin(); i != buffer_.end(); i++)
		std::cout << *i << ' ';
}


size_t int_sorted::size() const 
{
	return buffer_.size();
}

int* int_sorted::insert(int value)
{
	int_sorted val(&value, 1);

	//*this = merge(val);
	buffer_ = std::move(merge(val).buffer_);

	/*for (auto it = buffer_.begin(); it != buffer_.end(); it++)
	{
		if (*it == value) 
		{
			return buffer_.end() - *it;
		}
	}*/
	return std::find(buffer_.begin(), buffer_.end(), value);
	// alternativt lower bound:
	// std::lower_bound (buffer_.begin(), buffer_.end(), value)
}

const int* int_sorted::begin() const
{
	return buffer_.begin();
}

const int* int_sorted::end() const
{
	return buffer_.end();
}

int_sorted int_sorted::sort(const int* begin, const int* end) {
	if (begin == end) return
		int_sorted(nullptr, 0);

	if (begin == end - 1) return
		int_sorted(begin, 1);

	ptrdiff_t half = (end - begin) / 2; //

	const int* mid = begin + half;

	return sort(begin, mid).merge(sort(
		mid, end));
}

int_sorted int_sorted::merge(const int_sorted& merge_with) const
{
	int_buffer c(merge_with.size() + size());

	const int* thisIterator = begin();
	const int* otherIterator = merge_with.begin();
	int* c_buff = c.begin();

	while ( thisIterator != end() && otherIterator != merge_with.end() )
	{
		if (*otherIterator < *thisIterator)
		{
			*c_buff = *otherIterator;

			c_buff++;

			otherIterator++;
		}
		else 
		{
			*c_buff = *thisIterator;

			c_buff++;

			thisIterator++;
		}
	}

	while ( thisIterator != end() )
	{
		*c_buff = *thisIterator;

		c_buff++;

		thisIterator++;
	}

	while ( otherIterator != merge_with.end())
	{
		*c_buff = *otherIterator;

		c_buff++;

		otherIterator++;
	}

	int_sorted finalBuff(nullptr, 0);
	//finalBuff.buffer_ = c;
	finalBuff.buffer_ = std::move(c);

	return finalBuff;
}

