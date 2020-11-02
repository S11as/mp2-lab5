
#include <gtest.h>
#include <Multistack.h>

TEST(Multistack, can_create_multistack)
{
    ASSERT_NO_THROW(TMultiStack<int> s(9,3));
}

TEST(Multistack, cant_create_stack_with_zero_capacity)
{
    ASSERT_ANY_THROW(TMultiStack<int> s(0,0));
}

TEST(Multistack, can_push_item_to_stack)
{
    TMultiStack<int> s(9,3);
    ASSERT_NO_THROW(s.push(1, 0));
    ASSERT_NO_THROW(s.push(2, 1));
    ASSERT_NO_THROW(s.push(3, 2));
}

TEST(Multistack, can_pop_item_from_stack)
{
    TMultiStack<int> s(9,3);
    s.push(1, 0);
    s.push(2, 1);
    s.push(3, 2);

    int number = s.pop(0);
    EXPECT_EQ(number, 1);

    number = s.pop(1);
    EXPECT_EQ(number, 2);

    number = s.pop(2);
    EXPECT_EQ(number, 3);
}

TEST(Stack, default_stack_is_empty)
{
    TMultiStack<int> s(9,3);
    EXPECT_EQ(s.is_empty(0), true);
    EXPECT_EQ(s.is_empty(1), true);
    EXPECT_EQ(s.is_empty(2), true);
}

TEST(Stack, item_pop_makes_stack_empty)
{
    TMultiStack<int> s(9,3);
    s.push(1, 0);
    s.push(2, 1);
    s.push(3, 2);

    s.pop(0);
    s.pop(1);
    s.pop(2);

    EXPECT_EQ(s.is_empty(0), true);
    EXPECT_EQ(s.is_empty(1), true);
    EXPECT_EQ(s.is_empty(2), true);
}

TEST(Stack, stack_with_items_is_not_empty)
{
    TMultiStack<int> s(9,3);
    s.push(1, 0);
    s.push(2, 1);
    s.push(3, 2);

    EXPECT_EQ(s.is_empty(0), false);
    EXPECT_EQ(s.is_empty(1), false);
    EXPECT_EQ(s.is_empty(2), false);
}

TEST(Stack, item_push_makes_stack_full)
{
    TMultiStack<int> s(3,3);
    s.push(1, 0);
    s.push(2, 1);
    s.push(3, 2);

    EXPECT_EQ(s.is_full(0), true);
    EXPECT_EQ(s.is_full(1), true);
    EXPECT_EQ(s.is_full(2), true);
}

TEST(Stack, can_copy_stack)
{
    TMultiStack<int> s(3,3);
    s.push(1, 0);
    s.push(2, 1);
    s.push(3, 2);
    TMultiStack<int> s1 = s;

    int number = s1.pop(0);
    EXPECT_EQ(number, 1);

    number = s1.pop(1);
    EXPECT_EQ(number, 2);

    number = s1.pop(2);
    EXPECT_EQ(number, 3);
}

TEST(Stack, stack_can_relocate)
{
    TMultiStack<int> s(5,2);
    for (int i = 0; i < 3; ++i) {
        s.push(1,0);
    }
    for (int j = 0; j < 3; ++j) {
        int number = s.pop(0);
        EXPECT_EQ(number, 1);
    }
}

TEST(Stack, stack_relocates_properly)
{
    TMultiStack<int> s(5,2);

    for (int i = 0; i < 3; ++i) {
        s.push(1,0);
    }
    EXPECT_EQ(s.stacks[0].get_size(), 3);
    EXPECT_EQ(s.stacks[1].get_size(), 2);
}

TEST(Stack, stack_cant_relocate_without_space)
{
    TMultiStack<int> s(5,2);
    for (int i = 0; i < 4; ++i) {
        s.push(1,0);
    }
    ASSERT_ANY_THROW(s.push(1,0));
}

TEST(Stack, can_find_stack_with_least_elements)
{
    TMultiStack<int> s(6,3);
    for (int i = 0; i < 3; ++i) {
        s.push(1,0);
    }
    for (int i = 0; i < 2; ++i) {
        s.push(2,2);
    }
    EXPECT_EQ(s.get_stack_with_least_elements(), 1);
}



