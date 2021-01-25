/**************************************************************************
Copyright (C) 2021 Alexander Shaduri
License: 0BSD (Zero-Clause BSD)
***************************************************************************/
#ifndef BAR_SUPPORT_H
#define BAR_SUPPORT_H

#include "library_support.h"


/*
Preconditions:
Define BAR_LIBRARY_STATIC when building and using as a static library.
Define BAR_LIBRARY_BUILD when building the library.

Mark public symbols with BAR_LIBRARY_EXPORT.
*/
#ifdef BAR_LIBRARY_DYNAMIC
	/* It's a dynamic library.
	The public symbols must be marked as "exported" when building the library,
	and "imported" when using the library.
	*/
	#ifdef BAR_LIBRARY_BUILD
		/* Building the library */
		#define BAR_LIBRARY_EXPORT LIBRARY_DECL_EXPORT
	#else
		/* Using the library */
		#define BAR_LIBRARY_EXPORT LIBRARY_DECL_IMPORT
	#endif
#endif

#ifndef BAR_LIBRARY_EXPORT
	/* It's a static library, no need to import/export anything */
	#define BAR_LIBRARY_EXPORT
#endif


#endif
