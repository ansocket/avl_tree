cmake_minimum_required(VERSION 3.28)

add_compile_options(-g -fsanitize=address)
add_link_options(-fsanitize=address)
project(avl_tree C CXX)



add_subdirectory(Tree)
add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE AVL_Tree)