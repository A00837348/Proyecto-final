#ifndef SERIE_H
#define SERIE_H

#include "Video.h"

class Serie : public Video {
private:
    int numTemporadas;

public:
    Serie(std::string nombre, std::string genero, int calif, int año, int dur, int numTemp);
    void muestraDatos() override;
};
