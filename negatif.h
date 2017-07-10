#ifndef NEGATIF_H
#define NEGATIF_H

#include "filtre.h"


class Negatif : Filtre
{
public:
    Negatif(){}
    cv::Mat traitementImage(cv::Mat image);
};

#endif // NEGATIF_H
