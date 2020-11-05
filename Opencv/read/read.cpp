#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;
int main () {
    Mat i1 = imread("download.png",IMREAD_GRAYSCALE);
    Mat_<uint8_t> i2 = imread ("download.png",IMREAD_GRAYSCALE);
    std::cout << (i1.type() == i2.type()) << std::endl;
    return 0;
}