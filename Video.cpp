#include "Video.h"

Video::Video() : calificacion(0) {}

Video::Video(std::string tipo, std::string nombre, std::string genre, int calif, int año, int dur)
    : tipoVideo(tipo), nombreVideo(nombre), genero(genre), calificacion(calif), añoLanzamiento(año), duracion(dur) {}

Video::~Video() {}

void Video::muestraDatos() {
    std::cout << "Tipo: " << tipoVideo << std::endl;
    std::cout << "Nombre: " << nombreVideo << std::endl;
    std::cout << "Género: " << genero << std::endl;
    std::cout << "Calificación: " << calificacion << std::endl;
    std::cout << "Año de Lanzamiento: " << añoLanzamiento << std::endl;
    std::cout << "Duración: " << duracion << " minutos" << std::endl;
}