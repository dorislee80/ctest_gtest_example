# ctest_gtest_example
## cmake and ctest
Ctest is the framework used by cmake to run unit tests. A test corresponds to an executable. You can execute "make test" to execute a list of executables.

Ctest doesn't mandatory any unit testing framework. It simply checks the exit code of an executable to determine if the test is passed (0 means passed). So you can use your favirote framework to write your test.

To enable ctest, add the following line into your CMakeLists.txt

> enable_testing()

enable_testing() will create a task "test" in Makefile to trigger ctest when you execute "make test".

To register a test, add the following lines into CMakeLists.txt

> add_executable(vector_test "tests/test_container.cpp")
> add_test(NAME vector COMMAND vector_test)

add_executable() build an executable called vector_test. add_test() registers a test called "vector" with ctest. Its corresponding command is "vector_test".

## gtest 
gtest is a unit testing framework developed by Google. 

To install gtest on Ubunto, please execute the following commands

> sudo apt-get install libgtest-dev

Then you need to compile the libary (the command above just install the source code)

> cd /usr/src/gtest
> mkdir mybuild
> cd mybuild
> cmake ..
> make 
> make install

See code tests/gtest_map.cpp for gtest example.

To register the test with ctest, add the following code into CMakeLists.txt

> add_executable(map_test "tests/gtest_map.cpp")
> target_link_libraries(map_test "-lgtest -lgtest_main -pthread")
> add_test(NAME map COMMAND map_test)

The executable using gtest has to be linked with the libraries gtest, gtest_main and pthread that are specified in target_link_libraries().

# gmock
gmock is a mocking framewwork acompanying with gtest.

To install gmock on Ubunto, please execute the following commands

> sudo apt-get install google-mock

Then you need to compilte the library (the command above just installs the source code)

> cd /usr/src/gmock
> mkdir mybuild
> cd mybuild
> cmake ..
> make
> make install

See code tests/gmock_my_database_app.cpp, db_connection.h, my_database_app.h for gmock example.

To register the test with ctest, add the following code into CMakeLists.txt

> add_executable(map_test "tests/gtest_map.cpp")
> target_link_libraries(map_test "-lgtest -lgtest_main -pthread -lgmock")
> add_test(NAME map COMMAND map_test)

The executable using gmock has to be linked with the libraries gtest, gtest_main, gmock and pthread that are specified in target_link_libraries().
