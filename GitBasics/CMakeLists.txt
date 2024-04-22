cmake_minimum_required(VERSION 3.10)
project(GitBasics)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/CppUnitTest/include)
add_executable(GitBasics
    AnsiTest.cpp
    HtmlTest.cpp
)

target_link_libraries(GitBasics PRIVATE Ansi Html)
target_compile_definitions(GitBasics PRIVATE UNIT_TEST)

enable_testing()
add_test(NAME GitBasics COMMAND GitBasics)