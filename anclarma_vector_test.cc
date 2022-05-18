#include <gtest/gtest.h>
#include <vector>
#include "vector.hpp"

TEST(AnclarmaVectorTest, BasicFunctions)
{
	//contructor, begin
	{
		std::vector<int> std_first;
		std::vector<int> std_second (4,100);
		std::vector<int> std_third (std_second.begin(),std_second.end());
		std::vector<int> std_fourth (std_third);

		ft::vector<int> ft_first;
		ft::vector<int> ft_second (4,100);
		ft::vector<int> ft_third (ft_second.begin(),ft_second.end());
		ft::vector<int> ft_fourth (ft_third);

		int myints[] = {16,2,77,29};
		std::vector<int> std_fifth (myints, myints + sizeof(myints) / sizeof(int) );
		ft::vector<int> ft_fifth (myints, myints + sizeof(myints) / sizeof(int) );

		{
			std::vector<int>::iterator std_it = std_fifth.begin();
			ft::vector<int>::iterator ft_it = ft_fifth.begin();

			for (; std_it != std_fifth.end(); ++std_it, ++ft_it)
			{
				EXPECT_EQ(*std_it, *ft_it);
			}
		}
		{
			std::vector<int>::iterator std_it = std_fifth.begin();
			ft::vector<int>::iterator ft_it = ft_fifth.begin();

			for (; ft_it != ft_fifth.end(); ++std_it, ++ft_it)
			{
				EXPECT_EQ(*std_it, *ft_it);
			}
		}
	}
	//operator=
	{
		std::vector<int> std_foo (3,0);
		std::vector<int> std_bar (5,0);

		std_bar = std_foo;
		std_foo = std::vector<int>();

		ft::vector<int> ft_foo (3,0);
		ft::vector<int> ft_bar (5,0);

		ft_bar = ft_foo;
		ft_foo = ft::vector<int>();

		EXPECT_EQ(std_foo.size(), ft_foo.size());
		EXPECT_EQ(std_bar.size(), ft_bar.size());
	}
}

TEST(AnclarmaVectorTest, ConstFunctions)
{
}
