#include "igg_image/image.h"
#include "igg_image/io_strategies/png_strategy.h"
#include "igg_image/io_strategies/ppm_strategy.h"
#include "igg_image/io_strategies/strategy.h"
#include<gtest/gtest.h>
#include<iostream>

TEST(TestImage, ReadWriteTestPNG_With_strategy){
    std::string const str = "/media/marzan/data storage/C++/Modern C++/assignment_3_from_Bonn/igg_image/data/download.png";
    igg::Image image;
    auto strategy_png = std::make_shared<igg::PngIoStrategy>();
    image.SetIoStrategy(strategy_png);

    image.ReadFromDisk(str);
    std::string const write_png = "/media/marzan/data storage/C++/Modern C++/assignment_3_from_Bonn/igg_image/data/write.png";

    EXPECT_EQ(832, image.cols());
    EXPECT_EQ(690, image.rows());
    EXPECT_EQ(1, image.WriteToDisk(write_png));
}

TEST(TestImage, ReadWriteTestPNG_Without_strategy){
    std::string const str = "/media/marzan/data storage/C++/Modern C++/assignment_3_from_Bonn/igg_image/data/download.png";
    igg::Image image;
    image.ReadFromDisk(str);
    std::string const write_png = "/media/marzan/data storage/C++/Modern C++/assignment_3_from_Bonn/igg_image/data/write.png";

    EXPECT_EQ(0, image.ReadFromDisk(str));
    EXPECT_EQ(0, image.WriteToDisk(write_png));
}

TEST(TestImage, ReadWriteTestPPM_With_strategy){
    std::string const str_ppm = "/media/marzan/data storage/C++/Modern C++/assignment_3_from_Bonn/igg_image/data/pbmlib.ascii.ppm";
    igg::Image image_ppm;
    auto strategy_ppm = std::make_shared<igg::PpmIoStrategy>();;
    image_ppm.SetIoStrategy(strategy_ppm);
    image_ppm.ReadFromDisk(str_ppm);
    std::string const write_ppm = "/media/marzan/data storage/C++/Modern C++/assignment_3_from_Bonn/igg_image/data/write_ppm.ascii.ppm";
    image_ppm.WriteToDisk(write_ppm);

    EXPECT_EQ(300, image_ppm.cols());
    EXPECT_EQ(300, image_ppm.rows());
    EXPECT_EQ(1, image_ppm.WriteToDisk(write_ppm));
}

TEST(TestImage, ReadWriteTestPPM_Without_strategy){
    std::string const str_ppm = "/media/marzan/data storage/C++/Modern C++/assignment_3_from_Bonn/igg_image/data/pbmlib.ascii.ppm";
    igg::Image image_ppm;
    image_ppm.ReadFromDisk(str_ppm);
    std::string const write_ppm = "/media/marzan/data storage/C++/Modern C++/assignment_3_from_Bonn/igg_image/data/write_ppm.ascii.ppm";
    image_ppm.WriteToDisk(write_ppm);

    EXPECT_EQ(0, image_ppm.ReadFromDisk(str_ppm));
    EXPECT_EQ(0, image_ppm.WriteToDisk(write_ppm));
}