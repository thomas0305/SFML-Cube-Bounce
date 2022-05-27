#include <SFML/Graphics.hpp>

// https://www.youtube.com/watch?v=R87RUYUfgwM

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Cube Bouncer");
    window.setFramerateLimit(60);

    sf::RectangleShape rect;

    sf::Vector2f rectanglePosition(300, 200);


    int rectHeight = 100, rectWidth = 100;


    rect.setPosition(rectanglePosition);
    rect.setSize(sf::Vector2f(rectHeight, rectWidth));

    float xVelocity{ 3 };
    float yVelocity{ 3 };

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) 
                window.close();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) 
                window.close();
        }

        //physics
        if (rectanglePosition.x < 0 || rectanglePosition.x > 1280 - rectHeight) {
            xVelocity *= -1;
        }
        if (rectanglePosition.y < 0 || rectanglePosition.y > 720 - rectWidth) {
            yVelocity *= -1;
        }

        rectanglePosition.x += xVelocity;
        rectanglePosition.y += yVelocity;
        rect.setPosition(rectanglePosition);

        //render
        window.clear();
        window.draw(rect);
        window.display();


    }

    return 0;
}
