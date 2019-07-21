#include <gtest/gtest.h>
#include "squareRoot.cpp"


TEST(SquareRootTest, Positive) {
    ASSERT_EQ(squareRoot(6), 36);
}

TEST(SquareRootTest, Zero) {
    ASSERT_EQ(squareRoot(0), 0);
}

TEST(SquareRootTest, Negative) {
    ASSERT_EQ(squareRoot(-6), 36);
}



int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
