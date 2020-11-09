#include "int_buffer.h"


// Constructor initializer
int_buffer::int_buffer(size_t size) : ptr((new int[size])), buf_size(size) 
{

}

// Size
size_t int_buffer::size() const 
{
	return buf_size;
}

// copy construct
int_buffer::int_buffer(const int_buffer& rhs)
{

}

// Destructor
int_buffer::~int_buffer()
{
	// delete allocated memory
	delete[] p;

	// point on null
	p = nullptr;
}

// move construct
int_buffer::int_buffer(int_buffer&& rhs)
{

}

// copy assign
int_buffer& int_buffer::operator=(const int_buffer& rhs)
{

}

int_buffer& int_buffer::operator=(int_buffer&& rhs)
{

}