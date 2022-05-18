#include <gtest/gtest.h>
#include <vector>
#include "vector.hpp"
#include "mli_base.hpp"

TEST(MliVectorTest, Assign)
{
	std::vector<int>	std_vct(7);
	std::vector<int>	std_vct_two(4);
	std::vector<int>	std_vct_three;
	std::vector<int>	std_vct_four;
/*
	for (unsigned long int i = 0; i < std_vct.size(); ++i)
		std_vct[i] = (std_vct.size() - i) * 3;
	for (unsigned long int i = 0; i < std_vct_two.size(); ++i)
		std_vct_two[i] = (std_vct_two.size() - i) * 5;
	printSize(vct);
	printSize(vct_two);

	vct_three.assign(vct.begin(), vct.end());
	vct.assign(vct_two.begin(), vct_two.end());
	vct_two.assign(2, 42);
	vct_four.assign(4, 21);

	std::cout << "\t### After assign(): ###" << std::endl;

	printSize(vct);
	printSize(vct_two);
	printSize(vct_three);
	printSize(vct_four);

	vct_four.assign(6, 84);
	printSize(vct_four);

	std::cout << "\t### assign() on enough capacity and low size: ###" << std::endl;

	vct.assign(5, 53);
	vct_two.assign(vct_three.begin(), vct_three.begin() + 3);

	printSize(vct);
	printSize(vct_two);*/
}
