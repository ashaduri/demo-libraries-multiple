/**************************************************************************
Copyright (C) 2021 Alexander Shaduri
License: 0BSD (Zero-Clause BSD)
***************************************************************************/

#include "foo_library.h"
#include "bar_library.h"

#include <iostream>


int main()
{
	FooClass foo;
	foo.setA(5);
	std::cout << "FooClass::a is " << foo.getA() << std::endl;
	fooPublicFunction();
	
	BarClass bar;
	bar.setA(5);
	std::cout << "BarClass::a is " << bar.getA() << std::endl;
	barPublicFunction();

	return 0;
}
