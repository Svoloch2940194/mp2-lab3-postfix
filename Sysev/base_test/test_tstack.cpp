#include "stack.h"
#include <gtest.h>

TEST(TStack, can_create_stack_with_positive_length)
{
  ASSERT_NO_THROW(TStack<int> st(5));
}

TEST(TStack, checking_for_emptiness)
{
	TStack<int> s;
	ASSERT_TRUE(s.empty());
}

TEST(TStack, checking_for_emptiness1)
{
	TStack<int> s(1);
	s.push(1);
	ASSERT_FALSE(s.empty());
}

TEST(TStack, check_for_top_element)
{
	TStack<int> s;
	s.push(1);
	ASSERT_TRUE(s.get_top() == 1);
}

TEST(TStack, check_for_removal_from_empty_stack)
{
	TStack<int> st;
	ASSERT_ANY_THROW(st.pop());
}

TEST(TStack, check_for_return_after_deletion)
{
	TStack<int> st;
	st.push(1);
	ASSERT_TRUE(st.pop() == 1);
}

TEST(TStack, check_for_return_after_deletion1)
{
	TStack<int> st;
	st.push(1);
	ASSERT_NO_THROW(st.get_top());
}

TEST(TStack, check_for_return_after_deletion2)
{
	TStack<int> st;
	ASSERT_ANY_THROW(st.pop());
}

TEST(TStack, check_for_return_after_deletion2)
{
	TStack<int> st(5);
	ASSERT_TRUE(st.sz() == 5);
}

TEST(TStack, check_for_return_after_deletion2)
{
	TStack<int> st;
	ASSERT_TRUE(st.sz() == 1);
}
