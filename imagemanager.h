#ifndef IMAGEMANAGER_H
#define IMAGEMANAGER_H
#include <QString>
#include <QImage>

class ImageManager
{
private:
    QString fileSource;

public:
    ImageManager();
    ImageManager(QString fileSource);
    cv::Mat LoadImage();
    void SaveImage(cv::Mat image);
    void setFileName(QString fileName) { this->fileSource = fileName; }
    QString getFileName() const { return this->fileSource; }
    QPixmap MatToQPixmap(cv::Mat image);

};

#endif // IMAGEMANAGER_H
