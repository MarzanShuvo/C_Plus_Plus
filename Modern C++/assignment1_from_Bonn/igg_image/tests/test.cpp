#include "igg_image/image.h"
#include<string>
#include<vector>
#include<gtest/gtest.h>

TEST(TestImage, Initalization){
    igg::Image image(255, 255);
    EXPECT_EQ(255, image.rows());
    EXPECT_EQ(255, image.cols());
}

TEST(TestImage, ReadFromFile){
    std::string file_name = "/media/marzan/data storage/C++/Modern C++/assignment1_from_Bonn/igg_image/data/lena.ascii.pgm";
    igg::Image image(255, 255);
    bool is_found = image.FillFromPgm(file_name);
    EXPECT_EQ(true, is_found);
    EXPECT_EQ(512, image.rows());
    EXPECT_EQ(512, image.cols());
}

TEST(TestImage, ImageAtCheck){
    std::string file_name = "/media/marzan/data storage/C++/Modern C++/assignment1_from_Bonn/igg_image/data/lena.ascii.pgm";
    igg::Image image(255, 255);
    image.FillFromPgm(file_name);
    int val = image.at(1,2);
    image.at(1,3)=163;
    EXPECT_EQ(162, val);
    EXPECT_EQ(163, image.at(1,3));
}

TEST(TestImage, HistogramCheck){
    std::string file_name = "/media/marzan/data storage/C++/Modern C++/assignment1_from_Bonn/igg_image/data/lena.ascii.pgm";
    igg::Image image(255, 255);
    image.FillFromPgm(file_name);
    std::vector<float> histogram = image.ComputeHistogram(4);
    EXPECT_EQ(1, histogram[0]+histogram[1]+histogram[2]+histogram[3]);
}

TEST(TestImage, DownScaleCheck){
    std::string file_name = "/media/marzan/data storage/C++/Modern C++/assignment1_from_Bonn/igg_image/data/lena.ascii.pgm";
    igg::Image image(255, 255);
    image.FillFromPgm(file_name);
    image.DownScale(4);
    EXPECT_EQ(128, image.rows());
    EXPECT_EQ(128, image.cols());
}

TEST(TestImage, UpScaleCheck){
    std::string file_name = "/media/marzan/data storage/C++/Modern C++/assignment1_from_Bonn/igg_image/data/lena.ascii.pgm";
    igg::Image image(255, 255);
    image.FillFromPgm(file_name);
    image.UpScale(2);
    EXPECT_EQ(1024, image.rows());
    EXPECT_EQ(1024, image.cols());
}