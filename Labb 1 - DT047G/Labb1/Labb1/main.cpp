#include "int_buffer.h"
void f(int_buffer buf);
int main()
{
	int_buffer buf(10);

	f((buf));

	std::cin.ignore();
	return 0;
}

void f(int_buffer buf)
{
	std::cout << "Inserting integers to buffer.." << std::endl;
	for (int* i = buf.begin(); i < buf.end(); i++)
	{
		*i = i - buf.begin() + 1;
	}

	std::cout << "Displaying integers in buffer: " << std::endl;
	for (const int* i = buf.begin(); i < buf.end(); i++)
		std::cout << *i << std::endl;
}