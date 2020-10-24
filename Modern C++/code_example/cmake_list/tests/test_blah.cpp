#include <gtest/gtest.h>
#include "blah.h"

TEST(TestBlah, OutputTest){
    EXPECT_EQ(1, Sum(1,1));
}