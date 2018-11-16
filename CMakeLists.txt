cmake_minimum_required(VERSION 3.10)
project(ctest)

set(CMAKE_CXX_STANDARD 11)

add_executable(ctest main.cpp db_connection.h my_database_app.h)


#
# testing section
#

enable_testing()

add_executable(vector_test "tests/test_container.cpp")
add_test(NAME vector COMMAND vector_test)

add_executable(map_test "tests/gtest_map.cpp")
target_link_libraries(map_test -lgtest -lgtest_main -pthread)
add_test(NAME map COMMAND map_test)

add_executable(my_database_app_test "tests/gmock_my_database_app.cpp")
target_link_libraries(my_database_app_test -lgtest -lgtest_main -lgmock -pthread)
add_test(NAME my_database_app COMMAND my_database_app_test)
