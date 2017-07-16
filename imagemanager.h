#ifndef IMAGEMANAGER_H
#define IMAGEMANAGER_H

#include <QMainWindow>
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/core.hpp"
#include <iostream>

class ImageManager
{
    private:
        QString fileSource;
        cv::Mat matImage;

    public:
        ImageManager();
        QImage Mat2QImage(cv::Mat const& src);
        void SaveImage();

        void setFileSource(QString fileSource) { this->fileSource = fileSource; }
        QString getFileSource() const { return this->fileSource; }

        void setMatImage(cv::Mat matImage) { this->matImage = matImage; }
        cv::Mat getMatImage() const { return this->matImage; }
};

#endif // IMAGEMANAGER_H
