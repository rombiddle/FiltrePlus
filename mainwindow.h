#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "imagemanager.h"
#include "filtremanager.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        explicit MainWindow(QWidget *parent = 0);
        ~MainWindow();

    private slots:
        void on_addImageButton_clicked();
        void on_saveImageButton_clicked();
        void on_flipCheckBox_clicked();
        void on_grisCheckBox_clicked();
        void on_clearButton_clicked();
        void on_NegatifCheckBox_clicked();
        void on_lumiereCheckBox_clicked();
        void on_flouHorizontalSlider_valueChanged(int value);
        void on_flouHorizontalSlider_sliderReleased();
        void on_comboBox_currentIndexChanged(int index);
        void on_valiserColorMapcheckBox_clicked();
        void initUI();

        void on_transposePushButton_clicked();

private:
        Ui::MainWindow *ui;
        QString fileName;
        IplImage *iplImg;
        char* charFileName;
        QImage qimgNew;
        QImage qimgGray;
        QImage currentImage;

        ImageManager manage;
        FiltreManager filter;
        int valFlouImage;
        int valColorMap;
};

#endif // MAINWINDOW_H
