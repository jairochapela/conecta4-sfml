#ifndef __JUGADOR__
#define __JUGADOR__


#include "Tablero.h"

class Jugador {
    private:
    int color;

    public:
    Jugador(int color);

    void jugarFicha(int columna, Tablero& t);
};

#endif //__JUGADOR__
