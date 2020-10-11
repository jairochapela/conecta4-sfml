#include "Tablero.h"
#include "colores.h"

Tablero::Tablero() {

    for (int i = 0; i < 6; i++){
        for (int j = 0; j < 7; j++){
            casillas[i][j] = 0;  
        } 
    } 

    turno = 0;
} 

void Tablero::ponerFicha(int columna, int color){

    if (turno == color) throw "No es turno de este jugador";

    int fila;
    for (fila=5; casillas[fila][columna]!=0; fila--) ;

    if (fila < 0) {
        // no hay posibilidad de colocar ficha ahí
        throw "Esta columna está llena";
    } else {
        casillas[fila][columna] = color;
        turno = color;
    } 

    
} 


int Tablero::comprobarDireccion(int avanceH, int avanceV, int n){

    for (int fila = 0; fila < 6; fila++){
        for (int columna = 0; columna < 7; columna++) {
            int color = casillas[fila][columna];
            if (!color) continue;

            int k;

            for (k = 1; k < n; k++) {
                if (fila + avanceV*k < 0) break;
                if (fila + avanceV*k >= 6) break;
                if (columna + avanceH*k < 0) break;
                if (columna + avanceH*k >= 7) break;
                if (casillas[fila + avanceV*k][columna + avanceH*k] != color) break;
            }

            if (k == n){
                return color;
            } 

        } 
    } 

    return 0;
} 

int Tablero::ganador(){
    int colorGanador;
    // horizontales
    colorGanador = comprobarDireccion(1, 0, 4);
    if (colorGanador) return colorGanador;

    // verticales
    colorGanador = comprobarDireccion(0, 1, 4);
    if (colorGanador) return colorGanador;

    // diagonales
    colorGanador = comprobarDireccion(1, 1, 4);
    if (colorGanador) return colorGanador;

    // diagonales inversas
    colorGanador = comprobarDireccion(-1, 1, 4);
    return colorGanador;
} 

void Tablero::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    static sf::RectangleShape frame(sf::Vector2f(420, 360));
    static sf::CircleShape ficha[6][7];


    target.draw(frame);

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            ficha[i][j].setRadius(25);
            ficha[i][j].setPosition(sf::Vector2f(5 + j*60, 5 + i*60));

            switch (casillas[i][j])
            {
            case ROJO:
                ficha[i][j].setFillColor(sf::Color::Red);
                break;
            
            case AZUL:
                ficha[i][j].setFillColor(sf::Color::Blue);
                break;

            default:
                ficha[i][j].setFillColor(sf::Color::Black);
                break;
            }

            target.draw(ficha[i][j]);
        }
        
    }
    
}

std::ostream& operator<< (std::ostream& o, Tablero& t){
    for (int i=0; i<6; i++){
        for (int j=0; j<7; j++){
            o << t.casillas[i][j];  
        }
        o << std::endl;
    }

    return o;     
} 