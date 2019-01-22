cmake_minimum_required(VERSION 3.13)
project(fillit_cl C)

include_directories("libft/includes")

add_definitions(-Wall -Wextra -Werror)

add_executable(main fillit.c fillit.h read_and_validate.c inscribe_shapes.c print.c)

target_link_libraries(main ${CMAKE_SOURCE_DIR}/libft/libft.a)