#include "./io_tools.h"
#include "./image.h"
#include<iostream>
#include<string>

int main() {
    std::string file_name = "/media/marzan/data storage/C++/Modern C++/assignment1_from_Bonn/igg_image/data/lena.ascii.pgm";
    
    std::cout<<file_name<<std::endl;
    
    igg::Image image(50, 50);

    if (!(image.FillFromPgm(file_name))) { 
        return 1;
    }

    if ((image.FillFromPgm(file_name))) { 
        std::cout<<"Image is found"<<std::endl;
    }

    std::cout<<"Image's Row"<< image.rows()<<std::endl;
    std::cout<<"Image's column"<< image.cols()<<std::endl;
    std::cout<<"Image at 1,2"<< image.at(1,2)<<std::endl;

    auto histograms =image.ComputeHistogram(4);

    for(auto i=histograms.begin(); i !=histograms.end();++i){
        std::cout<<histograms.size()<<std::endl;
        std::cout<<*i<<std::endl;
    }
    

    
    return 0;
}

