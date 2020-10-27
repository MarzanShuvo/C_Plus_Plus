
#include "./image.h"
#include "./io_tools.h"
#include<iostream>

namespace igg {
    Image::Image(){}

    Image::Image(int rows, int cols) : rows_{rows}, cols_{cols}{
        data_.reserve(rows_*cols_);
    }

    int Image::rows() const {return rows_;}

    int Image::cols() const {return cols_;}

    int& Image::at(int row, int col){
        return data_.at(row*col+col);
    }

    const int& Image::at(int row, int col) const {
        return data_.at(row*col+col);
    }

    bool Image::FillFromPgm(const std::string& file_name){
         io_tools::ImageData image = io_tools::ReadFromPgm(file_name);

         if(image.data.empty()){
             return false;
         }

         rows_ = image.rows;
         cols_ = image.cols;
         max_val_ = image.max_val;
         data_.swap(image.data);
         return true;
    }

    void Image::WriteToPgm(const std::string& file_name){
        io_tools::ImageData image;
        image.data = data_;
        image.rows = rows_;
        image.cols = cols_;
        image.max_val = max_val_;

        if(io_tools::WriteToPgm(image,file_name)){
            std::cout<<"Succesful to"<<file_name<<std::endl;
        }
        else{
            std::cout<<"Failed to"<<file_name<<std::endl;
        }
        
    }

    std::vector<float> Image::ComputeHistogram(int bins) const {
          int total_size = cols_*rows_;
          std::vector<float> histogram;
          histogram.reserve(bins);

          int span = max_val_/bins;
          for(auto value: histogram){
              int index = value/span;
              histogram[index] = histogram[index]+1;
          }

          for(auto& value: histogram){
              value = value/total_size;
          }

          return histogram;

    }
}

