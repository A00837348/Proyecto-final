#ifndef VIDEO_H
#define VIDEO_H

#include <iostream>
#include <string>

class Video {
protected:
    std::string tipoVideo;
    std::string nombreVideo;
    std::string genero;
    int calificacion;
    int añoLanzamiento;
    int duracion;

public:
    Video();
    Video(std::string tipo, std::string nombre, std::string genre, int calif, int año, int dur);
    virtual ~Video();
    virtual void muestraDatos();
};

