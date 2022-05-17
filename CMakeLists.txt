# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    CMakeLists.txt                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/13 03:39:54 by anclarma          #+#    #+#              #
#    Updated: 2022/05/17 17:15:58 by anclarma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

cmake_minimum_required(VERSION 3.14)
project(ft_containers)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_STANDARD_REQUIRED 98)
set(CMAKE_CXX_FLAGS "-std=c++98 -Wall -Wextra -Werror")
# optonal flags
# set(CMAKE_CXX_FLAGS "-std=c++98 -Wall -Wextra -Werror -pedantic -Weffc++")

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
	stack_test
	stack_test.cc
	)
target_link_libraries(
	stack_test
	gtest_main
	)

include(GoogleTest)
gtest_discover_tests(stack_test)
