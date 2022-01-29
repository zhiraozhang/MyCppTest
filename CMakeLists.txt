cmake_minimum_required(VERSION 2.6)
project(mycpp)
aux_source_directory(Test TEST_DIR)
add_executable(mycpp ${TEST_DIR})