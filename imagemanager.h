#ifndef IMAGEMANAGER_H
#define IMAGEMANAGER_H


class ImageManager
{
private:
    string fileSource;

public:
    ImageManager();
    ImageManager(std::string fileSource);
    cv::Mat LoadImage();
    void SaveImage(cv::Mat image);
    void setFileName(std::string fileName) { this->fileSource = fileName; }
    std::string getFileName() const { return this->fileSource; }


};

#endif // IMAGEMANAGER_H
