#include <iostream>
#include <vector>
#include "Video.h"
#include "Pelicula.h"
#include "Serie.h"

void cargarDatos(std::vector<Video*>& videos) {
    std::cout << "Cargando datos desde el archivo..." << std::endl;
}

void mostrarVideos(const std::vector<Video*>& videos, int calificacion, const std::string& genero) {
    std::cout << "Mostrando videos..." << std::endl;
    for (const auto& video : videos) {
        if (video->calificacion >= calificacion && (genero.empty() || video->genero == genero)) {
            video->muestraDatos();
            std::cout << std::endl;
        }
    }
}

void mostrarEpisodios(const std::vector<Video*>& videos, const std::string& serie, int calificacion) {
    std::cout << "Mostrando episodios de la serie " << serie << " con calificación >= " << calificacion << std::endl;
    for (const auto& video : videos) {
        if (video->tipoVideo == "Serie" && video->nombreVideo == serie && video->calificacion >= calificacion) {
            video->muestraDatos();
            std::cout << std::endl;
        }
    }
}

void mostrarPeliculas(const std::vector<Video*>& videos, int calificacion) {
    std::cout << "Mostrando películas con calificación >= " << calificacion << std::endl;
    for (const auto& video : videos) {
        if (video->tipoVideo == "Película" && video->calificacion >= calificacion) {
            video->muestraDatos();
            std::cout << std::endl;
        }
    }
}

void calificarVideo(std::vector<Video*>& videos, const std::string& titulo, int nuevaCalificacion) {
    for (auto& video : videos) {
        if (video->nombreVideo == titulo) {
            video->calificacion = nuevaCalificacion;
            std::cout << "Video '" << titulo << "' ha sido calificado correctamente." << std::endl;
            return;
        }
    }
    std::cout << "Video '" << titulo << "' no encontrado." << std::endl;
}

int main() {
    std::vector<Video*> videos;

    int opcion;
    std::string archivo, genero, titulo;
    int calificacion, nuevaCalificacion;

    do {
        std::cout << " Menú: ";
        std::cout << "1. Cargar archivo de datos ";
        std::cout << "2. Mostrar videos ";
        std::cout << "3. Mostrar episodios de una serie ";
        std::cout << "4. Mostrar películas ";
        std::cout << "5. Calificar un video ";
        std::cout << "6. Salir ";
        std::cout << "Ingrese su opción: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                cargarDatos(videos);
                break;

            case 2:
                std::cout << "Ingrese la calificación mínima (-1 para ignorar): ";
                std::cin >> calificacion;
                std::cout << "Ingrese el género (vacío para ignorar): ";
                std::cin.ignore();
                std::getline(std::cin, genero);
                mostrarVideos(videos, calificacion, genero);
                break;

            case 3:
                std::cout << "Ingrese el nombre de la serie: ";
                std::cin.ignore();
                std::getline(std::cin, titulo);
                std::cout << "Ingrese la calificación mínima: ";
                std::cin >> calificacion;
                mostrarEpisodios(videos, titulo, calificacion);
                break;

            case 4:
                std::cout << "Ingrese la calificación mínima: ";
                std::cin >> calificacion;
                mostrarPeliculas(videos, calificacion);
                break;

            case 5:
                std::cout << "Ingrese el título del contenido a calificar: ";
                std::cin.ignore();
                std::getline(std::cin, titulo);
                std::cout << "Ingrese la nueva calificación: ";
                std::cin >> nuevaCalificacion;
                calificarVideo(videos, titulo, nuevaCalificacion);
                break;

            case 6:
                std::cout << "Saliendo del programa. ";
                break;

            default:
                std::cout << "Opción no válida. Intente de nuevo. ";
        }
    } while (opcion != 6);

    for (auto& video : videos) {
        delete video;
    }

    return 0;
}