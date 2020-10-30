#include "image.h"
#include<iostream>

namespace igg{

    Image::Image(const IoStrategy& io_strategy) : io_strategy_{io_strategy} {}

    Image::Image(int rows, int cols, const IoStrategy& io_strategy) : 
        rows_{rows}, cols_{cols}, io_strategy_{io_strategy} {
        data_.reserve(rows_*cols_);
    }

    int Image::rows() const {return rows_;}

    int Image::cols() const {return cols_;}

    void Image::DownScale(int scale){
        int row_down = rows_/scale;
        int col_down = cols_/scale;
        std::vector<Image::Pixel>downScaledImage;
        downScaledImage.reserve(row_down*col_down);
        for(int i=0; i<rows_; i+=scale){
            for(int j=0; j<cols_; j+=scale){
                downScaledImage.emplace_back(data_[i*cols_+j]);
            }
        }
        rows_ = row_down;
        cols_ = col_down;
        data_ = downScaledImage;    
    }

    void Image::UpScale(int scale){
    int re_cols_ = cols_ * scale;
    int re_rows_ = rows_ * scale;
    std::vector<Image::Pixel> resized_data(re_cols_ * re_rows_);

    for(int i = 0; i < re_rows_; i++){
       for(int j = 0; j < re_cols_; j++){
           resized_data[i * re_cols_ + j] = at(i / scale, j / scale);
       }
    }

    data_ = resized_data;
    rows_ = re_rows_;
    cols_ = re_cols_;
  }

    bool Image::ReadFromDisk(const std::string& file_name){
        const ImageData image = io_strategy_.Read(file_name);
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

    void Image::WriteToDisk(const std::string& file_name){
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
        io_strategy_.Write(file_name, image);
        std::cout<<"Writed to "<<file_name<<std::endl;
        std::cout<<"SuccessFully"<<std::endl;

    }
}

