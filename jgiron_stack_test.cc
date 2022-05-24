#include <gtest/gtest.h>
#include <stack>
#include "stack.hpp"
#ifndef NTEST
# define NTEST 5000
#endif

namespace monkey_stack {
	template<typename T>
		T get_value() {
			return (T());
		}

	std::string get_value() {
		std::string default_val[] = {"hola amigo", "amigo de la tornada", "amigo de pepito",
			"", "un", "dos", "atencion", "un dos tres quatro", "la pantera"};
		if (!(std::rand() % 4))
			return (std::string(default_val[std::rand() % 8]));
		std::string ret = "";
		for (int i = 0; i < 5; ++i)
			ret += (std::rand() % 26) + 'a';
		return (ret);
	}

	template<class FT_C, class STD_C>
		void print_full_stack(const FT_C &s1, const STD_C &s3) {
			EXPECT_EQ(s1.empty(), s3.empty());
			EXPECT_EQ(s1.size(), s3.size());
			if (!s1.empty())
			{
				EXPECT_EQ(s1.top(), s3.top());
			}
			if (!s3.empty())
			{
				EXPECT_EQ(s1.top(), s3.top());
			}
		}

	template<class FT_C, class STD_C>
		void test_copy_construct_equal(FT_C &s1, FT_C &s2, STD_C &s3, STD_C &s4) {
			FT_C v3(s1);
			STD_C v5(s3);
			print_full_stack<FT_C, STD_C>(s1, s3);
			print_full_stack<FT_C, STD_C>(s2, s4);
			print_full_stack<FT_C, STD_C>(v3, v5);
			v3 = s1;
			v5 = s3;
			print_full_stack<FT_C, STD_C>(s1, s3);
			print_full_stack<FT_C, STD_C>(s2, s4);
			print_full_stack<FT_C, STD_C>(v3, v5);
			s1 = v3;
			s1 = s2;
			s2 = v3;
			v3 = FT_C(v3);
			s3 = v5;
			s3 = s4;
			s4 = v5;
			v5 = STD_C(v5);
			print_full_stack<FT_C, STD_C>(s1, s3);
			print_full_stack<FT_C, STD_C>(s2, s4);
			print_full_stack<FT_C, STD_C>(v3, v5);
			v3 = FT_C(s1);
			v5 = FT_C(s3);
			print_full_stack<FT_C, STD_C>(s1, s3);
			print_full_stack<FT_C, STD_C>(s2, s4);
			print_full_stack<FT_C, STD_C>(v3, v5);
		}

	template<class FT_C, class STD_C>
		void test_construct(FT_C &s1, FT_C &, STD_C &s3, STD_C &) {
			switch (std::rand() % 5) {
				case 0:
					const typename FT_C::container_type v(std::rand() % 20, get_value());
					s1 = FT_C(v);
					s3 = STD_C(v);
					print_full_stack<FT_C, STD_C>(s1, s3);
					break;
			}
		}
	template<class FT_C, class STD_C>
		void test_push(FT_C &s1, FT_C &, STD_C &s3, STD_C &) {
			std::string	s = get_value();
			s1.push(s);
			s3.push(s);
		}

	template<class FT_C, class STD_C>
		void test_pop(FT_C &s1, FT_C &, STD_C &s3, STD_C &) {
			if (!s1.empty())
				s1.pop();
			if (!s3.empty())
				s3.pop();
		}

	template<class FT_C, class STD_C>
		void test_comparison(FT_C &s1, FT_C &s2, STD_C &s3, STD_C &s4) {
			EXPECT_EQ(s1 < s2, s3 < s4);
			EXPECT_EQ(s1 > s2, s3 > s4);
			EXPECT_EQ(s1 <= s2, s3 <= s4);
			EXPECT_EQ(s1 >= s2, s3 >= s4);
			EXPECT_EQ(s1 == s2, s3 == s4);
			EXPECT_EQ(s1 != s2, s3 != s4);
		}
}

template<class FT_C, class STD_C>
void	test_stack(int seed) {
	std::srand(seed);
	void  (*array[])(FT_C &, FT_C &, STD_C &, STD_C &) = {
		&monkey_stack::test_construct<FT_C, STD_C>,
		&monkey_stack::test_copy_construct_equal<FT_C, STD_C>,
		&monkey_stack::test_push<FT_C, STD_C>,
		&monkey_stack::test_pop<FT_C, STD_C>,
		&monkey_stack::test_comparison<FT_C, STD_C>
	};
	FT_C	s1;
	FT_C	s2;
	STD_C	s3;
	STD_C	s4;
	for (int i = 0; NTEST == -1 || i < NTEST; i++) {
		int rand = std::rand() % sizeof(array) / sizeof(void (*)(FT_C &, FT_C &, STD_C &, STD_C &));
		if (std::rand() % 2)
			array[rand](s1, s2, s3, s4);
		else
			array[rand](s2, s1, s4, s3);
		monkey_stack::print_full_stack<FT_C, STD_C>(s1, s3);
		monkey_stack::print_full_stack<FT_C, STD_C>(s2, s4);
	}
}

TEST(JgironStackTest, TestStack)
{
	test_stack<ft::stack<std::string>, ft::stack<std::string> >(42);
}
