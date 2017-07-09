#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QImageWriter>
#include <QFileDialog>
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/core.hpp"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addImageButton_clicked()
{
    fileName = QFileDialog::getOpenFileName(this,tr("Open Image"),QDir::currentPath(),tr("Image Files [ *.jpg , *.jpeg , *.bmp , *.png , *.gif]"));

    charFileName = fileName.toLocal8Bit().data();

    iplImg = cvLoadImage(charFileName);

    qimgNew = QImage((const unsigned char*)iplImg->imageData,iplImg->width,iplImg->height,QImage::Format_RGB888).rgbSwapped();
    currentImage = qimgNew;

    ui->lblImage->setPixmap(QPixmap::fromImage(qimgNew));
}

void MainWindow::on_saveImageButton_clicked()
{
    //currentImage.save(fileName);
    //QImageWriter writer("outimage.png", "png");
    // writer.setText("Author", "John Smith");
    // writer.write(currentImage);
    QImageWriter write(fileName);
    write.write(currentImage);
}



void MainWindow::on_BlurryRadioButton_clicked()
{
    ui->lblImage->clear();

    IplImage *imgGray = cvLoadImage(fileName.toLocal8Bit().data(), CV_LOAD_IMAGE_GRAYSCALE);

    qimgGray = QImage((const unsigned char*)imgGray->imageData,imgGray->width,imgGray->height,QImage::Format_Indexed8);

    qimgGray.setPixel(0,0,qRgb(0,0,0));
    currentImage = qimgGray;

    ui->lblImage->setPixmap(QPixmap::fromImage(qimgGray));
}




void MainWindow::on_effet2_clicked()
{

   /* ui->lblImage->clear();

     IplImage* img = cvLoadImage(fileName.toLocal8Bit().data());
     cv::namedWindow("Image",CV_WINDOW_AUTOSIZE);

     //Dilate Effect
     cvNot(img, img);
     cv::namedWindow("DilateEffect", CV_WINDOW_AUTOSIZE);
     qimgGray = QImage((const unsigned char*)img->imageData,img->width,img->height,QImage::Format_Indexed8);

     currentImage = qimgGray;

     ui->lblImage->setPixmap(QPixmap::fromImage(qimgGray));*/

    IplImage* img = cvLoadImage(fileName.toLocal8Bit().data());
    cv::namedWindow("Image", CV_WINDOW_AUTOSIZE);
    cvShowImage("Image", img);

    //Negative Effect
    cvNot(img, img);
    cv::namedWindow("NegativeEffect", CV_WINDOW_AUTOSIZE);
    cvShowImage("NegativeEffect", img);

}

void MainWindow::on_effet3_clicked()
{

    IplImage* img = cvLoadImage(fileName.toLocal8Bit().data());
    cv::namedWindow("Image", CV_WINDOW_AUTOSIZE);
    cvShowImage("Image", img);

    //Negative Effect
cvErode(img, img, 0, 2);
cv::namedWindow("NegativeEffect", CV_WINDOW_AUTOSIZE);
    cvShowImage("NegativeEffect", img);





}

void MainWindow::on_effet4_clicked()
{
    IplImage* img = cvLoadImage(fileName.toLocal8Bit().data());
     cv::namedWindow("Image",CV_WINDOW_AUTOSIZE);
     cvShowImage("Image", img);

     //Dilate Effect
     cvDilate(img, img, 0, 2);
     cv::namedWindow("DilateEffect", CV_WINDOW_AUTOSIZE);
     cvShowImage("DilateEffect", img);
}
