#include <gtest/gtest.h>
#include "mylib.h"

TEST(test_add_figure, basic_test_set)
{
    testing::internal::CaptureStdout();

    foo();

    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_TRUE(output == "Hello from lib");
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}