#include "mainwindow.h"
#include <QApplication>
#include <QCommandLineParser>
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/core.hpp"

using namespace std;
using namespace cv;

#include <iostream>
#include <string>
/*#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>*/

int main(int argc, char *argv[])
{
    /*QApplication app(argc, argv);
    QGuiApplication::setApplicationDisplayName(MainWindow::tr("Filtre Plus"));
    QCommandLineParser commandLineParser;
    commandLineParser.addHelpOption();
    commandLineParser.addPositionalArgument(MainWindow::tr("[file]"), MainWindow::tr("Image file to open."));
    commandLineParser.process(QCoreApplication::arguments());
    MainWindow mainWindow;
    if (!commandLineParser.positionalArguments().isEmpty()
        && !mainWindow.loadFile(commandLineParser.positionalArguments().front())) {
        return -1;
    }
    mainWindow.show();
    return app.exec();*/
    QApplication app(argc, argv);
MainWindow mainWindow;
mainWindow.show();
return app.exec();
    String imageName( "/Users/romainbrunie/Pictures/image001.jpg" ); // by default




        //char* imageName = argv[1];
         Mat image;
         image = imread( imageName, 1 );
         /*if( argc != 2 || !image.data )
         {
           printf( " No image data \n " );
           return -1;
         }*/
         Mat gray_image;
         cvtColor( image, gray_image, COLOR_BGR2GRAY );
         imwrite( "/Users/romainbrunie/Pictures/david.jpg", gray_image );
         namedWindow( imageName, WINDOW_AUTOSIZE );
         namedWindow( "Gray image", WINDOW_AUTOSIZE );
         imshow( imageName, image );
         imshow( "Gray image", gray_image );
         waitKey(0);
         return 0;

}

