#include "int_buffer.h"


// Constructor initializer
int_buffer::int_buffer(size_t size) : startPtr((new int[size])), endPtr(startPtr + size)
{
	std::cout << "Initializer constructor doing its thaaang." << std::endl;
}

int_buffer::int_buffer(const int* source, size_t size)
{

}

// Size of buffer
size_t int_buffer::size() const 
{
	return (endPtr - startPtr);
}

// first element pos
int* int_buffer::begin()
{
	return startPtr;
}

// last element pos
int* int_buffer::end()
{
	return endPtr;
}

// same as above but const
const int* int_buffer::begin() const
{
	return startPtr;
}

// same as above but const
const int* int_buffer::end() const
{
	return endPtr;
}

// copy construct
int_buffer::int_buffer(const int_buffer& rhs)
{
	std::cout << "Copy constructor doing its thaaaaaaang." << std::endl;

	startPtr = new int[rhs.size()];
	endPtr	 = rhs.startPtr + rhs.size();

	std::copy(rhs.startPtr, endPtr, startPtr);
}

// Destructor
int_buffer::~int_buffer()
{
	// delete allocated memory
	if(startPtr != nullptr)
		delete[] startPtr;

	if(endPtr != nullptr)
		delete[] endPtr;

	// point on null
	startPtr = nullptr;
	endPtr	 = nullptr;
}

// move construct
int_buffer::int_buffer(int_buffer&& rhs)
{

}

// copy assign
int_buffer& int_buffer::operator=(const int_buffer& rhs)
{
	if (this != &rhs)
	{
		// Delete old data
		delete[] startPtr;
		delete[] endPtr;

		// get new values
		startPtr = new int[rhs.size()];
		endPtr	 = startPtr + rhs.size();

		std::copy(rhs.startPtr, endPtr, startPtr);
	}
	return *this;
}

int_buffer& int_buffer::operator=(int_buffer&& rhs)
{

}

// move assign
int& int_buffer::operator[](size_t index)
{

}

const int& int_buffer::operator[](size_t index) const
{

}