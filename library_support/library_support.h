/**************************************************************************
Copyright (C) 2021 Alexander Shaduri
License: 0BSD (Zero-Clause BSD)
***************************************************************************/
#ifndef LIBRARY_SUPPORT_H
#define LIBRARY_SUPPORT_H

/*
A helper macro for implementation of library-specific export macro.
This macro abstracts away compiler-specific attributes.
*/
#ifndef LIBRARY_DECL_EXPORT
	#ifdef _WIN32
		#define LIBRARY_DECL_EXPORT __declspec(dllexport)
	#elif __GNUC__ >= 4
		#define LIBRARY_DECL_EXPORT __attribute__((visibility("default")))
	#else
		#define LIBRARY_DECL_EXPORT
	#endif
#endif


/*
A helper macro for implementation of library-specific export macro.
This macro abstracts away compiler-specific attributes.
*/
#ifndef LIBRARY_DECL_IMPORT
	#ifdef _WIN32
		#define LIBRARY_DECL_IMPORT __declspec(dllimport)
	#else
		#define LIBRARY_DECL_IMPORT
	#endif
#endif



#endif
