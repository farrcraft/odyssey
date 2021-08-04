# CMakeList.txt : CMake project for Odyssey, include source and define
# project specific logic here.
#
set(CMAKE_VERBOSE_MAKEFILE ON)
cmake_minimum_required (VERSION 3.8)

# I haven't figured out how to make this work with a relative path
set(CMAKE_MODULE_PATH "C:/Users/sigsegv/source/repos/Odyssey/Odyssey/cmake")

list(APPEND CMAKE_PREFIX_PATH "C:/Users/sigsegv/source/repos/Odyssey/vendor/boost/boost_1_76_0")

# This path is used by FindSDL2 module. 
# It will find include and lib folders under this directory.
# This is because find command doesn't include any path for Windows.
# So it can't find anything using default paths.
# SDL2_PATH is already expected in module file. I'm using the same variable.
set(SDL2_PATH "../vendor/sdl2/SDL2-2.0.14")

# CMake parses module files by their names. It will use FindSDL2 in this case.
find_package(SDL2 REQUIRED)

# SDL2_INCLUDE_DIR variable set by the FindSDL2 module (if it finds directory).
include_directories(${SDL2_INCLUDE_DIR})

# set(Boost_DEBUG ON)

# Need to set this for the COMPONENTS stanza to work next
set(Boost_USE_STATIC_LIBS ON)

# CMake already comes with a module for boost - https://cmake.org/cmake/help/latest/module/FindBoost.html
find_package(Boost 1.76.0 REQUIRED COMPONENTS log)

include_directories(
	${Boost_INCLUDE_DIRS}
	"../vendor/libjpeg-turbo-2.1.0"
	"../vendor/libpng-1.6.37"
	"../vendor/zlib-1.2.11")

link_directories(
	${Boost_LIBRARY_DIRS}
	"../vendor/libjpeg-turbo-2.1.0"
	"../vendor/libpng-1.6.37"
	"../vendor/zlib-1.2.11")

# This gets us C++17 and newer language features, e.g. nested namespace support - https://docs.microsoft.com/en-us/cpp/error-messages/compiler-errors-1/compiler-error-c2429?view=msvc-160
add_compile_options("/std:c++latest")

# Add source to this project's executable.
add_executable (Odyssey "Odyssey.cpp" "Odyssey.h" "ui/Window.h" 
"engine/Engine.h" "engine/Engine.cpp" "ui/Window.cpp" "ui/Screen.h" "ui/Screen.cpp" "config/Bootstrap.h" "config/Bootstrap.cpp" "config/JsonFile.h" "config/JsonFile.cpp" "engine/Logger.h" 
"engine/Logger.cpp" "image/Image.h" "image/Image.cpp" "image/Reader.cpp" "image/reader/Jpeg.h" "image/reader/Jpeg.cpp"
"image/reader/Png.h" "image/reader/Png.cpp")

# SDL2MAIN_LIBRARY is also specified within SDL2_LIBRARY by the FindSDL2 module.
# It's needed for Windows specific main function.
# If I don't use FindSDL2 module, I have to link it as well.
target_link_libraries(Odyssey
		${SDL2MAIN_LIBRARY}
        ${SDL2_LIBRARY}
		${Boost_LIBRARIES}
		"turbojpeg-static" "jpeg-static"
		"libpng16d" "zlibd")
