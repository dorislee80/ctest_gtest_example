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
