#ifndef FILTRE_H
#define FILTRE_H
#include <QString>

class Filtre
{
public:
    Filtre();
    virtual  cv::Mat traitementImage(cv::Mat image);

};

#endif // FILTRE_H
