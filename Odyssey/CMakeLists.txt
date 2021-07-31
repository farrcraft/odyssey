# CMakeList.txt : CMake project for Odyssey, include source and define
# project specific logic here.
#
set(CMAKE_VERBOSE_MAKEFILE ON)
cmake_minimum_required (VERSION 3.8)

# I haven't figured out how to make this work with a relative path
set(CMAKE_MODULE_PATH "C:/Users/sigsegv/source/repos/Odyssey/Odyssey/cmake")

# This path is used by FindSDL2 module. 
# It will find include and lib folders under this directory.
# This is because find command doesn't include any path for Windows.
# So it can't find anything using default paths.
# SDL2_PATH is already expected in module file. I'm using the same variable.
set(SDL2_PATH "../sdl2/SDL2-2.0.14")

# CMake parses module files by their names. It will use FindSDL2 in this case.
find_package(SDL2 REQUIRED)

# SDL2_INCLUDE_DIR variable set by the FindSDL2 module (if it finds directory).
include_directories(${SDL2_INCLUDE_DIR})

# Add source to this project's executable.
add_executable (Odyssey "Odyssey.cpp" "Odyssey.h" "ui/Window.h" "engine/Engine.h" "engine/Engine.cpp" "ui/Window.cpp" "ui/Screen.h" "ui/Screen.cpp")

# SDL2MAIN_LIBRARY is also specified within SDL2_LIBRARY by the FindSDL2 module.
# It's needed for Windows specific main function.
# If I don't use FindSDL2 module, I have to link it as well.
target_link_libraries(Odyssey
		${SDL2MAIN_LIBRARY}
        ${SDL2_LIBRARY})
