#include "negatif.h"

cv::Mat Negatif::traitementImage(cv::Mat image){
    cv::Mat imageResult;
    cv::cvtColor(image, imageResult, CV_BGR2HSV);
    return imageResult;
}
