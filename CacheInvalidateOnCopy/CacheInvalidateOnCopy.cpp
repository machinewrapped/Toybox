// CacheInvalidateOnCopy.cpp : A cache which is invalidated by copy/move
//

#include "stdafx.h"
#include "TestCache.h"

#include <iostream>

int main()
{
	TestCache a("one", "two", "three");

	{
		TestCache b("Arthur", "Ford", "Zaphod");
		a = b;
	}

	for (std::string* member : a)
	{
		std::cout << *member << "\n";
	}

	char c;
	std::cin >> c;

	return 0;
}

