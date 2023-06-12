cmake_minimum_required(VERSION 3.9)
project(HelloLog CXX)
set(CMAKE_CXX_STANDARD 20)

# обратите внимание на аргумент TARGETS у команды conan_basic_setup
include(build/conanbuildinfo.cmake)
#${CMAKE_BINARY_DIR} or build
conan_basic_setup(TARGETS)

find_package(Boost 1.78.0 REQUIRED)
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
endif()

add_executable(hello_log main.cpp)

# используем "импортированную" цель CONAN_PKG::boost
target_include_directories(hello_log PRIVATE CONAN_PKG::boost)
target_link_libraries(hello_log CONAN_PKG::boost)
