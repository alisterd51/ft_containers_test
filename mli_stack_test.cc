#include <gtest/gtest.h>
#include <stack>
#include <list>
#include "stack.hpp"
#include "mli_base.hpp"

#define TESTED_TYPE foo<int>
#define t_stack_ft ft::stack<TESTED_TYPE>
#define t_stack_std std::stack<TESTED_TYPE>
typedef t_stack_ft::container_type ft_container_type;
typedef t_stack_std::container_type std_container_type;

template <typename FT_STACK, typename STD_STACK>
void	printSize(FT_STACK &ft_stck, STD_STACK &std_stck, bool print_content = 1)
{
	EXPECT_EQ(ft_stck.size(), std_stck.size());
	if (print_content)
	{
		while (ft_stck.size() != 0 && ft_stck.size() != 0) {
			EXPECT_EQ(ft_stck.top(), std_stck.top());
			ft_stck.pop();
			std_stck.pop();
		}
	}
}

TEST(MliStackTest, Default)
{
	ft::stack<TESTED_TYPE>	ft_stck;
	std::stack<TESTED_TYPE>	std_stck;

	EXPECT_EQ(ft_stck.empty(), std_stck.empty());
	EXPECT_EQ(ft_stck.size(), std_stck.size());

	ft_stck.push(41);
	ft_stck.push(29);
	ft_stck.push(10);
	ft_stck.push(42);
	std_stck.push(41);
	std_stck.push(29);
	std_stck.push(10);
	std_stck.push(42);

	EXPECT_EQ(ft_stck.empty(), std_stck.empty());
	printSize(ft_stck, std_stck);
}

TEST(MliStackTest, DefaultCopy)
{
	ft_container_type	ft_ctnr;
	std_container_type	std_ctnr;

	ft_ctnr.push_back(21);
	ft_ctnr.push_back(42);
	ft_ctnr.push_back(1337);
	ft_ctnr.push_back(19);
	ft_ctnr.push_back(0);
	ft_ctnr.push_back(183792);

	std_ctnr.push_back(21);
	std_ctnr.push_back(42);
	std_ctnr.push_back(1337);
	std_ctnr.push_back(19);
	std_ctnr.push_back(0);
	std_ctnr.push_back(183792);

	t_stack_ft		ft_stck(ft_ctnr);
	t_stack_std		std_stck(std_ctnr);

	EXPECT_EQ(ft_stck.empty(), std_stck.empty());
	EXPECT_EQ(ft_stck.size(), std_stck.size());

	ft_stck.push(1);
	ft_stck.push(2);
	ft_stck.push(3);
	ft_stck.push(4);
	ft_stck.push(5);
	ft_stck.push(6);

	std_stck.push(1);
	std_stck.push(2);
	std_stck.push(3);
	std_stck.push(4);
	std_stck.push(5);
	std_stck.push(6);

	EXPECT_EQ(ft_stck.empty(), std_stck.empty());
	printSize(ft_stck, std_stck);
}

TEST(MliStackTest, ListCopy)
{
	std::list<TESTED_TYPE>	std_ctnr;

	std_ctnr.push_back(21);
	std_ctnr.push_back(42);
	std_ctnr.push_back(1337);
	std_ctnr.push_back(19);
	std_ctnr.push_back(0);
	std_ctnr.push_back(183792);

	ft::stack<TESTED_TYPE, std::list<TESTED_TYPE> >		ft_stck(std_ctnr);
	std::stack<TESTED_TYPE, std::list<TESTED_TYPE> >	std_stck(std_ctnr);

	EXPECT_EQ(ft_stck.empty(), std_stck.empty());
	EXPECT_EQ(ft_stck.size(), std_stck.size());

	ft_stck.push(1);
	ft_stck.push(2);
	ft_stck.push(3);
	ft_stck.push(4);
	ft_stck.push(5);
	ft_stck.push(6);

	std_stck.push(1);
	std_stck.push(2);
	std_stck.push(3);
	std_stck.push(4);
	std_stck.push(5);
	std_stck.push(6);

	EXPECT_EQ(ft_stck.empty(), std_stck.empty());
	printSize(ft_stck, std_stck);
}

template <class FT_STACK, class STD_STACK>
void	cmp(const FT_STACK &ft_lhs, const FT_STACK &ft_rhs,
		const STD_STACK &std_lhs, const STD_STACK &std_rhs)
{
	EXPECT_EQ(ft_lhs == ft_rhs, std_lhs == std_rhs);
	EXPECT_EQ(ft_lhs != ft_rhs, std_lhs != std_rhs);
	EXPECT_EQ(ft_lhs < ft_rhs, std_lhs < std_rhs);
	EXPECT_EQ(ft_lhs <= ft_rhs, std_lhs <= std_rhs);
	EXPECT_EQ(ft_lhs > ft_rhs, std_lhs > std_rhs);
	EXPECT_EQ(ft_lhs >= ft_rhs, std_lhs >= std_rhs);
}

TEST(MliStackTest, RelationalOpe)
{
	ft_container_type	ft_ctnr;
	std_container_type	std_ctnr;

	ft_ctnr.push_back(21);
	ft_ctnr.push_back(42);
	ft_ctnr.push_back(1337);
	ft_ctnr.push_back(19);
	ft_ctnr.push_back(0);
	ft_ctnr.push_back(183792);

	std_ctnr.push_back(21);
	std_ctnr.push_back(42);
	std_ctnr.push_back(1337);
	std_ctnr.push_back(19);
	std_ctnr.push_back(0);
	std_ctnr.push_back(183792);

	t_stack_ft	ft_stck(ft_ctnr);
	t_stack_ft	ft_stck2(ft_ctnr);
	t_stack_std	std_stck(std_ctnr);
	t_stack_std	std_stck2(std_ctnr);

	cmp(ft_stck, ft_stck, std_stck, std_stck);  // 0
	cmp(ft_stck, ft_stck2, std_stck, std_stck2); // 1

	ft_stck2.push(60);
	ft_stck2.push(61);
	ft_stck2.push(62);
	std_stck2.push(60);
	std_stck2.push(61);
	std_stck2.push(62);

	cmp(ft_stck, ft_stck2, std_stck, std_stck2); // 2
	cmp(ft_stck2, ft_stck, std_stck2, std_stck); // 3

	ft_stck.push(42);
	std_stck.push(42);

	cmp(ft_stck, ft_stck2, std_stck, std_stck2); // 4
	cmp(ft_stck2, ft_stck, std_stck2, std_stck); // 5

	ft_stck.push(100);
	std_stck.push(100);

	cmp(ft_stck, ft_stck2, std_stck, std_stck2); // 6
	cmp(ft_stck2, ft_stck, std_stck2, std_stck); // 7
}

TEST(MliStackTest, RelationalOpeList)
{
	std::list<TESTED_TYPE>	std_ctnr;

	std_ctnr.push_back(21);
	std_ctnr.push_back(42);
	std_ctnr.push_back(1337);
	std_ctnr.push_back(19);
	std_ctnr.push_back(0);
	std_ctnr.push_back(183792);

	ft::stack<TESTED_TYPE, std::list<TESTED_TYPE> >		ft_stck(std_ctnr);
	std::stack<TESTED_TYPE, std::list<TESTED_TYPE> >	std_stck(std_ctnr);
	ft::stack<TESTED_TYPE, std::list<TESTED_TYPE> >		ft_stck2(std_ctnr);
	std::stack<TESTED_TYPE, std::list<TESTED_TYPE> >	std_stck2(std_ctnr);

	cmp(ft_stck, ft_stck, std_stck, std_stck);  // 0
	cmp(ft_stck, ft_stck2, std_stck, std_stck2); // 1

	ft_stck2.push(60);
	ft_stck2.push(61);
	ft_stck2.push(62);
	std_stck2.push(60);
	std_stck2.push(61);
	std_stck2.push(62);

	cmp(ft_stck, ft_stck2, std_stck, std_stck2); // 2
	cmp(ft_stck2, ft_stck, std_stck2, std_stck); // 3

	ft_stck.push(42);
	std_stck.push(42);

	cmp(ft_stck, ft_stck2, std_stck, std_stck2); // 4
	cmp(ft_stck2, ft_stck, std_stck2, std_stck); // 5

	ft_stck.push(100);
	std_stck.push(100);

	cmp(ft_stck, ft_stck2, std_stck, std_stck2); // 6
	cmp(ft_stck2, ft_stck, std_stck2, std_stck); // 7
}
