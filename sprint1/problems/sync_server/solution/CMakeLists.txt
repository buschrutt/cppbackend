cmake_minimum_required(VERSION 3.11)

project(Radio CXX)
set(CMAKE_CXX_STANDARD 20)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
#${CMAKE_BINARY_DIR} or boost-build
conan_basic_setup()

find_package(Boost 1.78.0 REQUIRED)
if(Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIRS})
endif()

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

if(WIN32)
  add_definitions(-DNOMINMAX)
endif()

add_executable(hello src/main.cpp)
target_link_libraries(hello PRIVATE Threads::Threads)
