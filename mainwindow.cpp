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
    this->filter = FiltreManager::FiltreManager();
    initUI();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initUI(){
    // init ui combo box color map
    ui->comboBox->addItem("COLORMAP_AUTUMN");
    ui->comboBox->addItem("COLORMAP_BONE");
    ui->comboBox->addItem("COLORMAP_JET");
    ui->comboBox->addItem("COLORMAP_WINTER");
    ui->comboBox->addItem("COLORMAP_RAINBOW");
    ui->comboBox->addItem("COLORMAP_OCEAN");
    ui->comboBox->addItem("COLORMAP_SUMMER");
    ui->comboBox->addItem("COLORMAP_SPRING");
    ui->comboBox->addItem("COLORMAP_COOL");
    ui->comboBox->addItem("COLORMAP_HSV");
    ui->comboBox->addItem("COLORMAP_PINK");
    ui->comboBox->addItem("COLORMAP_HOT");
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
    ui->NegatifCheckBox->setCheckable(true);

    ui->grisCheckBox->setDown(false);
    ui->lumiereCheckBox->setDown(false);
    ui->flipCheckBox->setDown(false);
    ui->NegatifCheckBox->setDown(false);

    ui->lumiereCheckBox->setCheckState(Qt::Unchecked);
    ui->NegatifCheckBox->setCheckState(Qt::Unchecked);
    ui->grisCheckBox->setCheckState(Qt::Unchecked);
    ui->flipCheckBox->setCheckState(Qt::Unchecked);

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
    if (ui->flipCheckBox->isChecked()){
        manage.setMatImage(filter.flipFiltre(manage.getMatImage()));
        ui->lblImage->setPixmap(QPixmap::fromImage(manage.Mat2QImage(manage.getMatImage())));
    }
    ui->flipCheckBox->setDown(true);
    ui->flipCheckBox->setCheckable(false);
}

void MainWindow::on_grisCheckBox_clicked()
{
    if (ui->grisCheckBox->isChecked()){
        manage.setMatImage(filter.grisFiltre(manage.getMatImage()));
        ui->lblImage->setPixmap(QPixmap::fromImage(QImage((uchar*) manage.getMatImage().data, manage.getMatImage().cols, manage.getMatImage().rows, manage.getMatImage().step, QImage::Format_RGB888)));
    }
    ui->grisCheckBox->setDown(true);
    ui->grisCheckBox->setCheckable(false);
}

void MainWindow::on_NegatifCheckBox_clicked()
{
    if (ui->NegatifCheckBox->isChecked()){
        manage.setMatImage(filter.negatifFiltre(manage.getMatImage()));
        ui->lblImage->setPixmap(QPixmap::fromImage(manage.Mat2QImage(manage.getMatImage())));
    }
    ui->NegatifCheckBox->setDown(true);
    ui->NegatifCheckBox->setCheckable(false);
}


void MainWindow::on_lumiereCheckBox_clicked()
{
    if (ui->lumiereCheckBox->isChecked()){
        manage.setMatImage(filter.lumiereFiltre(manage.getMatImage()));
        ui->lblImage->setPixmap(QPixmap::fromImage(manage.Mat2QImage(manage.getMatImage())));
    }
    ui->lumiereCheckBox->setDown(true);
    ui->lumiereCheckBox->setCheckable(false);
}

void MainWindow::on_flouHorizontalSlider_valueChanged(int value)
{
    ui->lblImage->setPixmap(QPixmap::fromImage(manage.Mat2QImage(filter.flouFiltre(manage.getMatImage(), value))));
    valFlouImage = value;
}

void MainWindow::on_flouHorizontalSlider_sliderReleased()
{
    manage.setMatImage(filter.flouFiltre(manage.getMatImage(), valFlouImage));
    ui->lblImage->setPixmap(QPixmap::fromImage(manage.Mat2QImage(manage.getMatImage())));
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    valColorMap = index;
    ui->lblImage->setPixmap(QPixmap::fromImage(manage.Mat2QImage(filter.colorMapFiltre(manage.getMatImage(), index))));
}

void MainWindow::on_valiserColorMapcheckBox_clicked()
{
    manage.setMatImage(filter.colorMapFiltre(manage.getMatImage(), valColorMap));
    ui->lblImage->setPixmap(QPixmap::fromImage(manage.Mat2QImage(manage.getMatImage())));
}

void MainWindow::on_transposePushButton_clicked()
{
    manage.setMatImage(filter.transposeFiltre(manage.getMatImage()));
    ui->lblImage->setPixmap(QPixmap::fromImage(manage.Mat2QImage(manage.getMatImage())));
    ui->transposePushButton->setDisabled(true);
}
