#include "Pelicula.h"

Pelicula::Pelicula(std::string nombre, std::string genero, int calif, int año, int dur, std::string estudio)
    : Video("Película", nombre, genero, calif, año, dur), estudio(estudio) {}

void Pelicula::muestraDatos() {
    Video::muestraDatos();
    std::cout << "Estudio: " << estudio << std::endl;
}