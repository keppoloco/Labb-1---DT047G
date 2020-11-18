#include "int_buffer.h"
#include <algorithm>
// Constructor initializer
int_buffer::int_buffer(size_t size) : startPtr((new int[size])), endPtr(startPtr + size)
{
	std::cout << "Initializer constructor doing its thaaang." << std::endl;
}

int_buffer::int_buffer(const int* source, size_t size) : int_buffer(size)
{
	/*std::cout << "source resize" << std::endl;

	startPtr = new int[size];
	endPtr = startPtr + size;
	*/

	std::copy(source, source + size, startPtr);
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
int_buffer::int_buffer(const int_buffer& rhs) : int_buffer(rhs.startPtr,rhs.size())
{
	/*std::cout << "Copy constructor doing its thaaaaaaang." << std::endl;

	startPtr = new int[rhs.size()];
	endPtr	 = rhs.startPtr + rhs.size();*/

	std::copy(rhs.startPtr, rhs.endPtr, startPtr);
}

// Destructor
int_buffer::~int_buffer()
{
	// delete allocated memory
	delete[] startPtr;
}

// copy assign
int_buffer& int_buffer::operator=(const int_buffer& rhs)
{
	int_buffer temp(rhs);
	swap(temp);

	return *this;
	/*if (this != &rhs)
	{
		// Delete old data
		delete[] startPtr;

		// get new values
		startPtr = new int[rhs.size()];
		endPtr	 = startPtr + rhs.size();

		std::copy(rhs.startPtr, endPtr, startPtr);
	}
	return *this;*/
}

// move construct
int_buffer::int_buffer(int_buffer&& rhs) noexcept : startPtr(nullptr),endPtr(nullptr)
{
	swap(rhs);
	//*this = std::move(rhs);
}

// move assign
int_buffer& int_buffer::operator=(int_buffer&& rhs) noexcept 
{
	swap(rhs);
	return *this;
}

int& int_buffer::operator[](size_t index)
{	
	return startPtr[index];
}

const int& int_buffer::operator[](size_t index) const
{
	return startPtr[index];
}

void int_buffer::swap(int_buffer& rhs)
{
	std::swap(this->startPtr, rhs.startPtr);
	std::swap(this->endPtr, rhs.endPtr);
}

