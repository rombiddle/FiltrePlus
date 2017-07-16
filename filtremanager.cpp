#include "filtremanager.h"

FiltreManager::FiltreManager(){}

cv::Mat FiltreManager::flipFiltre(cv::Mat matImage){
    cv::Mat returnMatImage;
    cv::flip(matImage, returnMatImage, 1);
    return returnMatImage;
}

cv::Mat FiltreManager::grisFiltre(cv::Mat matImage){
    cv::Mat returnMatImage;
    cv::cvtColor(matImage, returnMatImage, CV_BGR2GRAY);
    cv::cvtColor(returnMatImage, returnMatImage,cv::COLOR_GRAY2RGB);
    return returnMatImage;
}

cv::Mat FiltreManager::negatifFiltre(cv::Mat matImage){
    cv::Mat returnMatImage;
    cv::threshold(matImage,returnMatImage,70, 255, CV_THRESH_BINARY_INV);
    return returnMatImage;
}

cv::Mat FiltreManager::lumiereFiltre(cv::Mat matImage){
    for( int y = 0; y < matImage.rows; y++ ){
        for( int x = 0; x < matImage.cols; x++ ){
            for( int c = 0; c < 3; c++ ){
                matImage.at<cv::Vec3b>(y,x)[c] = cv::saturate_cast<uchar>( 2.2*( matImage.at<cv::Vec3b>(y,x)[c] ) + 50 );
            }
        }
    }
    return matImage;
}

cv::Mat FiltreManager::flouFiltre(cv::Mat matImage, int val){
    cv::Mat returnMatImage;
    cv::blur(matImage,returnMatImage,cv::Size(val,val));
    return returnMatImage;
}

cv::Mat FiltreManager::colorMapFiltre(cv::Mat matImage, int val){
    cv::Mat returnMatImage;
    cv::applyColorMap(matImage,returnMatImage,val);
    return returnMatImage;
}

cv::Mat FiltreManager::transposeFiltre(cv::Mat matImage){
    cv::Mat returnMatImage;
    cv::transpose(matImage,returnMatImage);
    return returnMatImage;

}

