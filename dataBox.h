#pragma once
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include "Post.h" // Ensure this is correctly implemented
using namespace sf;
using namespace std;
#include <cctype>
#include <algorithm>

class dataBox {
public:
    struct Row {
        RectangleShape box;
        Text text1;
        Text text2;

        // Constructor for Row
        Row(float x, float y, float width, float height, const Post& post, Font& font) {
            box.setPosition(x, y);
            box.setSize(Vector2f(width, height));
            box.setFillColor(Color::White);
            box.setOutlineThickness(1);
            box.setOutlineColor(Color::Black);

            // Setup first line of text
            text1.setFont(font);
            text1.setString(post.platform + "      " + post.audienceGender  + "      " + post.sentiment  + "      " + post.postType  + "      " + post.audienceGender);
            text1.setCharacterSize(15);
            text1.setFillColor(Color::Black);
            text1.setPosition(x + 10, y + 2);

             //Setup second line of text
            text2.setFont(font);
            text2.setString("Post Content:  " + post.postContent);
            text2.setCharacterSize(15);
            text2.setFillColor(Color::Blue);
            text2.setPosition(x + 10, y + 19);
        }

        void draw(RenderWindow& window) {
            window.draw(box);
            window.draw(text1);
            window.draw(text2);
        }
    };




    // Corrected Constructor with initializer list
    dataBox(float x, float y, float width, float height, vector<Post>& initData, Font& font)
            : x(x), y(y), width(width), height(height), theData(initData), font(font) {
        background.setPosition(x, y);
        background.setSize(Vector2f(width, height));
        background.setFillColor(Color::Red);
        populateRows();  // Populate rows on initialization
    }

    void populateRows() {
        rows.clear();
        const int margin = 10;  // Horizontal margin inside the box
        const int verticalPadding = 20;  // Padding at the bottom of the box
        int count = 0;
        float effectiveHeight = height - verticalPadding;  // Reduce height to include padding
        float rowHeight = (effectiveHeight / 25) - 1;  // Adjust row height to fit within the new effective height
        float currentY = y + 10;  // Start slightly inside to show top border
        float rowWidth = width - 2 * margin;  // Row width adjusted for margins

        int NthPost = theData.size() - 1;
        for (const auto& post : theData) {
            if (post.display) {
                if (count < 25) {
                    rows.emplace_back(x + margin, currentY, rowWidth, rowHeight, theData[NthPost], font);
                    currentY += rowHeight + 1;
                    count++;
                }
                else {
                    break;
                }
            }
            NthPost--;
        }


//        for (int i = 0; i < 25; ++i) {
//            rows.emplace_back(x + margin, currentY, rowWidth, rowHeight, theData[i], font);
//            currentY += rowHeight + 1;
//        }
    }




    void draw(RenderWindow& window) {
        window.draw(background);
        for (auto& row : rows) {
            row.draw(window);
        }
    }

    void updateData(const vector<Post>& newData) {
        cout << "update data" << endl;
        theData = newData; // Assume this is a mutable vector for now
        populateRows(); // Refresh the rows with the new data
    }

    void clearRows() {
        cout << "clear rows" << endl;
        rows.clear();
    }

    void refreshDisplay() {
        clearRows();
        populateRows();
    }


private:
    RectangleShape background;
    vector<Row> rows;
    vector<Post>& theData; // Now a reference
    Font& font;
    float x, y, width, height;
    string currentSortAttribute;
};
