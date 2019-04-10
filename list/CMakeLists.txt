cmake_minimum_required(VERSION 3.12)
project(list)

set(CMAKE_CXX_STANDARD 14)

add_executable(list main.cpp linear_list.h vector_list.h linked_list.h linked_list_single.h linked_list_ordered.h stack.h queue.h)