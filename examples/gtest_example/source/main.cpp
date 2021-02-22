

#include <iostream>

#include <string>

#include <gtest.h>

using namespace std;

template <typename T>
T add(T a, T b)
{
    return a+b;
}

TEST(OperatorTest, addTest)
{
    EXPECT_EQ(5,add(2,3));
}

int main(int argc, char** argv)
{
    std::cout << "start gtest"<< std::endl;

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

}