#pragma once
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include "Post.h"
using namespace sf;
using namespace std;
#include <cctype>

class statsBox {
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
    statsBox(float x, float y, float width, float height, const vector<string>& theData, Font& font)
            : x(x), y(y), width(width), height(height), theData(theData), font(font) {
        background.setPosition(x, y);
        background.setSize(Vector2f(width, theData.size() * height)); // Adjust height based on number of rows
        background.setFillColor(Color::Red);

        populateBox();
    }

    void populateBox() {
        //update to fill in from statistics vector based on whichever filter is currently on or being sorted for
        const int margin = 10;
        int numRows = min(100, int(theData.size())); // Limit to a maximum of 100 rows or the size of the stats.
        float rowHeight = (height / numRows) - 20;
        float rowWidth = width - 20; // Divide the total height by the number of rows.

        float currentY = y + 1;
        for (int i = 0; i < numRows; ++i) {
            string displayText = "Post #" + to_string(i + 1) + ": " + theData[i];
            rows.emplace_back(x + margin, currentY, rowWidth, rowHeight, displayText, font);
            currentY += rowHeight; // Increment by calculated row height.
        }
    }

    void draw(RenderWindow& window) {
        window.draw(background);
        for (auto& row : rows) {
            row.draw(window);
        }
    }

private:
    RectangleShape background;
    vector<Row> rows;
    const vector<string>& theData; // Now a reference
    Font& font;
    float x, y, width, height;
};
