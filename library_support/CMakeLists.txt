
# Create a "header-only" library so that dependent targets can use its public
# include path by simply "linking" to it.
add_library(library_support INTERFACE)

target_sources(library_support
	INTERFACE
		# This doesn't have to be an absolute path starting with cmake 3.13
		${CMAKE_CURRENT_SOURCE_DIR}/library_support.h
)

target_include_directories(library_support
	INTERFACE
		${CMAKE_CURRENT_SOURCE_DIR}
)
