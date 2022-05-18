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

TEST(MazoiseStackTest, LmartinMain)
{
	ft::stack<int> ft_mystack;
	std::stack<int> std_mystack;

	EXPECT_EQ(ft_mystack.empty(), std_mystack.empty());
	EXPECT_EQ(ft_mystack.size(), std_mystack.size());
	ft_mystack.push(42);
	std_mystack.push(42);
	EXPECT_EQ(ft_mystack.empty(), std_mystack.empty());
	EXPECT_EQ(ft_mystack.size(), std_mystack.size());
	EXPECT_EQ(ft_mystack.top(), std_mystack.top());
	ft_mystack.push(2);
	std_mystack.push(2);
	EXPECT_EQ(ft_mystack.size(), std_mystack.size());
	EXPECT_EQ(ft_mystack.top(), std_mystack.top());
	ft_mystack.pop();
	std_mystack.pop();
	EXPECT_EQ(ft_mystack.size(), std_mystack.size());
	EXPECT_EQ(ft_mystack.top(), std_mystack.top());

	ft::stack<int, ft::vector<int> > ft_mystack2;
	std::stack<int, std::vector<int> > std_mystack2;

	EXPECT_EQ(ft_mystack2.empty(), std_mystack2.empty());
	EXPECT_EQ(ft_mystack2.size(), std_mystack2.size());
	ft_mystack2.push(42);
	std_mystack2.push(42);
	EXPECT_EQ(ft_mystack2.empty(), std_mystack2.empty());
	EXPECT_EQ(ft_mystack2.size(), std_mystack2.size());
	EXPECT_EQ(ft_mystack2.top(), std_mystack2.top());
	ft_mystack2.push(2);
	std_mystack2.push(2);
	EXPECT_EQ(ft_mystack2.size(), std_mystack2.size());
	EXPECT_EQ(ft_mystack2.top(), std_mystack2.top());
	ft_mystack2.pop();
	std_mystack2.pop();
	EXPECT_EQ(ft_mystack2.size(), std_mystack2.size());
	EXPECT_EQ(ft_mystack2.top(), std_mystack2.top());

	ft::stack<int>	ft_cpystack = ft_mystack;
	std::stack<int>	std_cpystack = std_mystack;

	EXPECT_EQ(ft_cpystack == ft_mystack, std_cpystack == std_mystack);
	ft_cpystack.push(7);
	std_cpystack.push(7);
	EXPECT_EQ(ft_cpystack == ft_mystack, std_cpystack == std_mystack);
}

TEST(MazoiseStackTest, PopMain)
{
	ft::stack<int>	ft_mystack;
	std::stack<int>	std_mystack;

	for (int i = 0; i < 5; ++i)
	{
		ft_mystack.push(i);
		std_mystack.push(i);
	}

	while (!ft_mystack.empty() && !std_mystack.empty())
	{
		EXPECT_EQ(ft_mystack.top(), std_mystack.top());
		ft_mystack.pop();
		std_mystack.pop();
	}
}

TEST(MazoiseStackTest, PushMain)
{
	ft::stack<int>	ft_mystack;
	std::stack<int>	std_mystack;

	for (int i = 0; i < 5; ++i)
	{
		ft_mystack.push(i);
		std_mystack.push(i);
	}

	while (!ft_mystack.empty() && !std_mystack.empty())
	{
		EXPECT_EQ(ft_mystack.top(), std_mystack.top());
		ft_mystack.pop();
		std_mystack.pop();
	}
}

TEST(MazoiseStackTest, RelationalOperatorsMain)
{
	ft::stack<int> ft_a, ft_b, ft_c;
	std::stack<int> std_a, std_b, std_c;

	ft_a.push(10);
	ft_a.push(20);
	ft_a.push(30);

	ft_b.push(10);
	ft_b.push(20);
	ft_b.push(30);

	ft_c.push(30);
	ft_c.push(20);
	ft_c.push(10);

	std_a.push(10);
	std_a.push(20);
	std_a.push(30);

	std_b.push(10);
	std_b.push(20);
	std_b.push(30);

	std_c.push(30);
	std_c.push(20);
	std_c.push(10);

	EXPECT_EQ(ft_a == ft_b, std_a == std_b);
	EXPECT_EQ(ft_b != ft_c, std_b != std_c);
	EXPECT_EQ(ft_b < ft_c, std_b < std_c);
	EXPECT_EQ(ft_c > ft_b, std_c > std_b);
	EXPECT_EQ(ft_a <= ft_b, std_a <= std_b);
	EXPECT_EQ(ft_a >= ft_b, std_a >= std_b);
}

TEST(MazoiseStackTest, SizeMain)
{
	ft::stack<int>	ft_myints;
	std::stack<int>	std_myints;

	EXPECT_EQ(ft_myints.size(), std_myints.size());
	for (int i=0; i<5; i++)
	{
		ft_myints.push(i);
		std_myints.push(i);
	}
	EXPECT_EQ(ft_myints.size(), std_myints.size());
	ft_myints.pop();
	std_myints.pop();
	EXPECT_EQ(ft_myints.size(), std_myints.size());
}

TEST(MazoiseStackTest, TopMain)
{
	ft::stack<int>	ft_mystack;
	std::stack<int>	std_mystack;

	ft_mystack.push(10);
	ft_mystack.push(20);
	ft_mystack.top() -= 5;
	std_mystack.push(10);
	std_mystack.push(20);
	std_mystack.top() -= 5;
	EXPECT_EQ(ft_mystack.top(), std_mystack.top());
}
