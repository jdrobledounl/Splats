/*
    El siguiente código crea un vector de Sprite y acumula los círculos (de color rojo cuando el usuario presiona
    el botón izquierdo del mouse y de color azul cuando presiona el botón derecho del mouse)
*/


#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>

int main() { // comienza el programa

    // Creamos la ventana
    sf::RenderWindow window(sf::VideoMode(800, 600, 32), "Agregar Círculos rojos y azules");

    //cargamos la imagen del circulo rojo
    sf::Texture redCircleTexture;
    if (!redCircleTexture.loadFromFile("rcircle.png")) {
        return -1; // Error al cargar la imagen
    }

    //cargamos la imagen del circulo azul
    sf::Texture blueCircleTexture;
    if (!blueCircleTexture.loadFromFile("rcircleb.png")) {
        return -1; // Error al cargar la imagen
    }

    // se crea un vector dinámico de Sprite que irá acumulando los círculos
    std::vector<sf::Sprite> circles;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            //evento que cierra la ventana
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            //ahora detecta si se presiona un boton del mouse
            else if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) { // en caso de ser presionado el boton izquierdo
                    sf::Sprite redCircle(redCircleTexture);
                    redCircle.setPosition(static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y));
                    circles.push_back(redCircle);
                }
                else if (event.mouseButton.button == sf::Mouse::Right) {//en caso de presionar el boton derecho
                    sf::Sprite blueCircle(blueCircleTexture);
                    blueCircle.setPosition(static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y));
                    circles.push_back(blueCircle);
                }
            }
        }
        // Limpiar la ventana en blanco
        window.clear(sf::Color::White);

        // Iteración de los círculos creados para dibujar
        for (const sf::Sprite& circle : circles) {
            window.draw(circle);
        }
        // Mostrar en ventana
        window.display();
    }

    return 0;
}

