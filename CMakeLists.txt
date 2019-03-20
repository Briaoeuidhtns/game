cmake_minimum_required(VERSION 3.10.2)
project(game VERSION 0.1.0 LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 17)

include(.conan/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

set(SRC src)

add_library(s7 ${SRC}/s7/s7.c)

target_link_libraries(s7 ${CMAKE_DL_LIBS})

add_executable(${PROJECT_NAME}
  ${SRC}/entry_point.cpp
  )

target_compile_options(${PROJECT_NAME} PRIVATE
  -Wall
  -Wextra
  -pedantic
  -Werror)

target_link_libraries(${PROJECT_NAME}
  CONAN_PKG::sfml
  CONAN_PKG::bullet3
  CONAN_PKG::entt
  s7)

target_include_directories(${PROJECT_NAME} PRIVATE
  ${SRC})

enable_testing()
include(.conan/ParseAndAddCatchTests.cmake)
ParseAndAddCatchTests(${PROJECT_NAME})
