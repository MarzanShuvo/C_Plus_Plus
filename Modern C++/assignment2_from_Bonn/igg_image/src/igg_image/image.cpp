#include "./image.h"

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
        std::vector<Pixel>downScaledImage;
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
        std::vector<Pixel>upScaledImage;
        upScaledImage.reserve(up_row*up_col);
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

