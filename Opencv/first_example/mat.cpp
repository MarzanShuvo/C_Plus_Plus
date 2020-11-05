#include <opencv2/opencv.hpp>
#include <iostream>
int main () {
    using Matf = cv::Mat_<float>;
    Matf image = Matf::zeros(10, 10);
    Matf image_no_copy = image; // Does not copy!
    image_no_copy.at <float>(5, 5) = 42.42f;
    std::cout << image.at <float>(5, 5) << std::endl;
    Matf image_copy = image.clone(); // Copies image .
    image_copy.at <float >(1, 1) = 42.42f;
    std::cout << image.at <float>(1, 1) <<std::endl;
    }