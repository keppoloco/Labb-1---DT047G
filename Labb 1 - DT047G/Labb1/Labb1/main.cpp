// Laboration 1 - Programmeringsmetodik, dt047g
// Timmy Nord (tino1800)
// main.cpp Created 10 Nov, Last edited 19 Nov
// innehåller laborations uppgifter

#include "int_buffer.h"
#include "int_sorted.h"

#include <random>
#include <time.h>
void f(int_buffer &buf);

void asd(int_sorted& const v)
{
	for (const int* i = v.begin(); i != v.end(); i++) {
		std::cout << *i << " ";
	}
	std::cout << '\n';
}

int main()
{
	srand(time(NULL));
	int_buffer buf(200);

	f(buf);

	int_sorted sorted(buf.begin(), buf.size());
	//int_sorted lol(buf.begin(), buf.size());

	sorted.sort(buf.begin(), buf.end());

	sorted.insert(755);
	sorted.insert(1002);

	sorted.sort(buf.begin(), buf.end());

	sorted.print();



	//sorted = sorted.merge(lol);
	//printBuffer(sorted.getHead());
	//std::cout << sorted.insert(67) << std::endl;

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