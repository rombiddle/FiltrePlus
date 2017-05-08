#include "mainwindow.h"
#include <QApplication>
#include <QCommandLineParser>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
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
    return app.exec();
}
