#include "Serie.h"

Serie::Serie(std::string nombre, std::string genero, int calif, int año, int dur, int numTemp)
    : Video("Serie", nombre, genero, calif, año, dur), numTemporadas(numTemp) {}

void Serie::muestraDatos() {
    Video::muestraDatos();
    std::cout << "Número de Temporadas: " << numTemporadas << std::endl;
}