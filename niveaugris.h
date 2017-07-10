#ifndef NIVEAUGRIS_H
#define NIVEAUGRIS_H
#include "filtre.h"

class NiveauGris : Filtre
{
private:

public:
    NiveauGris(){}
    cv::Mat traitementImage(cv::Mat image);
};

#endif // NIVEAUGRIS_H
