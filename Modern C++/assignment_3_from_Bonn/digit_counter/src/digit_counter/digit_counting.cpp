#include"./digit_counting.h"

namespace digit{
    double Warp(double number, double factor){
        number = number + factor;
        number = number - factor;
        return number;
    }
    
}