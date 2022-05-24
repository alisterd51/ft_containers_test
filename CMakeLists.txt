# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    CMakeLists.txt                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/13 03:39:54 by anclarma          #+#    #+#              #
#    Updated: 2022/05/24 04:38:20 by anclarma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

cmake_minimum_required(VERSION 3.14)
project(ft_containers)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_STANDARD_REQUIRED 98)
# set(CMAKE_CXX_FLAGS "-std=c++98 -Wall -Wextra -Werror")
# optonal flags with clang++ (not compatible with g++)
set(CMAKE_CXX_FLAGS "-std=c++98 -Wall -Wextra -Werror -pedantic -fsanitize=address -fsanitize=leak -fsanitize=undefined -g3")

include(FetchContent)
FetchContent_Declare(
	googletest
	URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
	)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include_directories(
	# specify your include directories
	../ft_containers/includes
	)

enable_testing()

add_executable(
	base_test
	anclarma_base_test.cc
	)
add_executable(
	stack_test
	anclarma_stack_test.cc
	mli_stack_test.cc
	mazoise_stack_test.cc
	jgiron_stack_test.cc
	)
add_executable(
	vector_test
	anclarma_vector_test.cc
	mli_vector_test.cc
	)
add_executable(
	map_test
	anclarma_map_test.cc
	)
target_link_libraries(
	base_test
	gtest_main
	)
target_link_libraries(
	stack_test
	gtest_main
	)
target_link_libraries(
	vector_test
	gtest_main
	)
target_link_libraries(
	map_test
	gtest_main
	)

include(GoogleTest)
gtest_discover_tests(stack_test)
