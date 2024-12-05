cmake_minimum_required(VERSION 3.5)

set(This test_homework5)

set(Sources
    test_homework5.cpp
)

add_executable(${This} ${Sources})
target_link_libraries(${This} PUBLIC
    gtest_main
    Homework5
)

add_test(
    NAME ${This}
    COMMAND ${This}
)