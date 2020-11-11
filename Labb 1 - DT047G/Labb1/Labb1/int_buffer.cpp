#include "int_buffer.h"

// Constructor initializer
int_buffer::int_buffer(size_t size) : startPtr((new int[size])), endPtr(startPtr + size)
{
	std::cout << "Initializer constructor doing its thaaang." << std::endl;
}

int_buffer::int_buffer(const int* source, size_t size)
{
	std::cout << "source resize" << std::endl;

	startPtr = new int[size];
	endPtr = startPtr + size;

	std::copy(source, source + size, startPtr);
}

// Size of buffer
size_t int_buffer::size() const 
{
	std::cout << "calculating size..." << std::endl;

	return (endPtr - startPtr);
}

// first element pos
int* int_buffer::begin()
{
	std::cout << "returning first object in buffer" << std::endl;

	return startPtr;
}

// last element pos
int* int_buffer::end()
{
	std::cout << "returning last object in buffer" << std::endl;

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

	// point on null
	startPtr = nullptr;
	endPtr	 = nullptr;
}

// move construct
int_buffer::int_buffer(int_buffer&& rhs) noexcept
{
	startPtr = rhs.startPtr;
	endPtr	 = rhs.endPtr;

	rhs.startPtr = nullptr;
	rhs.endPtr	 = nullptr;
}

// copy assign
int_buffer& int_buffer::operator=(const int_buffer& rhs)
{
	if (this != &rhs)
	{
		// Delete old data
		delete[] startPtr;

		// get new values
		startPtr = new int[rhs.size()];
		endPtr	 = startPtr + rhs.size();

		std::copy(rhs.startPtr, endPtr, startPtr);
	}
	return *this;
}

// move assign
int_buffer& int_buffer::operator=(int_buffer&& rhs) noexcept
{
	if (this != &rhs)
	{
		delete[] startPtr;

		startPtr = rhs.startPtr;
		endPtr	 = rhs.endPtr;

		rhs.startPtr = rhs.endPtr = nullptr;
	}
	return *this;
}

int& int_buffer::operator[](size_t index)
{	

	std::cout << "shalom" << std::endl;
	//startPtr[index] = index;

	return startPtr[index];
}

const int& int_buffer::operator[](size_t index) const
{
	std::cout << "salam aleikum" << std::endl;
	return startPtr[index];
}