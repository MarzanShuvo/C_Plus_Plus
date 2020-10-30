#include "./image.h"

namespace igg{

    Image::Image(const IoStrategy& io_strategy) : io_strategy_{io_strategy} {}

    Image::Image(int rows, int cols, const IoStrategy& io_strategy) : 
        rows_{rows}, cols_{cols}, io_strategy_{io_strategy} {
        data_.reserve(rows_*cols_);
    }



}

