#include "Jugador.h"
#include "Tablero.h"


Jugador::Jugador(int color){
    Jugador::color = color;
} 


void Jugador::jugarFicha(int columna, Tablero& t){
    try {
        t.ponerFicha(columna, color);
    } catch(const char* excepcion) {
        std::cerr << "Error: " << excepcion << std::endl;
    } 
} 