# Cmake最低版本要求
cmake_minimum_required(VERSION 3.10)
# 项目信息
project(mycpp)
# 指定生成目标
#aux_source_directory(test SRC_DIR)
add_executable(mycpp  "test/泛型和STL-模板/MyArray.hpp")