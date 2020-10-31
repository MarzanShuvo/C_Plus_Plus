#include "igg_image/image.h"
#include "igg_image/io_strategies/ppm_strategy.h"
#include<gtest/gtest.h>

TEST(TestImage, PMM_Strategy_upscale_test){
    std::string const str = "/media/marzan/data storage/C++/Modern C++/assignment2_from_Bonn/igg_image/data/pbmlib.ascii.ppm";
    igg::PpmIoStrategy ppm_str;
    igg::Image image(ppm_str);
    image.ReadFromDisk(str);
    image.UpScale(2);

    EXPECT_EQ(600, image.cols());
    EXPECT_EQ(600, image.rows());

}