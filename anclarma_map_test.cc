#include <gtest/gtest.h>
#include <map>
#include "map.hpp"

#include <utility> //pair make_pair
#include "utility.hpp" //pair make_pair //a enlever
#include <vector>

TEST(AnclarmaMapTest, BasicFunctions)
{
	{
		// test member type

		EXPECT_EQ(sizeof(ft::map<char,int>::key_type), sizeof(std::map<char,int>::key_type));
		EXPECT_EQ(sizeof(ft::map<char,int>::mapped_type), sizeof(std::map<char,int>::mapped_type));
		EXPECT_EQ(sizeof(ft::map<char,int>::value_type), sizeof(std::map<char,int>::value_type));
		EXPECT_EQ(sizeof(ft::map<char,int>::key_compare), sizeof(std::map<char,int>::key_compare));
		EXPECT_EQ(sizeof(ft::map<char,int>::value_compare), sizeof(std::map<char,int>::value_compare));
		EXPECT_EQ(sizeof(ft::map<char,int>::allocator_type), sizeof(std::map<char,int>::allocator_type));
		EXPECT_EQ(sizeof(ft::map<char,int>::reference), sizeof(std::map<char,int>::reference));
		EXPECT_EQ(sizeof(ft::map<char,int>::const_reference), sizeof(std::map<char,int>::const_reference));
		EXPECT_EQ(sizeof(ft::map<char,int>::pointer), sizeof(std::map<char,int>::pointer));
		EXPECT_EQ(sizeof(ft::map<char,int>::const_pointer), sizeof(std::map<char,int>::const_pointer));
		EXPECT_EQ(sizeof(ft::map<char,int>::iterator) != 0, sizeof(std::map<char,int>::iterator) != 0);
		EXPECT_EQ(sizeof(ft::map<char,int>::const_iterator) != 0, sizeof(std::map<char,int>::const_iterator) != 0);
		EXPECT_EQ(sizeof(ft::map<char,int>::reverse_iterator) != 0, sizeof(std::map<char,int>::reverse_iterator) != 0);
		EXPECT_EQ(sizeof(ft::map<char,int>::const_reverse_iterator) != 0, sizeof(std::map<char,int>::const_reverse_iterator) != 0);
		EXPECT_EQ(sizeof(ft::map<char,int>::difference_type), sizeof(std::map<char,int>::difference_type));
		EXPECT_EQ(sizeof(ft::map<char,int>::size_type), sizeof(std::map<char,int>::size_type));
	}
	std::vector<ft::pair<int, double> >	std_vector_ft_pair;

	std_vector_ft_pair.push_back(ft::make_pair(1, 21.0));
	std_vector_ft_pair.push_back(ft::make_pair(2, 25.0));
	std_vector_ft_pair.push_back(ft::make_pair(3, 42.0));

	std::vector<std::pair<int, double> >	std_vector_std_pair;

	std_vector_std_pair.push_back(std::make_pair(1, 21.0));
	std_vector_std_pair.push_back(std::make_pair(2, 25.0));
	std_vector_std_pair.push_back(std::make_pair(3, 42.0));

	ft::map<int, double, std::less<int>, std::allocator<ft::pair<const int, double> > > 	ft_empty_map;
	std::map<int, double, std::less<int>, std::allocator<std::pair<const int, double> > >	std_empty_map;

	EXPECT_EQ(ft_empty_map.empty(), std_empty_map.empty());
	EXPECT_EQ(ft_empty_map.size(), std_empty_map.size());
	EXPECT_EQ(ft_empty_map.max_size(), std_empty_map.max_size());

	ft::map<int, double, std::less<int>, std::allocator<ft::pair<const int, double> > >		ft_vector_map(std_vector_ft_pair.begin(), std_vector_ft_pair.end());
	std::map<int, double, std::less<int>, std::allocator<std::pair<const int, double> > >	std_vector_map(std_vector_std_pair.begin(), std_vector_std_pair.end());

	EXPECT_EQ(ft_vector_map.empty(), std_vector_map.empty());
	EXPECT_EQ(ft_vector_map.size(), std_vector_map.size());	

	{
		//test swap
		ft_empty_map.swap(ft_vector_map);
		std_empty_map.swap(std_vector_map);

		EXPECT_EQ(ft_empty_map.empty(), std_empty_map.empty());
		EXPECT_EQ(ft_empty_map.size(), std_empty_map.size());
		EXPECT_EQ(ft_vector_map.empty(), std_vector_map.empty());
		EXPECT_EQ(ft_vector_map.size(), std_vector_map.size());	

		ft_empty_map.swap(ft_vector_map);
		std_empty_map.swap(std_vector_map);

		EXPECT_EQ(ft_empty_map.empty(), std_empty_map.empty());
		EXPECT_EQ(ft_empty_map.size(), std_empty_map.size());
		EXPECT_EQ(ft_vector_map.empty(), std_vector_map.empty());
		EXPECT_EQ(ft_vector_map.size(), std_vector_map.size());	
	}
	{
		//test nonMemberSwap
		swap(ft_empty_map, ft_vector_map);
		swap(std_empty_map, std_vector_map);

		EXPECT_EQ(ft_empty_map.empty(), std_empty_map.empty());
		EXPECT_EQ(ft_empty_map.size(), std_empty_map.size());
		EXPECT_EQ(ft_vector_map.empty(), std_vector_map.empty());
		EXPECT_EQ(ft_vector_map.size(), std_vector_map.size());	

		swap(ft_empty_map, ft_vector_map);
		swap(std_empty_map, std_vector_map);

		EXPECT_EQ(ft_empty_map.empty(), std_empty_map.empty());
		EXPECT_EQ(ft_empty_map.size(), std_empty_map.size());
		EXPECT_EQ(ft_vector_map.empty(), std_vector_map.empty());
		EXPECT_EQ(ft_vector_map.size(), std_vector_map.size());	
	}
	{
		//test clear
		ft_empty_map = ft_vector_map;
		std_empty_map = std_vector_map;

		EXPECT_EQ(ft_empty_map.empty(), std_empty_map.empty());
		EXPECT_EQ(ft_empty_map.size(), std_empty_map.size());

		ft_empty_map.clear();
		std_empty_map.clear();

		EXPECT_EQ(ft_empty_map.empty(), std_empty_map.empty());
		EXPECT_EQ(ft_empty_map.size(), std_empty_map.size());
	}

	ft::map<int, double, std::less<int>, std::allocator<ft::pair<const int, double> > >	ft_map_map(ft_vector_map);
	std::map<int, double, std::less<int>, std::allocator<std::pair<const int, double> > >	std_map_map(std_vector_map);

	EXPECT_EQ(ft_vector_map.empty(), std_vector_map.empty());
	EXPECT_EQ(ft_map_map.size(), std_map_map.size());

	ft_empty_map = ft_map_map;
	std_empty_map = std_map_map;

	EXPECT_EQ(ft_empty_map.empty(), std_empty_map.empty());
	EXPECT_EQ(ft_empty_map.size(), std_empty_map.size());
	EXPECT_EQ(ft_empty_map.max_size(), std_empty_map.max_size());

	EXPECT_EQ(ft_empty_map[1], std_empty_map[1]);
	EXPECT_EQ(ft_empty_map[2], std_empty_map[2]);
	EXPECT_EQ(ft_empty_map[3], std_empty_map[3]);
	EXPECT_EQ(ft_empty_map[4], std_empty_map[4]);

	EXPECT_EQ(ft_empty_map.empty(), std_empty_map.empty());
	EXPECT_EQ(ft_empty_map.size(), std_empty_map.size());
	EXPECT_EQ(ft_empty_map.max_size(), std_empty_map.max_size());

	EXPECT_EQ(ft_empty_map.erase(42), std_empty_map.erase(42));

	EXPECT_EQ(ft_empty_map.empty(), std_empty_map.empty());
	EXPECT_EQ(ft_empty_map.size(), std_empty_map.size());
	EXPECT_EQ(ft_empty_map.max_size(), std_empty_map.max_size());

	EXPECT_EQ(ft_empty_map.erase(2), std_empty_map.erase(2));

	EXPECT_EQ(ft_empty_map.empty(), std_empty_map.empty());
	EXPECT_EQ(ft_empty_map.size(), std_empty_map.size());
	EXPECT_EQ(ft_empty_map.max_size(), std_empty_map.max_size());

	EXPECT_EQ(ft_empty_map.erase(1), std_empty_map.erase(1));
	EXPECT_EQ(ft_empty_map.erase(3), std_empty_map.erase(3));
	EXPECT_EQ(ft_empty_map.erase(4), std_empty_map.erase(4));
	EXPECT_EQ(ft_empty_map.erase(4), std_empty_map.erase(4));

	EXPECT_EQ(ft_empty_map.empty(), std_empty_map.empty());
	EXPECT_EQ(ft_empty_map.size(), std_empty_map.size());
	EXPECT_EQ(ft_empty_map.max_size(), std_empty_map.max_size());

	{
		//test key_comp
		ft::map<int,double>::key_compare ft_comp = ft_empty_map.key_comp();
		std::map<int,double>::key_compare std_comp = std_empty_map.key_comp();

		EXPECT_EQ(ft_comp(1, 2), std_comp(1, 2));
		EXPECT_EQ(ft_comp(3, 2), std_comp(3, 2));
		EXPECT_EQ(ft_comp(42, 42), std_comp(42, 42));
	}
	{
		//test key_comp
		ft::map<int,double>::key_compare	ft_comp = ft_empty_map.key_comp();
		std::map<int,double>::key_compare	std_comp = std_empty_map.key_comp();

		EXPECT_EQ(ft_comp(1.0, 2.0), std_comp(1.0, 2.0));
		EXPECT_EQ(ft_comp(3.0, 2.0), std_comp(3.0, 2.0));
		EXPECT_EQ(ft_comp(42.0, 42.0), std_comp(42.0, 42.0));
	}
	{
		//test get_allocator
		int							ft_psize;
		ft::map<char,int>			ft_mymap;
		ft::pair<const char,int>*	ft_p;
		int							std_psize;
		std::map<char,int>			std_mymap;
		std::pair<const char,int>*	std_p;

		// allocate an array of 5 elements using mymap's allocator:
		ft_p = ft_mymap.get_allocator().allocate(5);
		std_p = std_mymap.get_allocator().allocate(5);

		// assign some values to array
		ft_psize = sizeof(ft::map<char,int>::value_type) * 5;
		std_psize = sizeof(std::map<char,int>::value_type) * 5;

		EXPECT_EQ(ft_psize, std_psize);

		ft_mymap.get_allocator().deallocate(ft_p, 5);
		std_mymap.get_allocator().deallocate(std_p, 5);
	}
}
