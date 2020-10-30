#include "igg_image/image.h"
#include "igg_image/io_strategies/png_strategy.h"
#include<string>
#include<iostream>

int main()
{
    std::string const str = "/media/marzan/data storage/C++/Modern C++/assignment2_from_Bonn/igg_image/data/download.png";
    igg::PngIoStrategy strategy;
    igg::Image image(strategy);
    image.ReadFromDisk(str);
    std::cout<<" Row of image :"<<image.rows()<<std::endl;
    std::cout<<" col of image :"<<image.cols()<<std::endl;

    image.UpScale(2);
    std::cout<<" Row of image after Up:"<<image.rows()<<std::endl;
    std::cout<<" col of image after Up:"<<image.cols()<<std::endl;
    std::string const str_wr = "/media/marzan/data storage/C++/Modern C++/assignment2_from_Bonn/igg_image/data/upby2.png";
    image.WriteToDisk(str_wr);

    image.DownScale(2);
    std::cout<<" Row of image after Down:"<<image.rows()<<std::endl;
    std::cout<<" col of image after Down:"<<image.cols()<<std::endl;
    std::string const str_wd = "/media/marzan/data storage/C++/Modern C++/assignment2_from_Bonn/igg_image/data/downby2.png";
    image.WriteToDisk(str_wd);
    

    return 0;
}
