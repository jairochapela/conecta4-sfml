#include <SFML/Graphics.hpp>
#include "Jugador.h"
#include "Tablero.h"
#include "colores.h"

Jugador* jugadorActual = NULL;

void alternarJugador(Jugador& a, Jugador& b) {
    jugadorActual = (jugadorActual == &a)? &b : &a;
}


int main()
{
    Jugador jugador1(ROJO);
    Jugador jugador2(AZUL);
    jugadorActual = &jugador1;

    Tablero tablero;
    int columna = 0;

    sf::CircleShape cursor(15);

    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
    window.setVerticalSyncEnabled(true);

    //tablero.setPosition(sf::Vector2f(40, 40));

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();

            else if (event.type == sf::Event::KeyPressed) {
                switch(event.key.code) {
                    case sf::Keyboard::Key::A:
                    case sf::Keyboard::Key::Left:
                        if (columna>0) columna--;
                        break;

                    case sf::Keyboard::Key::D:
                    case sf::Keyboard::Key::Right:
                        if (columna<6) columna++;
                        break;

                    case sf::Keyboard::Key::Space:
                    case sf::Keyboard::Key::Enter:
                        jugadorActual->jugarFicha(columna, tablero);
                        alternarJugador(jugador1, jugador2);
                }
            }
        }

        cursor.setFillColor(jugadorActual==&jugador1? sf::Color::Red : sf::Color::Blue);
        cursor.setPosition(sf::Vector2f(15 + columna * 60, 370));


        if (tablero.ganador()) {
            //TODO: cambiar estado del juego
            std::cout << "Ganador: " << tablero.ganador() << std::endl;
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        window.draw(tablero);
        window.draw(cursor);

        // end the current frame
        window.display();
    }

    return 0;
}