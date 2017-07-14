#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/core.hpp"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    QImage Mat2QImage(cv::Mat const& src);
    ~MainWindow();

private slots:
    void on_addImageButton_clicked();

    void on_saveImageButton_clicked();

    void on_BlurryRadioButton_clicked();

    void on_effet2_clicked();

    void on_effet3_clicked();

    void on_effet4_clicked();


private:
    Ui::MainWindow *ui;
    QString fileName;
    IplImage *iplImg;
    char* charFileName;
    QImage qimgNew;
    QImage qimgGray;
    QImage currentImage;
    cv::Mat matImage;
};

#endif // MAINWINDOW_H
