
# A simple compatibility control - add version information to dynamic library filename.
# For more advanced usage, see https://semver.org
set(BAR_VERSION 1)

# This library is compiled as a STATIC library by default, unless
# BAR_LIBRARY_DYNAMIC is set to TRUE.
if (NOT DEFINED BAR_LIBRARY_DYNAMIC)
	set(BAR_LIBRARY_DYNAMIC FALSE)
endif()

# List all library sources
set(BAR_LIBRARY_SOURCES
	bar_library.h
	bar_library.cpp
	bar_support.h
)

# Create static or shared library target
if (NOT BAR_LIBRARY_DYNAMIC)
	add_library(bar_library STATIC ${BAR_LIBRARY_SOURCES})

else()
	add_library(bar_library SHARED ${BAR_LIBRARY_SOURCES})

	# Define BAR_LIBRARY_DYNAMIC when building and using this library.
	target_compile_definitions(bar_library
		PUBLIC
			BAR_LIBRARY_DYNAMIC
	)

	# Make all non-exported symbols are hidden by default (similar to Windows)
	set_target_properties(bar_library
		PROPERTIES
			C_VISIBILITY_PRESET hidden
			CXX_VISIBILITY_PRESET hidden
	)

	# If using cpack, we have to distribute the dynamic library as well
	if (WIN32)
		# Install dll only, not the import library
		install(TARGETS bar_library RUNTIME DESTINATION .)
	else()
		install(TARGETS bar_library DESTINATION .)
	endif()
endif()

# Treat the exported symbols as exported (and not imported) when building the library
target_compile_definitions(bar_library
	PRIVATE
		BAR_LIBRARY_BUILD
)

# Export the library's public include path to dependent targets
target_include_directories(bar_library
	INTERFACE
		${CMAKE_CURRENT_SOURCE_DIR}
)

# Make the library versioned (rename its file to contain version information and architecture)
set_target_properties(bar_library
	PROPERTIES
		OUTPUT_NAME "bar_library${BAR_VERSION}${DYNAMIC_LIBRARY_FILE_SUFFIX}"
)

# Add "library_support" to include path. This has to be public because it's used in library's public headers.
target_link_libraries(bar_library
	PUBLIC
		library_support
)

