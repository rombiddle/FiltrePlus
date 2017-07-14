#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QImageWriter>
#include <QFileDialog>
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/core.hpp"
#include <iostream>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
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

    matImage = cv::imread(fileName.toLocal8Bit().data(), CV_LOAD_IMAGE_COLOR);

    //currentImage = qimgNew;
    QImage test = Mat2QImage(matImage);
    ui->lblImage->setPixmap(QPixmap::fromImage(test));
}

void MainWindow::on_saveImageButton_clicked()
{
    cv::imwrite( fileName.toLocal8Bit().data() , matImage );
}

QImage MainWindow::Mat2QImage(cv::Mat const& src)
{
     cv::Mat temp(src.cols,src.rows,src.type());
     cvtColor(src, temp,CV_BGR2RGB);
     QImage dest= QImage((uchar*) temp.data, temp.cols, temp.rows, temp.step, QImage::Format_RGB888);
     return dest;
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
    cv::Mat image = cv::imread(fileName.toLocal8Bit().data(), CV_LOAD_IMAGE_COLOR);
    cv::flip(image, image, 1);

    currentImage = qimgGray;
    matImage = image;
    QImage test = Mat2QImage(image);
    ui->lblImage->setPixmap(QPixmap::fromImage(test));

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

void MainWindow::on_flipCheckBox_clicked()
{
    if (ui->flipCheckBox->isChecked()){
        //cv::Mat image = cv::imread(fileName.toLocal8Bit().data(), CV_LOAD_IMAGE_COLOR);
        cv::flip(matImage, matImage, 1);

        //currentImage = qimgGray;
        //matImage = image;
        QImage test = Mat2QImage(matImage);
        ui->lblImage->setPixmap(QPixmap::fromImage(test));
    }
    ui->flipCheckBox->setDown(true);
    ui->flipCheckBox->setCheckable(false);
}

void MainWindow::on_grisCheckBox_clicked()
{
    if (ui->grisCheckBox->isChecked()){
        cv::cvtColor(matImage, matImage, CV_BGR2GRAY);

        cvtColor(matImage, matImage,cv::COLOR_GRAY2RGB);
        QImage dest= QImage((uchar*) matImage.data, matImage.cols, matImage.rows, matImage.step, QImage::Format_RGB888);

        ui->lblImage->setPixmap(QPixmap::fromImage(dest));
    }
    ui->grisCheckBox->setDown(true);
    ui->grisCheckBox->setCheckable(false);
}

void MainWindow::on_clearButton_clicked()
{
    ui->grisCheckBox->setCheckable(true);
    ui->flipCheckBox->setCheckable(true);
    ui->grisCheckBox->setDown(false);
    ui->flipCheckBox->setDown(false);
    ui->grisCheckBox->setCheckState(Qt::Unchecked);
    ui->flipCheckBox->setCheckState(Qt::Unchecked);
    matImage.release();
    matImage = cv::imread(fileName.toLocal8Bit().data(), CV_LOAD_IMAGE_COLOR);
    QImage test = Mat2QImage(matImage);
    ui->lblImage->setPixmap(QPixmap::fromImage(test));
}
