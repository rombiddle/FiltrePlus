#ifndef FILTREMANAGER_H
#define FILTREMANAGER_H

#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/core.hpp"
#include "imagemanager.h"

class FiltreManager
{
    public:
        FiltreManager();
        cv::Mat flipFiltre(cv::Mat matImage);
        cv::Mat grisFiltre(cv::Mat matImage);
        cv::Mat negatifFiltre(cv::Mat matImage);
        cv::Mat lumiereFiltre(cv::Mat matImage);
        cv::Mat flouFiltre(cv::Mat matImage, int val);
        cv::Mat colorMapFiltre(cv::Mat matImage, int val);
        cv::Mat transposeFiltre(cv::Mat matImage);
};

#endif // FILTREMANAGER_H
