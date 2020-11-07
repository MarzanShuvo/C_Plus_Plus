#include "image.h"
#include<iostream>

namespace igg{


    Image::Image(int rows, int cols) : 
        rows_{rows}, cols_{cols}{
        data_.reserve(rows_*cols_);
    }

    void Image::SetIoStrategy(const std::shared_ptr<IoStrategy>& strategy_ptr){
         strategy_ptr_ = strategy_ptr;
    }

    int Image::rows() const {return rows_;}

    int Image::cols() const {return cols_;}

    bool Image::ReadFromDisk(const std::string& file_name){

        if(strategy_ptr_ == nullptr){
            return false;
        }
        
        const ImageData& image = strategy_ptr_->Read(file_name);
        if(image.data.empty()){return false;}
        rows_ = image.rows;
        cols_ = image.cols;
        max_val_ = image.max_val;
        data_.reserve(rows_*cols_);
        for(int i=0; i<rows_*cols_; i++){
                
            data_[i].red = image.data[0][i];
            data_[i].green = image.data[1][i];
            data_[i].blue = image.data[2][i];
        }
        return true;

    }

    bool Image::WriteToDisk(const std::string& file_name){

        if (strategy_ptr_ ==nullptr)
        {
            return false;
        }
        
    
        std::vector<int> red;
        std::vector<int> green;
        std::vector<int> blue;
        red.reserve(rows_*cols_);
        green.reserve(rows_*cols_);
        blue.reserve(rows_*cols_);

        for(int i=0; i<rows_*cols_; i++){
                
            red.emplace_back(data_[i].red);
            green.emplace_back(data_[i].green);
            blue.emplace_back(data_[i].blue);
        }

        ImageData image;
        image.cols = cols_;
        image.rows = rows_;
        image.max_val = max_val_;
        image.data = {red, green, blue};
        strategy_ptr_->Write(file_name, image);
        std::cout<<"Writed to "<<file_name<<std::endl;
        std::cout<<"SuccessFully"<<std::endl;
        return true;

    }
}

