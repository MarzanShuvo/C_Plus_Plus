#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
int main () {
    cv::Mat image = cv::imread("download.png",cv::IMREAD_COLOR);
    cv::imwrite ("copy.jpg", image);
    return 0;
}