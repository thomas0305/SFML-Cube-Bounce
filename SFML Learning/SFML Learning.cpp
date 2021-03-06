#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

// https://www.youtube.com/watch?v=R87RUYUfgwM

/*
This Function is called every time the corner hits the corner perfectly.
Because of cornerCount is a static variable, the result will be saved until the program is closed, meaning that the number will increase after each time it is called.
*/
int cornerHit() {
    static int cornerCount = 0;
    cornerCount++;
    return cornerCount;
}

int main()
{
    std::cout << "This is a test \n";


    // SETS THE WINDOW SIZE.
    // windowWidth Represents the width of the window, windowHeight represents the height of the window. 
    constexpr int windowWidth = 1280, windowHeight = 720;

    //Creates the window itsself, sets the window to the sizes above, and names the window to "My Program".
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "My Program");
    window.setVerticalSyncEnabled(true);

    //Draws the rectangle, sets its name to rect.
    sf::RectangleShape rect;

    //Creates a 2D vector from SFML's library that stores its X value and Y value. This will be updated in every loop further down. 
    auto rectanglePosition = sf::Vector2f(0.0f, 0.0f);
    auto velocity = sf::Vector2f(3.0f, 3.0f);

    // rectrangle sizes
    constexpr int rectHeight = 100, rectWidth = 150;

    rect.setPosition(rectanglePosition);
    rect.setSize(sf::Vector2f(rectHeight, rectWidth));

    // loop
    while (window.isOpen()) {
        sf::Event event;
          while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) 
                window.close();
        }
          if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
              window.close();

        //Checks if cube hits corner, will print to console if it does.
        if ((rectanglePosition.x == 0 && rectanglePosition.y == 0) || 
            (rectanglePosition.x == windowWidth - rectHeight && rectanglePosition.y == 0) || 
            (rectanglePosition.x == 0 && rectanglePosition.y == windowHeight - rectWidth) || 
            (rectanglePosition.x == windowWidth - rectWidth && rectanglePosition.y == windowHeight - rectHeight)) {
            std::cout << "The cube has hit the corner " << cornerHit() << " times. \n";
        }


        //physics
        // If it touches the border, it will invert the X/Y axis (depending on which it hits) thus making it go the other direction.  
        if (rectanglePosition.x < 0 || rectanglePosition.x > windowWidth - rectHeight) {
            velocity.x *= -1;
        }
        if (rectanglePosition.y < 0 || rectanglePosition.y > windowHeight - rectWidth) {
            velocity.y *= -1;
        }

        rectanglePosition += velocity;
        rect.setPosition(rectanglePosition);

        //render
        window.clear();
        window.draw(rect);
        window.display();


    }

    return 0;
}
