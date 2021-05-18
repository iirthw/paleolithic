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

TEST_F(TestBitmanip, SimpleIsPower2)
{
    ASSERT_TRUE(bitmanip::isPower2(2));
}
