/**************************************************************************
Copyright (C) 2021 Alexander Shaduri
License: 0BSD (Zero-Clause BSD)
***************************************************************************/
#ifndef BAR_LIBRARY_H
#define BAR_LIBRARY_H

#include "bar_support.h"


// All member functions of this class are exported
class BAR_LIBRARY_EXPORT BarClass {
	public:
		// Avoid using inline functions to access class data members,
		// otherwise they will also be exported.
		void setA(int value);
		int getA();

	private:
		int a = 0;
};


// Export a single global function
BAR_LIBRARY_EXPORT
void barPublicFunction();



#endif
