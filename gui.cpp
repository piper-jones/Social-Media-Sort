#include "gui.h"
#include <iostream>
#include <algorithm>  // For std::shuffle
#include <random>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include "Dropdown.h"
#include "dataBox.h"
#include "statsBox.h"
#include "read.h"

#include "Rank.h"

#include "Post.h"

using namespace sf;
using namespace std;
#include <cctype>


gui::gui(): window(VideoMode(1800, 1200), "Media Mirror") {
    width = 1800;
    height = 1200;
    loadFont();
    readFile(theData.vector);
    run(); }



void gui::loadFont(){
    if (!font.loadFromFile("files/font.ttf")) {
        cout << "Failed to load font" << endl;
    }
}
void gui::setText(){
    mainTitle.setFont(font);
    mainTitle.setString("Media Mirror");
    mainTitle.setCharacterSize(80);
    mainTitle.setFillColor(Color::Yellow);
    mainTitle.setStyle(Text::Bold | Text::Underlined);

    FloatRect textRect = mainTitle.getLocalBounds();
    mainTitle.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    mainTitle.setPosition(Vector2f(width / 2.0f, 50.0f));

    dataTitle.setFont(font);
    dataTitle.setString("Social Media Post Data:");
    dataTitle.setCharacterSize(35);
    dataTitle.setFillColor(Color::White);
    dataTitle.setStyle(Text::Bold);

    FloatRect dataRect = dataTitle.getLocalBounds();
    dataTitle.setOrigin(dataRect.left + dataRect.width / 2.0f, dataRect.top + dataRect.height / 2.0f);
    dataTitle.setPosition(Vector2f(485, 140));

    statsTitle.setFont(font);
    statsTitle.setString("Traditional News Source Data:");
    statsTitle.setCharacterSize(35);
    statsTitle.setFillColor(Color::White);
    statsTitle.setStyle(Text::Bold);

    FloatRect statsRect = statsTitle.getLocalBounds();
    statsTitle.setOrigin(statsRect.left + statsRect.width / 2.0f, statsRect.top + statsRect.height / 2.0f);
    statsTitle.setPosition(Vector2f(1325, 140));
}
void gui::positionText(Text &text, float x, float y, float scale){
    FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width / 2.0f,
                   textRect.top + textRect.height / 2.0f);
    text.setPosition(Vector2f((x/2), (y/2 - scale)));
}
void gui::drawText(){
    window.draw(mainTitle);
    window.draw(dataTitle);
    window.draw(statsTitle);
};

void gui::setOption() {


    Options.setSize(sf::Vector2f(175,550));
    Options.setPosition((25),(height/5));


    Options.setFillColor(Color::White);
}



void gui::drawBoxes() {
    window.draw(Options);
    window.draw(Merge);
    window.draw(Enter1);
    window.draw(Quick);
    window.draw(Enter2);
    window.draw(Random);
    window.draw(Randomizer);

}

void gui::optionContent() {
    Merge.setSize(sf::Vector2f(175,50));
    Merge.setPosition((25),(800));
    Merge.setFillColor(Color::Green);

    Enter1.setString("MergeSort");
    Enter1.setFont(font);
    Enter1.setPosition((60),(800));
    Enter1.setFillColor(Color::Black);
    Enter1.setCharacterSize(20);

    Quick.setSize(sf::Vector2f(175,50));
    Quick.setPosition((25),860);
    Quick.setFillColor(Color::Green);

    Enter2.setString("QuickSort");
    Enter2.setFont(font);
    Enter2.setPosition((60),(860));
    Enter2.setFillColor(Color::Black);
    Enter2.setCharacterSize(20);

    Random.setSize(sf::Vector2f(175,50));
    Random.setPosition(25,920);
    Random.setFillColor(Color::Black);

    Randomizer.setString("Randomize");
    Randomizer.setFont(font);
    Randomizer.setPosition(60,920);
    Randomizer.setFillColor(Color::White);
    Randomizer.setCharacterSize(20);
}

void gui::run() {
    //Set up Dropdown
    std::vector<std::string> options = {"Likes", "Comments", "Shares", "Impressions", "Reach", "Engagement", "Age"};
    Dropdown sorting((25), (height / 4), 175, 50, options, font, "Sort by:");

    std::vector<std::string> option2 = {"Any", "Linkedin", "Instagram", "Twitter", "Facebook"};
    Dropdown Platform((25), (height / 2.5), 175, 50, option2, font, "Platform:");

    std::vector<std::string> option3 = {"Any", "Male", "Female"};
    Dropdown Gender((25), (480 + 60), 175, 50, option3, font, "Gender:");

    std::vector<std::string> option4 = {"Any", "Positive", "Negative", "Neutral"};
    Dropdown Opinion((25), (480 + 120), 175, 50, option4, font, "Opinion:");


    //Ranking Box
    string Top = "Top 3 Posts";
    Rank rank(1000,650,750,475, Top,font);

    optionContent();

    //Top 25 posts in vector
    std::vector<Post> topData;
    for (int i = 1; i <= 25; ++i) {
        topData.push_back(theData.vector[i]);
    }
    //Bottom 25 posts in vector
    std::vector<Post> bottomData;
    for (int i = 25; i >= 1; --i) {
        bottomData.push_back(theData.vector[theData.vector.size() - 1 - i]);
    }

    //Running the data into data box
    dataBox rowsOfData(225, 160, 750, 1000, theData.vector, font);    //Running the statistics into stats box
    statsBox comparisonBox(1000, 160, 750, 475, font);


    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            //press X button in top right-closes program, does not lead to game window
            if (event.type == Event::Closed) {
                window.close();
            }
            //Drop Box Detection
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            sorting.update(mousePos, event);
            Platform.update(mousePos, event);
            Gender.update(mousePos, event);
            Opinion.update(mousePos, event);

            bool dataChanged = false;
            if (Merge.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                if (event.type == sf::Event::MouseButtonPressed && sorting.getSelectedIndex() >= 0) {
                    cout << "merge button pressed" << endl;
                    if (Platform.getSelectedIndex() >= 1) {
                        theData.filterOn("Platform", option2[Platform.getSelectedIndex()]);
                        cout << "platform filter 1" << endl;
                    }
                    if (Gender.getSelectedIndex() >= 1) {
                        theData.filterOn("Gender", option3[Gender.getSelectedIndex()]);
                        cout << "gender filter 2" << endl;
                    }
                    if (Opinion.getSelectedIndex() >= 1) {
                        theData.filterOn("Sentiment", option4[Opinion.getSelectedIndex()]);
                        cout << "sentiment filter 3" << endl;
                    }
                    theData.sortBy(options[sorting.getSelectedIndex()], theData.vector, true);
                    dataChanged = true;
                    rank.UpdateRanking(theData.vector,options[sorting.getSelectedIndex()]);
                    for (int i = 5; i >= 1; --i) {
                        cout << "1" << theData.vector[theData.vector.size() - 1 - i].likes << endl;
                    }
                }
            }
            if (Quick.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                if (event.type == sf::Event::MouseButtonPressed && sorting.getSelectedIndex() >= 1) {
                    cout << "quick button pressed" << endl;
                    if (Platform.getSelectedIndex() >= 1) {
                        theData.setActiveFilter("Platform", option2[Platform.getSelectedIndex()]);
                        cout << "platform filter 2" << endl;
                    }
                    if (Gender.getSelectedIndex() >= 1) {
                        theData.setActiveFilter("Gender", option3[Gender.getSelectedIndex()]);
                        cout << "gender filter 2" << endl;
                    }
                    if (Opinion.getSelectedIndex() >= 1) {
                        theData.setActiveFilter("Sentiment", option4[Opinion.getSelectedIndex()]);
                        cout << "sentiment filter 2" << endl;
                    }
                    theData.filterHandling();
                    theData.sortBy(options[sorting.getSelectedIndex()], theData.vector, false);
                    dataChanged = true;
                    for (int i = 5; i >= 1; --i) {
                        cout << "1" << theData.vector[theData.vector.size() - 1 - i].audienceGender << endl;
                    }
                }
            }

            if (dataChanged) {
                rowsOfData.updateData(theData.vector);
            }

            window.clear(Color::Blue);
            setText();
            setOption();
            drawText();
            drawBoxes();

            Opinion.draw(window);
            Gender.draw(window);
            Platform.draw(window);
            sorting.draw(window);

            rank.Draw(window);
            rowsOfData.draw(window);
            comparisonBox.draw(window);

            window.display();
        }
    }

}

