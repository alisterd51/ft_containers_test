#include <gtest/gtest.h>
#include <iterator>
#include "iterator.hpp"
#include <type_traits>
#include <algorithm>
#include <utility>

TEST(AnclarmaBaseTest, BasicFunctions)
{
	// iterators_traits
//	typedef ft::iterator_traits<int>	ft_t1;
//	typedef std::iterator_traits<int>	std_t1;
	typedef ft::iterator_traits<int*>	ft_t2;
	typedef std::iterator_traits<int*>	std_t2;
	typedef ft::iterator_traits<int**>	ft_t3;
	typedef std::iterator_traits<int**>	std_t3;

//	EXPECT_EQ(typeid(ft_t1::iterator_category), typeid(std_t1::iterator_category));
	EXPECT_EQ(typeid(ft_t2::iterator_category), typeid(std_t2::iterator_category));
	EXPECT_EQ(typeid(ft_t3::iterator_category), typeid(std_t3::iterator_category));
	// reverse_iterator
	// enable_if
	// is_integral
	// equal
	// lexicographical_compare
	// pair
	// make_pair
}
