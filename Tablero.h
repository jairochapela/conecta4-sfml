#ifndef __TABLERO__
#define __TABLERO__
#include <iostream>
#include <SFML/Graphics.hpp>


class Tablero : public sf::Drawable {

    private:
    int casillas[6][7];
    int turno;

    public:
    Tablero();
    void ponerFicha(int columna, int color);
    int comprobarDireccion(int avanceH, int avanceV, int n);
    int ganador();

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    
    friend std::ostream& operator<< (std::ostream& o, Tablero& t);
} ;



#endif
