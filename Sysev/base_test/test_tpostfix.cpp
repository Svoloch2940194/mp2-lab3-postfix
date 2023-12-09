#include "postfix.h"
#include <gtest.h>

TEST(TPostfix, can_create_postfix)
{
  ASSERT_NO_THROW(TPostfix p);
}

TEST(TPostfix, simple_get_infix)
{
	TPostfix x("1+1");

	string ans = "1+1";
	ASSERT_EQ(ans, x.GetInfix());
}

TEST(TPostfix, simple_get_postfix)
{
	TPostfix x("1+1");

	string ans = "11+";
	x.ToPostfix();
	ASSERT_EQ(ans, x.GetPostfix());
}

TEST(TPostfix, get_postfix)
{
	TPostfix x("1+(1+1)");

	string ans = "111++";
	x.ToPostfix();
	ASSERT_EQ(ans, x.GetPostfix());
}

TEST(TPostfix, get_postfix_with_MUL)
{
	TPostfix x("1*(1+1)");

	string ans = "111+*";
	x.ToPostfix();
	ASSERT_EQ(ans, x.GetPostfix());
}

TEST(TPostfix, get_postfix_with_MUL2)
{
	TPostfix x("2+1*1");

	string ans = "211*+";
	x.ToPostfix();
	ASSERT_EQ(ans, x.GetPostfix());
}

TEST(TPostfix, get_postfix_with_MUL3)
{
	TPostfix x("2+1*1/2");

	string ans = "211*2/+";
	x.ToPostfix();
	ASSERT_EQ(ans, x.GetPostfix());
}

TEST(TPostfix, get_postfix_with_MUL4)
{
	TPostfix x("(2+1)*1/2");

	string ans = "21+1*2/";

	x.ToPostfix();
	ASSERT_EQ(ans, x.GetPostfix());
}

TEST(TPostfix, get_postfix_with_all)
{
	TPostfix x("1/(7-(1+1))*3-(2+(1+1))*1/(7-(2+1))*3-(2+(1+1))*(1/(7-(1+1))*3-(2+(1+1))+1/(7-(1+1))*3-(2+(1+1)))");

	x.ToPostfix();
	//cout << x.GetPostfix() << endl;
	double ans = x.Calculate();

	int a = (ans == 24.8);

	ASSERT_EQ(1, a);
}

TEST(TPostfix, get_postfix_with_incorrect_parenthesis_sequence)
{
	TPostfix x("1/(7-(1+1))*3-(2+(1+1))*1/(7-(2+1))*3-(2+(1+1))*(1/(7-(1+1))*3-(2+(1+1))+1/(7-(1+1))*3-(2+(1+1))))");

	ASSERT_ANY_THROW(x.ToPostfix());
}

TEST(TPostfix, get_postfix_with_incorrect_parenthesis_sequence2)
{
	TPostfix x("1/(7-(1+1))*3-(2+(1+1))*1/(7-(2+1))*3-(2+(1+1))*(1/(7-(1+1))*3-(2+(1+1))+1/(7-(1+1))*3-(2+(1+1))");

	ASSERT_ANY_THROW(x.ToPostfix());
}

TEST(TPostfix, get_postfix_with_incorrect_placement_of_signs)
{
	TPostfix x("1/(7-(1+1))*3-(2+(1+1))*1/(7-(2+1))*3-(2+(1+1))*(1/(7-(1+1))*3--(2+(1+1))+1/(7-(1+1))*3-(2+(1+1)))");

	ASSERT_ANY_THROW(x.ToPostfix());
}

