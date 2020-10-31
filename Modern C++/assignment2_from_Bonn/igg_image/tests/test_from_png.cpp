#include "igg_image/image.h"
#include "igg_image/io_strategies/png_strategy.h"
#include<gtest/gtest.h>

TEST(TestImage, PNG_Strategy){
    std::string const str = "/media/marzan/data storage/C++/Modern C++/assignment2_from_Bonn/igg_image/data/download.png";
    igg::PngIoStrategy png_str;
    igg::Image image(png_str);
    image.ReadFromDisk(str);

    EXPECT_EQ(832, image.cols());
    EXPECT_EQ(690, image.rows());
}