#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

// https://www.youtube.com/watch?v=R87RUYUfgwM

int cornerHit() {
    static int cornerCount = 0;
    cornerCount++;
    return cornerCount;
}

int main()
{
    std::cout << "This is a test \n";


    constexpr int windowWidth = 1280, windowHeight = 720;

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight, "My Program");
    window.setFramerateLimit(60);

    sf::RectangleShape rect;

    sf::Vector2f rectanglePosition(0, 0);


    constexpr int rectHeight = 100, rectWidth = 100;

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

        //Checks if cube hits corner, will print to console if it does.
        if (rectanglePosition.x == 0 && rectanglePosition.y == 0) {
            std::cout << "The cube has hit the corner " << cornerHit() << " times. \n";
        }
        if (rectanglePosition.x == 1280 - rectHeight && rectanglePosition.y == 0) {
            std::cout << "The cube has hit the corner " << cornerHit() << " times. \n";
        }
        if (rectanglePosition.x == 0 && rectanglePosition.y == 720 - rectWidth) {
            std::cout << "The cube has hit the corner " << cornerHit() << " times. \n";
        }
        if (rectanglePosition.x == 1280 - rectHeight && rectanglePosition.y == 720 - rectWidth) {
            std::cout << "The cube has hit the corner " << cornerHit() << " times. \n";
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
