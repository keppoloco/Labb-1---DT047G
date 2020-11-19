// Laboration 1 - Programmeringsmetodik, dt047g
// Timmy Nord (tino1800)
// main.cpp Created 10 Nov, Last edited 19 Nov
// innehåller laborations uppgifter

#include "int_buffer.h"
#include "int_sorted.h"

#include <random>
#include <time.h>
void f(int_buffer &buf);
int main()
{
	srand(time(NULL));
	int_buffer buf(200);

	f(buf);

	int_sorted sorted(buf.begin(), buf.size());

	sorted.sort(buf.begin(), buf.end());

	sorted.insert(755);
	sorted.insert(1002);
	
	sorted.sort(buf.begin(), buf.end());

	sorted.print();

	std::cin.ignore();
	return 0;
}

void f(int_buffer &buf)
{
	for (int* i = buf.begin(); i < buf.end(); i++)
	{
		int numb = rand() % 200 + 1;
		*i = numb;
	}
	std::cout << std::endl;
}