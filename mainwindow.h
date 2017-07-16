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
        void on_clearButton_clicked();
        void on_flouHorizontalSlider_valueChanged(int value);
        void on_flouHorizontalSlider_sliderReleased();
        void on_comboBox_currentIndexChanged(int index);
        void initUI();
        void on_transposePushButton_clicked();
        void on_flipPushButton_clicked();
        void on_grisPushButton_clicked();
        void on_negatifPushButton_clicked();
        void on_lumierePushButton_clicked();
        void on_validerPushButton_clicked();
        void activateButton();
        void desactivateButton();

private:
        Ui::MainWindow *ui;
        QString fileName;
        ImageManager manage;
        FiltreManager filter;
        int valFlouImage;
        int valColorMap;
};

#endif // MAINWINDOW_H
