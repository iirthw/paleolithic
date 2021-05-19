#include "bitmanip/bitmanip.h"

#include "gtest/gtest.h"

class TestBitmanip : public ::testing::Test
{
    protected:
        // Uncomment any or all of the following is their
        // bodies would not be empty

        // TestBitmanip() {}
        // ~TestBitmanip() {}

        // void SetUp() override {}
        // void TearDown() override {}
};

TEST_F(TestBitmanip, simple_power2_true)
{
    ASSERT_TRUE(bitmanip::is_power2<int>(2));
}

TEST_F(TestBitmanip, advanced_power2_true)
{
    const int n = 15;
    int value = 2;
    for (int i = 2; i < n; ++i)
    {
        value *= 2;
        EXPECT_TRUE(bitmanip::is_power2<int>(value));
    }
}

TEST_F(TestBitmanip, corner_case)
{
    ASSERT_FALSE(bitmanip::is_power2<int>(0));
}

TEST_F(TestBitmanip, edge_power2_true)
{
    ASSERT_TRUE(bitmanip::is_power2<int>(1));
}

TEST_F(TestBitmanip, advanced_power2_false)
{
    const int n = 15;
    int value = 2;
    for (int i = 0; i < n; ++i)
    {
        value *= 2;
        EXPECT_FALSE(bitmanip::is_power2<int>(value - 1));
    }
}
