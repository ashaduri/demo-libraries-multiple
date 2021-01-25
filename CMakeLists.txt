cmake_minimum_required(VERSION 3.0)

# Set the project name
project(demo-libraries-multiple)


# Binaries should be placed in the project build binary directory.
# Be mindful of binary names conflicting with source root subdirectory names -
# this may cause weird linking errors.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/")

# Dynamic libraries should be placed next to the binaries
# (overrides putting them to lib on non-dll platforms)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/")

## Static and import libraries are placed in the "lib" subdirectory.
## Specifying this variable is required if we touch the ones above.
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib/")


# Disable setting build tree RPATH on generated executables.
set(CMAKE_SKIP_BUILD_RPATH true)

# Set installation destination RPATH as $ORIGIN (that is, the binary directory)
set(CMAKE_INSTALL_RPATH "$ORIGIN")

# Add installation path (as set above) to RPATH of the generated executable
set(CMAKE_BUILD_WITH_INSTALL_RPATH true)

# Don't add link paths to RPATH of the generated executable
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH false)


# Bar library is static by default. Introduce a switch to override that.
option(BAR_LIBRARY_DYNAMIC "Compile bar_library as dynamic library" OFF)

# Foo library is dynamic by default. Introduce a switch to override that.
option(FOO_LIBRARY_STATIC "Compile foo_library as static library" OFF)


# Construct a suffix for dynamic library filenames
set(DYNAMIC_LIBRARY_FILE_SUFFIX "")
if (WIN32)
	# We add the debug suffix on Windows only because the debug dlls
	# are not portable and it's better to explicitly mark them as such.
	set(CMAKE_DEBUG_POSTFIX "_debug")

	# Note: We add these suffixes on Windows only because it's very
	# difficult to differentiate between 32- and 64-bit dlls there.
	# It's generally not a problem under Linux (it can usually find
	# the proper .so files anyway).
	if (CMAKE_SIZEOF_VOID_P MATCHES 8)
		set(DYNAMIC_LIBRARY_FILE_SUFFIX "_x64")
	else()
		set(DYNAMIC_LIBRARY_FILE_SUFFIX "_x86")
	endif()
endif()


add_subdirectory(foo_library)
add_subdirectory(bar_library)
add_subdirectory(library_support)
add_subdirectory(demo_binary)

