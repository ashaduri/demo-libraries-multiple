
# A simple compatibility control - add version information to dynamic library filename.
# For more advanced usage, see https://semver.org
set(FOO_VERSION 1)

# This library is compiled as a DYNAMIC library by default, unless
# FOO_LIBRARY_STATIC is set to TRUE.
if (NOT DEFINED FOO_LIBRARY_STATIC)
	set(FOO_LIBRARY_STATIC FALSE)
endif()

# List all library sources
set(FOO_LIBRARY_SOURCES
	foo_library.h
	foo_library.cpp
	foo_support.h
)

# Create static or shared library target.
if (FOO_LIBRARY_STATIC)
	add_library(foo_library STATIC ${FOO_LIBRARY_SOURCES})

	# Define FOO_LIBRARY_STATIC when building and using this library.
	target_compile_definitions(foo_library
		PUBLIC
			FOO_LIBRARY_STATIC
	)

else()
	add_library(foo_library SHARED ${FOO_LIBRARY_SOURCES})

	# Make all non-exported symbols are hidden by default (similar to Windows)
	set_target_properties(foo_library
		PROPERTIES
			C_VISIBILITY_PRESET hidden
			CXX_VISIBILITY_PRESET hidden
	)

	# If using cpack, we have to distribute the dynamic library as well
	if (WIN32)
		# Install dll only, not the import library
		install(TARGETS foo_library RUNTIME DESTINATION .)
	else()
		install(TARGETS foo_library DESTINATION .)
	endif()
endif()

# Treat the exported symbols as exported (and not imported) when building the library
target_compile_definitions(foo_library
	PRIVATE
		FOO_LIBRARY_BUILD
)

# Export the library's public include path to dependent targets
target_include_directories(foo_library
	INTERFACE
		${CMAKE_CURRENT_SOURCE_DIR}
)

# Make the library versioned (rename its file to contain version information and architecture)
set_target_properties(foo_library
	PROPERTIES
		OUTPUT_NAME "foo_library${FOO_VERSION}${DYNAMIC_LIBRARY_FILE_SUFFIX}"
)

# Add "library_support" to include path. This has to be public because it's used in library's public headers.
target_link_libraries(foo_library
	PUBLIC
		library_support
)

