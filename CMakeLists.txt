cmake_minimum_required(VERSION 3.10)
project(game VERSION 0.1.0 LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 17)
add_compile_options(-Werror
                    -Wall
                    -Wextra
                    -pedantic
                    -Wold-style-cast
                   )


include(.conan/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

# Reusable lib target
add_library(core STATIC
            src/entry_point
            src/window
  )

target_include_directories(core PUBLIC src)

target_link_libraries(core
                      CONAN_PKG::sfml
                      CONAN_PKG::bullet3
                      CONAN_PKG::entt
                      CONAN_PKG::range-v3
                     )

# Wrapper for executable
add_executable(${PROJECT_NAME} dummy/main)

target_link_libraries(${PROJECT_NAME} core)

# Test configuration
add_executable(core_test
               test/main
               test/builds
  )

target_link_libraries(core_test
                      CONAN_PKG::Catch2
                      ${core_name}
                     )

find_package(Catch2 REQUIRED)
enable_testing()
include(CTest)
include(Catch)
catch_discover_tests(core_test)

# Doxygen config
find_package(Doxygen
             REQUIRED dot
             OPTIONAL_COMPONENTS mscgen dia
            )

doxygen_add_docs(core_docs src)
