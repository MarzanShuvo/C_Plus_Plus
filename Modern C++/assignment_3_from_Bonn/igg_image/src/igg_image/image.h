// Copyright Igor Bogoslavskyi, year 2018.
// In case of any problems with the code please contact me.
// Email: igor.bogoslavskyi@uni-bonn.de.

#pragma once

#include <vector>
#include "io_strategies/strategy.h"
#include<memory>
//#include "io_strategies/dummy_strategy.h"
//#include "io_strategies/png_strategy.h"

namespace igg {

class Image {
 public:
  /// A struct within class Image that defines a pixel.
  struct Pixel {
    int red;
    int green;
    int blue;
  };

  // TODO: fill public interface.
  Image(){}
  Image(int rows, int cols);
  void SetIoStrategy(const std::shared_ptr<IoStrategy>& strategy_ptr);
  int rows() const;
  int cols() const;
  //i have faced problem to call it in image.cpp//It is showing error//I was unable to resolve that error
  //so i implemented it here
  //"--------------------------->
  const Pixel& at(int row, int col) const {return data_[row * cols_ + col];}
  Pixel& at(int row, int col) {return data_[row * cols_ + col];}
  //<------------------------------------special type error"
  bool ReadFromDisk(const std::string& file_name);
  bool WriteToDisk(const std::string& file_name);

 private:

  // TODO: add missing private members when needed.
  int rows_ = 0;
  int cols_ = 0;
  int max_val_ = 255;
  std::vector<Pixel> data_;
  std::shared_ptr<IoStrategy> strategy_ptr_ = nullptr;
};

}  // namespace igg
