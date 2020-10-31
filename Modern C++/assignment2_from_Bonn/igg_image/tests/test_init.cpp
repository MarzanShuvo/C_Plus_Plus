#include "igg_image/image.h"
#include "igg_image/io_strategies/dummy_strategy.h"
#include "igg_image/io_strategies/strategy.h"
#include<gtest/gtest.h>

TEST(TestImage, InitFromStrategy){
    igg::DummyIoStrategy dummy_str;
    igg::Image image(dummy_str);

    EXPECT_EQ(0, image.cols());
    EXPECT_EQ(0, image.rows());
}

TEST(TestImage, test_init_row_col){
    igg::DummyIoStrategy dummy_str;
    igg::Image image(400,500, dummy_str);
    EXPECT_EQ(400, image.rows());
    EXPECT_EQ(500, image.cols());

}