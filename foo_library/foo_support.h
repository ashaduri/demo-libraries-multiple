/**************************************************************************
Copyright (C) 2021 Alexander Shaduri
License: 0BSD (Zero-Clause BSD)
***************************************************************************/
#ifndef FOO_SUPPORT_H
#define FOO_SUPPORT_H

#include "library_support.h"


/*
Preconditions:
Define FOO_LIBRARY_STATIC when building and using as a static library.
Define FOO_LIBRARY_BUILD when building the library.

Mark public symbols with FOO_LIBRARY_EXPORT.
*/
#ifndef FOO_LIBRARY_STATIC
	/* It's a dynamic library.
	The public symbols must be marked as "exported" when building the library,
	and "imported" when using the library.
	*/
	#ifdef FOO_LIBRARY_BUILD
		/* Building the library */
		#define FOO_LIBRARY_EXPORT LIBRARY_DECL_EXPORT
	#else
		/* Using the library */
		#define FOO_LIBRARY_EXPORT LIBRARY_DECL_IMPORT
	#endif
#endif

#ifndef FOO_LIBRARY_EXPORT
	/* It's a static library, no need to import/export anything */
	#define FOO_LIBRARY_EXPORT
#endif


#endif
