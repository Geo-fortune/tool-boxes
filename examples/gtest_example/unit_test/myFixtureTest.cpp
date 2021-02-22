
#include <gtest.h>

#include <classA.h>

#include <iostream>

class myFixtureText : public testing::Test
{

protected:
    virtual void SetUp()
    {
        a = 3;
        b = 5;
    }

    virtual void TearDown()
    {

    }

    int a;
    int b;

    A a_myClass;

};



TEST_F(myFixtureText, test_add_operate_0)
{
    EXPECT_EQ(8, a_myClass.add<int>(a,b));
}

TEST_F(myFixtureText, test_multiply_operate_0)
{
    EXPECT_EQ(15, a_myClass.multiply<int>(a,b));
    std::cout << "expect success!" << std::endl;
}

TEST_F(myFixtureText, test_multiply_operate_1)
{
    ASSERT_NE(19, a_myClass.multiply<int>(a,b));
    std::cout << "assert failed!" << std::endl;
}


int main(int argc, char ** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

}

