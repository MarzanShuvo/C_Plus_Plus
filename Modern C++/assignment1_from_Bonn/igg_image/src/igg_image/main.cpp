#include "./io_tools.h"
#include "./image.h"
#include<iostream>
#include<string>

int main() {
    std::string file_name = "/media/marzan/data storage/C++/Modern C++/assignment1_from_Bonn/igg_image/data/lena.ascii.pgm";
    std::string file_name_down = "/media/marzan/data storage/C++/Modern C++/assignment1_from_Bonn/igg_image/data/lena_downscaled.ascii.pgm";
    std::string file_name_up = "/media/marzan/data storage/C++/Modern C++/assignment1_from_Bonn/igg_image/data/lena_upscaled.ascii.pgm";

    std::cout<<file_name<<std::endl;
    
    igg::Image image(50, 50);

    if (!(image.FillFromPgm(file_name))) { 
        return 1;
    }

    if ((image.FillFromPgm(file_name))) { 
        std::cout<<"Image is found"<<std::endl;
    }
    std::cout<<"-------------------------------------------------------------"<<std::endl;
    std::cout<<"Image's Row: "<< image.rows()<<std::endl;
    std::cout<<"Image's column: "<< image.cols()<<std::endl;
    std::cout<<"Image at 1,2: "<< image.at(1,2)<<std::endl;
    std::cout<<"-------------------------------------------------------------"<<std::endl;
    auto histograms =image.ComputeHistogram(4);

    std::cout<<"Histogram size:"<<histograms.size()<<std::endl;
    for(unsigned i=0; i<histograms.size(); i++){
        std::cout<<"histogram Bin["<<i<<"]:"<<histograms[i]<<std::endl;
    }
    //std::cout<<"------------------------------------------------------------"<<std::endl;
    //std::cout<<"image is downscaled by 4"<<std::endl;
    //image.DownScale(4);

    //image.WriteToPgm(file_name_down);
    std::cout<<"------------------------------------------------------------"<<std::endl;
    std::cout<<"image is upscaled by 2"<<std::endl;
    image.UpScale(2);
    std::cout<<"Image's Row after upsacling: "<< image.rows()<<std::endl;
    std::cout<<"Image's column after upscaling: "<< image.cols()<<std::endl;

    image.WriteToPgm(file_name_up);


    
    

    
    return 0;
}

