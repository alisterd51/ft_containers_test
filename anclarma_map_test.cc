#include <gtest/gtest.h>
#include <map>
#include "map.hpp"

#include <utility> //pair make_pair
#include <set>

TEST(AnclarmaMapTest, BasicFunctions)
{
	std::vector<std::pair<int, double> >	std_vector;

	std_vector.push_back(std::make_pair(1, 21.0));
	std_vector.push_back(std::make_pair(2, 25.0));
	std_vector.push_back(std::make_pair(3, 42.0));

	ft::map<int, double>	ft_empty_map;
	std::map<int, double>	std_empty_map;

	EXPECT_EQ(ft_empty_map.empty(), std_empty_map.empty());
	EXPECT_EQ(ft_empty_map.size(), std_empty_map.size());
	EXPECT_EQ(ft_empty_map.max_size(), std_empty_map.max_size());

	ft::map<int, double>	ft_vector_map(std_vector.begin(), std_vector.end());
	std::map<int, double>	std_vector_map(std_vector.begin(), std_vector.end());

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

	ft::map<int, double>	ft_map_map(ft_vector_map);
	std::map<int, double>	std_map_map(std_vector_map);

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
}
