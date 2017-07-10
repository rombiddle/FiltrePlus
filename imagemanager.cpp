#include "imagemanager.h"
#include <QImageWriter>
#include <QFileDialog>
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/core.hpp"

ImageManager::ImageManager(){}

ImageManager::ImageManager(std::string fileSource)
{
    this->fileSource = fileSource;
}

cv::Mat ImageManager::LoadImage(){
    cv::Mat imageResult;

    imageResult =  imread(this->fileSource, CV_LOAD_IMAGE_COLOR);

    if( imageResult.empty() )                      // Check for invalid input
     {
            std::cout <<  "Erreu l'image n'existe pas" << std::endl ;
            return NULL;
    }

    return imageResult;

}

ImageManager::SaveImage(cv::Mat image){
    imwrite(fileSource, image);

}
