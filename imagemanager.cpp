#include "imagemanager.h"

ImageManager::ImageManager(){}

void ImageManager::SaveImage(){
    cv::imwrite( fileSource.toLocal8Bit().data() , matImage );
}

QImage ImageManager::Mat2QImage(cv::Mat const& src){
    // conversion
    cv::Mat temp(src.cols,src.rows,src.type());
    cvtColor(src, temp,CV_BGR2RGB);
    QImage dest= QImage((uchar*) temp.data, temp.cols, temp.rows, temp.step, QImage::Format_RGB888);

    // everytime i make a mat -> qimage conversion, it is because I added a filter, so I save the new mat image in matImage
    //matImage = src;

    return dest;
}
