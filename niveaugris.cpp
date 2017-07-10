#include "niveaugris.h"

NiveauGris::NiveauGris()
{
}

cv::Mat NiveauGris::traitementImage(cv::Mat image){
    cv::Mat imageResult;
    cv::cvtColor(image, imageResult, CV_BGR2GRAY);
    return imageResult;
}
