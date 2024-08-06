//
// Created by dang1 on 8/5/2024.
//

#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
using namespace sf;
using namespace std;
#include <cctype>

#ifndef SOCIAL_MEDIA_SORT_DROPDOWN_H
#define SOCIAL_MEDIA_SORT_DROPDOWN_H

class Dropdown {
public:
    Dropdown(float x, float y, float width, float height, const std::vector<std::string>& options, sf::Font &font, std::string label)
            : isOpen(false), selectedIndex(-1) {
        // Setup main button
        mainButton.setPosition(x, y);
        mainButton.setSize(sf::Vector2f(width, height));
        mainButton.setFillColor(sf::Color::White);
        mainButton.setOutlineThickness(1);
        mainButton.setOutlineColor(sf::Color::Black);

        // Setup text for main button
        text.setString(label);
        text.setFont(font);
        text.setCharacterSize(15);
        text.setFillColor(sf::Color::Black);
        text.setPosition(x + 10, y + 5);

        // Setup dropdown options
        for (size_t i = 0; i < options.size(); ++i) {
            sf::RectangleShape optionBox(sf::Vector2f(width, height));
            optionBox.setPosition(x, y + (i + 1) * height);
            optionBox.setFillColor(sf::Color::Black);
            optionBox.setOutlineThickness(1);
            optionBox.setOutlineColor(sf::Color::Black);
            optionBoxes.push_back(optionBox);

            sf::Text optionText;
            optionText.setFont(font);
            optionText.setCharacterSize(15);
            optionText.setFillColor(sf::Color::White);
            optionText.setString(options[i]);
            optionText.setPosition(x + 10, y + (i + 1) * height + 5);
            optionTexts.push_back(optionText);
        }
    }

    void draw(sf::RenderWindow& window) {
        window.draw(mainButton);
        window.draw(text);


        if (isOpen) {
            for (size_t i = 0; i < optionBoxes.size(); ++i) {

                window.draw(optionBoxes[i]);
                window.draw(optionTexts[i]);
            }
        }
    }

    void update(const sf::Vector2i& mousePos, const sf::Event& event) {
        if (mainButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
            if (event.type == sf::Event::MouseButtonPressed) {
                isOpen = !isOpen;
            }
        }

        if (isOpen) {
            for (size_t i = 0; i < optionBoxes.size(); ++i) {
                if (optionBoxes[i].getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                    if (event.type == sf::Event::MouseButtonPressed) {
                        selectedIndex = i;
                        text.setString(optionTexts[i].getString());
                        isOpen = false;

                    }
                }
            }
        }

    }

    int getSelectedIndex() const {
        return selectedIndex;
    }

private:
    sf::RectangleShape mainButton;
    sf::Text text;
    std::vector<sf::RectangleShape> optionBoxes;
    std::vector<sf::Text> optionTexts;
    bool isOpen;
    int selectedIndex;
};

#endif //SOCIAL_MEDIA_SORT_DROPDOWN_H
