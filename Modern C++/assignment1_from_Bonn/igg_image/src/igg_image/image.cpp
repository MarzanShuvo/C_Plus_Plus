
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
             std::cout<<"file is not found"<<std::endl;
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
            std::cout<<"Succesfully writted to"<<file_name<<std::endl;
        }
        else{
            std::cout<<"Failed to write"<<file_name<<std::endl;
        }
        
    }

    std::vector<float> Image::ComputeHistogram(int bins) const {
          int total_size = cols_*rows_;
          std::vector<float> histogram(bins,0);

          int span = 255/bins;
          for(auto value: data_){
              int index = value/span;
              histogram[index] = histogram[index]+1;
          }

          for(auto& value: histogram){
              value = value/total_size;
          }

          return histogram;

    }

    void Image::DownScale(int scale){
        int row_down = rows_/scale;
        int col_down = cols_/scale;
        std::vector<int> downScaledImage;
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
        int up_row = rows_*scale;
        int up_col = cols_*scale;
        std::vector<int>upScaledImage(up_row*up_col,0);
        // Iterate over the image
	    for (int i = 0; i < rows_; i++) {
	        int row_jump = i * scale;
	        for (int j = 0; j < cols_; j++) {
	            int col_jump = j*scale;
	            // Fill values for upscaled image
	            for (int u = 0; u < scale; u++) {
	                for (int v = 0; v < scale; v++) {
	                    upScaledImage[(row_jump+u)*up_col + col_jump + v] = data_[i*cols_ + j];
	                }
	            }
	        }
	    }

        rows_ = up_row;
        cols_ = up_col;
        data_ = upScaledImage;

    }
}

