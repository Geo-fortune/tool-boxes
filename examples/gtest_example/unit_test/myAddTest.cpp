

#include <classA.h>
#include <string>
#include <gtest.h>


TEST(operateTest, addTest)
{
    A a_test;
    int a =7, b= 1;
    int result_01 = a_test.add<int>(a,b);
    EXPECT_EQ(8, result_01);

    double c = 8.0, d = 2.5;
    double result_02 = a_test.add<double>(c, d);
    EXPECT_STREQ(std::string("20").c_str(), std::to_string(result_02).c_str());
    EXPECT_EQ(10.5,result_02);
}

int main(int argc, char ** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

