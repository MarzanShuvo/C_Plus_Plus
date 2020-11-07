#include "igg_image/image.h"
#include "igg_image/io_strategies/png_strategy.h"
#include "igg_image/io_strategies/ppm_strategy.h"
#include<string>
#include<iostream>
#include<memory>

int main()
{
    std::string const str = "/media/marzan/data storage/C++/Modern C++/assignment_3_from_Bonn/igg_image/data/download.png";

    igg::Image image;
    auto strategy_png = std::make_shared<igg::PngIoStrategy>();;
    image.SetIoStrategy(strategy_png);

    image.ReadFromDisk(str);
    std::cout<<"Png:"<<image.cols()<<image.rows()<<std::endl;
    std::string const write_png = "/media/marzan/data storage/C++/Modern C++/assignment_3_from_Bonn/igg_image/data/write.png";
    image.WriteToDisk(write_png);

    std::string const str_ppm = "/media/marzan/data storage/C++/Modern C++/assignment_3_from_Bonn/igg_image/data/pbmlib.ascii.ppm";
    igg::Image image_ppm;
    auto strategy_ppm = std::make_shared<igg::PpmIoStrategy>();;
    image_ppm.SetIoStrategy(strategy_ppm);
    image_ppm.ReadFromDisk(str_ppm);
    std::cout<<"Ppm:"<<image_ppm.cols()<<image_ppm.rows()<<std::endl;

    std::string const write_ppm = "/media/marzan/data storage/C++/Modern C++/assignment_3_from_Bonn/igg_image/data/write_ppm.ascii.ppm";
    image_ppm.WriteToDisk(write_ppm);
    return 0;
}
