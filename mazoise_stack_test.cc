#include <gtest/gtest.h>
#include <stack>
#include <vector>
#include "stack.hpp"
#include "vector.hpp"

TEST(MazoiseStackTest, EasyMain)
{
	ft::stack<float>			ft_other_stack;
	ft::vector<std::string>		ft_lst;
	std::stack<float>			std_other_stack;
	std::vector<std::string>	std_lst;

	ft_lst.push_back("salut");
	ft_lst.push_back("tu vas bien?");
	ft_lst.push_back("super");
	ft_lst.push_back("et toi?");
	std_lst.push_back("salut");
	std_lst.push_back("tu vas bien?");
	std_lst.push_back("super");
	std_lst.push_back("et toi?");

	ft::stack<std::string, ft::vector<std::string> >	ft_my_stack(ft_lst);
	std::stack<std::string, std::vector<std::string> >	std_my_stack(std_lst);

	EXPECT_EQ(ft_other_stack.empty(), std_other_stack.empty());

	ft_other_stack.push(8.5); // 8.5;
	ft_other_stack.push(42.4242); // 8.5; 42.4242;
	std_other_stack.push(8.5); // 8.5;
	std_other_stack.push(42.4242); // 8.5; 42.4242;
	EXPECT_EQ(ft_other_stack.size(), std_other_stack.size());
	ft_other_stack.pop(); // 8.5;
	std_other_stack.pop(); // 8.5;
	EXPECT_EQ(ft_other_stack.size(), std_other_stack.size());
	ft_other_stack.push(78541.987); // 8.5; 78541.987;
	std_other_stack.push(78541.987); // 8.5; 78541.987;

	EXPECT_EQ(ft_other_stack.size(), std_other_stack.size());
	EXPECT_EQ(ft_other_stack.top(), std_other_stack.top());
	EXPECT_EQ(ft_other_stack.empty(), std_other_stack.empty());

	const std::string	ft_const_top = ft_my_stack.top();
	const std::string	std_const_top = std_my_stack.top();

	EXPECT_EQ(ft_const_top, std_const_top);

	while (!ft_my_stack.empty() && !std_my_stack.empty())
	{
		EXPECT_EQ(ft_my_stack.top(), std_my_stack.top());
		ft_my_stack.pop();
		std_my_stack.pop();
	}	
}

TEST(MazoiseStackTest, EmptyMain)
{
	ft::stack<int>	ft_mystack;
	int				ft_sum(0);
	std::stack<int>	std_mystack;
	int				std_sum(0);

	for (int i = 1; i <= 10; i++)
	{
		ft_mystack.push(i);
		std_mystack.push(i);
	}

	while (!ft_mystack.empty())
	{
		ft_sum += ft_mystack.top();
		ft_mystack.pop();
	}
	while (!std_mystack.empty())
	{
		std_sum += std_mystack.top();
		std_mystack.pop();
	}

	EXPECT_EQ(ft_sum, std_sum);
}
