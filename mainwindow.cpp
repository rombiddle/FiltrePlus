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
    this->manage = ImageManager::ImageManager();
}

MainWindow::~MainWindow()
{
    delete ui;
}

//----------------------------//
//----image manager button----//
//----------------------------//

void MainWindow::on_addImageButton_clicked()
{
    // user file selection in a window
    fileName = QFileDialog::getOpenFileName(this,tr("Open Image"),QDir::currentPath(),tr("Image Files [ *.jpg , *.jpeg , *.bmp , *.png , *.gif]"));

    manage.setFileSource(fileName);

    cv::Mat matImage = cv::imread(manage.getFileSource().toLocal8Bit().data(), CV_LOAD_IMAGE_COLOR);

    // Check for invalid input
    if( !matImage.data )
    {
        ui->lblImage->setText("Erreur lors du chargement de l'image");
    }else{
        manage.setMatImage(matImage);
    }

    QImage test = manage.Mat2QImage(manage.getMatImage());

    ui->lblImage->setPixmap(QPixmap::fromImage(test));
}

void MainWindow::on_saveImageButton_clicked()
{
    manage.SaveImage();
}

void MainWindow::on_clearButton_clicked()
{
    ui->grisCheckBox->setCheckable(true);
    ui->flipCheckBox->setCheckable(true);
    ui->lumiereCheckBox->setCheckable(true);
    ui->BlurryCheckBox->setCheckable(true);

    ui->grisCheckBox->setDown(false);
    ui->lumiereCheckBox->setDown(false);
    ui->flipCheckBox->setDown(false);
    ui->BlurryCheckBox->setDown(false);

    ui->lumiereCheckBox->setCheckState(Qt::Unchecked);
    ui->BlurryCheckBox->setCheckState(Qt::Unchecked);
    ui->grisCheckBox->setCheckState(Qt::Unchecked);
    ui->flipCheckBox->setCheckState(Qt::Unchecked);

    //matImage.release();
    cv::Mat matImage = cv::imread(manage.getFileSource().toLocal8Bit().data(), CV_LOAD_IMAGE_COLOR);

    // Check for invalid input
    if( !matImage.data )
    {
        ui->lblImage->setText("Erreur lors du chargement de l'image");
    }else{
        manage.setMatImage(matImage);
    }

    QImage test = manage.Mat2QImage(manage.getMatImage());
    ui->lblImage->setPixmap(QPixmap::fromImage(test));
}

//----------------------------//
//----filter manager button---//
//----------------------------//

void MainWindow::on_flipCheckBox_clicked()
{
    cv::Mat matImage;
    if (ui->flipCheckBox->isChecked()){
        cv::flip(manage.getMatImage(), matImage, 1);
        manage.setMatImage(matImage);
        QImage test = manage.Mat2QImage(manage.getMatImage());
        ui->lblImage->setPixmap(QPixmap::fromImage(test));
    }
    ui->flipCheckBox->setDown(true);
    ui->flipCheckBox->setCheckable(false);
}

void MainWindow::on_grisCheckBox_clicked()
{
    cv::Mat matImage;
    if (ui->grisCheckBox->isChecked()){
        cv::cvtColor(manage.getMatImage(), matImage, CV_BGR2GRAY);
        cvtColor(matImage, matImage,cv::COLOR_GRAY2RGB);
        manage.setMatImage(matImage);
        QImage dest= QImage((uchar*) matImage.data, matImage.cols, matImage.rows, matImage.step, QImage::Format_RGB888);
        ui->lblImage->setPixmap(QPixmap::fromImage(dest));
    }
    ui->grisCheckBox->setDown(true);
    ui->grisCheckBox->setCheckable(false);
}

void MainWindow::on_BlurryCheckBox_clicked()
{
    cv::Mat matImage;
    if (ui->BlurryCheckBox->isChecked()){
        cv::threshold(manage.getMatImage(),matImage,70, 255, CV_THRESH_BINARY_INV);
        manage.setMatImage(matImage);
        QImage test = manage.Mat2QImage(manage.getMatImage());
        ui->lblImage->setPixmap(QPixmap::fromImage(test));
    }
    ui->BlurryCheckBox->setDown(true);
    ui->BlurryCheckBox->setCheckable(false);
}


void MainWindow::on_lumiereCheckBox_clicked()
{
    cv::Mat matImage = manage.getMatImage();
    if (ui->lumiereCheckBox->isChecked()){
        for( int y = 0; y < matImage.rows; y++ ){
            for( int x = 0; x < matImage.cols; x++ ){
                for( int c = 0; c < 3; c++ ){
                    matImage.at<cv::Vec3b>(y,x)[c] = cv::saturate_cast<uchar>( 2.2*( matImage.at<cv::Vec3b>(y,x)[c] ) + 50 );
                }
            }
        }
        manage.setMatImage(matImage);
        QImage test = manage.Mat2QImage(manage.getMatImage());
        ui->lblImage->setPixmap(QPixmap::fromImage(test));
    }
    ui->lumiereCheckBox->setDown(true);
    ui->lumiereCheckBox->setCheckable(false);
}






