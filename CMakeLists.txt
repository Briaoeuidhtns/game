cmake_minimum_required(VERSION 3.10.2)
project(game VERSION 0.1.0 LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 17)

include(.conan/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

set(SRC src)

add_executable(${PROJECT_NAME}
  ${SRC}/entry_point.cpp
  ${SRC}/s7/s7.c
  )

target_link_libraries(${PROJECT_NAME}
  CONAN_PKG::sfml
  CONAN_PKG::bullet3
  CONAN_PKG::entt
  ${CMAKE_DL_LIBS})

target_include_directories(${PROJECT_NAME} PRIVATE
  ${SRC})

enable_testing()
include(.conan/ParseAndAddCatchTests.cmake)
ParseAndAddCatchTests(${PROJECT_NAME})
