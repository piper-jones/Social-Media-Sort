#pragma once
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include "Post.h"
using namespace sf;
using namespace std;
#include <cctype>
#include <algorithm>

class dataBox {
public:
    struct Row {
        RectangleShape box;
        Text text;

        // Constructor for Row
        Row(float x, float y, float width, float height, const string& textContent, Font& font) {
            box.setPosition(x, y);
            box.setSize(Vector2f(width, height));
            box.setFillColor(Color::White);
            box.setOutlineThickness(1);
            box.setOutlineColor(Color::Black);

            text.setFont(font);
            text.setString(textContent);
            text.setCharacterSize(15);
            text.setFillColor(Color::Black);
            text.setPosition(x + 10, y + 5);
        }

        void draw(RenderWindow& window) {
            window.draw(box);
            window.draw(text);
        }
    };




    // Corrected Constructor with initializer list
    dataBox(float x, float y, float width, float height, const vector<string>& theData, Font& font)
            : x(x), y(y), width(width), height(height), theData(theData), font(font) {
        background.setPosition(x, y);
        background.setSize(Vector2f(width, height)); // Adjust height based on number of rows
        background.setFillColor(Color::Red);

        populateRows();
    }

    void populateRows() {
        const int margin = 10;  // Horizontal margin inside the box
        const int verticalPadding = 20;  // Padding at the bottom of the box
        int numRows = min(100, int(theData.size()));  // Limit the number of rows
        float effectiveHeight = height - verticalPadding;  // Reduce height to include padding
        float rowHeight = (effectiveHeight / 20) - 1;  // Adjust row height to fit within the new effective height

        float currentY = y + 10;  // Start slightly inside to show top border
        float rowWidth = width - 2 * margin;  // Row width adjusted for margins

        for (int i = 0; i < numRows; ++i) {
            string displayText = "Post #" + to_string(i + 1) + ": " + theData[i];
            rows.emplace_back(x + margin, currentY, rowWidth, rowHeight, displayText, font);
            currentY += rowHeight + 1;  // Move to the next row, adding a small gap between rows
        }
    }


    int scrollOffset = 0;

//very flawed attempt to make them scroll, we can revisit later
    void handleEvent(const sf::Event& event) {
        if (event.type == sf::Event::MouseWheelScrolled) {
            int rowHeightInt = static_cast<int>(rowHeight); // Ensure rowHeight is treated as int for calculations

            // Calculate the scroll delta using int type explicitly
            int scrollDelta = static_cast<int>(event.mouseWheelScroll.delta * rowHeightInt);

            if (event.mouseWheelScroll.delta > 0) { // Scrolling up
                scrollOffset = std::max(0, scrollOffset - scrollDelta);
            } else { // Scrolling down
                int maxOffset = std::max(0, static_cast<int>(rows.size()) * rowHeightInt - static_cast<int>(background.getSize().y));
                scrollOffset = std::min(maxOffset, scrollOffset - scrollDelta);
            }
        }
    }

    float effectiveHeight = height - 20;  // Reduce height to include padding
    float rowHeight = (effectiveHeight / 20) - 1;

    void draw(sf::RenderWindow& window) {
        window.draw(background);
        for (size_t i = scrollOffset; i < rows.size() && (i - scrollOffset) * rowHeight < background.getSize().y; i++) {
            rows[i].draw(window);
        }
    }

private:
    RectangleShape background;
    vector<Row> rows;
    const vector<string>& theData; // Now a reference
    Font& font;
    float x, y, width, height;
};
